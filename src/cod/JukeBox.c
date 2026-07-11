/* TU: JukeBox - recovered C++ class. */
#include "include_asm.h"

extern unsigned int D_00747A78;
extern void *D_003C2F84;
typedef struct { char pad[0x1B0]; short f; } CacT;
extern CacT D_005CAC90;              /* struct base; sh @0x1B0 */
extern int D_00747470;               /* fade obj base */
extern int D_005FEE00;               /* arg to func_002D14F8 */
extern void Set_bg_mode(int a, int b, int c, int d);
extern void classFADE_start(void *p, int b, int c, int d, int e, unsigned int f, int g);
extern void classFADE_kill(void *p);
extern void SetFieldsCESignalSemaSleep_2D5AA0(void *p, int a);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void pl00_reset(void *p);
extern void func_001F6B78(void *p, int a);
extern void func_001F6C40(void *p, int a);
extern int func_001F5A98(void *p);
extern void func_001F5E90(void *p);
extern void func_001F5C48(void *p);
extern void func_002D14F8(void *p, float f);

extern void cIDBase(void *);

__attribute__((section(".text.JukeBox")))
void *JukeBox(void *a0) {
    *((unsigned char *)a0 + 0x4) = 0;
    cIDBase((char *)a0 + 0x30);
    *(int *)((char *)a0 + 0x80) = 0;
    return a0;
}

__attribute__((section(".text.JukeBox_Execute")))
void JukeBox_Execute(void *a0)
{
    unsigned int color;

    D_00747A78 = D_00747A78 | 0x4000;
    color = *(int *)((char *)&D_00747A78 + 0x34);

    Set_bg_mode(1, 0, 0, 0);

    D_005CAC90.f = 0x1E;
    classFADE_start(&D_00747470, 0, 0xA, 0, 0, 0xFF000000U, 0xF);
    SetFieldsCESignalSemaSleep_2D5AA0(*(void **)((char *)D_003C2F84 + 0x20), 0xF);

    pl00_reset(Obj0000_Get_D_00747A94_2DB6B0());

    func_001F6B78(a0, 1);
    func_001F6C40(a0, 1);

    if (func_001F5A98(a0) && *(unsigned char *)((char *)a0 + 0x4) == 0) {
        do {
            func_001F5E90(a0);
            SetFieldsCESignalSemaSleep_2D5AA0(
                *(void **)((char *)D_003C2F84 + 0x20), 1);
        } while (*(unsigned char *)((char *)a0 + 0x4) == 0);
    }

    func_001F5C48(a0);

    D_005CAC90.f = 0x1E;
    func_002D14F8(&D_005FEE00, 20.0f);
    func_001F6B78(a0, 0);

    classFADE_start(&D_00747470, 0, 0xA, 0, 0xFF000000, 0, 0xF);
    SetFieldsCESignalSemaSleep_2D5AA0(*(void **)((char *)D_003C2F84 + 0x20), 0xF);
    classFADE_kill(&D_00747470);

    Set_bg_mode(1, color & 0xFF, (color >> 8) & 0xFF, (color >> 16) & 0xFF);

    func_001F6C40(a0, 0);
}
