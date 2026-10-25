extern char D_00762868[];
extern char D_00766BA8[];
extern char D_00766BD0[];
extern char D_00766BD8[];
extern int D_003EE2EC;
extern void SFMPVP_Init(void);
extern int func_003506D8(void);
extern int M2vDec_init(int, char *);
extern int func_0034DD70(int, int);
extern void *func_003A52F0(void *, int, int);

__attribute__((section(".text.func_003505F8")))
int func_003505F8(void)
{
    int r;

    SFMPVP_Init();
    if (func_003506D8() != 0) {
        for (;;) {
        }
    }
    r = M2vDec_init(8, D_00762868);
    if (r != 0) {
        return func_0034DD70(0, r == (int)0xFF03FF05 ? (int)0xFF000F13 : (int)0xFF000F01);
    }
    func_003A52F0(D_00766BA8, 0, 0x24);
    func_003A52F0(D_00766BD0, 0, 8);
    func_003A52F0(D_00766BD8, 0, 0x40);
    D_003EE2EC = 0;
    return 0;
}
