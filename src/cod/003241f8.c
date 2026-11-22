extern void Forward33B658_33E678(void);
extern void adxf_ExecOne(void *);
extern void Forward33B670_33E690(void);
extern signed char D_003EAEC8[];

__attribute__((section(".text.func_003241F8")))
void func_003241F8(void)
{
    signed char *entry;
    int remaining;
    Forward33B658_33E678();
    entry = D_003EAEC8;
    for (remaining = 15; remaining >= 0; remaining--) {
        if (*entry == 1)
            adxf_ExecOne(entry);
        entry += 0x44;
    }
    Forward33B670_33E690();
}
