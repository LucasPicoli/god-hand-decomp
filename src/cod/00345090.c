/* cygnus-2.96: func_00345090, SFD header callback: counts headers and records each valid one in an 8-entry ring. */
typedef struct {
    int ver;   /* 0x0 */
    int no;    /* 0x4 */
    int a;     /* 0x8 */
    int b;     /* 0xC */
    int c;     /* 0x10 */
} SfdHdrEnt;

typedef struct {
    char pad0[0xB4];
    int count;            /* 0xB4 */
    char padB8[0x4];
    int idx;              /* 0xBC */
    SfdHdrEnt ent[8];     /* 0xC0 */
} SfdHdrRing;

extern void *SFH_Create(char *buf, int len);
extern int SFH_IsSfdHeader(void *sfh, int *ver);
extern void SFH_Destroy(void *sfh);
extern int mwsffrm_AnalyColAdj(void *sfh);
extern int func_00344F30(void *sfh);
extern int mwsffrm_AnalyFxType(void *sfh);

__attribute__((section(".text.func_00345090")))
void func_00345090(SfdHdrRing *o, char *buf, int len)
{
    void *sfh;
    int tmp;
    int ver;
    int a, b, c;
    int i;

    o->count++;
    if (len < 0x800 || buf == 0)
        return;
    sfh = SFH_Create(buf, len);
    if (sfh == 0)
        return;
    if (SFH_IsSfdHeader(sfh, &tmp) != 1 || (ver = tmp) != 1) {
        SFH_Destroy(sfh);
        return;
    }
    a = mwsffrm_AnalyColAdj(sfh);
    b = func_00344F30(sfh);
    c = mwsffrm_AnalyFxType(sfh);
    i = o->idx;
    o->ent[i].no = o->count - 1;
    o->ent[i].a = a;
    o->ent[i].b = b;
    o->ent[i].c = c;
    o->ent[i].ver = ver;
    o->idx = (o->idx + 1) % 8;
    SFH_Destroy(sfh);
}
