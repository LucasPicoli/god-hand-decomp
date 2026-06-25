/* sn-2.95.3-136 matched TU. */

extern int D_0044E9F8;
extern int D_007863C8;
extern int D_007863F8;
extern void *GetOrInitGlobal7863C8_300148(void);
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);

__attribute__((section(".text.func_002EFA60")))
void *func_002EFA60(void)
{
    if (D_007863F8 == 0) {
        GetOrInitGlobal7863C8_300148();
        SetField_0_4_8_31EEA8(&D_007863F8, &D_0044E9F8, &D_007863C8);
    }
    return &D_007863F8;
}
