/* sn-2.95.3-136 matched TU. */

extern void func_001FC7C8(void *a0);
extern void func_001FDE00(void *a0);
extern char D_00569B80[];
extern char D_0056C380[];
extern char D_00574380[];

__attribute__((section(".text.func_001FE428")))
void func_001FE428(void *a0, int a1) {
    char *q;
    char *r;
    int i;
    int j;

    if (a1 == 0xFFFF && a0 != 0) {
        q = D_00569B80;
        /* closes with bne against a -1 register -> i != -1 */
        for (i = 0x9F; i != -1; i--) {
            func_001FC7C8(q);
            q += 0x40;
        }

        r = D_0056C380;
        for (j = 0x1FF; j != -1; j--) {
            func_001FC7C8(r);
            r += 0x40;
        }

        func_001FDE00(D_00574380);
    }
}
