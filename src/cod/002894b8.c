/* sn-2.95.3-136 matched TU. */

#include "godhand/cEma2.h"
#include "godhand/vu0.h"

extern cGameObj *Getplayer(void);
extern void cCollisionSolidManage_SetActive(void *manager, void *obj, int active);
extern char D_00462FC0[];
extern int D_00747A2C;
extern float capVu0MagnitudeSqXZ(cVec *a, cVec *b);

extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);




#define EMA2_COOLDOWN  30.0f            /* hitFlash value that makes the enemy untouchable */

/* The stack record starts at the first local, above ChkLine's 0x30 bytes of
 * outgoing arguments; the vector stores want the stack pointer as their base. */
#define FRAME ((char *)&from - 0x30)

/* Starts the hit cool-down when the player is not in one, the game flag 3 is
 * clear, the player is alive and a line from just above this enemy to just
 * above the player is blocked: sets hitFlash to 30 and switches the enemy's
 * solid collision off. Returns 1 when it started, else 0. */
__attribute__((section(".text.func_002894B8")))
int func_002894B8(cEma2 *self)
{
    cGameObj *player = Getplayer();
    cVec from;
    cVec to;
    cVec *start;
    unsigned long flags;
    unsigned long bit;
    long set;
    int n;

    if (0.0f < player->hitFlash)
        return 0;
    flags = D_00747A2C;
    bit = flags >> 3;
    set = bit & 1;
    if (set != 0)
        return 0;
    if (player->hp <= 0)
        return 0;
    start = &from;
    VU0_SQC2_VF0(FRAME, 0x30);
    VU0_SQC2_VF0(FRAME, 0x40);
    cVec_copy3(start, self->base.pos);
    cVec_copy3(&to, Getplayer()->pos);
    from.y += 0.5f;
    to.y += 0.5f;
    n = 1;
    if (ChkLine(start, &to, 0, 0, 1, 0x18, 0, 0, 0, 0, 0, 0, n) == n)
        return 0;
    self->base.hitFlash = EMA2_COOLDOWN;
    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    return 1;
}

#define EM_NO_TARGET(em)  (*(unsigned char *)((char *)(em) + 0x617))   /* set while the enemy cannot be picked */
#define EM_NEAR_HEIGHT    2.0f      /* height difference that still counts as near */

/* Ranks skip among the listed enemies of actor id 0x200..0x27F that can be
 * picked: counts those that are nearer to the player than skip in the xz
 * plane, and those at equal range whose height is within EM_NEAR_HEIGHT of
 * the player. */
__attribute__((section(".text.func_002917F8")))
int func_002917F8(cEmManage *self, cEmActor *skip)
{
    cEmSlot *slot;
    cGameObj *em;
    int count = 0;
    float refDist;
    float refHeight;
    float dist;
    float height;
    int id;
    int tooHigh;

    refDist = capVu0MagnitudeSqXZ(Getplayer()->pos, ((cGameObj *)skip)->pos);
    refHeight = Getplayer()->pos->y - ((cGameObj *)skip)->pos->y;
    if (refHeight < 0.0f)
        refHeight = -refHeight;
    for (slot = self->list.top; slot != 0; slot = slot->next) {
        em = (cGameObj *)slot->em;
        if (em == 0)
            continue;
        if (em == (cGameObj *)skip)
            continue;
        if ((cGameObj_idInRange(em, 0x200, 0x300) & 0xFF) == 0)
            continue;
        id = em->actorId;
        tooHigh = id >= 0x280;
        if (tooHigh)
            continue;
        if (EM_NO_TARGET(em) != 0)
            continue;
        dist = capVu0MagnitudeSqXZ(Getplayer()->pos, em->pos);
        height = Getplayer()->pos->y - em->pos->y;
        if (height < 0.0f)
            height = -height;
        if (dist < refDist) {
            if (refHeight < EM_NEAR_HEIGHT) {
                if (EM_NEAR_HEIGHT < height)
                    continue;
            }
            count++;
        } else {
            if (!(EM_NEAR_HEIGHT < refHeight))
                continue;
            if (!(height < EM_NEAR_HEIGHT))
                continue;
            count++;
        }
    }
    return count;
}
