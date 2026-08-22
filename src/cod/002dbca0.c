/* sn-2.95.3-136 matched TU. */

extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern int Obj0000_IsSet_Field_15F4_Bit_400000_10B698(void *p);
extern int Obj293_IsByteSet_53C(void *p);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern int D_005864F0;
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern void func_00129718(void *a, void *b, int c);

__attribute__((section(".text.func_002DBCA0")))
void func_002DBCA0(void *arg)
{
    char *s1;
    char *r;
    char *g;

    s1 = (char *) arg;
    r = Obj0000_Get_D_00747A94_2DB6B0();
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (Obj293_IsByteSet_53C(g) == 0) {
                    *((int *) (r + 0x640)) = (int) s1;
                    r[0x2F4] = 0;
                    r[0x2F6] = 0;
                    r[0x2F7] = 0;
                    r[0x2F5] = 0x11;
                    r[0x648] = 0x14;
                    ClearField15F4Bit1_124F60(r, 0, 0);
                }
            }
        }
    }
}

__attribute__((section(".text.func_002DC2F0")))
void func_002DC2F0(void *arg)
{
    char *s1;
    char *r;
    char *g;

    s1 = (char *) arg;
    r = Obj0000_Get_D_00747A94_2DB6B0();
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (Obj293_IsByteSet_53C(g) == 0) {
                    r[0x2F4] = 0;
                    r[0x2F5] = 0x17;
                    r[0x2F6] = 0;
                    r[0x2F7] = 0;
                    Turn_dest(*((void **) (r + 0xF0)), *((void **) (s1 + 0xF0)),
                              *((float *) (r + 0x104)), 3.14159274f);
                }
            }
        }
    }
}

__attribute__((section(".text.func_002DC420")))
void func_002DC420(void *arg)
{
    char *s0;
    char *r;
    char *g;

    s0 = (char *) arg;
    r = Obj0000_Get_D_00747A94_2DB6B0();
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (Obj293_IsByteSet_53C(g) == 0) {
                    s0[0x2F4] = 0;
                    s0[0x2F7] = 0;
                    s0[0x2F5] = 0x5D;
                    s0[0x2F6] = 2;
                    func_00129718(r, s0, 0x16);
                }
            }
        }
    }
}

__attribute__((section(".text.func_002DC548")))
void func_002DC548(void *arg)
{
    char *s0;
    char *r;
    char *g;

    s0 = (char *) arg;
    r = Obj0000_Get_D_00747A94_2DB6B0();
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (Obj293_IsByteSet_53C(g) == 0) {
                    s0[0x2F6] = 0;
                    s0[0x2F7] = 0;
                    s0[0x2F4] = 1;
                    s0[0x2F5] = 0x1C;
                    func_00129718(r, s0, 0x27);
                }
            }
        }
    }
}

__attribute__((section(".text.func_002DC898")))
void func_002DC898(void *arg)
{
    char *s1;
    char *r;
    char *g;

    s1 = (char *) arg;
    r = Obj0000_Get_D_00747A94_2DB6B0();
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (Obj293_IsByteSet_53C(g) == 0) {
                    *((int *) (r + 0x694)) = (int) s1;
                    r[0x2F5] = 0x44;
                    r[0x2F4] = 0;
                    r[0x2F6] = 0;
                    r[0x2F7] = 0;
                }
            }
        }
    }
}

__attribute__((section(".text.func_002DD270")))
void func_002DD270(void *arg)
{
    char *s1;
    char *r;
    char *g;

    s1 = (char *) arg;
    r = Obj0000_Get_D_00747A94_2DB6B0();
    if (s1 == 0) {
        return;
    }
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (Obj293_IsByteSet_53C(g) == 0) {
                    *((int *) (r + 0x640)) = (int) s1;
                    r[0x648] = 0x14;
                    func_00129718(r, s1, 0x1C);
                }
            }
        }
    }
}
