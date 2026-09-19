extern unsigned char D_00448788[];
extern void func_002A84A8(void *p);
extern void cCollisionSolidManage_ReleaseUnit_281940(void *p);
extern void func_0028EB88(void *p, int f);

__attribute__((section(".text.func_00281690")))
void func_00281690(void *p, int f)
{
    *(void **)((char *)p + 0x214) = (void *)D_00448788;
    func_002A84A8(p);
    cCollisionSolidManage_ReleaseUnit_281940(p);
    func_0028EB88(p, f);
}
