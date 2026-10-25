/* Struct: CGObj33C8_t — mixed byte/short/word fields +0xD..+0xCC; short array at +0xE2. */
#include "include_asm.h"
#include "godhand/criStm.h"
#include "godhand/adxbLoop.h"
#include "godhand/Obj33C8.h"

/* ── CALL CHAIN (4) — deferred ─────────────────────────── */
/* Release the record and clear the whole object. */
__attribute__((section(".text.func_0033C918")))
void func_0033C918(Obj33C8 *self) {
    if (self) {
        Obj33F8 *rec = self->rec;
        self->rec = 0;
        Obj33F8_InitIfNonNull_FA30(rec);
        func_003A52F0(self, 0, OBJ33C8_SIZE);
        self->state = 0;
    }
}

/* ── MEDIUM (1) — large initializer ───────────────────────────────────────*/
INCLUDE_ASM("nonmatching", func_0033CC50);


/* ── ACCESSOR / BRANCHED_LEAF (15) ─────────────────────────────────────── */
__attribute__((section(".text.Obj33C8_SetFields_78_7C")))
void Obj33C8_SetFields_78_7C(char *a0, int a1, int a2) {
    *(int *)(a0 + 0x78) = a1;
    *(int *)(a0 + 0x7C) = a2;
}

__attribute__((section(".text.Obj33C8_GetShort_98")))
int Obj33C8_GetShort_98(char *a0) {
    return *(short *)(a0 + 0x98);
}

__attribute__((section(".text.Obj33C8_GetField_14")))
int Obj33C8_GetField_14(char *a0) {
    return *(int *)(a0 + 0x14);
}

__attribute__((section(".text.Obj33C8_GetByte_D")))
int Obj33C8_GetByte_D(char *a0) {
    return a0[0xD];
}

__attribute__((section(".text.Obj33C8_GetField_10")))
int Obj33C8_GetField_10(char *a0) {
    return *(int *)(a0 + 0x10);
}

__attribute__((section(".text.Obj33C8_GetField_18")))
int Obj33C8_GetField_18(char *a0) {
    return *(int *)(a0 + 0x18);
}

__attribute__((section(".text.Obj33C8_GetShort_24")))
int Obj33C8_GetShort_24(char *a0) {
    return *(short *)(a0 + 0x24);
}

__attribute__((section(".text.Obj33C8_GetField_28")))
int Obj33C8_GetField_28(char *a0) {
    return *(int *)(a0 + 0x28);
}

__attribute__((section(".text.Obj33C8_GetField_2C_OrZeroIfNull")))
int Obj33C8_GetField_2C_OrZeroIfNull(char *a0) {
    if (!a0) return 0;
    return *(int *)(a0 + 0x2C);
}

__attribute__((section(".text.Obj33C8_GetField_30")))
int Obj33C8_GetField_30(char *a0) {
    return *(int *)(a0 + 0x30);
}

__attribute__((section(".text.Obj33C8_GetField_34")))
int Obj33C8_GetField_34(char *a0) {
    return *(int *)(a0 + 0x34);
}

/* Size of the ADX AINF chunk, 0 without one. */
__attribute__((section(".text.ADXB_GetAinfLen")))
int ADXB_GetAinfLen(ADX_BASIC *self) {
    return self->ainfLen;
}

/* AINF volume offset. */
__attribute__((section(".text.ADXB_GetDefOutVol")))
short ADXB_GetDefOutVol(ADX_BASIC *self) {
    return self->defOutVol;
}

/* AINF pan offset of one channel. Byte arithmetic, not defPan[ch]: sn-2.95.3 emits other bytes for the index form. */
__attribute__((section(".text.ADXB_GetDefPan")))
short ADXB_GetDefPan(ADX_BASIC *self, int ch) {
    return *(short *)((char *)self->defPan + ch * 2);
}

/* ── CALL CHAIN (continued) ─────────────────────────────────────────────── */
/* Reload the cached u16 values of the record behind the object. */
__attribute__((section(".text.func_0033CFB8")))
void func_0033CFB8(Obj33C8 *self) {
    Obj33F8_LoadPair_28_2C_F9D8(self->rec, self->pairA, self->pairB);
    Obj33F8_LoadU16Trio_34_FA10(self->rec, &self->trio[0], &self->trio[1], &self->trio[2]);
}
extern void Obj33F8_StorePair_28_2C_F9B0(AdxbDec *dec, unsigned short *a, unsigned short *b);
extern void Obj33F8_StoreS16Trio_34_FA00(AdxbDec *dec, short x, short y, short z);

/* Copy both loop point pairs, then the three loop start shorts, into the decoder. */
__attribute__((section(".text.AdxbLoop_storeLoopInfo")))
void AdxbLoop_storeLoopInfo(AdxbLoop *self)
{
    Obj33F8_StorePair_28_2C_F9B0(self->dec, &self->loopA, &self->loopB);
    Obj33F8_StoreS16Trio_34_FA00(self->dec, self->loopStartX, self->loopStartY, self->loopStartZ);
}
