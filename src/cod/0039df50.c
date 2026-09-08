/* ee-2.9-991111 matched TU. */

extern void func_0039DB28(void *pic, int *mv, int p3, int p8,
                          int p9, int p10, int p11, int z);

__attribute__((section(".text.func_0039DF50")))
void func_0039DF50(void *pic, char *mv, int p3, int *tbl, int idx,
                   int mtype, int p7, int p8,
                   int p9, int p10, int p11)
{
    int r;
    int *m;

    if (mtype == 1) {
        if (p7 == 0 && p10 == 0) {
            int *q;
            r = func_0039EAA8(pic, 1);
            q = (int *)(idx * 4 + (unsigned int)tbl);
            q[0] = r;
            q[2] = r;
        }
        m = (int *)(mv + idx * 8);
        func_0039DB28(pic, m, p3, p8, p9, p10, p11, 0);
        m[4] = m[0];
        m[5] = m[1];
    } else {
        int *w;
        int off;
        r = func_0039EAA8(pic, 1);
        w = (int *)(idx * 4 + (unsigned int)tbl);
        off = idx * 8;
        w[0] = r;
        func_0039DB28(pic, (int *)(mv + off), p3, p8, p9, p10, p11, 0);
        r = func_0039EAA8(pic, 1);
        off = off + 0x10;
        w[2] = r;
        func_0039DB28(pic, (int *)(mv + off), p3, p8, p9, p10, p11, 0);
    }
}
