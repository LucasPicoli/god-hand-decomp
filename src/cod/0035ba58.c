/* cygnus-2.96 matched TU. */

extern int Obj0000_Get_D_003EEA70_LT_2_360C40(void);
extern long Obj0000_Get_D_003EEA70_360C58(void);
extern void *D_003EE0B8;
extern char D_003EE0C0[];
extern long D_00766C80;

__attribute__((section(".text.func_0035BA58")))
int func_0035BA58(void) {
    int r = Obj0000_Get_D_003EEA70_LT_2_360C40();
    char *base = D_003EE0C0;

    if (r == 0) {
        D_00766C80 = Obj0000_Get_D_003EEA70_360C58();
        return func_00360B18();
    } else {
        char *p = (char *)D_003EE0B8;
        int t;

        if (p != 0 && *(int *)(p + 0x48) != 0) {
            void (*fn)(int, int *, int *) = *(void (**)(int, int *, int *))(p + 0x1004);

            if (fn != 0) {
                int local0;
                int local1;

                fn(*(int *)(p + 0x1018), &local0, &local1);
                D_00766C80 = local1;
                return local0;
            }
        }
        t = *(volatile int *)(base + 0x1B0);
        D_00766C80 = *(int *)(base + 0x1B8);
        return t * 1000;
    }
}
