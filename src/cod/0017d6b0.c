/* sn-2.95.3-136 matched TU. */

#include "godhand/cScenario.h"
#include "godhand/vu0.h"
#include "godhand/cGameObj.h"
#include "godhand/CustomIDWork.h"
#include "godhand/globals.h"

extern cGameObj *Getplayer(void);
extern int D_003C264C;
extern int D_00747A24;
extern void func_002BFC80(int a0);
extern void cScenario_beginRoomJump_2C4548(cScenario *self, int room, float angle, void *pos, int a3, unsigned int t0, int t1);
extern void CustomIDWork_SetMessNo(CustomIDWork *work, int messNo);
extern void CustomIDWork_SetLocalPosY(CustomIDWork *work, int y);
extern int ClearField5B4IfFlagUnset_1B76B0(int a0);
extern void func_001B76D8(void *a0);
extern float cEmManage_GetSpeedRate(void *a0);
extern char D_005864F0[];

typedef struct RoomJumpTarget {
    float pos[4];               /* 0x00 */
    float angle;                /* 0x10 */
    unsigned char pending;      /* 0x14 */
    char unk15;
    unsigned short roomNo;      /* 0x16 */
} RoomJumpTarget;

__attribute__((section(".text.cScenario_endExtraGame")))
void cScenario_endExtraGame(RoomJumpTarget *target)
{
    float pos[4];
    unsigned short room;
    float angle;
    int dead;

    if (target->pending == 1) {
        target->pending = 0;
        room = target->roomNo;
        VU0_LQC2(4, target, 0);
        VU0_SQC2(4, pos, 0);
        angle = target->angle;
        dead = Getplayer()->hp == 0;
        func_002BFC80(D_003C264C);
        if (dead == 0) {
            cScenario_beginRoomJump_2C4548(D_003C2F84, room, angle, pos, 0, 2, 1);
        } else {
            cScenario_beginRoomJump_2C4548(D_003C2F84, room, angle, pos, 0, 0, 1);
        }
        D_00747A24 = (D_00747A24 | 0x1000000) & 0xF7FFFFFF;
    }
}

#define SLOT_COUNT      5
#define WORK_SIZE       0x7C            /* sizeof(CustomIDWork) */
#define BANK_A_OFFSET   0x630
#define BANK_B_OFFSET   0xB84
#define BANK_Y_OFFSET   0x348

typedef struct { int w[5]; } SlotY;

/* Set message `messNo` on slot `msgSlot` of both banks and move the work entry of slot `ySlot` to that slot's Y
 * from the table. Both slots must be below 5. */
__attribute__((section(".text.CustomIDWork_setSlotMessAndPosY")))
void CustomIDWork_setSlotMessAndPosY(char *self, unsigned char msgSlot, unsigned char ySlot, int messNo)
{
    SlotY tbl;

    if (msgSlot < SLOT_COUNT && ySlot < SLOT_COUNT) {
        int off = msgSlot * WORK_SIZE;
        CustomIDWork_SetMessNo((CustomIDWork *)(self + (off + BANK_A_OFFSET)), messNo);
        CustomIDWork_SetMessNo((CustomIDWork *)(self + (off + BANK_B_OFFSET)), messNo);
        tbl = *(SlotY *)D_0042BDC0;
        CustomIDWork_SetLocalPosY((CustomIDWork *)(self + (ySlot * WORK_SIZE + BANK_Y_OFFSET)), tbl.w[msgSlot]);
    }
}

/* One row of the mode table: this adjust, method index (or -1), table offset in the object, or the inline handler. */
struct Entry_func_0017D6B0 { short f0; short f2; short f4; short f6; };
struct Table_func_0017D6B0 { struct Entry_func_0017D6B0 e[1]; };

extern struct Table_func_0017D6B0 D_003BDA58;

#define OBJ_TIMER_OFFSET  0x608         /* seconds left in the current mode */

/* Mode tick: run the handler of the mode's table row, count the mode timer down by the speed rate (floored at 0), then
 * the shared post-update step. */
__attribute__((section(".text.cEmObj_tickModeTimer")))
void cEmObj_tickModeTimer(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    float rate;
    float left;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDA58 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDA58 + i8 + 4);
    }
    f0 = D_003BDA58.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    rate = cEmManage_GetSpeedRate(D_005864F0);
    left = *(float *)(s0 + OBJ_TIMER_OFFSET) - rate;
    *(float *)(s0 + OBJ_TIMER_OFFSET) = left;
    if (left < 0.0f)
        *(float *)(s0 + OBJ_TIMER_OFFSET) = 0.0f;
    func_001B76D8(s0);
}
