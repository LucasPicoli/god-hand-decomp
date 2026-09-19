/* cygnus-2.96 */

typedef struct Obj { int w[4]; } Obj;
typedef struct Lib { int num; int cnt; Obj *tbl; } Lib;

extern Lib D_00766C90;
extern int Obj35D0_IsField0Zero_D7A8(Obj *o);
extern void Obj35D0_SetFields_1_a1_a2_D740(Obj *o, void *a, void *b);

__attribute__((section(".text.SFH_Create")))
Obj *SFH_Create(void *a, void *b)
{
    Obj *obj = 0;
    Obj *tbl;
    int num;
    int cnt;
    int i;

    num = D_00766C90.num;
    cnt = D_00766C90.cnt;
    tbl = D_00766C90.tbl;
    if (cnt >= num) return 0;
    for (i = 0; i < num; i++) {
        obj = &tbl[i];
        if (Obj35D0_IsField0Zero_D7A8(obj) != 0) break;
    }
    Obj35D0_SetFields_1_a1_a2_D740(obj, a, b);
    D_00766C90.cnt++;
    return obj;
}
