/* sn-2.95.3-136 matched TU. */

#include "godhand/ptrVec.h"
#include "godhand/cScenario.h"
#include "godhand/cVec.h"

extern void func_0031B410(void *ctx, void *out);
extern void *_MemoryAlloc(int size, int align, int heap);
extern void cHeap_free(int heap, void *p);
extern void *Getplayer(void);
extern int cEmBase_checkDeadFlag(void *em);
extern float capVu0LengthSq(void *v);
extern int Dest_ck(void *from, void *to, float heading, float angle);
extern void cActionButton_set(void *a0, int a1, int a2, int a3, int t0, int t1, int t2);
extern void cScenario_startSoftTask(void *self);

/* libgcc2 runtime: the default terminate handler. */
extern void func_003A7B48(void) __attribute__((noreturn)); /* abort */

/* __default_terminate: called when an exception has no handler; aborts. */
__attribute__((section(".text.Forward3A7B48_320270")))
void Forward3A7B48_320270(void)
{
    func_003A7B48();
}

/* Pad input: stop key handling. */
#define KEY_F_STOP  0x2000000      /* key input stopped */
#define KEY_WORK_FLAGS_OFFSET 0x460 /* D_00747A78 is the flags word at +0x460 of the key work */

extern int D_00747A78;             /* key work flags */
extern int D_005E8140;             /* classPAD_WORK */


/* KeyStop: sets the stop bit in the key work flags and clears the pad state through func_0031B410. */
__attribute__((section(".text.KeyStop")))
void KeyStop(void)
{
    D_00747A78 |= KEY_F_STOP;
    func_0031B410(&D_005E8140, (char *)&D_00747A78 - KEY_WORK_FLAGS_OFFSET);
}

/* sn-2.95.3-136: the object pointer lists (ptrVec.h): create a list's vector. */


#define PTRVEC_ALIGN 0x10
#define HEAP_BLOCK_OWNER_OFFSET 0x20 /* each heap block keeps its heap pointer 0x20 B before the data */
#define PTRVEC_ALLOC(v) (*(unsigned char *)&(v)->unk00) /* the g++ empty allocator object */

extern int D_003C3CF0;  /* default heap */

extern void *func_003A51F4(void *dst, const void *src, unsigned int n); /* memmove */


/* Allocates an empty vector for list and reserves room for count pointers.
 * The allocator byte is rebuilt from an uninitialised temporary, as the
 * inlined g++ allocator copy does in retail. */
__attribute__((section(".text.PtrVec_create")))
void PtrVec_create(PtrVecRef *list, unsigned int count)
{
    PtrVec *v;
    void **old;
    void **buf;
    unsigned char hold[16];
    unsigned char junk;
    int used;

    v = _MemoryAlloc(sizeof(PtrVec), PTRVEC_ALIGN, D_003C3CF0);
    if (v != 0) {
        hold[0] = PTRVEC_ALLOC(v);
        PTRVEC_ALLOC(v) = junk;
        PTRVEC_ALLOC(v) = hold[0];
        v->begin = 0;
        v->end = 0;
        v->cap = 0;
    }
    list->v = v;
    old = v->begin;
    if ((unsigned int)(v->cap - old) < count) {
        used = v->end - old;
        buf = _MemoryAlloc(count * sizeof(void *), PTRVEC_ALIGN, D_003C3CF0);
        func_003A51F4(buf, old, used * sizeof(void *));
        if (v->begin != 0)
            cHeap_free(*(int *)((char *)v->begin - HEAP_BLOCK_OWNER_OFFSET), v->begin);
        v->end = buf + used;
        v->begin = buf;
        v->cap = buf + count;
    }
}

/* Enemy: offer the talk/action button when the player stands close in front of it. */



#define SCENARIO_BUSY(s)   (((unsigned char *)(s))[0x14])  /* 1 while a scenario step owns the input */
#define TALK_HEIGHT_MAX    2.0f
#define TALK_RANGE_SQ      9.0f                            /* 3 m */
#define TALK_VIEW_ANGLE    1.9198622f                      /* 110 degrees */
#define ACTBTN_TALK        4
#define ACTBTN_TALK_ICON   0xE
#define CHKLINE_MASK       7

/* g++ 2.x method table entries (delta, function) of cGameObj at 0x214. */
#define VT_LOCKON_POS 0x80   /* the point the camera locks onto */
#define VT_ROT        0x88   /* the object's rotation */
typedef cVec *(*vfn)(void *);
#define VCALL(o, slot) ((*(vfn *)(*(char **)((char *)(o) + 0x214) + (slot) + 4)) \
                        ((char *)(o) + *(short *)(*(char **)((char *)(o) + 0x214) + (slot))))





extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);


extern char D_00568288;   /* the action button */

/* Sets the talk button (which starts this enemy's soft task) when no scenario
 * step is running, the enemy is alive, the player is within 3 m and 2 m of
 * height, faces it within 110 degrees, and nothing blocks the line. */
__attribute__((section(".text.cEmBase_setTalkButton")))
void cEmBase_setTalkButton(void *self)
{
    CVEC_TEMPS;
    int one = 1;

    if (SCENARIO_BUSY(D_003C2F84) == one)
        return;
    if (cEmBase_checkDeadFlag(self) == one)
        return;
    {
        void *pl = Getplayer();
        cVec *a_ = VCALL(pl, VT_LOCKON_POS);
        cVec *b_ = VCALL(self, VT_LOCKON_POS);

        VU0_ZERO_VSUB_XYZ_MEM(&tmp_, 0, a_, b_);
        VU0_LQC2(4, &tmp_, 0);
        VU0_SQC2_MEM(4, &ret_, 0);
    }
    {
        void *pl = Getplayer();
        cVec *a = VCALL(pl, VT_LOCKON_POS);
        cVec *b = VCALL(self, VT_LOCKON_POS);

        float dy = __builtin_fabsf(a->y - b->y);

        do { } while (0); /* keeps the 2.0 constant below the abs.s, as retail */
        if (!(dy < TALK_HEIGHT_MAX))
            return;
    }
    if (!(capVu0LengthSq(&ret_) < TALK_RANGE_SQ))
        return;
    {
        void *pl = Getplayer();
        cVec *from = VCALL(pl, VT_LOCKON_POS);
        void *pl2 = Getplayer();
        cVec *rot = VCALL(pl2, VT_ROT);
        cVec *to = VCALL(self, VT_LOCKON_POS);

        if (Dest_ck(from, to, rot->y, TALK_VIEW_ANGLE) == 0)
            return;
    }
    {
        void *pl = Getplayer();
        cVec *a = VCALL(pl, VT_LOCKON_POS);
        cVec *b = VCALL(self, VT_LOCKON_POS);

        if (ChkLine(a, b, 0, 0, CHKLINE_MASK, 0, 0, 0, 0, 0, 0, 0, one) != 0)
            return;
    }
    cActionButton_set(&D_00568288, ACTBTN_TALK, ACTBTN_TALK_ICON, 0,
                      (int)cScenario_startSoftTask, (int)self, 0);
}
