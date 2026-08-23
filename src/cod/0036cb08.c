/* cygnus-2.96 matched TU. */

extern unsigned char D_003F1EC8[];

typedef struct {
    unsigned char pad0[0x4];
    int count;
    unsigned char ents[1];
} Root3F1EC8;

typedef struct { int f0; unsigned char pad[0x20]; } Ent3F1EC8;

__attribute__((section(".text.func_0036CB08")))
void *func_0036CB08(void) {
    int n = ((Root3F1EC8 *)D_003F1EC8)->count;
    Ent3F1EC8 *p = (Ent3F1EC8 *)((Root3F1EC8 *)D_003F1EC8)->ents;
    int i;
    for (i = 0; i < n; i++) {
        if (*(volatile int *)&p[i].f0 == 0) return &p[i];
    }
    return 0;
}
