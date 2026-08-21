/* sn-2.95.3-136 matched TU. */

extern int D_0044FA38;
extern void func_002D9F68(void *, int, ...);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_003002B0")))
void func_003002B0(char *o, char *w) {
    unsigned int t = *(unsigned char *)(o + 0x247);

    switch (t) {
    case 0:
        *(long *)(w + 0) = 0x8000000044L;
        break;
    case 1:
        *(long *)(w + 0) = 0x8000000048L;
        break;
    case 2:
        *(long *)(w + 0) = 0x80000000A1L;
        break;
    case 3:
        *(long *)(w + 0) = 0x8000000041L;
        break;
    case 4:
        *(long *)(w + 0) = 0x8000000049L;
        break;
    case 5:
        *(long *)(w + 0) = 0x8000000068L;
        break;
    case 6:
        *(long *)(w + 0) = 0x8000000009L;
        break;
    case 7:
        *(long *)(w + 0) = 0x8000000046L;
        break;
    case 8:
        *(long *)(w + 0) = 0x80000000A4L;
        break;
    case 9:
        *(long *)(w + 0) = 0x8000000042L;
        break;
    case 10:
        *(long *)(w + 0) = 0x8000000006L;
        break;
    default:
        func_002D9F68(o, (int)&D_0044FA38, *(unsigned char *)(o + 0x102), t);
        break;
    }
    *(long *)(w + 8) = 0x42;
}
