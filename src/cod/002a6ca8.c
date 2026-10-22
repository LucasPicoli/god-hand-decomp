/* sn-2.95.3-136 */
#include "godhand/cOmBase.h"
#include "godhand/cTaskWork.h"
#include "godhand/gameWork.h"
#include "godhand/cIDManager.h"

/* The draw context Gp_draw_poly4 takes. */
typedef struct PolyCtx {
    int mode;                           /* 0x00 */
    char pad04[0x30 - 4];
    long prim;                          /* 0x30 GS PRIM register value */
    char pad38[0x48 - 0x38];
} PolyCtx;

struct cDvdState;

extern char D_00583F20[];               /* cDvd state */
extern float D_003C1184;                /* quad right edge */
extern float D_003C1190;                /* quad bottom edge */
extern unsigned char cDvd_stepState(struct cDvdState *self);
extern void *Gp_draw_poly4(cVec *v, int color, int count, PolyCtx *ctx, int a5, int a6);

/* While the disc state is counting down, draw a black full-screen quad each frame.
 * The caller passes a pointer; it is not read. */
__attribute__((section(".text.func_002A6CA8")))
void func_002A6CA8(void *arg)
{
    cVec vt[4];
    PolyCtx ctx;

    while (cDvd_stepState((struct cDvdState *)D_00583F20) == 1) {
        ctx.mode = 0;
        func_003A52F0(&ctx, 0, sizeof(ctx));
        ctx.mode |= 0x20;
        ctx.prim = 0x30000;
        vt[0].y = vt[2].y = vt[0].x = vt[1].x = 0.0f;
        vt[2].x = vt[3].x = D_003C1184;
        vt[1].y = vt[3].y = D_003C1190;
        vt[0].z = vt[1].z = vt[2].z = vt[3].z = 65535.0f;
        vt[0].w = vt[1].w = vt[2].w = vt[3].w = 1.0f;
        Gp_draw_poly4(vt, 0x80000000, 1, &ctx, 6, 5);
        cTaskWork_sleep(D_00752C00.task, 1);
    }
}
