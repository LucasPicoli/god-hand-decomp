/* sn-2.95.3-136 matched TU. */

extern int D_003C118C;
extern float D_003C1190;
extern char D_00586C00[];
extern int D_00586B80;
extern float D_00586B84;
extern float D_00586B88;

/* sn-2.95.3-136 matched TU. */








__attribute__((section(".text.func_002A48A8")))
void func_002A48A8(int a0, int a1)
{
    char *p;
    int n;

    if (a1 == 0xFFFF && a0 != 0) {
        p = D_00586C00;
        n = D_003C118C;
        D_00586B80 = 0x800 - n / 2;
        D_00586B84 = 2048.0f - D_003C1190 * 0.5f;
        D_00586B88 = (float)n / 480.0f;
        *(long *)(p + 0x140C8) = 0;
        *(long *)(p + 0x14098) = 0;
    }
}
