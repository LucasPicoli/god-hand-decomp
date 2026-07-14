/* sn-2.95.3-136 matched TU. */

extern void func_003A52F0(void *dst, int c, int n);
extern char D_0076E510[];
extern char D_0076E590[];
extern char D_0076E910[];

typedef struct E1 {
    unsigned char pad0[2];
    short id;
    unsigned char pad1[0x6C];
} E1;

typedef struct E2 {
    unsigned char pad0[2];
    short id;
    unsigned char pad1[0x9C];
} E2;

__attribute__((section(".text.func_00377D80")))
void func_00377D80(void) {
    int i;

    func_003A52F0(D_0076E510, 0, 0x80);
    func_003A52F0(D_0076E590, 0, 0x380);
    func_003A52F0(D_0076E910, 0, 0x140);

    for (i = 7; i >= 0; i--) {
        ((E1 *)D_0076E590)[i].id = i;
    }
    for (i = 1; i >= 0; i--) {
        ((E2 *)D_0076E910)[i].id = i;
    }
}
