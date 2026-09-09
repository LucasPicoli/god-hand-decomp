/* cygnus-2.96 matched TU. */

typedef struct Obj { int f0; void *tbl; } Obj;
extern int isEffectiveVer(Obj *o);
extern void *searchStmId(void *tbl, int id);
__attribute__((section(".text.SFH_IsExistStmId")))
int SFH_IsExistStmId(Obj *o, unsigned char id, int *out)
{
    void *tbl;

    tbl = o->tbl;
    *out = 0;
    if (isEffectiveVer(o) == 0) return 0;
    if (searchStmId(tbl, id) != 0) *out = 1;
    else *out = 0;
    return 1;
}
