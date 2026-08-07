/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void pl00_reset(void *p);
extern void cEmManage_ReleaseEmAll(void *a0);
extern void cDataManager_clear(void *a0);
extern void cDataHolder_systemInit(void *a0);
extern int D_00586B30[];
extern char D_005864F0[];
extern int D_005864E0[];

/* sn-2.95.3-136 matched TU. */











__attribute__((section(".text.func_00296818")))
int func_00296818(void *a0) {
    char *s2 = (char *)a0;
    pl00_reset(Obj0000_Get_D_00747A94_2DB6B0());
    if ((D_00586B30[1] & 1) == 0) {
        switch (*(char *)(s2 + 5)) {
        case 0:
            cEmManage_ReleaseEmAll(D_005864F0);
            *(unsigned char *)(s2 + 5) = *(unsigned char *)(s2 + 5) + 1;
            goto ret0;
        case 6:
            if (D_00586B30[1] & 0x400) {
                break;
            }
            /* fallthrough */
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
            *(unsigned char *)(s2 + 5) = *(unsigned char *)(s2 + 5) + 1;
            goto ret0;
        case 8:
            {
                int p;
                int i;
                cDataManager_clear(D_005864E0);
                p = D_005864E0[2];
                i = D_005864E0[1];
                if (p != 0) {
                    while (--i != -1) {
                        cDataHolder_systemInit((void *)(p + i * 0x5C));
                    }
                }
            }
            break;
        default:
            goto ret0;
        }
    }
    *(unsigned char *)(s2 + 4) = 2;
    *(unsigned char *)(s2 + 5) = 0;
    *(unsigned char *)(s2 + 6) = 0;
    *(unsigned char *)(s2 + 7) = 0;
    return 1;
ret0:
    return 0;
}
