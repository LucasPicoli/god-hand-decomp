/* sn-2.95.3-136 matched TU. */

extern int D_00747A84;
extern int cCoreSave_getGameLevel(void *a0);
extern void cCoreSave_setGameLevel(void *a0, int level);

__attribute__((section(".text.cCoreSave_GameLevelUp")))
void cCoreSave_GameLevelUp(void *a0)
{
    int level;
    int *p;

    if (*(int *)a0 == 0) {
        return;
    }
    if ((D_00747A84 & 0x400000) != 0) {
        return;
    }
    level = cCoreSave_getGameLevel(a0);
    switch (level - 1) {
    default:
    case 0:
        cCoreSave_setGameLevel(a0, 2);
        break;
    case 1:
        cCoreSave_setGameLevel(a0, 3);
        break;
    case 2:
        cCoreSave_setGameLevel(a0, 5);
        break;
    case 3:
        cCoreSave_setGameLevel(a0, 5);
        break;
    case 4:
        return;
    }
    p = *(int **)a0;
    *(unsigned char *)((char *)p + 0x1E) = 2;
}
