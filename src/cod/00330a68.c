extern unsigned int strlen(const char *s);
extern void *func_003A5148(void *d, const void *s, unsigned int n);
extern char D_00756080[];

__attribute__((section(".text.getDefDev")))
void getDefDev(char *dst)
{
    int len = strlen(D_00756080);

    if (D_00756080[0] == 0) {
        *dst = 0;
    } else {
        func_003A5148(dst, D_00756080, len + 1);
    }
}
