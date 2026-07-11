/* sn-2.95.3-136 matched TU. */

extern char *D_00754C38;
extern void func_003A52F0(void *a0, int a1, int a2);
extern char D_0061B7C0[];
extern char D_0071B7C0[];
extern char D_0071B840[];
extern char D_0071B8C0[];
extern void func_00307060(char *a0);

__attribute__((section(".text.setAlphaScrollLayer")))
void setAlphaScrollLayer(int a0, float f12) {
    char **a1;
    char *obj;
    a1 = *(char ***)((char *)D_00754C38 + 4);
    if (a1 != *(char ***)((char *)D_00754C38 + 8)) {
        do {
            obj = *a1;
            if (a0 == *(unsigned char *)(obj + 0x2FD)) {
                *(float *)(obj + 0x24C) = f12;
                *(float *)(*a1 + 0x31C) = f12;
            }
            a1++;
        } while (a1 != *(char ***)((char *)D_00754C38 + 8));
    }
}

__attribute__((section(".text.func_001B7E50")))
void func_001B7E50(char *a0, char *a1) {
    char *v1;
    char *v0;
    v1 = a0 + 0x490;
    if (v1 != a1) {
        *(float *)(a0 + 0x490) = *(float *)(a1 + 0x0);
        *(float *)(v1 + 0x4) = *(float *)(a1 + 0x4);
        *(float *)(v1 + 0x8) = *(float *)(a1 + 0x8);
    }
    v0 = *(char **)(a0 + 0xF0);
    if (v0 != v1) {
        *(float *)(v0 + 0x0) = *(float *)(a0 + 0x490);
        *(float *)(v0 + 0x4) = *(float *)(v1 + 0x4);
        *(float *)(v0 + 0x8) = *(float *)(v1 + 0x8);
    }
    v0 = *(char **)(a0 + 0x5B8);
    *(int *)(a0 + 0x5B8) = (int)v0 | 0x10;
}

__attribute__((section(".text.func_001FFF30")))
int func_001FFF30(void *a0, short a1, float *a2, unsigned char a3, float f, int t0, unsigned char t1) {
    *(short*)((char*)a0 + 0x14) = a1;
    *(float*)((char*)a0 + 0x4) = a2[0];
    *(float*)((char*)a0 + 0x8) = a2[1];
    *(float*)((char*)a0 + 0xC) = a2[2];
    *(float*)((char*)a0 + 0x10) = f;
    *(unsigned char*)((char*)a0 + 0x16) = (unsigned char)0xFF;
    *(unsigned char*)((char*)a0 + 0x17) = a3;
    *(int*)((char*)a0 + 0x18) = t0;
    *(unsigned char*)((char*)a0 + 0x3A) = t1;
    return cDoor_setDoorJump(a0);
}

__attribute__((section(".text.cGameObj_setPos")))
void cGameObj_setPos(void *a0, float *a1) {
    float *d = (float*)((char*)a0 + 0x490);
    float *p;
    if (d != a1) {
        d[0] = a1[0];
        d[1] = a1[1];
        d[2] = a1[2];
    }
    p = *(float**)((char*)a0 + 0xF0);
    if (p != d) {
        p[0] = d[0];
        p[1] = d[1];
        p[2] = d[2];
    }
}

__attribute__((section(".text.cOm59_setParent")))
void cOm59_setParent(void *a0, int a1, int a2, float *a3, float *t0) {
    float *d1 = (float*)((char*)a0 + 0x9B0);
    float *d2;
    *(int*)((char*)a0 + 0x9A0) = a1;
    *(int*)((char*)a0 + 0x9A4) = a2;
    if (d1 != a3) {
        d1[0] = a3[0];
        d1[1] = a3[1];
        d1[2] = a3[2];
    }
    d2 = (float*)((char*)a0 + 0x9C0);
    if (d2 != t0) {
        d2[0] = t0[0];
        d2[1] = t0[1];
        d2[2] = t0[2];
    }
}

__attribute__((section(".text.func_001B15C8")))
void func_001B15C8(void *a0, int a1, int a2, float *a3, float *t0) {
    float *d1 = (float*)((char*)a0 + 0x610);
    float *d2;
    *(int*)((char*)a0 + 0x600) = a1;
    *(int*)((char*)a0 + 0x604) = a2;
    if (d1 != a3) {
        d1[0] = a3[0];
        d1[1] = a3[1];
        d1[2] = a3[2];
    }
    d2 = (float*)((char*)a0 + 0x620);
    if (d2 != t0) {
        d2[0] = t0[0];
        d2[1] = t0[1];
        d2[2] = t0[2];
    }
}

__attribute__((section(".text.func_002CD890")))
void func_002CD890(void *a0, int a1) {
    int *p;
    int *a2;
    if (a1 == 0) return;
    if (*(int*)((char*)a0 + 0x380) == 0) return;
    p = func_002CD8F8();
    a2 = (int*)p[1];
    a2[2] = p[2];
    a2[3] = a2[3] + (p[6] + p[3]);
    if (p[2] != 0) {
        *(int*)(p[2] + 4) = (int)a2;
    }
    p[5] = 0;
}

__attribute__((section(".text.InitEspWork")))
void InitEspWork(void) {
    func_003A52F0(D_0061B7C0, 0, 0x100000);
    func_003A52F0(D_0071B7C0, 0, 0x80);
    func_003A52F0(D_0071B840, 0, 0x80);
    func_003A52F0(D_0071B8C0, 0, 0x80);
}

struct Node_001aad88 {
    struct Node_001aad88 *prev;
    struct Node_001aad88 *next;
    int pad;
    int key;
};

__attribute__((section(".text.func_00306FF8")))
void func_00306FF8(char *a0, struct Node_001aad88 *a1) {
    struct Node_001aad88 *a2 = (struct Node_001aad88 *)(a0 + 0x4200);
    if (a2 != 0) {
        do {
            if ((unsigned int)a1->key < (unsigned int)a2->key) {
                struct Node_001aad88 *p = a2->prev;
                a1->next = a2;
                a1->prev = p;
                p->next = a1;
                a2->prev = a1;
                goto done;
            }
            if (a2->next == 0) {
                a2->next = a1;
                a1->prev = a2;
                a1->next = 0;
                goto done;
            }
            a2 = a2->next;
        } while (1);
    }
done:
    func_00307060(a0);
}
