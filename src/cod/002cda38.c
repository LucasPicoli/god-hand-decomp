/* cygnus-2.96 matched TU. */
#include "godhand/cSnd.h"

extern void func_003A5148(void);
extern void func_0034C2D0(void *, void *, void *, int);

__attribute__((section(".text.func_00356358")))
int func_00356358(void *a0) {
    void *v1 = *(void **)((char *)a0 + 0x1FC0);
    return *(int *)((char *)v1 + 0x1128) != 0;
}

__attribute__((section(".text.func_0032F4C8")))
int func_0032F4C8(void *a0) {
    return *(signed char *)((char *)a0 + 0xAC);
}

/* True while the voice holds a sound-driver handle. */
__attribute__((section(".text.cSndSeVoice_IsActive")))
int cSndSeVoice_IsActive(cSndSeVoice *v) {
    return v->handle != 0;
}

__attribute__((section(".text.func_00366960")))
void func_00366960(void) {
    func_003A5148();
}

__attribute__((section(".text.func_0034C2B8")))
void func_0034C2B8(void *a0, void *a1, void *a2) {
    func_0034C2D0(a0, a1, a2, 1);
}

__attribute__((section(".text.func_0035AB98")))
int func_0035AB98(void *a0, void *a1, void *a2) {
    char *p = (char *)a0 + 0xD30;
    *(int *)a1 = *(int *)(p + 0x28C);
    *(int *)a2 = *(int *)(p + 0x290);
    return 0;
}
