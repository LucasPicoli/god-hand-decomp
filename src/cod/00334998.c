/* cygnus-2.96: func_00334998, stop a running stream: cancel its request, then poll until it leaves
 * state 2 (giving up with an error after 0x63FFF6 polls) and reset it. */
typedef struct CdStream {
    char unk00[2];
    char state;                 /* 0x02 */
    char unk03[0x25];
    int pos;                    /* 0x28 */
    void *req;                  /* 0x2C */
} CdStream;

extern void func_00334008(CdStream *s, char *msg);
extern int func_00331570(void *req);
extern void CdSrd_finishRead(void);
extern void func_003341B8(void);
extern int func_00334A90(CdStream *s);
extern void func_00333FD8(void);
extern void func_003260C8(char *msg);
extern char D_004549C0[];
extern char D_004549D8[];

__attribute__((section(".text.func_00334998")))
void func_00334998(CdStream *s)
{
    int n = 0;

    if (s == 0) {
        func_00334008(s, D_004549C0);
        return;
    }
    if ((unsigned char)s->state < 2)
        return;
    if (s->req != 0)
        func_00331570(s->req);
    for (;;) {
        CdSrd_finishRead();
        func_003341B8();
        func_00334A90(s);
        if (s->state != 2)
            break;
        if (++n > 0x63FFF6) {
            func_003260C8(D_004549D8);
            break;
        }
        func_00333FD8();
    }
    s->state = 0;
    s->pos = 0;
}
