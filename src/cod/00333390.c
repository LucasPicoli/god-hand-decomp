/* cygnus-2.96 matched TU. */

extern char D_003D9DE0[];
extern char D_004544E0[];
extern char D_004544E8[];
extern void func_003A57C4(char *, char *);
extern void func_003A53A8(char *, char *);
extern unsigned int strlen(const char *);
extern int dvci_to_large_to_yen(char *);

__attribute__((section(".text.func_00333390")))
int func_00333390(char *a0, char *a1) {
    char c;

    func_003A57C4(a1, D_003D9DE0);
    c = *a0;
    if (c != 0x2F && c != 0x5C) {
        func_003A53A8(a1, D_004544E0);
    }
    func_003A53A8(a1, a0);
    if (func_003A5678(a1 + strlen(a1) - 2, D_004544E8) != 0) {
        func_003A53A8(a1, D_004544E8);
    }
    return dvci_to_large_to_yen(a1);
}
