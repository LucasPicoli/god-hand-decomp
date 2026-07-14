/* sn-2.95.3-136 matched TU. */

extern void func_003A52F0(void *dst, int a, int b);
extern unsigned char D_00773318[];
extern char D_0045B170[];

typedef struct {
    char b[8];
} Blob8;

__attribute__((section(".text.func_00378540")))
void func_00378540(void) {
    unsigned char *base = D_00773318;
    unsigned char *p;
    int i;

    func_003A52F0(base, 0, 0x8B5C);

    base[0x4] = 1;
    base[0x5] = 0;
    base[0x6] = 0;
    base[0x7] = 0;
    base[0x8] = 0;

    *(Blob8 *)(base + 0x1B2) = *(Blob8 *)D_0045B170;
    *(Blob8 *)(base + 0x2B2) = *(Blob8 *)D_0045B170;
    *(Blob8 *)(base + 0x3B2) = *(Blob8 *)D_0045B170;

    *(short *)(base + 0x10) = 0x30;
    *(short *)(base + 0x12) = 4;
    *(short *)(base + 0x14) = 0x30;

    p = base + 0x7C;
    for (i = 0x1F; i >= 0; i--) {
        p[-0x20] = 4;
        p[0] = 4;
        p++;
    }
}
