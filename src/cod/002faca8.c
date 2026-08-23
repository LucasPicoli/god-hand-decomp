/* sn-2.95.3-136 matched TU. */

extern char D_0061B7C0[];
extern void *InitObjectSetVtable_4E090_2FFA90(void *);
extern void *InitObjectSetVtable_4E820_2FFC20(void *);
extern void *InitObjectSetVtable_4EA10_2FFC88(void *);
extern void *InitObjectSetVtable_4EAB8_2FFCC8(void *);
extern void *InitObjectSetVtable_4EB70_2FFD08(void *);
extern void *InitObjectSetVtable_4EC68_2FFD48(void *);
extern void *InitVtablePtrAndClearField_2FFD88(void *);
extern void *InitObjectSetVtable_4EFA0_2FFE10(void *);
extern void *InitObjectSetVtable_4F078_2FFE50(void *);
extern void *InitObjectSetVtable_4F1C8_2FFE90(void *);
extern void *InitObjectSetVtable_4F270_2FFED0(void *);
extern void *InitObjectSetVtable_4F3A0_2FFF50(void *);
extern void *InitObjectSetVtable_4F630_300020(void *);
extern void *InitObjectFieldsIfNonNull_300060(void *);
extern void *InitObjectSetVtable_4F880_3000B0(void *);

__attribute__((section(".text.func_002FACA8")))
void *func_002FACA8(int slot, int type) {
    char *r;

    switch (type) {
    case 0:  r = (char *)func_002FFA68(&D_0061B7C0[slot << 10]); break;
    case 1:  r = (char *)InitObjectSetVtable_4E090_2FFA90(&D_0061B7C0[slot << 10]); break;
    case 2:  r = (char *)func_002FFAD0(&D_0061B7C0[slot << 10]); break;
    case 3:  r = (char *)func_002FFB10(&D_0061B7C0[slot << 10]); break;
    case 4:  r = (char *)func_002FFB38(&D_0061B7C0[slot << 10]); break;
    case 5:  r = (char *)func_002FFB80(&D_0061B7C0[slot << 10]); break;
    case 6:  r = (char *)func_002FFBD0(&D_0061B7C0[slot << 10]); break;
    case 7:  r = (char *)func_002FFBF8(&D_0061B7C0[slot << 10]); break;
    case 8:  r = (char *)InitObjectSetVtable_4E820_2FFC20(&D_0061B7C0[slot << 10]); break;
    case 9:  r = (char *)func_002FFC60(&D_0061B7C0[slot << 10]); break;
    case 15: r = (char *)InitObjectSetVtable_4EA10_2FFC88(&D_0061B7C0[slot << 10]); break;
    case 16: r = (char *)InitObjectSetVtable_4EAB8_2FFCC8(&D_0061B7C0[slot << 10]); break;
    case 18: r = (char *)InitObjectSetVtable_4EB70_2FFD08(&D_0061B7C0[slot << 10]); break;
    case 19: r = (char *)InitObjectSetVtable_4EC68_2FFD48(&D_0061B7C0[slot << 10]); break;
    case 20: r = (char *)InitVtablePtrAndClearField_2FFD88(&D_0061B7C0[slot << 10]); break;
    case 21: r = (char *)func_002FFDC8(&D_0061B7C0[slot << 10]); break;
    case 22: r = (char *)InitObjectSetVtable_4EFA0_2FFE10(&D_0061B7C0[slot << 10]); break;
    case 24: r = (char *)InitObjectSetVtable_4F078_2FFE50(&D_0061B7C0[slot << 10]); break;
    case 25: r = (char *)InitObjectSetVtable_4F1C8_2FFE90(&D_0061B7C0[slot << 10]); break;
    case 26: r = (char *)InitObjectSetVtable_4F270_2FFED0(&D_0061B7C0[slot << 10]); break;
    case 29: r = (char *)func_002FFF10(&D_0061B7C0[slot << 10]); break;
    case 30: r = (char *)InitObjectSetVtable_4F3A0_2FFF50(&D_0061B7C0[slot << 10]); break;
    case 31: r = (char *)func_002FFF90(&D_0061B7C0[slot << 10]); break;
    case 32: r = (char *)func_002FFFB8(&D_0061B7C0[slot << 10]); break;
    case 33: r = (char *)func_002FFFE0(&D_0061B7C0[slot << 10]); break;
    case 35: r = (char *)InitObjectSetVtable_4F630_300020(&D_0061B7C0[slot << 10]); break;
    case 36: r = (char *)InitObjectFieldsIfNonNull_300060(&D_0061B7C0[slot << 10]); break;
    case 37: r = (char *)func_00300088(&D_0061B7C0[slot << 10]); break;
    case 38: r = (char *)InitObjectSetVtable_4F880_3000B0(&D_0061B7C0[slot << 10]); break;
    default: return 0;
    }
    r[0x102] = type;
    return r;
}
