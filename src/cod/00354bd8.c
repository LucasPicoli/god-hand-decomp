/* cygnus-2.96: apply a pending request: copy its parameter blocks to the globals and run it, then
 * change state on success or clear the request. */
#include "godhand/sftim.h"
#include "godhand/globals.h"
typedef struct ReqPrmA { int w[9]; } ReqPrmA;      /* 0x24 */
typedef struct ReqPrmB { int w[2]; } ReqPrmB;      /* 0x08 */
typedef struct ReqPrmC { int w[16]; } ReqPrmC;     /* 0x40 */

typedef struct PendingReq {
    int id;                             /* 0x00 */
    ReqPrmA a;                          /* 0x04 */
    ReqPrmB b;                          /* 0x28 */
    ReqPrmC c;                          /* 0x30 */
    char unk70[0x1080 - 0x70];
    int x;                              /* 0x1080 */
    int y;                              /* 0x1084 */
    int z;                              /* 0x1088 */
} PendingReq;

extern ReqPrmA D_00766BA8;
extern ReqPrmB D_00766BD0;
extern ReqPrmC D_00766BD8;

extern void func_003567E0(char *p);
extern int func_00354D68(int id);

__attribute__((section(".text.func_00354BD8")))
int func_00354BD8(char *p)
{
    PendingReq *req = *(PendingReq **)(p + 0x1FC0);
    int id = req->id;

    if (id == 0)
        return 0;
    D_00766BA8 = req->a;
    D_00766BD0 = req->b;
    D_00766BD8 = req->c;
    D_00766C18 = req->x;
    D_00766C1C = req->y;
    D_00766C20 = req->z;
    func_003567E0(p);
    if (func_00354D68(id))
        return func_0034DD70((SftimHn *)p, 0xFF000F0C);
    req->id = 0;
    return 0;
}
