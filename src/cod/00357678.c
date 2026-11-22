/* cygnus-2.96 matched TU. */

extern int GetArrayElemA0C_35A1C8(void *p, int idx);
extern int Obj35C0_GetIndexed_1F34_C368(void *p, int idx);
extern void SFSEE_FixAvPlay(void *p, int a, int v);

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
        if (SFBUF_GetTermFlg(p, i) != 0) return 1;
    }
    return 0;
}

typedef struct Sub {
    char pad0[0x14];
    int f14;
    int f18;
} Sub;





__attribute__((section(".text.sfply_FixAvPlay")))
void sfply_FixAvPlay(char *p)
{
    Sub *s;

    s = (Sub *)(p + 0xA0C);
    if (s->f14 == 1 && SFBUF_GetWTot(p, 1) == 0 && SFBUF_GetRTot(p, 1) == 0) {
        s->f14 = 0;
    }
    if (s->f18 == 1 && SFBUF_GetWTot(p, 2) == 0 && SFBUF_GetRTot(p, 2) == 0) {
        s->f18 = 0;
    }
    SFSEE_FixAvPlay(p, s->f14, s->f18);
}
