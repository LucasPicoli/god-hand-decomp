/* sn-2.95.3-136 matched TU. */

extern char D_00568288[];
extern char D_0042C2D8[];
extern char D_0042C2B0[];
extern void Setup_1F7AE8(void *p);

__attribute__((section(".text.func_001F7A30")))
void func_001F7A30(int flag, int id) {
    char *base;
    int *p;
    int *q;
    int i;
    int j;

    if (id == 0xFFFF) {
        if (flag != 0) {
            base = D_00568288;
            p = (int *)(base + 4);
            for (i = 0xF; i != -1; i--) {
                p[0] = 3;
                p[2] = (int)D_0042C2D8;
                p += 4;
            }

            q = (int *)(base + 0x104);
            for (j = 7; j != -1; j--) {
                q[0] = 3;
                q[2] = (int)D_0042C2B0;
                Setup_1F7AE8(q);
                q = (int *)((char *)q + 0x44);
            }
        }
    }
}
