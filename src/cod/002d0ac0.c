/* sn-2.95.3-136 matched TU. */

extern char D_003C3138[];
extern char D_005FEE00[];
extern void cSnd_SetBgmState(void *a0, int a1);

/* sn-2.95.3-136 matched TU. */

typedef struct BgmEntry {
    /* 0x00 */ unsigned short id;
    /* 0x02 */ unsigned short pad;
    /* 0x04 */ int f04;
    /* 0x08 */ int f08;
    /* 0x0C */ int f0C;
    /* 0x10 */ int f10;
    /* 0x14 */ int f14;
} BgmEntry;





__attribute__((section(".text.SetBgmTbl")))
void SetBgmTbl(unsigned short id, int val, int state) {
    BgmEntry *found = 0;
    unsigned int i;

    for (i = 0; i < 44; i++) {
        if (((BgmEntry *)D_003C3138)[i].id == id) {
            found = &((BgmEntry *)D_003C3138)[i];
        }
    }

    if (found == 0) {
        return;
    }
    cSnd_SetBgmState(D_005FEE00, state);
    switch (state) {
    default:
    case 0:
        found->f04 = val;
        break;
    case 1:
        found->f08 = val;
        break;
    case 2:
        found->f0C = val;
        break;
    case 3:
        found->f10 = val;
        break;
    case 4:
        found->f14 = val;
        break;
    }
}
