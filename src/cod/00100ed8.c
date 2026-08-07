/* sn-2.95.3-136 matched TU. */

extern int D_00569B70;
extern int cCoreSave_getCostumeNo(void *a0);

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.pl01__SetParent")))
void pl01__SetParent(void *a0, void *a1, int a2)
{
    unsigned char frame[0x10] __attribute__((aligned(16)));
    char *s0 = (char *)a0;
    int b1, b2;
    unsigned char ok1, ok2;
    int parent, child;
    int v;

    if (a1 == 0) return;
    ok1 = ((*(int *)frame = b1 = *(unsigned char *)(s0 + 0x2B4)), (0 >= 0 && 0 < b1));
    if (ok1) parent = *(int *)(*(int *)(s0 + 0x278) + 0 * 4); else parent = 0;
    if (parent == 0) return;
    ok2 = ((*(int *)frame = b2 = *(unsigned char *)((char *)a1 + 0x2B4)), (a2 >= 0 && a2 < b2));
    if (ok2) child = *(int *)(*(int *)((char *)a1 + 0x278) + a2 * 4); else child = 0;
    if (child == 0) return;
    *(int *)(parent + 0x148) = child;
    *(int *)(s0 + 0x20D4) = a2;
    *(int *)(s0 + 0x20D0) = (int)a1;
    *(int *)(s0 + 0x20A8) = (int)a1;
    switch (cCoreSave_getCostumeNo(&D_00569B70)) {
    case 2:
    case 3:
        v = 0xB;
        break;
    case 4:
    case 5:
        v = 7;
        break;
    case 0:
    case 1:
    case 6:
    case 7:
    default:
        v = 0xC;
        break;
    }
    *(int *)(s0 + 0x2088) = v;
}
