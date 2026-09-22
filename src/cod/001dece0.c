/* sn-2.95.3-136 matched TU. */

extern int EnsureInitThenForward_2A9538_30EE08(void *ctx, int k, int v);
extern char D_0044B288[];
extern void cIDBase_initialize(void *p, int a, int b);
extern void cIDBase_restartAnim(void *p);
extern void *cIDBase_getIDWork(void *p, int i);
extern void CustomIDWork_Initialize(void *p, void *w);
extern void CustomIDWork_SetDisp(void *p, int f);
extern void CustomIDWork_SetMessNo(void *p, int n);
extern void func_001DEE60(void *p, int a, int b);
extern char *Obj0000_Get_Field_20_Plus_A1_Shifted3_1333B8(void *p, unsigned short i);
extern int cScrArray_SearchScroll(void *p, long v);
extern void HideModelMgr_ClearHiddenModelList(void *p);
extern char D_005CAE50[];
extern char D_00754C38[];
extern void func_003A52F0(void *d, int c, int n);
extern void func_001FC810(void *n, void *buf, int cnt);

typedef struct { int w[2]; } Blob8;

__attribute__((section(".text.func_002B5AF8")))
int func_002B5AF8(void *a0, int a1, void *ctx)
{
    Blob8 buf;
    char *res;
    int i;
    int v;

    buf = *(Blob8 *)D_0044B288;
    res = func_002B4FE8(a0, 0);
    if (res == 0) return 0;

    for (i = 0; i < 2; i++) {
        v = EnsureInitThenForward_2A9538_30EE08(ctx, 0x80, buf.w[i]);
        if (v != 0) {
            *(int *)(res + 0x0) = v;
            *(int *)(res + 0x4) = buf.w[i];
            return v;
        }
    }
    return 0;
}

__attribute__((section(".text.func_001DECE0")))
void func_001DECE0(char *p)
{
    int i;

    cIDBase_initialize(p + 0x10, 0x12, 1);
    cIDBase_restartAnim(p + 0x10);
    for (i = 0; i < 0x11; i++) {
        CustomIDWork_Initialize(p + 0x60 + i * 0x7C, cIDBase_getIDWork(p + 0x10, i));
    }
    CustomIDWork_SetDisp(p + 0x60, 0);
    CustomIDWork_SetMessNo(p + 0x3C4, 0x1000);
    CustomIDWork_SetMessNo(p + 0x4BC, 0x1001);
    CustomIDWork_SetMessNo(p + 0x538, 0x1002);
    func_001DEE60(p, 0x11, 0);
}

__attribute__((section(".text.func_00307A60")))
void func_00307A60(void *p)
{
    char *m;
    char *e;
    int i;
    int r;

    m = *(char **)D_005CAE50;
    if (m != 0 && *(unsigned short *)(m + 0x2A) != 0) {
        i = 0;
        do {
            e = Obj0000_Get_Field_20_Plus_A1_Shifted3_1333B8((void *)D_005CAE50, i);
            if (e != 0 && *(int *)e != 0) {
                r = cScrArray_SearchScroll((void *)D_00754C38, *(long *)e);
                if (r != 0) {
                    *(int *)(e + 0x4) = r;
                    *(int *)(e + 0x0) = 0;
                }
            }
            i++;
        } while (i < *(unsigned short *)(m + 0x2A));
    }
    HideModelMgr_ClearHiddenModelList(p);
}

__attribute__((section(".text.func_001FDD38")))
int func_001FDD38(char *p, int key)
{
    int buf[0x14];
    char *n;
    char *o;
    int *q;
    int v;
    int i;

    func_003A52F0(buf, 0, 0x50);

    n = *(char **)(p + 0x3C);
    if (n == 0) goto ng;
    do {
        func_001FC810(n, buf, 0x14);
        i = 0;
        v = buf[0];
        if (v != 0) {
            q = buf;
            do {
                o = func_002BB138((char *)v + 0x14, 1);
                if (*(int *)(o + 0x30) == key) return 1;
                i++;
                q++;
                if (i >= 0x14) break;
                v = *q;
            } while (v != 0);
        }
        n = *(char **)(n + 0x24);
    } while (n != 0);
ng:
    return 0;
}
