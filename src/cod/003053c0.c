/* sn-2.95.3-136 matched TU. */

extern void func_003A6C58(void *a0, void *a1, ...);
extern char D_0044FEA8[];
extern char D_0044FEB8[];
extern char D_0044FEC8[];
extern char D_0044FED8[];
extern char D_0044FEE0[];
extern char D_0044FEF0[];
extern char D_0044FF00[];
extern char D_0044FF10[];
extern char D_0044FF20[];
extern char D_0044FF30[];
extern char D_0044FF40[];
extern char D_0044FF50[];
extern char D_0044FF60[];
extern char D_0044FF70[];
extern char D_0044FF80[];
extern char D_0044FF90[];
extern char D_0044FFA0[];
extern char D_0044FFB0[];
extern char D_0044FFC0[];
extern char D_0044FFD0[];
extern char D_0044FFE0[];
extern char D_0044FFF0[];
extern char D_00450000[];
extern char D_00450010[];

/* sn-2.95.3-136 */




























typedef struct { char b[8]; } T8;
typedef struct { char b[9]; } T9;
typedef struct { char b[10]; } T10;
typedef struct { char b[12]; } T12;

__attribute__((section(".text.getEffTypeString")))
void getEffTypeString(char *dst, int type) {
    if (type < 7) {
        switch (type) {
        case 0:
            *(T9 *)dst = *(T9 *)D_0044FEA8;
            break;
        case 1:
            *(T9 *)dst = *(T9 *)D_0044FEB8;
            break;
        case 2:
            *(T9 *)dst = *(T9 *)D_0044FEC8;
            break;
        case 3:
            *(T8 *)dst = *(T8 *)D_0044FED8;
            break;
        case 4:
            *(T10 *)dst = *(T10 *)D_0044FEE0;
            break;
        case 5:
            *(T12 *)dst = *(T12 *)D_0044FEF0;
            break;
        case 6:
            *(T10 *)dst = *(T10 *)D_0044FF00;
            break;
        default:
            func_003A6C58(dst, D_0044FF10, type);
            break;
        }
    } else if (type < 8) {
        func_003A6C58(dst, D_0044FF20, type - 0x7);
    } else if (type < 0x48) {
        func_003A6C58(dst, D_0044FF30, type - 0x8);
    } else if (type == 0x48) {
        func_003A6C58(dst, D_0044FF40);
    } else if (type < 0x58) {
        func_003A6C58(dst, D_0044FF50, type - 0x48);
    } else if (type < 0x158) {
        func_003A6C58(dst, D_0044FF60, type - 0x58);
    } else if (type < 0x258) {
        func_003A6C58(dst, D_0044FF70, type - 0x158);
    } else if (type < 0x358) {
        func_003A6C58(dst, D_0044FF80, type - 0x258);
    } else if (type < 0x458) {
        func_003A6C58(dst, D_0044FF90, type - 0x358);
    } else if (type < 0x4D8) {
        func_003A6C58(dst, D_0044FFA0, type - 0x458);
    } else if (type == 0x4D8) {
        func_003A6C58(dst, D_0044FFB0);
    } else if (type == 0x4D9) {
        func_003A6C58(dst, D_0044FFC0);
    } else if (type == 0x4DA) {
        func_003A6C58(dst, D_0044FFD0);
    } else if (type == 0x4DB) {
        func_003A6C58(dst, D_0044FFE0);
    } else if (type == 0x4E0) {
        func_003A6C58(dst, D_0044FFF0);
    } else if (type == 0x4E1) {
        func_003A6C58(dst, D_00450000);
    } else {
        func_003A6C58(dst, D_00450010);
    }
}
