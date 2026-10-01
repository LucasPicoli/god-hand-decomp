/* sn-2.95.3-136 matched TU. */

#include "godhand/ColiseumBattle.h"

extern char D_005864F0[];
extern int cEmBase_checkDeadFlag(void *e);
extern ColiseumEmNode *D_005869F0;
extern char D_00747470[];
extern unsigned char D_0074748C;
extern int D_00747A24[];
extern int D_00747A78;
extern char **D_003C2384;
extern void KeyStop(void);
extern void classFADE_kill(void *p);
extern void classFADE_start(void *p, int b, int c, int d, unsigned int e, unsigned int f, int g);
extern void func_001EFD00(ColiseumBattle *self);
extern void ColiseumBattle_StartFade(ColiseumBattle *self, unsigned char mode);
extern void func_001F28C0(void *ui);
extern void func_001F28F0(void *ui);
extern void func_001F2990(void *ui);
extern void func_001F3260(void *ui);
extern void NoOp_1F0490(ColiseumBattle *self);

/* sn-2.95.3-136 */





/* Calls the defeat handler (vtable slot 27) on every regular enemy that is
 * still alive, then clears the arena's fight flag. */

__attribute__((section(".text.ColiseumBattle_DefeatAllEnemies")))
void ColiseumBattle_DefeatAllEnemies(void)
{
    ColiseumEmNode *node;
    ColiseumEm *em;
    ColiseumVtEnt *vt;
    long ok;
    int k;
    int t;
    char *arena = D_005864F0;
    char *arenaEnd;  /* second address pseudo, as retail rebuilds it after the loop */

    node = *(ColiseumEmNode **)(arena + 0x500);
    while (node != 0) {
        em = node->em;
        if (em != 0) {
            k = em->kind;
            ok = 0; if (k >= 0x200) { t = (k < 0x300); ok = t; }
            if (ok & 0xFF) {
                ok = 0; if (k >= 0x2A0) { t = (k < 0x300); ok = t; }
                if (!(ok & 0xFF)) {
                    if (cEmBase_checkDeadFlag(em) != 1) {
                        vt = em->vt;
                        vt[COLISEUM_EM_VSLOT_DEFEAT].pfn((char *)em + vt[COLISEUM_EM_VSLOT_DEFEAT].delta);
                    }
                }
            }
        }
        node = node->next;
    }
    arenaEnd = D_005864F0;
    arenaEnd[0x5B5] = 0;
}

/* sn-2.95.3-136 */





/* Counts the regular enemies (kind 0x200..0x29F) that are still alive. The
 * argument is unused; retail callers pass the battle object. */

__attribute__((section(".text.ColiseumBattle_CountLiveEnemies")))
int ColiseumBattle_CountLiveEnemies(ColiseumBattle *self)
{
    ColiseumEmNode *node;
    ColiseumEm *em;
    int alive;
    long ok;
    int k;
    int t;

    alive = 0;
    node = D_005869F0;
    while (node != 0) {
        em = node->em;
        if (em != 0) {
            k = em->kind;
            ok = 0; if (k >= 0x200) { t = (k < 0x300); ok = t; }
            if (ok & 0xFF) {
                ok = 0; if (k >= 0x2A0) { t = (k < 0x300); ok = t; }
                if (!(ok & 0xFF)) {
                    if (cEmBase_checkDeadFlag(em) != 1) {
                        /* the read through a pointer gives retail's addu operand order (found by the permuter) */
                        {
                            int *count = &alive;

                            alive = (t = em->hp > 0) + *count;
                        }
                    }
                }
            }
        }
        node = node->next;
    }
    return alive;
}

/* sn-2.95.3-136 */


















__attribute__((section(".text.ColiseumBattle_PlCtrlOff")))
void ColiseumBattle_PlCtrlOff(ColiseumBattle *self, int off)
{
    unsigned int flags;

    if (off) {
        KeyStop();
        flags = self->flags | COLISEUM_FLAG_CTRL_OFF;
    } else {
        D_00747A78 = D_00747A78 & 0xFDFFFFFF;
        flags = *(int *)&self->flags & ~COLISEUM_FLAG_CTRL_OFF; /* int pointee keeps this load after the D_00747A78 store */
    }
    self->flags = flags;
}

/* sn-2.95.3-136 */


















__attribute__((section(".text.ColiseumBattle_StartFade")))
void ColiseumBattle_StartFade(ColiseumBattle *self, unsigned char mode)
{
    long t = self->flags;
    unsigned int f;

    if (((t >> 1) % 2L) != 0L) {
        classFADE_kill(D_00747470);
        self->flags = (int)self->flags & ~COLISEUM_FLAG_FADE;
    }
    switch (mode) {
    case 0:
    default:
        classFADE_start(D_00747470, 0, 0xA, 0, 0xFF000000u, 0, 0xF);
        break;
    case 1:
        classFADE_start(D_00747470, 0, 0xA, 0, 0, 0xFF000000u, 0xF);
        /* net no-op; its flag stores make jump2 share the two call tails, as retail does */
        self->flags++;
        self->flags--;
        break;
    }
    f = self->flags;
    do { } while (0);   /* keeps the epilogue restores behind the flag store */
    self->flags = f | COLISEUM_FLAG_FADE;
}
