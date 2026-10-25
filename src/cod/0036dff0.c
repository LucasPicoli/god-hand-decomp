/* cygnus-2.96: MPV header decode over a stream joint: walk the delimiters, parse each header chunk,
 * pass the parsed bytes on, and stop once a picture is ready or a parser needs more data. */
#include "godhand/criSj.h"
typedef struct SfdCounters {
    char pad000[0x308];
    int f308;                           /* 0x308 */
    int f30C;                           /* 0x30C */
    char pad310[0x494 - 0x310];
    int ready;                          /* 0x494 */
    int bytes;                          /* 0x498 */
    int readyTotal;                     /* 0x49C */
    int bytesTotal;                     /* 0x4A0 */
} SfdCounters;

extern int MPV_GoNextDelimSj(SjObj *sj);
extern char *func_0036E380(char *dec, char *p);
extern char *func_0036EB58(char *dec, char *p);
extern char *MpvBits_searchStartCode(char *dec, char *p);
extern char *func_0036F048(char *dec, char *p);
extern char *func_00372028(char *dec, char *p);
extern char *func_00372590(char *dec, char *p);
extern void func_0033ACA0(SjChunk *ck, int len, SjChunk *head, SjChunk *tail);

__attribute__((section(".text.func_0036DFF0")))
int func_0036DFF0(char *dec, SjObj *sj)
{
    SjChunk ck;
    SjChunk tail;
    SfdCounters *c;
    char *end;
    int d;

    c = (SfdCounters *)(dec + 0x160);
    c->ready = 0;
    c->bytes = 0;
    c->f308 = 0;
    c->f30C = 0;
    for (;;) {
        if ((d = MPV_GoNextDelimSj(sj)) == 0)
            break;
        sj->vt->getChunk(sj, 1, 0x7FFFFFFF, &ck);
        end = 0;
        switch (d) {
        case 0x40:
            end = func_0036E380(dec, ck.data);
            break;
        case 0x80:
            end = func_0036EB58(dec, ck.data);
            break;
        case 0x20:
            end = MpvBits_searchStartCode(dec, ck.data);
            break;
        case 0x10:
            end = func_0036F048(dec, ck.data);
            break;
        case 0x08:
            end = func_00372028(dec, ck.data);
            break;
        case 0x04:
            end = func_00372590(dec, ck.data);
            break;
        }
        if (end == 0) {
            sj->vt->ungetChunk(sj, 1, &ck);
            break;
        }
        func_0033ACA0(&ck, end - (char *)ck.data, &ck, &tail);
        sj->vt->putChunk(sj, 0, &ck);
        sj->vt->ungetChunk(sj, 1, &tail);
        if (c->ready != 0)
            break;
    }
    c->readyTotal += c->ready;
    c->bytesTotal += c->bytes;
    return c->ready != 0 ? -2 : 0;
}
