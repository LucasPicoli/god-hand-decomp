extern int D_00747A34;
extern unsigned char D_00754220[];
extern unsigned char D_00754C10[];

__attribute__((section(".text.ForwardInitVtable214Buffer_3137B0")))
int ForwardInitVtable214Buffer_3137B0(void)
{
    void *p;
    if (D_00747A34 & 0x100000)
        return 0;
    p = EnsureInitThenForward_2A9538_30EE08(0x15B0, 0x10, D_00754220);
    if (p == 0)
        return 0;
    func_003A52F0(p, 0, 0x15B0);
    return Init_Vtable214_TypeName4AC_279CE8(p);
}

__attribute__((section(".text.ForwardInitBuffer_313820")))
int ForwardInitBuffer_313820(void)
{
    void *p;
    if (D_00747A34 & 0x100000)
        return 0;
    p = EnsureInitThenForward_2A9538_30EE08(0x1610, 0x10, D_00754220);
    if (p == 0)
        return 0;
    func_003A52F0(p, 0, 0x1610);
    return func_00284A28(p);
}

__attribute__((section(".text.ForwardInitBuffer_313890")))
int ForwardInitBuffer_313890(void)
{
    void *p;
    if (D_00747A34 & 0x100000)
        return 0;
    p = EnsureInitThenForward_2A9538_30EE08(0x1600, 0x10, D_00754220);
    if (p == 0)
        return 0;
    func_003A52F0(p, 0, 0x1600);
    return func_00289728(p);
}

__attribute__((section(".text.ForwardInitObj28B0Buffer_313900")))
void *ForwardInitObj28B0Buffer_313900(void) {
    void *s0;
    if (!(D_00747A34 & 0x100000)) {
        s0 = EnsureInitThenForward_2A9538_30EE08(0x1660, 0x10, D_00754220);
        if (s0 != 0) {
            func_003A52F0(s0, 0, 0x1660);
            return cEma6_construct(s0);
        }
    }
    return 0;
}

__attribute__((section(".text.ForwardSetupBuffer_28E018_313970")))
void *ForwardSetupBuffer_28E018_313970(void) {
    void *s0;
    if (!(D_00747A34 & 0x100000)) {
        s0 = EnsureInitThenForward_2A9538_30EE08(0x1560, 0x10, D_00754220);
        if (s0 != 0) {
            func_003A52F0(s0, 0, 0x1560);
            return cEmad_construct(s0);
        }
    }
    return 0;
}

__attribute__((section(".text.ForwardInitBuffer_313A60")))
void *ForwardInitBuffer_313A60(void) {
    void *s0;
    if (!(D_00747A34 & 0x10000)) {
        s0 = EnsureInitThenForward_2A9538_30EE08(0x8F0, 0x10, D_00754C10);
        if (s0 != 0) {
            func_003A52F0(s0, 0, 0x8F0);
            return func_00186738(s0);
        }
    }
    return 0;
}
