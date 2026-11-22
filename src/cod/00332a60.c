#include "godhand/criFs.h"
#include "godhand/globals.h"
extern int func_00333C00(char *file, CriFileStat *st);
extern int func_00333390(char *file, char *dst);
extern void PushGlobalD8478History_331C78(int tag);
extern int func_00398DA0(int a0);
extern int func_00332838(CriFileStat *st, char *dst);

__attribute__((section(".text.func_00332A60")))
int func_00332A60(char *file)
{
    CriFileStat st;

    if (file == 0)
        return 0;
    func_00333C00(file, &st);
    if (st.found == 0) {
        func_00333390(file, D_003D9C90);
        PushGlobalD8478History_331C78(0x8100);
        func_00398DA0(0);
        PushGlobalD8478History_331C78(0x8101);
        if (func_00332838(&st, D_003D9C90) == 0)
            return 0;
    }
    return 1;
}
