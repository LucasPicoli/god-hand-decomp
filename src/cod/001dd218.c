/* sn-2.95.3-136 matched TU. */

extern int sceSifFreeSysMemory(void *);
extern void CustomIDWork_SetNumber(void *, int);
extern int FindAndForwardEntry_3059A8(void *, int, void *);

__attribute__((section(".text.Tramp_sceSifFreeSysMemory_3B5A50")))
int Tramp_sceSifFreeSysMemory_3B5A50(void *a0) {
    return sceSifFreeSysMemory(a0);
}

__attribute__((section(".text.CustomIDWork_SetNumber_1DD218")))
void CustomIDWork_SetNumber_1DD218(void *a0, int a1) {
    CustomIDWork_SetNumber((char *)a0 + 0x918, a1);
}

__attribute__((section(".text.espSys_effDataRelease")))
int espSys_effDataRelease(void *a0, int a1) {
    return FindAndForwardEntry_3059A8(a0, a1, 0);
}
