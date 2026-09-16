/* sn-2.95.3-136 matched TU. */

extern void func_001EF978(void);
extern unsigned char D_00447BA0[];
extern void func_002A84A8(void *p);
extern void cCollisionSolidManage_ReleaseUnit_277540(void *p);
extern void func_0028EB88(void *p, int f);

__attribute__((section(".text.func_001F0778")))
void func_001F0778(int a0)
{
    if (*(int *)(a0 + 0xB94) == 0) {
        func_001EF978();
        *(int *)(a0 + 0xB94) = *(int *)(a0 + 0xB94) + 1;
    }
}

__attribute__((section(".text.func_001F0878")))
void func_001F0878(int a0)
{
    if (*(int *)(a0 + 0xB94) == 0) {
        func_001EF978();
        *(int *)(a0 + 0xB94) = *(int *)(a0 + 0xB94) + 1;
    }
}

__attribute__((section(".text.func_001F1100")))
void func_001F1100(int a0)
{
    if (*(int *)(a0 + 0xB94) == 0) {
        func_001EF978();
        *(int *)(a0 + 0xB94) = *(int *)(a0 + 0xB94) + 1;
    }
}

__attribute__((section(".text.func_001F17D0")))
void func_001F17D0(int a0)
{
    if (*(int *)(a0 + 0xB94) == 0) {
        func_001EF978();
        *(int *)(a0 + 0xB94) = *(int *)(a0 + 0xB94) + 1;
    }
}

__attribute__((section(".text.func_001F2650")))
void func_001F2650(int a0)
{
    if (*(int *)(a0 + 0xB94) == 0) {
        func_001EF978();
        *(int *)(a0 + 0xB94) = *(int *)(a0 + 0xB94) + 1;
    }
}

__attribute__((section(".text.func_002772F8")))
void func_002772F8(void *p, int f)
{
    *(void **)((char *)p + 0x214) = (void *)D_00447BA0;
    func_002A84A8(p);
    cCollisionSolidManage_ReleaseUnit_277540(p);
    func_0028EB88(p, f);
}
