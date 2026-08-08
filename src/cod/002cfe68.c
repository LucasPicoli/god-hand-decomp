/* sn-2.95.3-136 matched TU. */

extern char D_0044D010[];
extern char D_0044D018[];
extern int D_003C3100[];
extern int D_003C3104;
extern int D_003C310C;
extern int D_003C3118;

/* sn-2.95.3-136 matched TU. */









__attribute__((section(".text.func_002CFE68")))
void func_002CFE68(int a0, int sel, int val, int arg) {
    switch (sel) {
    case 3:
        func_003A6C58(arg, D_0044D010, D_003C310C, val & 0xFF);
        break;
    case 2:
        func_003A6C58(arg, D_0044D018, D_003C3100[sel], val & 0xFFF);
        break;
    case 1:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 16:
    case 17:
    case 18:
    case 19:
        func_003A6C58(arg, D_0044D010, D_003C3104, val & 0xFF);
        break;
    case 6:
        func_003A6C58(arg, D_0044D010, D_003C3118, val & 0xFF);
        break;
    default:
        break;
    }
}
