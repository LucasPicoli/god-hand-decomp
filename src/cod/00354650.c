/* cygnus-2.96: create the MPV decoder for a Sofdec handle: set it up with its header callback, picture
 * sizes and mode, and attach the work buffer when one is configured. */
#include "godhand/sftim.h"
typedef struct SfdDecView {
    char pad0[0x38];
    int mode;               /* 0x38 */
    char pad3C[0x1FC0 - 0x3C];
    void *dec;              /* 0x1FC0 */
    char pad1FC4[0x23A8 - 0x1FC4];
    int mpv;                /* 0x23A8 */
} SfdDecView;

extern int D_00766C18;
extern int D_00766C1C;
extern int D_00766C20;

extern int SfdDec_init(SfdDecView *sf, int *dec);
extern void func_003563B8(SfdDecView *sf);
extern int func_0036C248(void);
extern int func_00369E98(int mpv, int (*cb)(int a0, int a1), SfdDecView *sf);
extern int func_00354D68(int mpv);
extern int func_0036C450(int mpv, int id, int val);
extern int ReturnK_003EE2BC_00358A38_358A38(void);
extern void func_00350528(SfdDecView *sf, int a, int b, int c);
extern int func_00354B98(int a0, int a1);

__attribute__((section(".text.func_00354650")))
int func_00354650(SfdDecView *sf)
{
    int *dec = &sf->mpv;
    int r;
    int mpv;

    r = GetArrayElemA0C_35A1C8(sf, 5);
    if (r == 0)
        return r;
    sf->dec = dec;
    r = SfdDec_init(sf, dec);
    if (r != 0)
        return r;
    func_003563B8(sf);
    mpv = func_0036C248();
    if (mpv == 0)
        return func_0034DD70(0, 0xFF000F0A);
    if (func_00369E98(mpv, func_00354B98, sf) != 0) {
        func_00354D68(mpv);
        return func_0034DD70(0, 0xFF000F0B);
    }
    func_0036C450(mpv, 1, GetArrayElemA0C_35A1C8(sf, 0));
    func_0036C450(mpv, 2, GetArrayElemA0C_35A1C8(sf, 1));
    func_0036C450(mpv, 6, sf->mode);
    *dec = mpv;
    if (ReturnK_003EE2BC_00358A38_358A38() != 0)
        func_00350528(sf, D_00766C18, D_00766C1C, D_00766C20);
    return 0;
}
