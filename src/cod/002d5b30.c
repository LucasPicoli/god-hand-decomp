/* sn-2.95.3-136 matched TU. */

extern int D_003F5520[];
extern int D_0040A420;
extern char *D_003F852C;
extern char *D_00754C38;
extern char D_0061B7C0[];
extern char D_0071B7C0[];
extern char D_0071B840[];
extern char D_0071B8C0[];

/* compiler: sn-2.95.3-136 ; extra keys: none */




__attribute__((section(".text.func_00394D58")))
int func_00394D58(int *a0) {
    char *p;
    int n;
    D_003F5520[1] = 0x31415926;
    D_003F5520[0] = 0;
    if (a0 != 0) {
        *a0 = D_0040A420;
    }
    n = *(int *)(D_003F852C + 0x10);
    p = *(char **)(D_003F852C + 0xC);
    if (n != 0) {
        do {
            switch (*(unsigned char *)(p + 0xA)) {
            default:
                return 7;
            case 0:
            case 1:
                *(char *)(p + 0xB) = 0;
                break;
            case 2:
            case 3:
            case 4:
                *(char *)(p + 0xB) = 1;
                break;
            }
            p += 0xC;
        } while (--n != 0);
    }
    return 0;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.SetViewScrollIdAll")))
void SetViewScrollIdAll(unsigned int *a0) {
    char **a2;
    char *obj;
    unsigned int id;
    a2 = *(char ***)((char *)D_00754C38 + 4);
    if (a2 != *(char ***)((char *)D_00754C38 + 8)) {
        do {
            obj = *a2;
            id = *(unsigned char *)(obj + 0x2FD);
            if (id < 0x100) {
                if (a0[id >> 5] & (0x80000000 >> (id & 0x1F))) {
                    *(int *)(obj + 0x250) |= 2;
                } else {
                    *(int *)(obj + 0x250) &= 0xFFFFFFFD;
                }
            }
            a2++;
        } while (a2 != *(char ***)((char *)D_00754C38 + 8));
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.SetSuspendScrollLayerAll")))
void SetSuspendScrollLayerAll(unsigned int *a0) {
    char **a2;
    char *obj;
    unsigned int id;
    a2 = *(char ***)((char *)D_00754C38 + 4);
    if (a2 != *(char ***)((char *)D_00754C38 + 8)) {
        do {
            obj = *a2;
            id = *(unsigned char *)(obj + 0x2FD);
            if (a0[id >> 5] & (0x80000000 >> (id & 0x1F))) {
                *(int *)(obj + 0x250) |= 0x8000;
            } else {
                *(int *)(obj + 0x250) &= 0xFFFF7FFF;
            }
            a2++;
        } while (a2 != *(char ***)((char *)D_00754C38 + 8));
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */





__attribute__((section(".text.func_002FB060")))
int func_002FB060(char *a0) {
    unsigned int d;
    unsigned int slot;
    unsigned int w;
    unsigned int bit;
    d = (unsigned int)(a0 - D_0061B7C0);
    slot = d >> 10;
    if (slot >= 0x400) {
        return 0;
    }
    w = (d >> 15) * 4;
    bit = 0x80000000 >> (slot & 0x1F);
    if ((*(unsigned int *)(w + (int)D_0071B7C0) & bit) == 0) {
        return 0;
    }
    if ((*(unsigned int *)(w + (int)D_0071B840) & bit) != 0) {
        return 0;
    }
    return (*(unsigned int *)(w + (int)D_0071B8C0) & bit) == 0;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_002D5B30")))
int func_002D5B30(char **a0, int a1) {
    int cnt;
    char *p;
    if (a1 < 0) {
        cnt = *(unsigned short *)((char *)a0 + 0xC);
        a1 = 2;
        if (a1 < cnt) {
            p = *a0 + 0xBC;
            do {
                if (*(unsigned short *)p == 0) {
                    return a1;
                }
                a1++;
                p += 0x58;
            } while (a1 < cnt);
        }
        return -1;
    }
    if (a1 < *(unsigned short *)((char *)a0 + 0xC)) {
        return *(unsigned short *)(a1 * 0x58 + (int)*a0 + 0xC) == 0 ? a1 : -1;
    }
    return -1;
}
