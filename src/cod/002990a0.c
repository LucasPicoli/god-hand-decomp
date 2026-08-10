/* sn-2.95.3-136 matched TU. */

extern char D_00754C58[];
extern signed char D_0044AC28[];
extern signed char D_0044AC30[];
extern void *cObjBaseArray_SearchOM(char *arr, long mask);

static inline void Clr(char *tbl, signed char *str) {
    signed char *s;
    long acc = 0;
    int i = 0;
    void *om;
    if (str[0] != 0) {
        s = str;
        do {
            acc |= (long)*s << (i * 8);
            i++;
            s++;
            if (i >= 8) break;
        } while (*s != 0);
    }
    om = cObjBaseArray_SearchOM(tbl, acc);
    if (om != 0) {
        *(unsigned int *)((char *)om + 0x250) &= 0xFFFFFFFDU;
    }
}

__attribute__((section(".text.func_002990A0")))
void func_002990A0(void) {
    Clr(D_00754C58, D_0044AC28);
    Clr(D_00754C58, D_0044AC30);
}
