#include "godhand/seqNode.h"
#include "godhand/sndTiming.h"
extern int func_00377FA0(void);
extern void func_003777C0(void);
extern void func_0037C930(void);
extern void func_003754A8(SndTiming *sys);
extern void func_0037CA98(void);
extern void func_00386D48(void);
extern void func_00376E00(void);
extern void func_00375F68(void);
extern void func_0037CAE0(void);
extern void func_00374B00(void);
extern void func_003778D8(void);
extern void func_0037CE20(void);
extern void Obj0000_Set_D_0076B080_Field_A4_3754F0(SndTiming *sys);
extern void func_00372CB0(SndVoiceNode *v);

__attribute__((section(".text.func_00375380")))
void func_00375380(void)
{
    unsigned int start;
    unsigned int now;
    int i;
    SndTiming *sys = &D_0076A790;

    if (sys->unk84 != 0) {
        func_00375500();
        sys->unk84 = 0;
    }
    start = *(volatile int *)0x10000800;
    sys->frame++;
    func_00377FA0();
    func_003777C0();
    func_0037C930();
    func_003754A8(sys);
    func_0037CA98();
    func_00386D48();
    func_00376E00();
    func_00375F68();
    func_0037CAE0();
    func_00374B00();
    func_003778D8();
    func_0037CE20();
    Obj0000_Set_D_0076B080_Field_A4_3754F0(sys);
    for (i = 0; i < 3; i++) {
        func_00372CB0(&D_0076A600[i]);
    }
    now = *(volatile int *)0x10000800;
    if (now < start) {
        sys->time = 0;
    } else {
        sys->time = now - start;
    }
    if (sys->time > sys->timeMax) {
        sys->timeMax = sys->time;
    }
}
