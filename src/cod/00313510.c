extern int D_00747A34;
extern char D_00754220[];

__attribute__((section(".text.AllocAndInitObjVtable_313510")))
void *AllocAndInitObjVtable_313510(void)
{
    void *p;
    if (!(D_00747A34 & 0x100000))
    {
        p = _MemoryAlloc(0x1570, 0x10, D_00754220);
        if (p != 0)
        {
            func_003A52F0(p, 0, 0x1570);
            return EnemyBase_constructTriVec(p);
        }
    }
    return 0;
}

__attribute__((section(".text.AllocAndSetupObj_313580")))
void *AllocAndSetupObj_313580(void)
{
    void *p;
    if (!(D_00747A34 & 0x100000))
    {
        p = _MemoryAlloc(0x15B0, 0x10, D_00754220);
        if (p != 0)
        {
            func_003A52F0(p, 0, 0x15B0);
            return Em_construct278068(p);
        }
    }
    return 0;
}

__attribute__((section(".text.AllocZeroedAndInitVtable_3135F0")))
void *AllocZeroedAndInitVtable_3135F0(void)
{
    void *p;
    if (!(D_00747A34 & 0x100000))
    {
        p = _MemoryAlloc(0x15E0, 0x10, D_00754220);
        if (p != 0)
        {
            func_003A52F0(p, 0, 0x15E0);
            return InitObjVtable_27B768(p);
        }
    }
    return 0;
}

__attribute__((section(".text.AllocZeroedAndSetupObj_313660")))
int AllocZeroedAndSetupObj_313660(void)
{
    void *p;
    if (D_00747A34 & 0x100000)
        return 0;
    p = _MemoryAlloc(0x31B0, 0x10, D_00754220);
    if (p == 0)
        return 0;
    func_003A52F0(p, 0, 0x31B0);
    return cEm66_construct(p);
}

__attribute__((section(".text.AllocAndInitObjVtableFull_3136D0")))
int AllocAndInitObjVtableFull_3136D0(void)
{
    void *p;
    if (D_00747A34 & 0x100000)
        return 0;
    p = _MemoryAlloc(0x15C0, 0x10, D_00754220);
    if (p == 0)
        return 0;
    func_003A52F0(p, 0, 0x15C0);
    return InitObjVtableAndTypeFull_27EE68(p);
}

__attribute__((section(".text.ForwardInitBuffer_313740")))
int ForwardInitBuffer_313740(void)
{
    void *p;
    if (D_00747A34 & 0x100000)
        return 0;
    p = _MemoryAlloc(0x15C0, 0x10, D_00754220);
    if (p == 0)
        return 0;
    func_003A52F0(p, 0, 0x15C0);
    return Em_construct281638(p);
}
