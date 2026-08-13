/* sn-2.95.3-136 matched TU. */

extern void func_001E7848(char *a0, int a1);
extern void func_001E7868(char *a0, int a1);
extern void func_001E7888(char *a0, int a1);
extern void func_001E78A8(char *a0, int a1);
extern void func_001E78C8(char *a0, int a1);
extern void func_001E78E8(char *a0, int a1);
extern void func_001E3758(char *a0, int a1, int a2, int a3);
extern void func_001E4200(char *a0, int a1, int a2, int a3);
extern void func_001E3630(char *a0);
extern void func_001E3D78(char *a0, int a1, int a2);
extern void func_001E3E40(char *a0, int a1, int a2, int a3);
extern void func_001E4438(char *a0, int a1, int a2);
extern void func_001E7660(char *a0, int a1);
extern void func_001E77B0(char *a0, int a1);
extern int GetTimerValue_1FA710(char *a0);
extern void cCoreSave_addGold(char *a0, int a1, int a2);
extern void cCoreSave_subGold(char *a0, int a1);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, short a2, short a3, short a4, int a5, int a6);
extern char D_00569B70[];
extern char D_005FEE00[];
extern int D_007474A0;
extern int D_00747A2C;
extern long D_00747640;

/* sn-2.95.3-136 matched TU. */

























__attribute__((section(".text.func_001E0310")))
void func_001E0310(void *a0)
{
    char *s1 = (char *)a0;
    long v;
    int done;

    switch (*(int *)(s1 + 0x8)) {
    case 0: {
        char *s0 = s1 + 0x4D0;
        char *p0;
        char *p1;
        char *p2;

        func_001E7848(s0, *(int *)(s1 + 0x3CC));
        func_001E7868(s0, *(int *)(s1 + 0x3D0));
        func_001E7888(s0, *(int *)(s1 + 0x3D4));
        func_001E78A8(s0, *(int *)(s1 + 0x3D8));
        func_001E78C8(s0, *(int *)(s1 + 0x3DC));
        func_001E78E8(s0, *(int *)(s1 + 0x3E0));
        *(unsigned short *)(s1 + 0x48E) = 0;
        func_001E3758(s1, 0, 0, 0);
        func_001E3758(s1, 1, 0, 0);
        func_001E3758(s1, 2, 0, 0);
        func_001E4200(s1, 0, 0, 0);
        func_001E4200(s1, 1, 0, 0);
        func_001E4200(s1, 2, 0, 0);
        func_001E4200(s1, 3, 0, 0);
        func_001E4200(s1, 4, 0, 0);
        func_001E3630(s1);
        func_001E3D78(s1, 0, 0);
        func_001E3E40(s1, 0, 0, 0);
        func_001E3E40(s1, 1, 0, 0);
        func_001E3E40(s1, 2, 0, 0);
        func_001E3E40(s1, 3, 0, 0);
        func_001E3E40(s1, 4, 0, 0);
        func_001E4438(s1, 0, 0);
        func_001E4438(s1, 1, 0);
        p0 = s1 + 0x58;
        p1 = s1 + 0x160;
        p2 = s1 + 0x268;
        *(int *)(p0 + 0x4) = 0;
        *(int *)(p0 + 0x8) = 0;
        *(int *)(p0 + 0xC) = 0;
        *(int *)(p1 + 0x4) = 0;
        *(int *)(p1 + 0x8) = 0;
        *(int *)(p1 + 0xC) = 0;
        *(int *)(p2 + 0x4) = 0;
        *(int *)(p2 + 0x8) = 0;
        *(int *)(p2 + 0xC) = 0;
        *(int *)(s1 + 0x8) = *(int *)(s1 + 0x8) + 1;
    }
    /* fallthrough */
    case 1:
        if (D_00747A2C & 0x200) {
            char *o = (char *)&D_00747A2C;
            if (*(long *)(o - 0x3DC) & 0x33000000000L) {
                cCoreSave_addGold(D_00569B70, 0x3E8, 0);
            }
        }
        v = *(unsigned int *)(s1 + 0x118);
        if ((v & 1) == 0) {
            return;
        }
        v = *(unsigned int *)(s1 + 0x220);
        if ((v & 1) == 0) {
            return;
        }
        v = *(unsigned int *)(s1 + 0x328);
        if ((v & 1) == 0) {
            return;
        }
        if (*(unsigned short *)(s1 + 0x48E) == 0) {
            char *g = (char *)&D_007474A0;
            if (*(long *)(g + 0x1A0) & 0x200000000L) {
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x161, -1, -1, 0, 0);
                *(int *)(s1 + 0x4) = 4;
                *(int *)(s1 + 0x8) = 0;
                *(int *)(s1 + 0xC) = 0;
                return;
            }
        }
        {
            char *g = (char *)&D_007474A0;
            long f = *(long *)(g + 0x1A0);

            if (f & 0x400000000L) {
                if (*(unsigned short *)(s1 + 0x48E) >= 3) {
                    return;
                }
                if (GetTimerValue_1FA710(D_00569B70) < *(int *)(s1 + 0x3C8)) {
                    return;
                }
                *(unsigned short *)(s1 + 0x48E) += 1;
                cCoreSave_subGold(D_00569B70, *(int *)(s1 + 0x3C8));
                func_001E3630(s1);
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
                return;
            }
            if (f & 0x200000000L) {
                if (*(unsigned short *)(s1 + 0x48E) == 0) {
                    return;
                }
                *(unsigned short *)(s1 + 0x48E) -= 1;
                cCoreSave_addGold(D_00569B70, *(int *)(s1 + 0x3C8), 0);
                func_001E3630(s1);
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x161, -1, -1, 0, 0);
                return;
            }
            if (*(unsigned short *)(s1 + 0x48E) != 0 && (f & 0x2200802000000L)) {
                *(int *)(s1 + 0x4) = 1;
                *(int *)(s1 + 0x8) = 0;
                *(int *)(s1 + 0xC) = 0;
                return;
            }
        }
        {
            char *g = (char *)&D_007474A0;
            if ((*(long *)(g + 0x1A0) & 0x10000000000L) == 0) {
                return;
            }
        }
        func_001E7660(s1 + 0x4D0, 1);
        *(int *)(s1 + 0x10) = 0xF;
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
        *(int *)(s1 + 0x8) = *(int *)(s1 + 0x8) + 1;
        break;
    case 2:
        if (*(int *)(s1 + 0x10) != 0) {
            *(int *)(s1 + 0x10) -= 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            func_001E77B0(s1 + 0x4D0, 1);
            *(int *)(s1 + 0x10) = 0xA;
            *(int *)(s1 + 0x8) = *(int *)(s1 + 0x8) + 1;
        }
        break;
    case 3:
        if (*(int *)(s1 + 0x10) != 0) {
            *(int *)(s1 + 0x10) -= 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            if (D_00747640 & 0x33F00000000L) {
                char *s0 = s1 + 0x4D0;
                func_001E77B0(s0, 0);
                func_001E7660(s0, 2);
                *(int *)(s1 + 0x10) = 0xA;
                *(int *)(s1 + 0x8) = *(int *)(s1 + 0x8) + 1;
            }
        }
        break;
    case 4:
        if (*(int *)(s1 + 0x10) != 0) {
            *(int *)(s1 + 0x10) -= 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            *(int *)(s1 + 0x8) = 1;
        }
        break;
    }
}
