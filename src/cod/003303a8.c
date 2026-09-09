/* cygnus-2.96 matched TU. */

extern void toUpperStr(char *s);
extern char *getDevice(char *name);
extern int strlen(const char *s);


struct DEVENT { void *dev; char name[12]; };
extern struct DEVENT D_00755E80[32];

__attribute__((section(".text.func_003303A8")))
void *func_003303A8(char *name, void *(*openfn)(void))
{
    void *d;
    char *dst;
    int i;

    toUpperStr(name);
    d = openfn();
    i = 0;
    if (getDevice(name) != 0) return d;
    for (; i < 32; i++) {
        if (D_00755E80[i].name[0] == 0) break;
    }
    if (i == 32) return 0;
    D_00755E80[i].dev = d;
    dst = D_00755E80[i].name;
    func_003A5148(dst, name, strlen(name) + 1);
    return d;
}
