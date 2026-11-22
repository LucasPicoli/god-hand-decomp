/* cygnus-2.96 matched TU. */

extern void (*D_003D8404)(int);
extern int D_003D8408;
extern int D_003E0710;
extern int D_003E0708;

__attribute__((section(".text.func_003302B0")))
void func_003302B0(void) {
    if (D_003D8404 != 0) {
        D_003D8404(D_003D8408);
    }
}

__attribute__((section(".text.PS2RNA_SetPlaySw")))
void PS2RNA_SetPlaySw(void *a0, int a1) {
    if (D_003E0710 != 1) {
        *(char*)((char*)a0 + 0x50) = a1;
        return;
    }
    if (D_003E0708 > 0) {
        *(char*)((char*)a0 + 0x50) = a1;
    }
}

__attribute__((section(".text.PS2RNA_SetDiscardSw")))
void PS2RNA_SetDiscardSw(void *a0, int a1) {
    if (D_003E0710 != 1) {
        *(char*)((char*)a0 + 0x5B) = a1;
        return;
    }
    if (D_003E0708 > 0) {
        *(char*)((char*)a0 + 0x5B) = a1;
    }
}

__attribute__((section(".text.PS2RNA_SetNumChan")))
void PS2RNA_SetNumChan(void *a0, int a1) {
    if (D_003E0710 != 1) {
        *(char*)((char*)a0 + 0x52) = a1;
        return;
    }
    if (D_003E0708 > 0) {
        *(char*)((char*)a0 + 0x52) = a1;
    }
}

__attribute__((section(".text.PS2RNA_SetOutBalance")))
void PS2RNA_SetOutBalance(void *a0, int a1) {
    if (D_003E0710 != 1) {
        *(int*)((char*)a0 + 0x5C) = a1;
        return;
    }
    if (D_003E0708 > 0) {
        *(int*)((char*)a0 + 0x5C) = a1;
    }
}

__attribute__((section(".text.memcpy2")))
void memcpy2(short *a0, unsigned short *a1, int a2) {
    unsigned short v;
    if (a2 <= 0) return;
    do {
        v = *a1;
        a1++;
        a2--;
        *a0 = v;
        a0++;
    } while (a2 > 0);
}
