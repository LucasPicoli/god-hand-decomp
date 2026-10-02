/* sn-2.95.3-136 matched TU. */

extern void func_001268F0(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
__attribute__((section(".text.func_00115F60")))
void func_00115F60(void *a0) {
    char *s0 = (char *)a0;
    int v0;
    float one;
    *(float *)(s0 + 0x54C) = 5.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(short *)(s0 + 0x5E0) = 0;
        *(short *)(s0 + 0x5E2) = 0;
        func_001268F0(s0);
        Obj0000_Clear_Fields_640_648_124E58(s0);
        *(float *)(*(int *)(s0 + 0xF0) + 0) = *(float *)(s0 + 0x660);
        *(float *)(*(int *)(s0 + 0xF0) + 8) = *(float *)(s0 + 0x668);
        {
            char *d = s0 + 0x490;
            char *p = (char *)*(int *)(s0 + 0xF0);
            if (d != p) {
                *(float *)(d + 0) = *(float *)(p + 0);
                *(float *)(d + 4) = *(float *)(p + 4);
                *(float *)(d + 8) = *(float *)(p + 8);
            }
        }
        *(float *)(s0 + 0x104) = *(float *)(s0 + 0x670);
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x8B8) + v0, *(int *)(v0 + 0x8BC) + v0, 0.0f, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            pl00_clearMotionCam(s0, 1, 0);
            *(unsigned char *)(s0 + 0x2F4) = 0; *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0; *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}
