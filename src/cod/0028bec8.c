/* sn-2.95.3-136 matched TU. */

extern int D_00747A78;
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void CopyVec3From110To120_14A2B0(void *a0);
extern void Forward30A2B0_2DA9B8(void *a0);
extern void cObjBase_SetSeqEffect(void *a0);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void func_0028CEA8(void *a0);
extern void func_0028D7E8(void *a0);
extern void func_0028CB90(void *a0);

__attribute__((section(".text.func_0028BEC8")))
void func_0028BEC8(void *a0)
{
    char *s0 = (char *)a0;

    if ((D_00747A78 & 0x40000000) != 0)
        return;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        float f;
        switch (*(unsigned short *)(s0 + 0x640) % 15) {
        default:
        case 0:
            f = 14.0f;
            break;
        case 1:
            f = 13.0f;
            break;
        case 2:
            f = 12.0f;
            break;
        case 3:
            f = 11.0f;
            break;
        case 4:
            f = 10.0f;
            break;
        case 5:
            f = 9.0f;
            break;
        case 6:
            f = 8.0f;
            break;
        case 7:
            f = 7.0f;
            break;
        case 8:
            f = 6.0f;
            break;
        case 9:
            f = 5.0f;
            break;
        case 10:
            f = 4.0f;
            break;
        case 11:
            f = 3.0f;
            break;
        case 12:
            f = 2.0f;
            break;
        case 13:
            f = 1.0f;
            break;
        case 14:
            f = 0.0f;
            break;
        }
        switch (*(unsigned char *)(s0 + 0x1540)) {
        default:
        case 0:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0x80) + w, 0, f, 0, 0, 0);
        }
            break;
        case 1:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0x84) + w, 0, f, 0, 0, 0);
        }
            break;
        case 2:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0x88) + w, 0, f, 0, 0, 0);
        }
            break;
        case 3:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0x8C) + w, 0, f, 0, 0, 0);
        }
            break;
        case 4:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0x90) + w, 0, f, 0, 0, 0);
        }
            break;
        case 5:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0x94) + w, 0, f, 0, 0, 0);
        }
            break;
        case 6:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0x98) + w, 0, f, 0, 0, 0);
        }
            break;
        case 7:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0x9C) + w, 0, f, 0, 0, 0);
        }
            break;
        case 8:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xA0) + w, 0, f, 0, 0, 0);
        }
            break;
        case 9:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xA4) + w, 0, f, 0, 0, 0);
        }
            break;
        case 10:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xA8) + w, 0, f, 0, 0, 0);
        }
            break;
        case 11:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xAC) + w, 0, f, 0, 0, 0);
        }
            break;
        case 12:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xB0) + w, 0, f, 0, 0, 0);
        }
            break;
        case 13:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xB4) + w, 0, f, 0, 0, 0);
        }
            break;
        case 14:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xB8) + w, 0, f, 0, 0, 0);
        }
            break;
        case 15:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xBC) + w, 0, f, 0, 0, 0);
        }
            break;
        case 16:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xC0) + w, 0, f, 0, 0, 0);
        }
            break;
        case 17:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xC4) + w, 0, f, 0, 0, 0);
        }
            break;
        case 18:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xC8) + w, 0, f, 0, 0, 0);
        }
            break;
        case 19:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xCC) + w, 0, f, 0, 0, 0);
        }
            break;
        case 20:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xD0) + w, 0, f, 0, 0, 0);
        }
            break;
        case 21:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xD4) + w, 0, f, 0, 0, 0);
        }
            break;
        case 22:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xD8) + w, 0, f, 0, 0, 0);
        }
            break;
        case 23:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xDC) + w, 0, f, 0, 0, 0);
        }
            break;
        case 24:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xE0) + w, 0, f, 0, 0, 0);
        }
            break;
        case 25:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xE4) + w, 0, f, 0, 0, 0);
        }
            break;
        case 26:
        {
            int w = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(w + 0xE8) + w, 0, f, 0, 0, 0);
        }
            break;
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1:
        moveMotion(s0);
        CopyVec3From110To120_14A2B0(s0);
        Forward30A2B0_2DA9B8(s0);
        break;
    default:
        break;
    }
    cObjBase_SetSeqEffect(s0);
    cModel_calcParts(s0);
    IK_InverseKinematics(s0 + 0x448, s0);
    cModel_calcWorldParts(s0);
    func_0028CEA8(s0);
    func_0028D7E8(s0);
    func_0028CB90(s0);
    {
        char *d = s0 + 0x490;
        char *p = *(char **)(s0 + 0xF0);
        if (d != p) {
            *(float *)(d + 0) = *(float *)(p + 0);
            *(float *)(d + 4) = *(float *)(p + 4);
            *(float *)(d + 8) = *(float *)(p + 8);
        }
    }
}
