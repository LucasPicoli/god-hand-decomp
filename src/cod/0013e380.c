/* sn-2.95.3-136 matched TU. */

extern char *D_003BD6E8;
extern void func_00143A90(char *a0);
extern void cIDBase_initialize(void *a0, int a1, int a2);
extern int cIDBase_getIDWork(void *a0, int a1);
extern void func_002B2580(char *self);
extern void func_002B2E80(char *self);
extern int D_00747A34;
extern char D_00754C10[];
extern int D_0044B840;
extern void *EnsureInitThenForward_2A9538_30EE08(int size, int align, void *region);
extern void func_003A52F0(void *dst, int val, int len);
extern void cObjBase(void *a0);
extern int D_00450B98;

/* Slot1 end-of-game stage: on the first call run the end hook, then flag the game as over. */
#define SLOT_STEP(s)     (*(int *)((s) + 0x08))
#define SLOT_END_FLAG(s) (*(unsigned int *)((s) + 0x54))




__attribute__((section(".text.func_001E31B0")))
void func_001E31B0(char *self) {
    switch (SLOT_STEP(self)) {
    case 0:
        func_00143A90(D_003BD6E8 + 0x1AE0);
        SLOT_STEP(self)++;
        /* fallthrough */
    case 1:
        SLOT_END_FLAG(self) |= 1;
        break;
    }
}

/* Set up two id works: initialise the id manager, fetch each work into the table at +0x9C, clear the counter at +0x90. */



__attribute__((section(".text.func_0013E380")))
void func_0013E380(void *a0) {
    int *tbl;
    unsigned short i;
    tbl = (int *)((char *)a0 + 0x9C);
    cIDBase_initialize(a0, 1, 0x1F);
    i = 0;
    do {
        *(int *)((char *)tbl + (i << 2)) = cIDBase_getIDWork(a0, i);
        i = i + 1;
    } while (i < 2);
    *(int *)((char *)a0 + 0x90) = 0;
}

/* PLAY stage of a two-phase scene: start it on phase 0, step it until it ends, then fall back to the next stage. */




__attribute__((section(".text.func_002B2500")))
int func_002B2500(char *self) {
    int ret;
    switch (*(unsigned char *)(self + 0xD)) {
    case 0:
        func_002B2580(self);
        *(unsigned char *)(self + 0xD) = *(unsigned char *)(self + 0xD) + 1;
    case 1:
        if (func_002B2588(self)) {
            func_002B2E80(self);
            ret = 1;
            *(unsigned char *)(self + 0xF) = 0;
            *(unsigned char *)(self + 0xD) = 0;
            *(unsigned char *)(self + 0xE) = 0;
            *(unsigned char *)(self + 0xC) = ret;
            return ret;
        }
        return 0;
    }
}

/* Allocate and zero a 0x4E0-byte object, run the base constructor and set its vtable pointer; 0 if the allocator is locked or full. */







__attribute__((section(".text.func_003139E0")))
void *func_003139E0(void) {
    char *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = EnsureInitThenForward_2A9538_30EE08(0x4E0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x4E0);
    cObjBase(s0);
    *(int **)(s0 + 0x214) = &D_0044B840;
    return s0;
}

/* Allocate and zero a 0x4D0-byte object, run the base constructor and set its vtable pointer; 0 if the allocator is locked or full. */







__attribute__((section(".text.func_00317E80")))
void *func_00317E80(void) {
    char *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = EnsureInitThenForward_2A9538_30EE08(0x4D0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x4D0);
    cObjBase(s0);
    *(int **)(s0 + 0x214) = &D_00450B98;
    return s0;
}
