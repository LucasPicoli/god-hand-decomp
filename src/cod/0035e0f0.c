/* cygnus-2.96 matched TU. */

typedef struct Obj { int f0; void *tbl; } Obj;

extern int isEffectiveVer(Obj *o);
extern void *searchStmId(void *tbl, int id);

__attribute__((section(".text.getElemInfPtr")))
void *getElemInfPtr(Obj *o, int id)
{
    void *tbl;

    tbl = o->tbl;
    if (isEffectiveVer(o) == 0) return 0;
    return searchStmId(tbl, id);
}
