/* cygnus-2.96: SFD_IsSvrWait, 1 when every one of the 8 registered objects is busy or done. */
extern void *D_003EE2C4[8];
extern int Obj34D8_SetGlobalEE0B8_IfField48(void *obj);
extern int Obj0000_Get_Field_44_LT_1_If_Field_48_In_1_4(void *obj);

__attribute__((section(".text.SFD_IsSvrWait")))
int SFD_IsSvrWait(void)
{
    void **p = D_003EE2C4;
    int i;
    int r;

    for (i = 0; i < 8; i++) {
        void *o = *p++;
        if (Obj34D8_SetGlobalEE0B8_IfField48(o) == 0) {
            r = Obj0000_Get_Field_44_LT_1_If_Field_48_In_1_4(o);
            if (r == 0)
                return r;
        }
    }
    return 1;
}
