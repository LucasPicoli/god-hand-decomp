/* cygnus-2.96 matched TU. */

__attribute__((section(".text.func_0033D198")))
void func_0033D198(char *o, int a1, int a2) {
    int q;
    if (*(short *)(o + 0x98) == 0) {
        *(int *)(o + 0x48) = a1;
        q = a2 / (int)*(signed char *)(o + 0xF);
        *(int *)(o + 0x74) = 0;
    } else {
        int d = ((int)*(signed char *)(o + 0xD) / 8) * (int)*(signed char *)(o + 0xE);
        *(int *)(o + 0x48) = a1;
        q = a2 / d;
        *(int *)(o + 0x74) = 0;
    }
    *(int *)(o + 0x4C) = q;
    *(int *)(o + 0x90) = 0;
    *(int *)(o + 0x94) = 0;
    *(int *)(o + 0xF8) = 0;
    *(int *)(o + 0xF4) = 0;
}

__attribute__((section(".text.func_0036E208")))
void func_0036E208(int *s){
    unsigned int w = ((unsigned int)s[0x50/4] << 12) | s[0x4/4];
    unsigned int h = ((unsigned int)s[0x54/4] << 12) | s[0x8/4];
    int v1, a0;
    s[0x2CC/4] = (w + 0xF) >> 4;
    s[0x2C4/4] = w;
    s[0x2C8/4] = h;
    if (s[0x48/4] == 1) { s[0x2D0/4] = (h + 0xF) >> 4; }
    else if (s[0x118/4] == 3) { s[0x2D0/4] = ((h + 0x1F) >> 5) << 1; }
    else { s[0x2D0/4] = (h + 0x1F) >> 5; }
    v1 = s[0x2CC/4] << 4;
    a0 = s[0x2D0/4] << 4;
    s[0x3BC/4] = v1 >> 1;
    s[0x3B4/4] = v1;
    s[0x3B8/4] = a0;
    s[0x3C0/4] = a0 >> 1;
}

struct Obj_0033d198 { char pad0[7]; unsigned char unk7; unsigned char unk8; unsigned char unk9; char pad_a[2]; int unkC; char pad10[0x1A]; unsigned short unk2A; };
__attribute__((section(".text.func_0033D9C0")))
int func_0033D9C0(struct Obj_0033d198 *obj, int a1u, short *out2, char *outNeg1, signed char *out5, signed char *out6, signed char *out7, int *out8, int *out9, int *out10, short *out11) {
 unsigned char type; int v;
 *out2 = obj->unk7 << 4; *out7 = (obj->unk9 & 3) + 1; *out8 = obj->unk2A;
 type = obj->unk8;
 switch (type) {
 case 0: { int d; *out5 = 0x10; d = *out7; *out6 = d << 1; *out10 = 1; *out11 = 0; v = obj->unkC/2; *out9 = v; break; }
 case 1: { int d; *out5 = 8; d = *out7; *out6 = d; *out10 = type; *out11 = type; v = obj->unkC; *out9 = v; break; }
 case 2: case 3: { int d; *out5 = 4; d = *out7; *out6 = d; *out10 = 2; *out11 = 2; v = obj->unkC*2; *out9 = v; break; }
 }
 *out6 = 2; *out10 = 1; *out9 = obj->unkC / 2; *out5 = 0x10; *outNeg1 = -1; return 0; }
