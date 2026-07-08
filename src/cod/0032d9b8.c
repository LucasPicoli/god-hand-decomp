/* cygnus-2.96 matched TU. */

extern void Forward33B658_3403C8(void);
extern void func_00340A60(int a0, int a1);
extern void Forward33B670_3403E0(void);
extern void func_0032AB70(void *a0, int a1);
extern void func_00329D38(void *a0, int a1);
extern void func_0034B030(void);
extern void func_0035B0D8(void *a0, int a1, int a2);
extern void func_0035A000(void *a0, int a1, int a2);
extern void func_00335CD8(int a0);
extern void func_003355C0(void *a0, int a1);
extern void func_00335CE0(void);
extern void func_00335CA8(int a0, int a1);
extern void Obj33F8_NoOp_FCA0(void);
extern void Forward32D868_32DA08(void *a0, int a1, int a2);
extern void Obj33F8_NoOp_FCA8(void);

__attribute__((section(".text.func_00340A20")))
void func_00340A20(int a0, int a1) {
    Forward33B658_3403C8();
    func_00340A60(a0, a1);
    Forward33B670_3403E0();
}

__attribute__((section(".text.func_00342A30")))
void func_00342A30(void *obj, int a1) {
    func_0032AB70(obj, 0x14);
    func_00329D38(obj, a1);
}

__attribute__((section(".text.func_0034AFF0")))
void func_0034AFF0(void *obj) {
    func_0035B0D8(obj, (int)func_0034B030, 2);
    func_0035A000(obj, 0xF, 2);
}

__attribute__((section(".text.func_00335580")))
void func_00335580(void *obj, int a1) {
    func_00335CD8((int)obj);
    func_003355C0(obj, a1);
    func_00335CE0();
}

__attribute__((section(".text.func_00335C68")))
void func_00335C68(int a0, int a1) {
    func_00335CD8(a0);
    func_00335CA8(a0, a1);
    func_00335CE0();
}

__attribute__((section(".text.func_0032D9B8")))
void func_0032D9B8(void *a0, int a1, int a2) {
    Obj33F8_NoOp_FCA0();
    Forward32D868_32DA08(a0, a1, a2);
    Obj33F8_NoOp_FCA8();
}
