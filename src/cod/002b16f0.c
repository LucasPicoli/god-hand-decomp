/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern void func_002B17A8(void *a0);
extern void func_002B17F8(void *a0);
extern void func_002B1830(void *a0);
extern void func_002B1BE8(void *a0);
extern void func_002B1C30(void *a0);
extern int D_00747A2C;

__attribute__((section(".text.func_002B16F0")))
void func_002B16F0(void *a0)
{
    char *p = (char *)a0;
    char *g = (char *)&D_00747A2C;

    {
        unsigned long f = *(int *)(g + 4);
        unsigned long b = (f >> 1) & 1;
        if (b) {
            return;
        }
    }
    if ((*(int *)(g + 0x58) & 0x8000000) != 0) {
        return;
    }
    switch (*(unsigned char *)(p + 0xA4)) {
    case 0:
        func_002B17A8(p);
        break;
    case 2:
        func_002B17F8(p);
        break;
    case 3:
        func_002B1830(p);
        break;
    case 4:
        func_002B1BE8(p);
        break;
    case 5:
        func_002B1C30(p);
        break;
    default:
        break;
    }
}
