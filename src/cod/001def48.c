/* sn-2.95.3-136 matched TU. */

/* Show or hide the two cursor elements: mode 0 hides the first and shows the second, mode 1 shows both, any other mode leaves them. */
#define PANEL_ELEM_LEFT   2
#define PANEL_ELEM_RIGHT  3

typedef struct PanelObj {
    char unk00[4];
} PanelObj;

extern void func_001DEE60(PanelObj *self, int element, int show);

__attribute__((section(".text.func_001DEF48")))
void func_001DEF48(PanelObj *self, unsigned char mode)
{
    switch (mode) {
    case 0:
        func_001DEE60(self, PANEL_ELEM_LEFT, 0);
        func_001DEE60(self, PANEL_ELEM_RIGHT, 1);
        break;
    case 1:
        func_001DEE60(self, PANEL_ELEM_LEFT, 1);
        func_001DEE60(self, PANEL_ELEM_RIGHT, 1);
        break;
    }
}

/* Two-phase wait of a slot machine part: phase 0 counts a blink timer down and clears the blink flag when it runs out, phase 1 resets the state machine. */
#define SLOT2PART_F_BLINK  0x100            /* flag word bit 8 */

typedef struct Slot2Part {
    int unk00;
    int state;                          /* 0x004 */
    int step;                           /* 0x008 */
    int phase;                          /* 0x00C */
    char unk10[0x44];
    int flags;                      /* 0x054 */
    char unk58[0x46A];
    unsigned short blinkTimer;          /* 0x4C2 frames of blinking left */
} Slot2Part;

extern void func_001E4520(Slot2Part *self, int mode);

__attribute__((section(".text.func_001E3128")))
void func_001E3128(Slot2Part *self)
{
    switch (self->phase) {
    case 0:
        if (self->blinkTimer != 0) {
            self->blinkTimer--;
            if (self->blinkTimer == 0) {
                self->flags &= ~SLOT2PART_F_BLINK;
                func_001E4520(self, 0);
            }
        }
        self->phase = self->phase + 1;
        break;
    case 1:
        self->state = 0;
        self->step = 0;
        self->phase = 0;
        break;
    }
}

/* 1 when no loaded bank entry uses this key (a zero key, or an idle table, counts as free); 0 when the current or any live entry holds it. */
#define BANKTAB_ENTRY_NUM  16

typedef struct BankEntry {
    unsigned int flags;                 /* 0x00 bit 0: entry in use */
    char unk04[0x7C];
    int key;                            /* 0x80 */
    char unk84[0x3C];
} BankEntry;                            /* 0xC0 */

typedef struct BankTable {
    BankEntry *cur;                     /* 0x00 entry being loaded, 0 when idle */
    char unk04[0x3C];
    BankEntry entry[BANKTAB_ENTRY_NUM]; /* 0x40 */
} BankTable;

extern int func_002D3210(BankEntry *entry);     /* entry in use */

__attribute__((section(".text.func_002D2EE8")))
int func_002D2EE8(BankTable *self, int key)
{
    BankEntry *e;
    int i;
    if (key == 0) {
        return 1;
    }
    if (self->cur == 0) {
        return 1;
    }
    if (self->cur->key == key) {
        return 0;
    }
    e = self->entry;
    for (i = 0; i < BANKTAB_ENTRY_NUM; i++) {
        if (func_002D3210(e) != 0) {
            if (e->key == key) {
                return 0;
            }
        }
        e++;
    }
    return 1;
}
