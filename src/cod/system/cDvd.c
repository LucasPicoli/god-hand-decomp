/* TU: cDvd [system] - recovered C++ class. */
extern char D_00580D40[];
extern void func_00201228(char *a0, char *a1);
extern void func_00201290(char *a0);
extern int cDvd_Check(int a0, int a1);
extern void func_00200B20(int a0);

__attribute__((section(".text.cDvd_ReadAlloc")))
int cDvd_ReadAlloc(char *a0, char *a1, int *a2, int a3, int t0, int t1, int t2, int t3)
{
    char *s0;

    *a2 = 0;
    s0 = func_002017A8(a0);
    if (s0 == 0)
        return 0;

    {
        int v0 = FindEntryValue_1FF9C0(D_00580D40, a1, s0 + 0x78, s0 + 0xC);
        *(int *)(s0 + 0x8) = v0;
        *(int *)(s0 + 0x7C) = a3;
        *(int *)(s0 + 0x74) = (unsigned int)(*(int *)(s0 + 0x78) + 0x7FF) >> 11;
        if (v0 < 0)
            return 0;
    }

    *(int *)(s0 + 0x0) = 1;
    if (t0 == 0)
        *(int *)(s0 + 0x4) = func_00201788(a0);
    else
        *(int *)(s0 + 0x4) = t0;

    *(int *)(s0 + 0x6C) = t3;
    *(int *)(s0 + 0x70) = t2;
    *(int *)(s0 + 0x80) = 0;
    if (t1 != 0)
        *(int *)(s0 + 0x74) = (unsigned int)(t1 + 0x7FF) >> 11;

    {
        int r = EnsureInitThenForward_2A9538_30EE08(*(int *)(s0 + 0x74) << 11, 0x80, a3);
        *(int *)(s0 + 0x80) = r;
        if (r == 0) {
            func_00201228(a0, s0);
            return 0;
        }
        *a2 = r;
    }

    if (*(int *)(a0 + 0x0) == 0)
        func_00201290(a0);
    return *(int *)(s0 + 0x4);
}
__attribute__((section(".text.cDvd_CheckWait")))
void cDvd_CheckWait(int a0, int a1)
{
    while (cDvd_Check(a0, a1))
        func_00200B20(a0);
}
