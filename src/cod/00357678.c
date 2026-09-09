/* cygnus-2.96 matched TU. */

extern int GetArrayElemA0C_35A1C8(void *p, int idx);
extern int Obj35C0_GetIndexed_1F34_C368(void *p, int idx);
extern void func_003597D0(void *p, int a, int v);

__attribute__((section(".text.sfply_IsAnyoneTerm")))
int sfply_IsAnyoneTerm(void *p)
{
    unsigned int i;

    if (GetArrayElemA0C_35A1C8(p, 5) != 0) {
        if (Obj35C0_GetIndexed_1F34_C368(p, 6) != 0) return 1;
    }
    if (GetArrayElemA0C_35A1C8(p, 6) != 0) {
        if (Obj35C0_GetIndexed_1F34_C368(p, 7) != 0) return 1;
    }
    for (i = 0; i < 8; i++) {
        if (func_0034CA98(p, i) != 0) return 1;
    }
    return 0;
}

typedef struct Sub {
    char pad0[0x14];
    int f14;
    int f18;
} Sub;





__attribute__((section(".text.func_00357678")))
void func_00357678(char *p)
{
    Sub *s;

    s = (Sub *)(p + 0xA0C);
    if (s->f14 == 1 && func_0034C7F0(p, 1) == 0 && func_0034C7D0(p, 1) == 0) {
        s->f14 = 0;
    }
    if (s->f18 == 1 && func_0034C7F0(p, 2) == 0 && func_0034C7D0(p, 2) == 0) {
        s->f18 = 0;
    }
    func_003597D0(p, s->f14, s->f18);
}
