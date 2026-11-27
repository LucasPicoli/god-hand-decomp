/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */
typedef struct SfdPlay {
    char unk00[0x74];
    unsigned int stat;                  /* 0x74 */
} SfdPlay;

typedef struct SfdHn {
    char unk0000[0x1FC0];
    SfdPlay *play;                      /* 0x1FC0 */
} SfdHn;

/* 1 when the play status admits the request: status 3 only request 3, status 2 requests 2 and 3. */
__attribute__((section(".text.SfdHn_acceptsRequest")))
int SfdHn_acceptsRequest(SfdHn *hn, int req)
{
    unsigned int stat = hn->play->stat;
    int ok = 0;

    switch (stat) {
    case 2:
        if ((unsigned int)(req - 2) < 2)
            ok = 1;
        break;
    case 3:
        ok = (req == stat);
        break;
    case 4:     /* no arm of its own; the label makes gcc root the case tree at 3 as retail does */
        break;
    }
    return ok;
}
