/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int D_005FEE00[];

/* sn-2.95.3-136 matched TU. */








__attribute__((section(".text.func_002804F8")))
void func_002804F8(void *a0) {
    char *s0 = (char *)a0;
    unsigned long t0 = 0;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        switch (*(unsigned char *)(s0 + 0x2F7)) {
        default:
        case 0: {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0xA8) + v, *(int *)(v + 0xAC) + v, 0.0f, 2, t0, 0);
            break;
        }
        case 1: {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0xA0) + v, *(int *)(v + 0xA4) + v, 0.0f, 2, t0, 0);
            break;
        }
        case 2: {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0xB0) + v, *(int *)(v + 0xB4) + v, 0.0f, 2, t0, 0);
            break;
        }
        case 3: {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0xB8) + v, *(int *)(v + 0xBC) + v, 0.0f, 2, t0, 0);
            break;
        }
        case 4: {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0xC0) + v, *(int *)(v + 0xC4) + v, 0.0f, 2, t0, 0);
            break;
        }
        case 5: {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0xC8) + v, *(int *)(v + 0xCC) + v, 0.0f, 2, t0, 0);
            break;
        }
        }
        cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)Obj0000_Get_Field_424_1595F0(s0), s0, 0, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        moveMotion(s0);
        break;
    }
}
