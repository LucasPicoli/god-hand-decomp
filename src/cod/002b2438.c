/* sn-2.95.3-136 matched TU. */

extern void func_002B3078(void *a0);
extern void func_002B3240(void *a0);
extern void func_002B3D70(void *a0);
extern void func_002B3EC8(void *a0);
extern void func_002B4028(void *a0);
extern void func_002B4188(void *a0);
extern void func_002B4390(void *a0);

__attribute__((section(".text.func_002B2438")))
void func_002B2438(char *a0)
{
    unsigned char idx = *(unsigned char *)(a0 + 0xC);
    unsigned short v0;

    switch (idx) {
    case 0:
        if (func_002B2500(a0) == 0) {
            break;
        }
    case 1:
        func_002B3078(a0);
        break;
    case 2:
        func_002B3240(a0);
        break;
    case 3:
        func_002B3D70(a0);
        break;
    case 4:
        func_002B3EC8(a0);
        break;
    case 5:
        func_002B4028(a0);
        break;
    case 6:
        func_002B4188(a0);
    case 7:
        break;
    }
    v0 = *(unsigned short *)(a0 + 0x2E);
    if (v0 != 0) {
        *(unsigned short *)(a0 + 0x2E) = v0 - 1;
    }
    func_002B4390(a0);
}
