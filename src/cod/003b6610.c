/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

extern void supplement_crt0(void);
extern void InitSystemCallTableAddress(void);
extern void func_003B68B8(void);
extern void func_003B6A30(int a0);
extern void func_003B6B90(void);
extern void func_003B0950(void);
extern void func_003B6738(void);
extern void func_003B7B40(void);
extern void func_003B7988(void);

__attribute__((section(".text._InitSys")))
void _InitSys(void)
{
    supplement_crt0();
    InitSystemCallTableAddress();
    func_003B68B8();
    func_003B6A30(2);
    func_003B6B90();
    func_003B0950();
    func_003B6738();
    func_003B7B40();
    func_003B7988();
}
