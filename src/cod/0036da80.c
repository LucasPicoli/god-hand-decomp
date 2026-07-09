/* cygnus-2.96 matched TU. */

extern int Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(int *);
extern void M2VERR_SetCode(int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_003B9DE0(void *);
extern void func_003B9DB0(void);
extern void func_003BA148(void *);
extern void func_003B9DC8(void);
extern int D_00460950;

__attribute__((section(".text.func_0036DA80")))
void func_0036DA80(char *o, void *dst) {
    if (Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2((int *)o)) {
        M2VERR_SetCode(0, 0xFF03020C);
        return;
    }
    memcpy(dst, o + 0x58, 0x80);
}

__attribute__((section(".text.func_003BA0C8")))
void func_003BA0C8(int *o) {
    int i;
    if (o == 0) {
        func_003B9DE0(&D_00460950);
        return;
    }
    func_003B9DB0();
    for (i = 0; i < o[6]; i++)
        func_003BA148(o);
    func_003B9DC8();
}
