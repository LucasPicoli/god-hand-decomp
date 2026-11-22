/* cygnus-2.96 matched TU. */

extern void getDefDev(char *path);
extern void addDevName(char *dev, char *path);
extern char *getDevice(char *name);


__attribute__((section(".text.variousProc")))
char *variousProc(char *path, char *out, char *src)
{
    char *dev;

    if (*path == 0) {
        getDefDev(path);
        if (*path == 0) return 0;
    }
    addDevName(path, out);
    dev = getDevice(path);
    if (dev == 0) {
        getDefDev(path);
        dev = getDevice(path);
        if (dev == 0) return 0;
        func_003A57C4(out, src);
    }
    return dev;
}
