/* cygnus-2.96 matched TU. */

extern int D_003E8C08[];
extern char D_003F0298[];

__attribute__((section(".text.func_0033C2F0")))
int func_0033C2F0(char *p) {
    if (*(int *)(p + 0xC0) == 0) {
        return 0;
    }
    *(int *)(p + 0x88) = 0;
    *(short *)(p + 0x2) = 1;
    *(int *)(p + 0x10) = 0x600;
    *(unsigned char *)(p + 0xE) = 1;
    *(unsigned char *)(p + 0xD) = 0x10;
    *(int *)(p + 0x18) = 0x7FFFFFFF;
    *(unsigned char *)(p + 0xF) = 0x7F;
    *(short *)(p + 0x98) = 0xF;
    *(int *)(p + 0x50) = 1;
    *(int *)(p + 0x54) = 0x7F;
    *(int *)(p + 0x58) = 0x600;
    *(int *)(p + 0x5C) = *(int *)(p + 0x3C);
    *(int *)(p + 0x60) = *(int *)(p + 0x40);
    *(int *)(p + 0x64) = *(int *)(p + 0x44);
    *(int *)(p + 0x8C) = 0;
    *(short *)(p + 0x1C) = 0;
    *(short *)(p + 0x24) = 0;
    *(short *)(p + 0x26) = 0;
    *(int *)(p + 0x20) = 0;
    *(int *)(p + 0x28) = 0;
    *(int *)(p + 0x2C) = 0;
    *(int *)(p + 0x30) = 0;
    *(int *)(p + 0x34) = 0;
    *(int *)(p + 0x14) = 0xBB80;
    return 1;
}

__attribute__((section(".text.sj_hexstr_to_val")))
int sj_hexstr_to_val(char *s) {
    int v;

    v = D_003E8C08[s[0]];
    v = (v << 4) + D_003E8C08[s[1]];
    v = (v << 4) + D_003E8C08[s[2]];
    v = (v << 4) + D_003E8C08[s[3]];
    v = (v << 4) + D_003E8C08[s[4]];
    v = (v << 4) + D_003E8C08[s[5]];
    v = (v << 4) + D_003E8C08[s[6]];
    return v;
}

typedef struct {
    char b[0x1800];
} Blk1800;

__attribute__((section(".text.func_003665C0")))
void func_003665C0(void *dst) {
    *(Blk1800 *)dst = *(Blk1800 *)D_003F0298;
}
