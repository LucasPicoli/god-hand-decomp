extern int D_00785848;
extern int D_004209D0;
extern int D_00785858;
extern unsigned char D_005864F0[];
extern int D_00747B00[];
extern int *D_003C2F84;

__attribute__((section(".text.GetOrInitSingleton785848_171020")))
void *GetOrInitSingleton785848_171020(void) {
    if (D_00785848 == 0) {
        GetPilotClassDesc_1BDE00();
        SetField_0_4_8_31EEA8(&D_00785848, &D_004209D0, &D_00785858);
    }
    return &D_00785848;
}

__attribute__((section(".text.FindResolveActor_295978")))
int FindResolveActor_295978(unsigned char *a0)
{
    int v0 = cEmManage_GetEm(D_005864F0, *a0);
    *(int *)((char *)a0 + 4) = v0;
    return v0 != 0;
}

struct vec4 { int a; float b; int c; float d; };

__attribute__((section(".text.UpdateSlotCurValues_295860")))
int UpdateSlotCurValues_295860(char *a0)
{
    int *v1 = D_003C2F84;
    int s3;
    unsigned int s2;
    char *s0;

    if (*(unsigned char *)((char *)v1 + 0x14) == 1) {
        return 0;
    }

    s3 = 0;
    s2 = 0;
    s0 = a0 + 0x10;
    for (; s2 < 2; s2++, s0 += 0x18) {
        if (*(unsigned char *)(s0 + 0x13)) {
            int v1b = func_002951B0(a0, s0);
            short cur = *(short *)(s0 + 0x16);
            if (cur >= *(short *)(v1b + 0x548)) {
                *(short *)(v1b + 0x54A) = *(unsigned short *)(v1b + 0x548);
            } else {
                *(short *)(v1b + 0x54A) = cur;
            }
            *(int *)(a0 + 4) = *(unsigned char *)(s0 + 0x12) + 0x200;
            *(unsigned char *)(s0 + 0x13) = 0;
            s3++;
        }
    }
    return s3 != 0;
}

__attribute__((section(".text.SetVia4_Float_54C_295B80")))
void SetVia4_Float_54C_295B80(void *a0, float f)
{
    if (FindResolveActor_295978(a0)) {
        char *p = *(char **)((char *)a0 + 4);
        *(float *)(p + 0x54C) = f;
    }
}

