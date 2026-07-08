/* sn-2.95.3-136 matched TU. */

extern int D_007474A0;
extern int D_00747A2C;
extern int PTR_DAT_003c2f84;
extern int D_005FEA60;
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void ClearSoundSlot_2C4390(int a0);
extern void func_002C14F8(int *a0);
extern void func_002D5358(char *a0);
extern void func_002C4E18(char *a0);

__attribute__((section(".text.cScenario_move")))
void cScenario_move(char *a0)
{
    char *g = (char *)&D_007474A0;

    if (*(unsigned short *)(g + 0x5B0) != 0x20) {
        if (Obj0000_Get_D_00747A94_2DB6B0() != 0) {
            long t = *(unsigned int *)(a0 + 0x48);
            if (((t >> 1) & 1) == 0) {
                if (*(short *)(Obj0000_Get_D_00747A94_2DB6B0() + 0x54A) <= 0) {
                    *(int *)(a0 + 0x48) = *(int *)(a0 + 0x48) | 2;
                    ClearSoundSlot_2C4390(PTR_DAT_003c2f84);
                    *(int *)(g + 0x5E0) = *(int *)(g + 0x5E0) | 0x100000;
                }
            } else {
                if (*(short *)(Obj0000_Get_D_00747A94_2DB6B0() + 0x54A) > 0) {
                    *(int *)(a0 + 0x48) = *(int *)(a0 + 0x48) & -3;
                    *(int *)(g + 0x5E0) = *(int *)(g + 0x5E0) & 0xFFEFFFFF;
                }
            }
        }
    }

    if (*(int *)&D_00747A2C >= 0) {
        char *o = (char *)&D_00747A2C;
        unsigned long w8;
        if ((*(int *)(o + 0x58) & 0x8000000) == 0 &&
            (w8 = *(int *)(o - 0x8), ((w8 >> 3) & 1) == 0) &&
            (*(int *)(o + 0x4C) & 0x10000) == 0 &&
            (*(int *)(o + 0x4) & 1) == 0) {
            char *p = a0 + 0x1C;
            long t2 = *(unsigned int *)(a0 + 0x48);
            if (((t2 >> 1) & 1) == 0) {
                int (*fp)();
                func_002C14F8(&D_005FEA60);
                fp = *(int (**)())(*(int *)(a0 + 0xD4) + 0xC);
                if (fp)
                    (*fp)();
                func_002D5358(p);
                func_002C4E18(a0);
            } else {
                int (*fp)();
                fp = *(int (**)())(*(int *)(a0 + 0xD4) + 0xC);
                if (fp)
                    (*fp)();
                func_002D5358(p);
            }
        }
    }
}
