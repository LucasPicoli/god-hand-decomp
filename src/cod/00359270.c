/* cygnus-2.96 matched TU. */

extern int Obj34D8_SetGlobalEE0B8_IfField48(int *a0);
extern int SFBUF_SetSupplySj(int *a0, int a1);
extern void func_0035B0D8(int *a0, int a1);
extern void func_0035A000(int *a0, int a1, int a2);
extern void Obj35E8_SetField_68(int *a0, void *a1);
extern void Obj35E8_SetField_6C(int *a0, void *a1);
extern void Obj35E8_SetIndirect_30_18(int *a0, void *a1);
extern void Obj35E8_SetIndirect_30_20(int *a0, void *a1);
extern void Obj35E8_SetIndirect_30_1C(int *a0, void *a1);
extern void Obj35E8_SetField_70(int *a0, void *a1);
extern void func_00365D18(void);
extern void func_00366730(void);
extern void func_00365EC0(void);
extern void func_00366368(void);
extern void func_00366110(void);
extern void func_003665C0(void);

/* MATCH via cygnus-2.96. */




__attribute__((section(".text.func_00359270")))
int func_00359270(int *a0, int a1)
{
    if (Obj34D8_SetGlobalEE0B8_IfField48(a0) != 0) {
        return func_0034DD70(0, 0xFF000139);
    }
    return SFBUF_SetSupplySj(a0, a1);
}

/* MATCH via cygnus-2.96. */



__attribute__((section(".text.func_00359758")))
int func_00359758(int *a0, int a1)
{
    if (Obj34D8_SetGlobalEE0B8_IfField48(a0) != 0) {
        return func_0034DD70(0, 0xFF000151);
    }
    a0[0xDAC] = a1;
    return 0;
}

/* MATCH via cygnus-2.96. */



__attribute__((section(".text.func_0035AE70")))
int func_0035AE70(int *a0, int a1)
{
    if (Obj34D8_SetGlobalEE0B8_IfField48(a0) != 0) {
        return func_0034DD70(0, 0xFF000124);
    }
    a0[0x352] = a1;
    return 0;
}

/* MATCH via cygnus-2.96. */





__attribute__((section(".text.func_0035AEE0")))
int func_0035AEE0(int *a0, int a1)
{
    if (Obj34D8_SetGlobalEE0B8_IfField48(a0) != 0)
        return func_0034DD70(0, 0xFF000123, 4);
    func_0035B0D8(a0, a1);
    if (a1 != 0)
        func_0035A000(a0, 0xF, 4);
    return 0;
}

/* MATCH via cygnus-2.96. */














__attribute__((section(".text.func_0035F788")))
int func_0035F788(int *a0, int a1, int a2)
{
    a0[0x14] = 0;
    Obj35E8_SetField_68(a0, (void *)&func_00365D18);
    Obj35E8_SetField_6C(a0, (void *)&func_00366730);
    Obj35E8_SetIndirect_30_18(a0, (void *)&func_00365EC0);
    Obj35E8_SetIndirect_30_20(a0, (void *)&func_00366368);
    Obj35E8_SetIndirect_30_1C(a0, (void *)&func_00366110);
    Obj35E8_SetField_70(a0, (void *)&func_003665C0);
    return func_0035EF78(a0, a1, a2);
}
