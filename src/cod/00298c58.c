/* sn-2.95.3-136 matched TU. */

extern char D_00754C58[];
extern signed char s_Handcart_0044abe0[];
extern int *cObjBaseArray_SearchOM(char *arr, long mask);
extern int D_00586AF0;
extern void func_00297B60(void *a, void *b);
extern void func_00298CF0(void);

/* SN ProDG ee-gcc 2.95.3 matched TU.
   compile_units: {"path": "src/cod/00298c58.c", "compiler": "sn-2.95.3-136",
                   "c_flags_add": ["-f=-fno-gcse"]}
   func_00298C58 needs -fno-gcse: with gcse on, the %hi halves of D_00586AF0 and
   func_00298CF0 are hoisted above the cObjBaseArray_SearchOM call into two
   callee-saved registers (+4 instructions, one sq pair).  func_00298CF0 is
   byte-exact with the flag and without it. */








__attribute__((section(".text.func_00298C58")))
void func_00298C58(void)
{
    char *tbl = D_00754C58;
    signed char *str = s_Handcart_0044abe0;
    signed char *s;
    long acc = 0;
    int i = 0;
    int *om;
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
        *(unsigned int *)((char *)om + 0x250) |= 2;
    }
    func_00297B60(&D_00586AF0, (void *)&func_00298CF0);
}

/* SN ProDG ee-gcc 2.95.3 matched TU.
   compile_units: {"path": "src/cod/00298c58.c", "compiler": "sn-2.95.3-136",
                   "c_flags_add": ["-f=-fno-gcse"]}
   func_00298C58 needs -fno-gcse: with gcse on, the %hi halves of D_00586AF0 and
   func_00298CF0 are hoisted above the cObjBaseArray_SearchOM call into two
   callee-saved registers (+4 instructions, one sq pair).  func_00298CF0 is
   byte-exact with the flag and without it. */








__attribute__((section(".text.func_00298CF0")))
void func_00298CF0(void)
{
    char *tbl = D_00754C58;
    signed char *str = s_Handcart_0044abe0;
    signed char *s;
    long acc = 0;
    int i = 0;
    int *om;
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
