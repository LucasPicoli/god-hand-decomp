/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00447D48[];
extern void func_002A84A8(void *p);
extern void cCollisionSolidManage_ReleaseUnit_278368(void *p);
extern void func_0028EB88(void *p, int f);
extern unsigned char D_004481A8[];
extern void func_0027BB30(void *p);
extern unsigned char D_00448598[];
extern void ForwardDispatchByMode_27F170(void *p);

__attribute__((section(".text.func_002780C0")))
void func_002780C0(void *p, int f)
{
    *(void **)((char *)p + 0x214) = (void *)D_00447D48;
    func_002A84A8(p);
    cCollisionSolidManage_ReleaseUnit_278368(p);
    func_0028EB88(p, f);
}

__attribute__((section(".text.func_0027B7C0")))
void func_0027B7C0(void *p, int f)
{
    *(void **)((char *)p + 0x214) = (void *)D_004481A8;
    func_002A84A8(p);
    func_0027BB30(p);
    func_0028EB88(p, f);
}

__attribute__((section(".text.func_0027EEC0")))
void func_0027EEC0(void *p, int f)
{
    *(void **)((char *)p + 0x214) = (void *)D_00448598;
    func_002A84A8(p);
    ForwardDispatchByMode_27F170(p);
    func_0028EB88(p, f);
}
