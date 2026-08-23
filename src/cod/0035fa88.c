/* cygnus-2.96 matched TU. */

extern unsigned char D_003EE338[];

typedef struct {
    unsigned char pad0[0x4];
    int count;
    unsigned char pad1[0x10];
    unsigned char ents[1];
} Root3EE338;


typedef struct { int f0; unsigned char pad[0x90]; } Ent3EE338;
__attribute__((section(".text.func_0035FA88")))
void *func_0035FA88(void) {
    int n = ((Root3EE338 *)D_003EE338)->count;
    Ent3EE338 *p = (Ent3EE338 *)((Root3EE338 *)D_003EE338)->ents;
    int i;
    for (i = 0; i < n; i++) {
        if (*(volatile int *)&p[i].f0 == 0) return &p[i];
    }
    return 0;
}
