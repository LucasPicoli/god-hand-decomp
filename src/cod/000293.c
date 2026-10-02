/* cEmManage accessors at 0x2930A8..0x293750: the running number, the
 * player-reaction waits, the list head and the unk5A3..unk5A5 bit sets. */
#include "include_asm.h"
#include "godhand/cEmManage.h"

/* Returns the running number and advances it. */
__attribute__((section(".text.cEmManage_getNextNo")))
int cEmManage_getNextNo(cEmManage *self) {
    int no = self->nextNo;
    self->nextNo = no + 1;
    return no;
}

/* Starts the 2-frame unk53A wait. */
__attribute__((section(".text.Obj293_SetByte_53A_2")))
void Obj293_SetByte_53A_2(cEmManage *self) { self->unk53A = 2; }

/* Starts the wait after the player's bomb hit. */
__attribute__((section(".text.cEmManage_SetPlBombHit")))
void cEmManage_SetPlBombHit(cEmManage *self) { self->plBombHit = EM_PL_BOMB_HIT_TIME; }

/* 1 while the bomb-hit wait runs. */
__attribute__((section(".text.cEmManage_CkPlBombHit")))
int cEmManage_CkPlBombHit(cEmManage *self) { return self->plBombHit != 0; }

/* Starts the wait after the player is caught. */
__attribute__((section(".text.cEmManage_SetPlCatched")))
void cEmManage_SetPlCatched(cEmManage *self) { self->plCatched = EM_PL_CATCHED_TIME; }

/* 1 while the player-caught wait runs. */
__attribute__((section(".text.cEmManage_CkPlCatched")))
int cEmManage_CkPlCatched(cEmManage *self) { return self->plCatched != 0; }

/* Starts the wait after the player's sorry pose. */
__attribute__((section(".text.cEmManage_SetPlSorry")))
void cEmManage_SetPlSorry(cEmManage *self) { self->plSorry = EM_PL_SORRY_TIME; }

/* 1 while the player-sorry wait runs. */
__attribute__((section(".text.cEmManage_CkPlSorry")))
int cEmManage_CkPlSorry(cEmManage *self) { return self->plSorry != 0; }

/* The first listed slot. */
__attribute__((section(".text.cEmManage_getTop")))
cEmSlot *cEmManage_getTop(cEmManage *self) { return self->list.top; }

/* func_00293138 (fp+bnel, 376 insn) stays in monolithic — PERMANENT. */

/* Sets bits in unk5A3; Main sets unk5A0 once it reads 3. */
__attribute__((section(".text.Obj293_OrByte_5A3")))
void Obj293_OrByte_5A3(cEmManage *self, unsigned int bits) {
    self->unk5A3 |= bits;
}

/* Clears unk5A3 and unk5A0. Written 5A3 first: with 5A0 first, ee-gcc 2.96
 * puts the 5A0 store in the delay slot, and retail has the 5A3 store there. */
__attribute__((section(".text.Obj293_ClearBytes_5A0_5A3")))
void Obj293_ClearBytes_5A0_5A3(cEmManage *self) {
    self->unk5A3 = 0;
    self->unk5A0 = 0;
}

/* Sets bits in unk5A4; Main sets unk5A1 once it reads 3. */
__attribute__((section(".text.Obj293_OrByte_5A4")))
void Obj293_OrByte_5A4(cEmManage *self, unsigned int bits) {
    self->unk5A4 |= bits;
}

/* Sets bit 0 of unk5A5; Main sets unk5A2 while it is non-zero. */
__attribute__((section(".text.Obj293_OrByte_5A5_1")))
void Obj293_OrByte_5A5_1(cEmManage *self) { self->unk5A5 |= 1; }

/* func_002937C0 (fp+bnel, 288 insn) stays in monolithic — PERMANENT. */

/* func_00293C40 (fp+bnel, 530 insn) stays in monolithic — PERMANENT. */
