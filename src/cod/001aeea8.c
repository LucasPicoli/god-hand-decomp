/* func_001AEEA8 — stash a1 at +0x986; when phase byte +0x2F5 == 1, run the
 * 0x30F348 handler and fire func_002A8578 against record field 0x14 or 0x18
 * depending on the handler's low bit.  sn-2.95.3-136. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int irand(void *a0);

__attribute__((section(".text.func_001AEEA8")))
void func_001AEEA8(void *a0, int a1){
    char *s0 = (char *)a0;
    int v0;
    *(short *)(s0 + 0x986) = (short)a1;
    if (*(unsigned char *)(s0 + 0x2F5) == 1) {
        if (irand(s0) & 1) {
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x14) + v0, 0, 0.0f, 0, 0, 0);
        } else {
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x18) + v0, 0, 0.0f, 0, 0, 0);
        }
    }
}
