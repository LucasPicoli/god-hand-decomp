extern void SdeStrCtlFadeOutEnd(void *self);

typedef struct SndSeqCtl {
    unsigned short flags;   /* 0x00 */
    char pad02[0x12];
    unsigned short mode;    /* 0x14 */
    unsigned short count;   /* 0x16 */
    char pad18[0x22];
    short wait;             /* 0x3A */
} SndSeqCtl;

__attribute__((section(".text.strCtlInit")))
void strCtlInit(SndSeqCtl *o)
{
    unsigned short flags = o->flags;

    if (flags & 0x10) {
        if (o->wait == 0) {
            o->flags = flags & ~0x10;
            SdeStrCtlFadeOutEnd(o);
            return;
        }
    }
    if (flags & 2) {
        if (o->count != 0) {
            o->flags = flags | 4;
            o->mode = 2;
        }
    }
}
