/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00747BA0[];

typedef struct {
    unsigned char pad0[0x14];
    int key;
    unsigned char pad1[0x98];
} Ent00747BA0;



__attribute__((section(".text.func_00150D78")))
short func_00150D78(void *a0, int id) {
    int n = 0x100;
    int i = 0;
    if (id == 0) return 0;
    for (;;) {
        if (((Ent00747BA0 *)D_00747BA0)[i].key == id) return (short)i;
        i++;
        if (--n == 0) break;
    }
    return -1;
}
