/* cygnus-2.96 matched TU. */

#include "godhand/mwPlyOpen.h"

extern volatile int D_003EEA78;
extern int D_003EEA7C;
extern unsigned int D_003EEA80;
extern volatile unsigned int *D_0045A260[];
extern int D_003EE098;
extern volatile int D_003EE09C;
extern int D_003EC7DC;
extern char *GetD003EC7E0_3452B0(void);
extern int Forward33BF18_348BC8(void *p);
extern void func_00357240(void);
extern volatile int D_00766CE0;
extern int D_0045A3D0[];
extern char *D_00766D38;
extern int Obj0000_Check_D_0045A460_Magic_And_D_0045A470_Val(void);
extern void func_0036BF50(void);
extern void func_0036C0B0(int a0, int a1);
extern void func_00369E60();
extern void func_0036A378(void);
extern void func_0036BF60(int a0);
extern void func_0036C038(void);
extern void func_0036C0A8(void);
extern void func_0036C628(void);
extern volatile int D_003D140C;
extern int D_003D1414;
extern char D_003C7420[];
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void func_003276A8(void);
extern void func_0032CFC8(char *ent);
extern void Obj3260_Tramp_00338638_D390(void);
extern volatile int D_00451AC0;
extern char D_00452A20[];
extern char D_00452A48[];
extern char D_00452A78[];

/* Drop one nesting level; at zero, write the saved control word (bit 0xC00 toggled) to the register picked by D_003EEA7C unless the low bits say 0x82. Never leaves the count negative. */
__attribute__((section(".text.func_00360AA8")))
void func_00360AA8(void)
{
    D_003EEA78--;
    if (D_003EEA78 == 0 && D_003EEA7C != -1 && (D_003EEA80 & 0xC7) != 0x82)
        *D_0045A260[D_003EEA7C] = D_003EEA80 ^ 0xC00;
    if (D_003EEA78 < 0)
        D_003EEA78 = 0;
}

/* Count the call; with the server active and its work item taken, run the shutdown hook and clear the item's word. */
__attribute__((section(".text.func_00349328")))
void func_00349328(void)
{
    int mode;
    int *work;
    int r;

    D_003EE098++;
    D_003EE09C++;
    mode = D_003EC7DC;
    if (mode == 1) {
        work = (int *)(GetD003EC7E0_3452B0() + 0x5C);
        r = Forward33BF18_348BC8(work);
        if (r == mode) {
            if (D_003EC7DC == r)
                func_00357240();
            *work = 0;
        }
    }
}

/* Initialise the M2V decoder: check the library magic, run the setup steps and clear the work area; returns 0, or the magic check's code when it is the benign one. */
__attribute__((section(".text.func_0036BE00")))
int func_0036BE00(int a0, int a1)
{
    int r;
    char *work;

    D_00766CE0 = (int)D_0045A3D0;
    r = Obj0000_Check_D_0045A460_Magic_And_D_0045A470_Val();
    if (r != 0) {
        if (r != (int)0xFF03FF05) {
            while (1) {
            }
        }
        return r;
    }
    func_0036BF50();
    func_0036C0B0(a0, (int)func_0036BF58((void *)a1));
    work = D_00766D38;
    func_00369E60();
    func_0036A378();
    func_0036BF60((int)work + 0x17E0);
    func_0036C038();
    func_0036C0A8();
    func_0036C628();
    return 0;
}

#define STREAM_ENT_SIZE   0xC8
#define STREAM_ENT_NUM    16

/* Run one pass of the stream manager's start-up unless one is already running: step its state 1, 2, 3, back to 0, refreshing each active entry. */
__attribute__((section(".text.func_0032AFB0")))
void func_0032AFB0(void)
{
    char *ent;
    int i;
    int active;

    Forward33B658_33E678();
    if (D_003D140C != 0) {
        Forward33B670_33E690();
        return;
    }
    D_003D140C = 1;
    Forward33B670_33E690();
    Forward33B658_33E678();
    func_003276A8();
    D_003D140C = 2;
    active = 1;
    ent = D_003C7420;
    for (i = STREAM_ENT_NUM - 1; i >= 0; i--) {
        if (*ent == active)
            func_0032CFC8(ent);
        ent += STREAM_ENT_SIZE;
    }
    D_003D140C = 3;
    Obj3260_Tramp_00338638_D390();
    if (D_003D1414 < 0x33)
        Obj3260_Tramp_00338638_D390();
    D_003D140C = 0;
    Forward33B670_33E690();
}

/* Open a player on a file name with two sizes; report and leave on a null handle or name or a bad size. */
__attribute__((section(".text.func_0032D868")))
void func_0032D868(MwPlyOpen *o, char *file, int a2, int sizeA, int sizeB)
{
    (void)D_00451AC0;   /* dead volatile read, retail has the lw */

    if (o == 0 || file == 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452A20);
        return;
    }
    if (sizeA < 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452A48);
        return;
    }
    if (sizeB <= 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452A78);
        return;
    }
    func_0032DBA0(o);
    Obj33F8_Tramp_0033B658_FC70();
    func_003A57C4(o->name, file);
    o->nameSaved = o->name;
    o->unk1D4 = a2;
    o->unk1D8 = sizeA;
    o->unk1DC = sizeB;
    o->sj = o->sjDefault;
    func_0032F4B0(o->adx, o->sj);
    o->ownSj = 0;
    o->unk1B2 = 1;
    o->stat = 1;
    Obj33F8_Tramp_0033B670_FC88();
}
