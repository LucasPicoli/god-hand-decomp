/* cygnus-2.96 matched TU. */

extern unsigned char D_003EE800[];

typedef struct {
    unsigned char pad0[0x8];
    int count;
    unsigned char ents[1];
} Root3EE800;

typedef struct { int f0; unsigned char pad[0x48]; } Ent3EE800;

__attribute__((section(".text.func_0035FF48")))
void *func_0035FF48(void) {
    int n = ((Root3EE800 *)D_003EE800)->count;
    Ent3EE800 *p = (Ent3EE800 *)((Root3EE800 *)D_003EE800)->ents;
    int i;
    for (i = 0; i < n; i++) {
        if (*(volatile int *)&p[i].f0 == 0) return &p[i];
    }
    return 0;
}
