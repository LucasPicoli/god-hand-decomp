/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void *Getplayer(void);
extern void func_002A74E0(void *a0, int a1, int a2);

extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_007476B0;
extern char D_00462FC0[];

__attribute__((section(".text.func_00244CF8")))
void func_00244CF8(void *a0)
{
    char *s0 = (char *)a0;
    float one;

    cCollisionSolidManage_SetActive(D_00462FC0, s0, 0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int t0, b;
        *(int *)(s0 + 0x4A8) = *(int *)(s0 + 0x4A8) | 0x80000000;
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        b = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0xD78) + b, 0, 0.0f, 0, t0, 0);
    }
        moveMotion(s0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        *(float *)(s0 + 0x54C) = 2.0f;
        *(unsigned char *)(s0 + 0x617) = 1;
        *(char *)(s0 + 0x531) = -1;
        if ((*(int *)(s0 + 0x1644) & 0x10008000) == 0) {
            if (*(int *)(s0 + 0x16D0) & 0x200000) {
                if (*(float *)(s0 + 0x618) < 64.0f && (D_007476B0 & 7) == (*(int *)(s0 + 0x17D0) & 7)) {
                    *(int *)(s0 + 0x16D4) = *(int *)(s0 + 0x16D4) & 0xF7FFFFFF;
                    func_002A74E0(s0, *(int *)((char *)Getplayer() + 0xF0), 1);
                    if (func_002A7CA0(s0, s0 + 0x16A0) != 0) {
                        *(int *)(s0 + 0x16D4) = *(int *)(s0 + 0x16D4) | 0x8000000;
                    }
                    if (*(float *)(s0 + 0x510) < 8.0f) {
                        *(unsigned char *)(s0 + 0x2F6) = 2;
                    }
                }
                if (*(float *)(s0 + 0x618) < 9.0f) {
                    *(unsigned char *)(s0 + 0x2F6) = 2;
                }
            }
            if (*(int *)(s0 + 0x16EC) != 0) {
                *(unsigned char *)(s0 + 0x2F6) = 2;
            }
        }
        if (*(int *)(s0 + 0x16D0) & 0x20000000) {
            *(unsigned char *)(s0 + 0x2F6) = 2;
        }
        if (0.0f < *(float *)(s0 + 0x16C0)) {
            *(unsigned char *)(s0 + 0x2F6) = 2;
        }
        break;
    case 2:
    {
        int t0, b;
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        b = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0xD78) + b, *(int *)(b + 0xD7C) + b, 0.0f, 0, t0, 0);
    }
        *(float *)(s0 + 0x1744) = 300.0f;
        *(char *)(s0 + 0x531) = 3;
        *(int *)(s0 + 0x4A8) = *(int *)(s0 + 0x4A8) & 0x7FFFFFFF;
        *(float *)(s0 + 0x54C) = 5.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 3:
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}
