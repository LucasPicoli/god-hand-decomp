/* cygnus-2.96 matched TU. */

extern int Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(char *h);
extern void M2VERR_SetCode(int a, int b);
extern void func_0036D630(int n, void *fn);
extern void func_0036CD70(void);
extern void *D_0076A590[];

__attribute__((section(".text.M2V_SetCond")))
void M2V_SetCond(char *h, int n, void *fn)
{
    void **p;

    if (n == 8) {
        if (fn == 0) fn = func_0036CD70;
    }
    if (h == 0) {
        func_0036D630(n, fn);
        p = D_0076A590;
    } else {
        if (Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(h) != 0) {
            M2VERR_SetCode(0, 0xFF030202);
            return;
        }
        p = (void **)(h + 0x18);
    }
    p[n] = fn;
}
