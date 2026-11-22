/* cygnus-2.96 matched TU. */
#include "godhand/cSnd.h"

extern void *func_003A5148(void *dst, const void *src, int n);
extern int func_0034C2D0(void *, void *, void *, int);

__attribute__((section(".text.SFMPVP_IsSceMpegUsed")))
int SFMPVP_IsSceMpegUsed(void *a0) {
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

__attribute__((section(".text.MEM_Copy")))
void *MEM_Copy(void *dst, const void *src, int n) {
    return func_003A5148(dst, src, n);
}

__attribute__((section(".text.SFBUF_RingGetRead")))
int SFBUF_RingGetRead(void *a0, void *a1, void *a2) { return func_0034C2D0(a0, a1, a2, 1); }

__attribute__((section(".text.SFTIM_GetTime")))
int SFTIM_GetTime(void *a0, void *a1, void *a2) {
    char *p = (char *)a0 + 0xD30;
    *(int *)a1 = *(int *)(p + 0x28C);
    *(int *)a2 = *(int *)(p + 0x290);
    return 0;
}
