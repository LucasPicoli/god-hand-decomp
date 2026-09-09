/* cygnus-2.96 matched TU. */

extern void func_00330A68(char *path);
extern void addDevName(char *dev, char *path);
extern char *getDevice(char *name);


__attribute__((section(".text.variousProc")))
char *variousProc(char *path, char *out, char *src)
{
    char *dev;

    if (*path == 0) {
        func_00330A68(path);
        if (*path == 0) return 0;
    }
    addDevName(path, out);
    dev = getDevice(path);
    if (dev == 0) {
        func_00330A68(path);
        dev = getDevice(path);
        if (dev == 0) return 0;
        func_003A57C4(out, src);
    }
    return dev;
}
