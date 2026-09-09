/* sn-2.95.3-136 matched TU. */

/* cygnus-2.96 matched TU. */

typedef struct {
    unsigned char pad0[0x11C];
    int flags;                            /* +0x11C */
    unsigned char pad120[0x2CB - 0x120];
    unsigned char req;                    /* +0x2CB */
} Obj;

extern void func_002FEB18(Obj *p);

__attribute__((section(".text.func_002E7FA8")))
void func_002E7FA8(Obj *p)
{
    if (p->flags & 0x800000) return;
    if (p->req == 0) return;
    func_002FEB18(p);
}
