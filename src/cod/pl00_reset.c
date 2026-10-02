/* TU: pl00_reset [player] - recovered method extracted to its own TU
   (sn-2.95.3-136 cc1 ICEs on this body inside the full pl00.c). */
/* pl00_reset — sn-2.95.3-136. Player reset: clears state bytes, rebuilds the
 * model (move/calcParts/IK/calcWorldParts), refreshes the held-object model,
 * fixes the 0x15F4 flag word, resets heat mode and clears 0x640. */

extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_00126770(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void moveMotion(void *a0);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void func_001CF3A8(void *a0);
extern void cHeatSys_SetHeatMode(void *a0, int a1);
extern int D_005CB000;

__attribute__((section(".text.pl00_reset")))
void pl00_reset(void *a0)
{
    char *s0 = (char *)a0;
    int v0;

    pl00_clearMotionCam(s0, 0, 0);
    func_00126770(s0);
    v0 = *(int *)(s0 + 0x304);
    *(unsigned char *)(s0 + 0x2F4) = 0;
    *(unsigned char *)(s0 + 0x2F5) = 0;
    *(unsigned char *)(s0 + 0x2F6) = 0;
    *(unsigned char *)(s0 + 0x2F7) = 0;
    func_002A8578(s0, *(int *)(v0 + 0x28) + v0, *(int *)(v0 + 0x2C) + v0, 0.0f, 0, 0, 0);
    moveMotion(s0);
    cModel_calcParts(s0);
    IK_InverseKinematics(s0 + 0x448, s0);
    cModel_calcWorldParts(s0);
    if (*(int *)(s0 + 0x6A8) != 0) {
        func_001CF3A8(*(void **)(s0 + 0x6A8));
        cModel_calcParts(*(void **)(s0 + 0x6A8));
    }
    *(int *)(s0 + 0x15F4) = (*(int *)(s0 + 0x15F4) & ~0x10) | 0x20;
    cHeatSys_SetHeatMode(&D_005CB000, 0);
    *(int *)(s0 + 0x640) = 0;
}
