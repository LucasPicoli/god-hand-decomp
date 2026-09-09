/* ee-2.9-991111 matched TU. */

typedef struct MpegState {
    char pad0[0xFC];
    int  f0xFC;             /* 252  */
    char pad1[0x1B4 - 0x100];
    int  closed_gop;        /* 436  */
    int  broken_link;       /* 440  */
    char pad2[0x85C - 0x1BC];
    int  f0x85C;            /* 2140 */
    int  f0x860;            /* 2144 */
    int  f0x864;            /* 2148 */
} MpegState;


extern void func_003A0C18(MpegState *s);

__attribute__((section(".text.func_003A05E0")))
void func_003A05E0(MpegState *s)
{
    s->f0xFC  = 0;
    s->f0x864 = 1;
    s->f0x85C = s->f0x860 + 1;
    func_0039EAA8(s, 1);
    func_0039EAA8(s, 5);
    func_0039EAA8(s, 6);
    func_0039EAA8(s, 1);
    func_0039EAA8(s, 6);
    func_0039EAA8(s, 6);
    s->closed_gop  = func_0039EAA8(s, 1);
    s->broken_link = func_0039EAA8(s, 1);
    func_003A0C18(s);
}
