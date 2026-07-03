/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_00292048")))
int func_00292048(int a0, int a1)
{
    int b;
    if (a1 < 0x900) {
        return a1;
    }
    if (a1 < 0x940) {
        return 0x3DA;
    }
    b = a1 < 0xB00;
    if (a1 < 0xA00) {
        switch (a1) {
        case 0x9C0: return 0x9C0;
        case 0x9C2: return 0x3DC;
        }
        return a1;
    }
    if (b) return 0x3DB;
    return 0xFFFF;
}
