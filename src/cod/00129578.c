/* sn-2.95.3-136 matched TU. */

extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern int cCoreSave_getCostumeNo(void *);
extern int D_00569B70;

__attribute__((section(".text.func_00129578")))
void func_00129578(void *this)
{
    int cn;
    if (*(int *)((char *)this + 0x15F4) & 0x20) {
        *(int *)((char *)this + 0x15F4) &= ~0x20;
        cn = cCoreSave_getCostumeNo(&D_00569B70);
        switch (cn) {
        case 0:
        case 2:
        case 4:
        case 6:
        default:
            SetEffect(0, 0x19, this, 0, -1, 0xFFFFFFFFu);
            break;
        case 1:
        case 3:
        case 5:
        case 7:
            SetEffect(0, 0x75, this, 0, -1, 0xFFFFFFFFu);
            break;
        }
    }
    *(char *)((char *)this + 0x649) = 0;
}
