/* sn-2.95.3-136 matched TU. */

extern int D_00569B70;
extern unsigned int D_00568240;
extern int Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(void *a0);
extern int cCoreSave_getGameLevel(void *a0);
extern void cCoreSave_setGameLevel(void *a0, int level);

__attribute__((section(".text.func_001FA1A0")))
void func_001FA1A0(void *a0)
{
    int byte;
    int *p;
    long v;
    int level;

    if (*(int *)a0 == 0) {
        return;
    }
    byte = Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(a0);
    if (byte == 2) {
        return;
    }
    p = *(int **)&D_00569B70;
    if ((*(int *)((char *)p + 0x14) & 0x4000000) != 0) {
        v = *(unsigned int *)&D_00568240;
        if (((v >> 1) & 1) == 0) {
            return;
        }
    }
    level = cCoreSave_getGameLevel(a0);
    switch (level - 1) {
    default:
    case 0:
        *(short *)(*(int *)a0 + 0x1C) = 0;
        return;
    case 1:
        cCoreSave_setGameLevel(a0, 1);
        return;
    case 2:
    case 3:
        cCoreSave_setGameLevel(a0, 2);
        return;
    case 4:
        cCoreSave_setGameLevel(a0, 3);
        return;
    }
}
