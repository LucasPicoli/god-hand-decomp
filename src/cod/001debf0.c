/* sn-2.95.3-136 matched TU. */

typedef struct { int w[5]; } Blk1DE;
extern Blk1DE D_0042B5D0;
extern void CustomIDWork_SetOffsetPosXY(char *p, int x, int y);

__attribute__((section(".text.func_001DEBF0")))
void func_001DEBF0(char *a0, unsigned char a1, int a2, int a3) {
    Blk1DE buf;
    if (a1 < 5) {
        buf = D_0042B5D0;
        CustomIDWork_SetOffsetPosXY(a0 + (buf.w[a1] * 0x7C + 0x60), a2, a3);
    }
}
