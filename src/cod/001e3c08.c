/* sn-2.95.3-136 matched TU. */

extern int cModel_setMeshDisplay(void *model, char *name, int on);
extern char D_0044A9B0[];
extern char D_0044A9B8[];
extern void displayScrollLayer(int layer, int on);

/* Costume hook for the objects with actor id 0x605 and 0x607: from costume 0x10 on, hide the first part mesh (and show the second one on 0x605). */
#define ACTOR_ID_COSTUME_A   0x605
#define ACTOR_ID_COSTUME_B   0x607
#define COSTUME_PART_MIN     0x10

typedef struct CostumeObj {
    char unk000[0x2FE];
    unsigned short actorId;             /* 0x2FE */
} CostumeObj;





__attribute__((section(".text.func_00298110")))
void func_00298110(CostumeObj *self, int unused, int costume)
{
    if (self == 0) {
        return;
    }
    switch (self->actorId) {
    case ACTOR_ID_COSTUME_A:
        if (costume >= COSTUME_PART_MIN) {
            cModel_setMeshDisplay(self, D_0044A9B0, 0);
            cModel_setMeshDisplay(self, D_0044A9B8, 1);
        }
        break;
    case ACTOR_ID_COSTUME_B:
        if (costume >= COSTUME_PART_MIN) {
            cModel_setMeshDisplay(self, D_0044A9B0, 0);
        }
        break;
    }
}

/* Show or hide the four scroll layers of a slot machine mark; showing also sets the mark's flag word (bit 15 start lit, bit 14 on). */
#define SLOT2MARK_F_START_LIT  0x8000
#define SLOT2MARK_F_ON         0x4000

typedef struct Slot2Marks {
    char unk000[0x430];
    int layerA;                         /* 0x430 */
    char unk434[0x40];
    int layerC;                         /* 0x474 */
    int layerD;                         /* 0x478 */
    int layerB;                         /* 0x47C */
    char unk480[0x26];
    unsigned short markFlag;            /* 0x4A6 */
} Slot2Marks;



__attribute__((section(".text.func_001E3C08")))
void func_001E3C08(Slot2Marks *self, int show, int startLit)
{
    self->markFlag = 0;
    if (startLit) {
        self->markFlag = SLOT2MARK_F_START_LIT;
    }
    if (show) {
        self->markFlag = self->markFlag | SLOT2MARK_F_ON;
        displayScrollLayer(self->layerA, 1);
        displayScrollLayer(self->layerB, 1);
        displayScrollLayer(self->layerC, 1);
        displayScrollLayer(self->layerD, 1);
    } else {
        displayScrollLayer(self->layerA, 0);
        displayScrollLayer(self->layerB, 0);
        displayScrollLayer(self->layerC, 0);
        displayScrollLayer(self->layerD, 0);
    }
}
