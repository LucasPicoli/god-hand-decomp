/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005FEA60[];

typedef struct { char pad[0x64]; unsigned char f64; char pad2[0xB]; char *f70; } S002C2418;


__attribute__((section(".text.func_002C2418")))
int func_002C2418(char *a0, int flags) {
    if (((S002C2418 *)D_005FEA60)->f70 == 0) {
        if (flags & 0x10) {
            ((S002C2418 *)D_005FEA60)->f70 = a0 + 0x5C;
            ((S002C2418 *)D_005FEA60)->f64 = *(unsigned char *)(a0 + 0x7C);
        } else if (flags & 0x20) {
            ((S002C2418 *)D_005FEA60)->f64 = *(unsigned char *)(a0 + 0x7D);
        } else {
            ((S002C2418 *)D_005FEA60)->f70 = a0 + 0x5C;
        }
    }
    return 0;
}
