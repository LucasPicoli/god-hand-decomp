/* sn-2.95.3-136 matched TU. */

extern void AddQueueEntry_1FF4D0(int a0, int a1);
extern int UpdateStateReady_1FF238(int a0);
extern void func_002D5250(int a0);
extern unsigned short D_00747A50;

/* sn-2.95.3-136 matched TU. */







__attribute__((section(".text.func_001FEAA0")))
void func_001FEAA0(void *a0, int a1, int a2, int a3) {
    void *p = a0;
    int kind = a1;
    int id = a2;
    int flags = a3;
    int v0;

    v0 = func_001FEE00(p, kind);
    if (v0 < 0) {
        return;
    }
    if ((flags & 1) != 0) {
        switch (id) {
        case 0x200:
            id = 0x227;
            break;
        case 0x203:
            id = 0x22A;
            break;
        case 0x204:
            id = 0x22B;
            break;
        case 0x21A:
            id = 0x22C;
            break;
        case 0x21D:
            id = 0x22E;
            break;
        case 0x21E:
            id = 0x22F;
            break;
        case 0x21B:
            id = 0x22D;
            break;
        case 0x225:
            id = 0x24D;
            break;
        case 0x240:
            id = 0x24A;
            break;
        case 0x242:
            id = 0x243;
            break;
        case 0x249:
            id = 0x24E;
            break;
        }
    }
    if (D_00747A50 == 0x504) {
        if ((unsigned int)(id - 0x250) < 2) {
            return;
        }
    }
    AddQueueEntry_1FF4D0(*(int *)((char *)p + 8) + v0 * 0x5C, id);
    switch (kind) {
    case 0x264:
        AddQueueEntry_1FF4D0(*(int *)((char *)p + 8) + v0 * 0x5C, 0x263);
        break;
    case 0x278:
        AddQueueEntry_1FF4D0(*(int *)((char *)p + 8) + v0 * 0x5C, 0x20F);
        break;
    case 0x211:
        AddQueueEntry_1FF4D0(*(int *)((char *)p + 8) + v0 * 0x5C, 0x200);
        AddQueueEntry_1FF4D0(*(int *)((char *)p + 8) + v0 * 0x5C, 0x203);
        AddQueueEntry_1FF4D0(*(int *)((char *)p + 8) + v0 * 0x5C, 0x227);
        AddQueueEntry_1FF4D0(*(int *)((char *)p + 8) + v0 * 0x5C, 0x22A);
        break;
    }
    while (UpdateStateReady_1FF238(*(int *)((char *)p + 8) + v0 * 0x5C) == 0) {
        func_002D5250(1);
    }
}
