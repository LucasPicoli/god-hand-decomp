/* cygnus-2.96 matched TU. */

extern void Obj0000_Set_D_003EE34C_35FC18(int a0);
extern void func_00360CA0(void);
extern char D_003EE338[];

__attribute__((section(".text.func_0035F8B8")))
void func_0035F8B8(void) {
    func_003A52F0(D_003EE338, 0, 0x4C8);
    *(int *)(D_003EE338 + 4) = 8;
    Obj0000_Set_D_003EE34C_35FC18(1);
    func_00360CA0();
}
