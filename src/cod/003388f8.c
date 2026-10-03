/* cygnus-2.96 matched TU. */

extern int D_003E0710;
extern int D_003E0708;
extern char D_004558C8[];
extern void func_003260C8(char *a0);
extern int D_003E3AC8;
extern char D_003E3AD0[];
extern void func_003A52F0(void *dst, int val, int len);
extern int D_003E3FB0;
extern char D_003E3FB8[];
extern int D_003E7FE8;
extern char D_003E7FF0[];

/* Refresh the entry at D_004558C8 unless the mode flag is 1 and the counter is not positive; always return 0. */





__attribute__((section(".text.RefreshEntryIfActive")))
int RefreshEntryIfActive(void) {
    if (D_003E0710 == 1) {
        if (D_003E0708 <= 0) {
            return 0;
        }
    }
    func_003260C8(D_004558C8);
    return 0;
}

/* Reference-count style enter: clear the buffer on the first call, then bump the counter. */




__attribute__((section(".text.ResetBufferOnFirstEnterA")))
void ResetBufferOnFirstEnterA(void) {
    if (D_003E3AC8 == 0) {
        func_003A52F0(D_003E3AD0, 0, 0x480);
    }
    D_003E3AC8 = D_003E3AC8 + 1;
}

/* Reference-count style enter: clear the buffer on the first call, then bump the counter. */




__attribute__((section(".text.ResetBufferOnFirstEnterB")))
void ResetBufferOnFirstEnterB(void) {
    if (D_003E3FB0 == 0) {
        func_003A52F0(D_003E3FB8, 0, 0x4000);
    }
    D_003E3FB0 = D_003E3FB0 + 1;
}

/* Reference-count style enter: clear the buffer on the first call, then bump the counter. */




__attribute__((section(".text.ResetBufferOnFirstEnterC")))
void ResetBufferOnFirstEnterC(void) {
    if (D_003E7FE8 == 0) {
        func_003A52F0(D_003E7FF0, 0, 0xC00);
    }
    D_003E7FE8 = D_003E7FE8 + 1;
}
