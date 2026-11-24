#include "godhand/cCollisionSolid.h"
extern int D_005CAFF0;
extern int D_00463050;

__attribute__((section(".text.func_001352F8")))
void func_001352F8(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        func_00134650(&D_00462FC0);
    }
}

__attribute__((section(".text.Forward1352F8_135328")))
void Forward1352F8_135328(void) {
    func_001352F8(1, 0xFFFF);
}

__attribute__((section(".text.func_00138F98")))
void func_00138F98(void *a0) {
    if (*(int *)((char *)a0 + 0x1028) & 4) {
        cCamera_move(D_005CAFF0);
    }
}

__attribute__((section(".text.func_00139010")))
void func_00139010(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        func_00138BE8(&D_00463050);
    }
}

__attribute__((section(".text.Forward139010_139040")))
void Forward139010_139040(void) {
    func_00139010(1, 0xFFFF);
}
