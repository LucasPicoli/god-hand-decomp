#include "include_asm.h"

/* ──────────────────────────── small picks ─────────────────────────────── */

/* InitPilotVtable_1B0B70: addiu sp,-0x20; sq s0; sd ra; jal func_001BD580 (daddu s0,a0);
 *                lui v1,%hi(D_00428228); daddu v0,s0; addiu v1,v1,%lo(...);
 *                ld ra; sw v1,0x214(s0); lq s0; jr ra; addiu sp,0x20
 *                13 insns, 52 B — save+forward shape, returns arg unchanged. */
extern void func_001BD580(void *);
extern int D_00428228;

__attribute__((section(".text.InitPilotVtable_1B0B70")))
void *InitPilotVtable_1B0B70(void *a) {
    func_001BD580(a);
    *(int **)((char *)a + 0x214) = &D_00428228;
    return a;
}

/* GetPilotClassDesc_1BDE00: lazy-init singleton getter for &D_00785858; calls
 *                GetOrInitGlobal785878_1B8058() + SetField_0_4_8_31EEA8(&D_00785858, &D_004294D0,
 *                &D_00785878) when the underlying word is 0.
 *                20 insns, 80 B. */
extern int D_00785858;
extern int D_004294D0;
extern int D_00785878;
extern void GetOrInitGlobal785878_1B8058(void);
extern void SetField_0_4_8_31EEA8(void *, void *, void *);

__attribute__((section(".text.GetPilotClassDesc_1BDE00")))
void *GetPilotClassDesc_1BDE00(void) {
    if (D_00785858 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(&D_00785858, &D_004294D0, &D_00785878);
    }
    return &D_00785858;
}

/* GetPilotClassDesc2_2BA948: lazy-init singleton getter for &D_00786358; structurally
 *                identical to GetPilotClassDesc_1BDE00 — calls GetOrInit_460D68_2BAFA0() +
 *                SetField_0_4_8_31EEA8(&D_00786358, &D_0044BE48, &D_00460D68) when
 *                the underlying word is 0.
 *                20 insns, 80 B. */
extern int D_00786358;
extern int D_0044BE48;
extern int D_00460D68;
extern void GetOrInit_460D68_2BAFA0(void);
extern void SetField_0_4_8_31EEA8(void *, void *, void *);

__attribute__((section(".text.GetPilotClassDesc2_2BA948")))
void *GetPilotClassDesc2_2BA948(void) {
    if (D_00786358 == 0) {
        GetOrInit_460D68_2BAFA0();
        SetField_0_4_8_31EEA8(&D_00786358, &D_0044BE48, &D_00460D68);
    }
    return &D_00786358;
}

/* ─────────────────────────── medium picks ─────────────────────────────── */

/* ResetAnimState_1F5EF8: jal cIDBase_restartAnim + 4-arg jal classFADE_start + 1-arg jal
 *                SetFieldsCESignalSemaSleep_2D5AA0 via vtable; sets bytes 0..3 of $a0 struct;
 *                29 insns, 116 B. */
extern void cIDBase_restartAnim(void *);
extern void classFADE_start(void *p, int b, int c, int d, unsigned int e, int f, int g);
extern void SetFieldsCESignalSemaSleep_2D5AA0(void *p, int a);
extern int D_00747470;
extern void *PTR_DAT_003c2f84;

__attribute__((section(".text.ResetAnimState_1F5EF8")))
void ResetAnimState_1F5EF8(unsigned char *this) {
    cIDBase_restartAnim(this + 0x30);
    this[0] = 1;
    this[1] = 1;
    this[2] = 0;
    this[3] = 0;
    classFADE_start(&D_00747470, 0, 0xA, 0, 0xFF000000U, 0, 0xA);
    SetFieldsCESignalSemaSleep_2D5AA0(*(void **)((char *)PTR_DAT_003c2f84 + 0x20), 0xA);
}

/* AllocZeroedBlock_313E50: 28 insns, 112 B — sq-prologue, no VU0, no jumptable. */
extern int D_00747A34;
extern int D_00754C10;
extern void *EnsureInitThenForward_2A9538_30EE08(int size, int align, void *region);
extern void func_003A52F0(void *p, int v, int size);
extern int func_0018B290(void *p);

__attribute__((section(".text.AllocZeroedBlock_313E50")))
int AllocZeroedBlock_313E50(void) {
    void *p;
    if (D_00747A34 & 0x10000) {
        return 0;
    }
    p = EnsureInitThenForward_2A9538_30EE08(0x9C0, 0x10, &D_00754C10);
    if (p == (void *)0) {
        return 0;
    }
    func_003A52F0(p, 0, 0x9C0);
    return func_0018B290(p);
}

/* func_001DE5F8: 116 insns, 464 B — sq-prologue, no VU0, no jumptable. */
INCLUDE_ASM("nonmatching", func_001DE5F8);

/* BuildObjEntry_387160: jal func_00377998 ; conditional ldl/ldr/sdl/sdr 0x20-byte
 *                memcpy loop; multiple sb/sh writes to allocated struct
 *                @ a2+0x10; 66 insns, 264 B. */
extern void *func_00377998(void);
extern void *memcpy(void *dst, const void *src, unsigned int n);

__attribute__((section(".text.BuildObjEntry_387160")))
int BuildObjEntry_387160(short arg1, const void *src) {
    unsigned char *obj = (unsigned char *)func_00377998();
    if (obj == 0) {
        return -1;
    }
    obj[8] = 0x10;
    obj[9] = 2;
    *(short *)(obj + 0x0) = 1;
    *(short *)(obj + 0xA) = 1;
    *(short *)(obj + 0xC) = arg1;
    *(int   *)(obj + 0x4) = 0;
    memcpy(obj + 0x10, src, 0x60);
    return 0;
}

/* ──────────────────────────── large picks ─────────────────────────────── */

/* func_001F35C0: 183 insns, 732 B — sq-prologue, saves $s0..$s4,$ra. */
INCLUDE_ASM("nonmatching", ColiseumEmSelect__Initialize);

/* func_001F4928: 147 insns, 588 B — sq-prologue, saves $s0..$s5,$ra. */
extern void SetCustomIDDispOneOrAll_1F4778(int a0, int a1, int a2);

__attribute__((section(".text.func_001F4928")))
void func_001F4928(int a0, int a1)
{
    SetCustomIDDispOneOrAll_1F4778(a0, 0x50, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x51, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x52, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x53, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x54, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x55, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x56, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x57, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x58, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x59, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x5A, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x5B, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x5C, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x5D, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x5E, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x5F, 0);
    SetCustomIDDispOneOrAll_1F4778(a0, 0x60, 0);
    if (a1 != 0) {
        SetCustomIDDispOneOrAll_1F4778(a0, 0x50, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x51, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x52, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x53, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x54, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x55, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x56, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x57, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x58, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x59, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x5A, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x5B, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x5C, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x5D, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x5E, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x5F, 1);
        SetCustomIDDispOneOrAll_1F4778(a0, 0x60, 1);
    }
}

/* func_002A10E8: 341 insns, 1364 B — sq-prologue, deepest pick;
 *                no VU0, no jumptable. */
INCLUDE_ASM("nonmatching", func_002A10E8);
