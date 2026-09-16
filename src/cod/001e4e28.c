/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern void func_001E7848(char *a0, int a1);
extern void func_001E7868(char *a0, int a1);
extern void func_001E7888(char *a0, int a1);
extern void func_001E78A8(char *a0, int a1);
extern void func_001E78C8(char *a0, int a1);
extern void func_001E78E8(char *a0, int a1);
extern void func_001E6ED8(char *a0, int a1, int a2);
extern void func_001E6A48(char *a0);
extern void func_001E6B70(char *a0, int a1, int a2);
extern void func_001E6C80(char *a0, int a1, int a2);
extern void func_001E6D48(char *a0, int a1, int a2);
extern void func_001E6E10(char *a0, int a1, int a2);
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

__attribute__((section(".text.func_001E4E28")))
void func_001E4E28(void *a0)
{
    char *s1 = (char *)a0;
    long v;
    int done;

    switch (*(int *)(s1 + 0x8)) {
    case 0: {
        char *s0 = s1 + 0x400;
        char *p0;
        char *p1;
        char *p2;

        func_001E7848(s0, *(int *)(s1 + 0x36C));
        func_001E7868(s0, *(int *)(s1 + 0x370));
        func_001E7888(s0, *(int *)(s1 + 0x374));
        func_001E78A8(s0, *(int *)(s1 + 0x378));
        func_001E78C8(s0, *(int *)(s1 + 0x37C));
        func_001E78E8(s0, *(int *)(s1 + 0x380));
        *(unsigned short *)(s1 + 0x3D2) = 0;
        func_001E6ED8(s1, 0, 0);
        func_001E6A48(s1);
        func_001E6B70(s1, 0, 0);
        func_001E6C80(s1, 0, 0);
        func_001E6D48(s1, 0, 0);
        func_001E6E10(s1, 0, 0);
        p0 = s1 + 0x58;
        p1 = s1 + 0x140;
        p2 = s1 + 0x228;
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
        v = *(unsigned int *)(s1 + 0x200);
        if ((v & 1) == 0) {
            return;
        }
        v = *(unsigned int *)(s1 + 0x2E8);
        if ((v & 1) == 0) {
            return;
        }
        if (*(unsigned short *)(s1 + 0x3D2) == 0) {
            char *g = (char *)&D_007474A0;
            if (*(long *)(g + 0x1A0) & 0x20000000L) {
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
                if (*(unsigned short *)(s1 + 0x3D2) >= 3) {
                    return;
                }
                if (GetTimerValue_1FA710(D_00569B70) < *(int *)(s1 + 0x368)) {
                    return;
                }
                *(unsigned short *)(s1 + 0x3D2) += 1;
                cCoreSave_subGold(D_00569B70, *(int *)(s1 + 0x368));
                func_001E6A48(s1);
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
                return;
            }
            if (f & 0x20000000L) {
                if (*(unsigned short *)(s1 + 0x3D2) == 0) {
                    return;
                }
                *(unsigned short *)(s1 + 0x3D2) -= 1;
                cCoreSave_addGold(D_00569B70, *(int *)(s1 + 0x368), 0);
                func_001E6A48(s1);
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x161, -1, -1, 0, 0);
                return;
            }
            if (*(unsigned short *)(s1 + 0x3D2) != 0 && (f & 0x2200012000000L)) {
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
        func_001E7660(s1 + 0x400, 1);
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
            func_001E77B0(s1 + 0x400, 1);
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
                char *s0 = s1 + 0x400;
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
