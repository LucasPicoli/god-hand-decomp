/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct {
    int           cmd;
    int           port;
    int           slot;
    unsigned char align[6];
    unsigned char pad12[2];
    int           result;
    int           rest[26];
} PadSif;

extern PadSif D_0077C300;
extern char   D_0077C0C0[];




__attribute__((section(".text.scePadSetActAlign")))
int scePadSetActAlign(int port, int slot, const unsigned char *align)
{
    PadSif *p = &D_0077C300;
    int i;
    int r;

    p->cmd  = 8;
    p->port = port;
    p->slot = slot;
    for (i = 0; i < 6; i++)
        p->align[i] = align[i];
    if (func_003B3128(D_0077C0C0, 1, 0, p, 128, p, 128, 0, 0) < 0)
        return 0;
    r = p->result;
    if (r == 1) {
        func_00397E18(port, slot, 2);
        r = p->result;
    }
    return r;
}
