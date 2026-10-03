/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cOmBase.h"

extern void *Getplayer(void);
extern int cCamManager_isCk_CamClass(void *mgr, int cls);
extern void func_001325A0(void *self, cVec *pos);
extern char D_00463050[];
extern char D_00747A2C[];
extern char *D_005CAFF0;

typedef struct VtEnt {
    short delta;
    short index;
    void (*pfn)(void *self, int a, int b);
} VtEnt;

/* The same slot read as a one-argument method. */
typedef struct VtEnt1 {
    short delta;
    short index;
    void (*pfn)(void *self);
} VtEnt1;

/* A listed child: next link first, method table at 0x5C. */
typedef struct ListNode {
    struct ListNode *next;              /* 0x00 */
    char unk04[0x58];
    VtEnt *vt;                          /* 0x5C */
} ListNode;

typedef struct ListOwner {
    char unk000[0x190];
    ListNode *first;                    /* 0x190 */
} ListOwner;

#define SYSFLAG_FOLLOW_CAM   0x8000000  /* D_00747A2C word 2 */
#define CAMCLASS_FOLLOW      0x10
#define CAM_FOCUS_OFFSET     0x200

/* Run method 3 of every listed child; when the follow flag is set, point the owner at the camera focus (or the player) and run method 2 of every child. */
__attribute__((section(".text.func_0012E840")))
void func_0012E840(ListOwner *self)
{
    cVec pos __attribute__((aligned(16)));
    ListNode *n;
    void *pl;
    cVec *src;
    char *g;

    n = self->first;
    while (n != 0) {
        ((VtEnt1 *)n->vt)[3].pfn((char *)n + n->vt[3].delta);
        n = n->next;
    }
    g = D_00747A2C;
    if ((*(unsigned int *)(g + 8) & SYSFLAG_FOLLOW_CAM) != 0) {
        pl = Getplayer();
        pos.x = 0.0f;
        pos.y = 0.0f;
        pos.z = 0.0f;
        pos.w = 1.0f;
        if (cCamManager_isCk_CamClass(D_00463050, CAMCLASS_FOLLOW) != 0) {
            if (D_005CAFF0 != 0) {
                cVec_copy3(&pos, (cVec *)(D_005CAFF0 + CAM_FOCUS_OFFSET));
            }
        } else if (pl != 0) {
            src = *(cVec **)((char *)pl + 0xF0);
            cVec_copy3(&pos, src);
        }
        func_001325A0(self, &pos);
        n = self->first;
        while (n != 0) {
            n->vt[2].pfn((char *)n + n->vt[2].delta, 0, 0);
            n = n->next;
        }
    }
}
