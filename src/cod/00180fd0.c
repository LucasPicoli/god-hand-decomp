/* sn-2.95.3-136 matched TU. */

#include "godhand/ColiseumBattle.h"

extern char D_00747470[];
extern void classFADE_kill(void *p);
extern void classFADE_start(void *p, int b, int c, int d, unsigned int e, unsigned int f, int g);
extern void func_00300D20(int a0, int a1);
extern void func_002FB898(int a0, int a1);
extern void func_003009F8(int a0, int a1);
extern void func_002FBA60(int a0, int a1, int a2);
extern int ClearField5B4IfFlagUnset_1B76B0(int a0);
extern void func_002A87E8(void *a0, int a1);
extern void func_001B76D8(void *a0);
extern void func_001AC908(void *);
extern void func_001810A0(void *);
extern void cModel_calcParts(void *);
extern void cModel_calcWorldParts(void *);

/* Start a screen fade (mode 0 fades to black, mode 1 from black): stop a running fade first, then flag a fade as running. */






__attribute__((section(".text.func_001F4428")))
void func_001F4428(ColiseumBattle *self, unsigned char mode)
{
    long t = self->flags;
    unsigned int f;

    if (((t >> 1) % 2L) != 0L) {
        classFADE_kill(D_00747470);
        self->flags = (int)self->flags & ~COLISEUM_FLAG_FADE;
    }
    switch (mode) {
    case 0:
    default:
        classFADE_start(D_00747470, 0, 0xA, 0, 0xFF000000u, 0, 0xF);
        break;
    case 1:
        classFADE_start(D_00747470, 0, 0xA, 0, 0, 0xFF000000u, 0xF);
        /* net no-op; its flag stores make jump2 share the two call tails, as retail does */
        self->flags++;
        self->flags--;
        break;
    }
    f = self->flags;
    do { } while (0);   /* keeps the epilogue restores behind the flag store */
    self->flags = f | COLISEUM_FLAG_FADE;
}

/* Remove an effect from one or both of its lists: mode 0 the first list, 1 the second, 2 both. */



__attribute__((section(".text.KillEffect_306168")))
void KillEffect_306168(int a0, int a1, int a2) {
    switch (a2) {
    case 0:
        func_00300D20(a0, a1);
        break;
    case 1:
        func_002FB898(a0, a1);
        break;
    case 2:
        func_002FB898(a0, a1);
        func_00300D20(a0, a1);
        break;
    }
}

/* Remove an effect (unless it is the null/-1 pair) from one or both lists; mode 0 first list, 1 second list with flag, 2 both. */



__attribute__((section(".text.func_003063B8")))
void func_003063B8(int a0, int a1, int a2, unsigned char a3) {
    if (a0 == 0 && a1 == -1) {
        return;
    }
    switch (a2) {
    case 0:
        func_003009F8(a0, a1);
        break;
    case 1:
        func_002FBA60(a0, a1, a3);
        break;
    case 2:
        func_002FBA60(a0, a1, a3);
        func_003009F8(a0, a1);
        break;
    }
}

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */
struct Entry_func_001AC838 { short f0; short f2; short f4; short f6; };
struct Table_func_001AC838 { struct Entry_func_001AC838 e[1]; };




extern struct Table_func_001AC838 D_003BDC18;


__attribute__((section(".text.func_001AC838")))
void func_001AC838(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDC18 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDC18 + i8 + 4);
    }
    f0 = D_003BDC18.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_001AC908(s0);
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */
struct Entry_func_00180FD0 { short f0; short f2; short f4; short f6; };
struct Table_func_00180FD0 { struct Entry_func_00180FD0 e[1]; };




extern struct Table_func_00180FD0 D_003BDAF8;


__attribute__((section(".text.func_00180FD0")))
void func_00180FD0(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDAF8 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDAF8 + i8 + 4);
    }
    f0 = D_003BDAF8.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_001810A0(s0);
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */
struct Entry_func_001B5A58 { short f0; short f2; short f4; short f6; };
struct Table_func_001B5A58 { struct Entry_func_001B5A58 e[1]; };




extern struct Table_func_001B5A58 D_003BDD60;



__attribute__((section(".text.func_001B5A58")))
void func_001B5A58(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDD60 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDD60 + i8 + 4);
    }
    f0 = D_003BDD60.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    cModel_calcParts(s0);
    cModel_calcWorldParts(s0);
    func_001B76D8(s0);
}
