/* sn-2.95.3-136 matched TU. */

extern void cModel_calcParts(void *m);

/* SN ProDG ee-gcc 2.95.3 matched TU. */



static inline void SetBit(int *w, int b) {
    if ((unsigned int)b < 0x20) {
        *w |= (int)(1L << b);
    }
}

static inline void ClrBit(int *w, int b) {
    if ((unsigned int)b < 0x20) {
        *w &= ~(int)(1L << b);
    }
}

__attribute__((section(".text.func_001EBF50")))
void func_001EBF50(char *p, unsigned short idx, void *flag) {
    int b1, b2, e;
    char *tbl;
    void **q;
    void **q2;
    void *m;

    if ((unsigned int)idx < 5) {
        e = idx * 2 + 1;
        b1 = idx + 1;
        b2 = idx + 6;
        if (flag != 0) {
            SetBit((int *)(p + 0x54), b1);
            SetBit((int *)(p + 0x54), b2);
        } else {
            tbl = p + 0x1C4;
            q = (void **)(tbl + idx * 8);
            m = *q;
            if (m != 0) {
                q2 = (void **)(tbl + e * 4);
                if (*q2 != 0) {
                    *(int *)((char *)m + 0x104) = 0;
                    *(int *)((char *)*q2 + 0x104) = 0;
                    cModel_calcParts(*q);
                    cModel_calcParts(*q2);
                    ClrBit((int *)(p + 0x54), b1);
                    ClrBit((int *)(p + 0x54), b2);
                }
            }
        }
    }
}
