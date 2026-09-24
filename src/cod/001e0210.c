/* sn-2.95.3-136 matched TU. */

extern char D_003BE0B0[];
extern int D_00569B70;
extern int D_00747A2C;
extern void func_001E3858(int a0);
extern void func_001E39D0(int a0);
extern void func_001E3B40(int a0);
extern void func_001E3CB0(int a0);
extern void func_001E3DD0(int a0);
extern void func_001E4010(int a0);
extern void func_001E4308(int a0);
extern void func_001E44A8(int a0);
extern void func_001E4610(int a0);
extern void func_001E79E8(int a0);
extern void func_001E7EA0(int a0);
extern int GetTimerValue_1FA710(void *a0);
extern void CustomIDWork_SetNumber(int a0, int a1);
extern void func_001E73C0(int a0);
extern void func_001E7440(int a0);
extern void func_001E33B0(int a0);

__attribute__((section(".text.func_001E0210")))
void func_001E0210(int a0)
{
    int p = a0 + 0x4D0;
    int v;
    int i = *(int *)(a0 + 0x4);
    short off = *(short *)(D_003BE0B0 + i * 8);
    void (*fn)() = *(void (**)())(D_003BE0B0 + i * 8 + 4);
    fn(a0 + off);
    func_001E3858(a0);
    func_001E39D0(a0);
    func_001E3B40(a0);
    func_001E3CB0(a0);
    func_001E3DD0(a0);
    func_001E4010(a0);
    func_001E4308(a0);
    func_001E44A8(a0);
    func_001E4610(a0);
    func_001E79E8(a0 + 0x370);
    func_001E7EA0(a0 + 0x58);
    func_001E7EA0(a0 + 0x160);
    func_001E7EA0(a0 + 0x268);
    v = GetTimerValue_1FA710(&D_00569B70);
    CustomIDWork_SetNumber(a0 + 0x520, v);
    func_001E73C0(p);
    func_001E7440(p);
    if (D_00747A2C & 0x200)
        func_001E33B0(a0);
}
