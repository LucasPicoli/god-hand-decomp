
#include "godhand/cIDBase.h"

extern void cIDBase(void *);
extern void CustomIDWork(void *);

/* -- PERMANENT (bnel/beql) — stay in monolithic asm/cod/000000 ------------ */
/* func_001F20F8 (beql+bnel, 0x324 B) stays in monolithic — PERMANENT.      */
/* func_001F2428 (bnel, 0x110 B) stays in monolithic — PERMANENT.           */
/* ArenaEm_stepBossIntro (beql+bnel, 0x108 B) stays in monolithic — PERMANENT.      */
/* func_001F2650 (bnel, 0x40 B) stays in monolithic — PERMANENT.            */

/* -- Accessor C bodies (5) — jr $ra; nop empty functions ------------------ */

/* jr $ra; nop */
__attribute__((section(".text.Obj1F20_NoOp_20F0")))
void Obj1F20_NoOp_20F0(void) {}

/* jr $ra; nop */
__attribute__((section(".text.Obj1F20_NoOp_2420")))
void Obj1F20_NoOp_2420(void) {}

/* jr $ra; nop */
__attribute__((section(".text.Obj1F20_NoOp_2538")))
void Obj1F20_NoOp_2538(void) {}

/* jr $ra; nop */
__attribute__((section(".text.Obj1F20_NoOp_2648")))
void Obj1F20_NoOp_2648(void) {}

/* jr $ra; nop */
__attribute__((section(".text.Obj1F20_NoOp_2690")))
void Obj1F20_NoOp_2690(void) {}

/* -- Call-chain (nonmatching) --------------------------------------------- */
/* Arena enemy intro: step 0 defeats every enemy and moves on, step 1 moves to the last step. */
typedef struct ArenaEm {
    char unk000[0xB94];
    int introStep;                      /* 0xB94 */
} ArenaEm;

extern void ColiseumBattle_DefeatAllEnemies(ArenaEm *self);

__attribute__((section(".text.ArenaEm_stepIntro")))
void ArenaEm_stepIntro(ArenaEm *self)
{
    switch (self->introStep) {
    case 0:
        ColiseumBattle_DefeatAllEnemies(self);
        self->introStep = self->introStep + 1;
        break;
    case 1:
        self->introStep = 2;
        break;
    }
}

__attribute__((section(".text.func_001F2708")))
void *func_001F2708(void *a0) {
    char *this = (char *)a0;
    char *p;
    int i;

    *(int *)this = 0;
    cIDBase(this + 0x10);

    p = this + 0x60;
    /* `i != -1`, not `i >= 0`: retail materialises -1 and closes with bne. */
    for (i = 0x11; i != -1; i--) {
        CustomIDWork(p);
        p += 0x7C;
    }

    cIDBase(this + 0x930);

    p = this + 0x980;
    for (i = 2; i != -1; i--) {
        CustomIDWork(p);
        p += 0x7C;
    }

    return this;
}

extern void cIDBase_initialize(void *p, int a, int b);
extern void cIDBase_restartAnim(void *p);
extern void CustomIDWork_Initialize(void *p, void *w);
extern void CustomIDWork_SetMessNo(void *p, int n);
extern void SetCustomIDDispOneOrAll_1F29C0(void *p, int n, int f);
extern void CustomIDOwner_setPanelState(void *p, int a);

#define UI_WORK_SIZE      0x7C          /* one CustomIDWork */
#define UI_MAIN_WORK_NUM  0x12
#define UI_SUB_WORK_NUM   3
#define UI_SUB_TITLE      2             /* the sub display's title work */
#define UI_IDDATA_KIND    0x15
#define UI_TITLE_MESS     0x300F

/* Two cIDBase displays, each with its CustomIDWork records. The records are
 * kept as bytes: this unit calls the CustomIDWork constructor, whose name is
 * the type's. */
typedef struct IdUi {
    char unk000[0x10];
    cIDBaseObj id;                              /* 0x010 */
    char unk058[0x60 - 0x10 - sizeof(cIDBaseObj)];
    char work[UI_MAIN_WORK_NUM][UI_WORK_SIZE];  /* 0x060 */
    char unk918[0x930 - 0x918];
    cIDBaseObj id2;                             /* 0x930 */
    char unk978[0x980 - 0x930 - sizeof(cIDBaseObj)];
    char sub[UI_SUB_WORK_NUM][UI_WORK_SIZE];    /* 0x980 */
} IdUi;                                         /* 0xAF4 */

typedef char IdUi_id2_check[((int)&((IdUi *)0)->id2 == 0x930) ? 1 : -1];

/* Build the 18 custom-ID works of a UI object's main display and the 3 of its sub display, hide the main works, set the sub title message and run the final setup step. */
__attribute__((section(".text.IdUi_initWorks")))
void IdUi_initWorks(IdUi *p)
{
    int i;
    int j;

    cIDBase_initialize(&p->id, UI_IDDATA_KIND, 1);
    cIDBase_restartAnim(&p->id);
    for (i = 0; i < UI_MAIN_WORK_NUM; i++) {
        CustomIDWork_Initialize(p->work[i], cIDBase_getIDWork(&p->id, i));
    }
    SetCustomIDDispOneOrAll_1F29C0(p, 0x12, 0);
    cIDBase_initialize(&p->id2, UI_IDDATA_KIND, 2);
    cIDBase_restartAnim(&p->id2);
    for (j = 0; j < UI_SUB_WORK_NUM; j++) {
        CustomIDWork_Initialize(p->sub[j], cIDBase_getIDWork(&p->id2, j));
    }
    CustomIDWork_SetMessNo(p->sub[UI_SUB_TITLE], UI_TITLE_MESS);
    CustomIDOwner_setPanelState(p, 0);
}
