/* sn-2.95.3-136 */
/* func_00383170: when enabled, send each list channel's value to the list object (-0x3C0 for flagged channels
 * if any is flagged); otherwise send the master value to the main object (sn-2.95.3-136) */

typedef struct CtlList {
    char pad0[8];
    int count;                  /* 0x08 */
    char pad0C[0x18 - 0xC];
    unsigned char on[8];        /* 0x18 indexed from 1 */
    void *obj;                  /* 0x20 */
} CtlList;

typedef struct ListCtl {
    char pad0[8];
    short vals[(0x64 - 8) / 2]; /* 0x08 [0] master, [1..] per channel */
    void *obj64;                /* 0x64 */
    char pad68[0xA4 - 0x68];
    CtlList list;               /* 0xA4 */
} ListCtl;

extern int func_00383280(void *a0, CtlList *l);
extern void func_0032EC78(int a0, int a1, int a2);
extern void func_0032A9F0(int a0, int a1);

__attribute__((section(".text.func_00383170")))
void func_00383170(void *a0, ListCtl *c, unsigned char enable)
{
    CtlList *l;
    int i;

    if (enable) {
        l = &c->list;
        if (func_00383280(a0, l) != 0) {
            for (i = 0; i < l->count; i++) {
                if (l->on[i + 1])
                    func_0032EC78((int)l->obj, i, -0x3C0);
                else
                    func_0032EC78((int)l->obj, i, c->vals[i + 1]);
            }
        } else {
            for (i = 0; i < l->count; i++)
                func_0032EC78((int)l->obj, i, c->vals[i + 1]);
        }
    } else {
        func_0032A9F0((int)c->obj64, c->vals[0]);
    }
}
