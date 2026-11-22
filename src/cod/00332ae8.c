#include "godhand/criFs.h"
#include "godhand/globals.h"
extern int func_00333C00(char *name, CriFileStat *info);
extern int func_00333390(char *name, char *dir);
extern void PushGlobalD8478History_331C78(int id);
extern int func_00398DA0(int a);
extern int func_00332838(CriFileStat *info, char *dir);
extern void func_003260C8(char *fmt, char *dir);
extern void func_00332808(void *obj, char *msg);

__attribute__((section(".text.func_00332AE8")))
int func_00332AE8(char *name)
{
    CriFileStat info;

    if (name == 0) {
        func_00332808(name, D_004542F8);
        return 0;
    }
    func_00333C00(name, &info);
    if (info.found == 0) {
        func_00333390(name, D_003D9C90);
        PushGlobalD8478History_331C78(0x8200);
        func_00398DA0(0);
        PushGlobalD8478History_331C78(0x8201);
        if (func_00332838(&info, D_003D9C90) == 0) {
            func_003260C8(D_00454328, D_003D9C90);
            func_00332808(0, D_00454350);
            return 0;
        }
    }
    return info.found;
}
