/* sn-2.95.3-136 matched TU. */

extern void func_003A52F0(void *dst, int val, int len);
extern char D_0076EA50[];
extern char D_0076F050[];
extern char D_00770850[];

typedef struct StructB {
    short unk0;
    short id;
    char pad[0x3C];
} StructB;

typedef struct StructC {
    short unk0;
    short id;
    char pad[0xDC];
} StructC;

__attribute__((section(".text.func_00377E28")))
void func_00377E28(void) {
    int i;

    func_003A52F0(D_0076EA50, 0, 0x600);
    func_003A52F0(D_0076F050, 0, 0x1800);
    func_003A52F0(D_00770850, 0, 0x2A00);

    for (i = 0x5F; i >= 0; i--) {
        ((StructB *)D_0076F050)[i].id = i;
    }
    for (i = 0x2F; i >= 0; i--) {
        ((StructC *)D_00770850)[i].id = i;
    }
}
