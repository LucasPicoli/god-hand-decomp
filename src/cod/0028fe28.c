/* cygnus-2.96 matched TU. */
#include "godhand/cEvent.h"

__attribute__((section(".text.func_0028FE28")))
int func_0028FE28(void) { return 0; }

__attribute__((section(".text.func_0028FE30")))
int func_0028FE30(void) { return 0; }

__attribute__((section(".text.func_0028FE38")))
int func_0028FE38(void) { return 0; }

__attribute__((section(".text.func_0028FE40")))
int func_0028FE40(void) { return 0; }

__attribute__((section(".text.func_0028FE48")))
void func_0028FE48(void) {}

__attribute__((section(".text.func_0028FE50")))
int func_0028FE50(void) { return 0; }

__attribute__((section(".text.func_00292F68")))
void func_00292F68(void) {}

__attribute__((section(".text.func_00294AD8")))
void func_00294AD8(void) {}

__attribute__((section(".text.func_002962A8")))
int func_002962A8(int a0) { return a0; }

/* Number of the cutscene. */
__attribute__((section(".text.func_00297B80")))
int func_00297B80(cEvent *self) { return self->dataNo; }

/* Set the callback run once the data has loaded. */
__attribute__((section(".text.func_00297C80")))
void func_00297C80(cEvent *self, void (*onLoaded)(void)) {
    self->onLoaded = onLoaded;
}

__attribute__((section(".text.func_00299860")))
void func_00299860(void) {
}

__attribute__((section(".text.cGameObj_getRot")))
int cGameObj_getRot(int a0) {
    return a0 + 0x100;
}

__attribute__((section(".text.func_002AEF90")))
int func_002AEF90(void *a0) {
    return *(unsigned char*)((char*)a0+0xBF0);
}

__attribute__((section(".text.func_002AEF98")))
void func_002AEF98(void *a0) {
    *(char*)((char*)a0+0xBF0) = 0;
}

__attribute__((section(".text.func_002AF708")))
void func_002AF708(void *a0, int a1) {
    *(short*)((char*)a0+0x54) = a1;
}
