/* cygnus-2.96 matched TU. */

extern int D_003DA380[4];
extern void func_003350F0(int *out, char *name, int tbl, int num);
extern int strlen(const char *s);
extern char D_00755E84[];
extern char *Obj0000_Get_D_00756080_3306C8(void);
extern int isNeedDevName(char *name);
extern char D_00756090[];
extern const char D_00453D80[];

/* htci_get_finf (second link instance).  D_003DA380 is the file-list header:
 * [0] = table pointer, [1] = entry count. */


__attribute__((section(".text.func_003351C0")))
void func_003351C0(char *name, int *out) {
    out[0] = 0;
    out[1] = 0;
    if (D_003DA380[0] != 0) func_003350F0(out, name, D_003DA380[0], D_003DA380[1]);
}

__attribute__((section(".text.getDevice")))
char *getDevice(char *name)
{
    int len = strlen(name);
    unsigned int i;

    for (i = 0; i < 32; i++) {
        if (func_003A5BD8(name, D_00755E84 + i * 16, len) == 0) {
            return *(char **)(D_00755E84 - 4 + i * 16);
        }
    }
    return 0;
}

__attribute__((section(".text.addDevName")))
void addDevName(char *dev, char *path)
{
    if (dev == 0) {
        dev = Obj0000_Get_D_00756080_3306C8();
    }
    if (isNeedDevName(dev) == 1) {
        func_003A57C4(D_00756090, path);
        func_003A6C58(path, D_00453D80, dev, D_00756090);
    }
}
