/* sn-2.95.3-136: func_00378B58, toggles the actor's facing pair (5/7) and keeps it only if the new motion starts. */
typedef struct {
    char pad0[5];
    signed char dir;     /* 0x05 */
    char pad6;
    signed char side;    /* 0x07 */
    char pad8[0x16 - 8];
    short motion[15];    /* 0x16 */
    int flags;           /* 0x34 */
} SeqActor;

extern int SdeTblTestBlkNoCheck(SeqActor *a, int motion, int mode);

__attribute__((section(".text.func_00378B58")))
int func_00378B58(SeqActor *a)
{
    signed char dir;
    signed char side;

    if ((a->flags & 0x0F000000) == 0)
        return 0;
    dir = a->dir;
    side = a->side;
    if (dir == 0) {
        a->side = a->dir = 2;
    } else {
        a->dir = 0;
        a->side = 0;
    }
    if (SdeTblTestBlkNoCheck(a, a->motion[a->side], 1) < 0) {
        a->dir = dir;
        a->side = side;
        return 0;
    }
    return 1;
}
