/* sn-2.95.3-136 matched TU. */

extern int cIDBase_initialize();
extern int cIDBase_getIDWork(void *a, int b);
extern void func_001468B0(void *a);
extern int cSceAtManager_getUnit(int a0, int a1);
extern void func_002C1D68(int a0, int a1, int a2);
extern int cArea_HitCheck_1F83E8(int a0, int a1);

/* sn-2.95.3-136. Loop shape inherited verbatim from the matched
   func_0013C220 in src/cod/001342b8.c (same dead-head class, wave 18 K3). */





__attribute__((section(".text.func_001467E8")))
void func_001467E8(void *a0) {
    int *tbl;
    unsigned short i;
    tbl = (int *)((char *)a0 + 0x90);
    cIDBase_initialize(a0, 1, 0x1D);
    cIDBase_initialize((char *)a0 + 0xA0, 1, 0x1E);
    i = 0;
    do {
        *(int *)((char *)tbl + (i << 2)) = cIDBase_getIDWork(a0, i);
        i = i + 1;
    } while (i < 4);
    *(short *)((char *)a0 + 0x100) = 0;
    func_001468B0(a0);
}

/* SN ProDG ee-gcc 2.95.3. House style inherited from the matched
   src/cod/002c2138.c, which calls all three of these callees. */





__attribute__((section(".text.func_002C2F08")))
int func_002C2F08(int a0, float *a1, int a2) {
    float pos[4];
    int buf[12];
    int u;

    u = cSceAtManager_getUnit(a0, a2);
    pos[0] = a1[0];
    pos[1] = a1[1];
    pos[2] = a1[2];
    pos[3] = 1.0f;
    if (u == 0) return 0;
    func_002C1D68(a0, buf, u);
    return cArea_HitCheck_1F83E8(buf, pos);
}
