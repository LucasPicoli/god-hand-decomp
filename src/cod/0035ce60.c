typedef struct { char pad0[8]; char *ents; char pad0C[4]; int state; } SfdEntSet;

extern int Obj34D8_SetGlobalEE0B8_IfField48(char *a0);
extern int func_0034DD70(int a0, int a1);
extern void Obj35D0_SetFields_0_4_8_C_D1B0(char *p, int a1, int a2, int a3, int a4);
extern void SFBUF_SetUoch(char *a0, int a1, int a2, char *a3);

__attribute__((section(".text.SFD_SetUsrSj")))
int SFD_SetUsrSj(char *a0, int idx, int a2, int a3)
{
    SfdEntSet *s = (SfdEntSet *)(a0 + 0x2150);
    int state;
    char *p;
    char *e;

    if (Obj34D8_SetGlobalEE0B8_IfField48(a0) != 0)
        return func_0034DD70(0, 0xFF000191);
    state = s->state;
    e = s->ents;
    if (state == 8)
        return func_0034DD70((int)a0, 0xFF000602);
    p = e + idx * 16 + 4;
    Obj35D0_SetFields_0_4_8_C_D1B0(p, a2, a3, 0, 0);
    SFBUF_SetUoch(a0, state, idx, p);
    return 0;
}
