/* sn-2.95.3-136: func_00394DD8, module load/start: resolves the module, links it, reports the result and runs its start callback. */
#include "godhand/regTbl.h"
#include "godhand/globals.h"
#include "godhand/iopModStop.h"
typedef struct {
    char pad0[0x14];
    int arg;              /* 0x14 */
    void (*start)(void);  /* 0x18 */
    char pad1C[0x4];
    int res;              /* 0x20 */
    int hasRes;           /* 0x24 */
} IopModule;

extern int func_00393F80(IopModule *m);
extern void func_003951C0(void);
extern int func_00394828(IopModule *m, IopModule *m2);
extern void func_003951D0(void);
extern int func_00394C18(int arg, IopModule *m);
extern void func_003951B0(void);
extern int func_003A6A20(const char *fmt, ...);

__attribute__((section(".text.func_00394DD8")))
int func_00394DD8(IopModule *m, int *res)
{
    int r;
    int id;

    if (res)
        *res = 0;
    r = func_00393F80(m);
    if (r != 0)
        return r;
    func_003951C0();
    r = func_00394828(m, m);
    if (r != 0) {
        func_003951D0();
        return r;
    }
    if (res && m->hasRes)
        *res = m->res;
    id = func_00394C18(m->arg, m);
    r = id >= 0 ? 0 : 6;
    func_003951D0();
    if (r != 0)
        return r;
    if (D_003F8528 == 0)
        func_003951B0();
    else if (D_003F8528 == 1)
        func_003A6A20(D_0045DBD8, id, D_003F5520.ent[id].a, D_003F5520.ent[id].key,
                      D_003F5520.ent[id].check, D_003F5520.ent[id].a);
    if (m->start)
        m->start();
    return 0;
}
