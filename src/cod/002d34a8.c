/* sn-2.95.3-136 matched TU. */

#include "godhand/StreamBuf.h"

#define SD_TRANS_START 0x80D0   /* sceSdRemote command: start a voice transfer */
#define SD_TRANS_STAT  0x80F0   /* sceSdRemote command: transfer status */

extern int func_002D3210(void *self);               /* flags & STREAMBUF_F_USED */
extern void StreamBuf_startRead(StreamBuf *self, int slot);
extern void func_002D3388(char *self);
extern int func_002D3220(void *self);               /* clear the record */
extern int SifDmaStat(unsigned int id);
extern int sceSdRemote(int arg, int cmd, ...);
extern int Tramp_sceSifFreeSysMemory_3B5A50(void *p);

/* Step a stream once: in one-slot mode wait for the read and finish; in
 * two-slot mode start EE reads into idle slots, send each finished read on
 * to SPU2, and when everything is sent free the buffers and finish. */
__attribute__((section(".text.func_002D34A8")))
void func_002D34A8(StreamBuf *self)
{
    int i;
    int st;
    void **p;
    unsigned int n;

    if (func_002D3210(self) == 0)
        return;
    if (self->dual == 0) {
        if (self->flags & STREAMBUF_F_STARTED) {
            if (SifDmaStat(self->handle[0]) < 0)
                func_002D3220(self);
            return;
        }
        StreamBuf_startRead(self, 0);
        return;
    }
    if (!(self->flags & STREAMBUF_F_STARTED))
        func_002D3388((char *)self);
    for (i = 0; i < STREAMBUF_NSLOT; i++) {
        st = self->state[i];
        switch (st) {
        case STREAMBUF_ST_IDLE:
            self->state[i] = STREAMBUF_ST_READING;
            StreamBuf_startRead(self, i);
            break;
        case STREAMBUF_ST_READING:
            if (SifDmaStat(self->handle[i]) >= 0 || self->busy != 0)
                break;
            self->busy = st;
            n = self->limit;
            if (self->spuLeft < n)
                n = self->spuLeft;
            self->spuLen = n;
            sceSdRemote(1, SD_TRANS_START, 0, 0, self->bufDst[i],
                        self->spuBase + self->spuPos, n);
            self->state[i] = STREAMBUF_ST_SPU;
            break;
        case STREAMBUF_ST_SPU:
            if (sceSdRemote(1, SD_TRANS_STAT, 0, 0) == 1)
                self->busy = st;
            if (self->busy == st) {
                self->spuPos += self->spuLen;
                self->spuLeft -= self->spuLen;
                if (self->left != 0)
                    self->state[i] = STREAMBUF_ST_IDLE;
                else
                    self->state[i] = STREAMBUF_ST_DONE;
                self->busy = 0;
            }
            /* fall through */
        case STREAMBUF_ST_DONE:
            if (self->spuLeft != 0)
                break;
            p = self->bufDst;
            for (i = 1; i >= 0; i--, p++) {
                if (*p != 0) {
                    Tramp_sceSifFreeSysMemory_3B5A50(*p);
                    *p = 0;
                }
            }
            func_002D3220(self);
            return;
        default:
            break;
        }
    }
}
