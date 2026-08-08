/* sn-2.95.3-136 matched TU. */

extern int GetField_2B1_14B638(void *a0);
extern void *cModel_getMeshPtr(void *a0, int a1);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_00319E00")))
void func_00319E00(void *a0) {
    char *s3 = (char *)a0;
    int n;
    int i;

    unsigned long v;

    n = GetField_2B1_14B638(a0);
    v = *(unsigned int *)(*(int *)(s3 + 0x320) + 0x3C);
    switch ((unsigned char)v & 0xF) {
    case 2:
        for (i = 0; i < n; i++) {
            *(int *)((char *)cModel_getMeshPtr(s3, i) + 0x380) |= 0x20000;
        }
        break;
    case 3:
        for (i = 0; i < n; i++) {
            *(int *)((char *)cModel_getMeshPtr(s3, i) + 0x380) |= 0x2;
        }
        break;
    case 4:
        for (i = 0; i < n; i++) {
            *(int *)((char *)cModel_getMeshPtr(s3, i) + 0x380) |= 0x40000;
        }
        break;
    case 5:
        for (i = 0; i < n; i++) {
            *(int *)((char *)cModel_getMeshPtr(s3, i) + 0x380) |= 0x10000000;
        }
        break;
    case 0:
        for (i = 0; i < n; i++) {
            *(int *)((char *)cModel_getMeshPtr(s3, i) + 0x380) |= 0x200000;
        }
        break;
    default:
    case 1:
        for (i = 0; i < n; i++) {
            *(int *)((char *)cModel_getMeshPtr(s3, i) + 0x380) &= 0xEFD9FFFD;
        }
        break;
    }
}
