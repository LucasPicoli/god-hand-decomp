/* sn-2.95.3-136 matched TU. */

#include "godhand/cRoomSave.h"
#include "godhand/cIDBase.h"
#include "godhand/CustomIDWork.h"

extern void cIDBase_initialize(void *p, int a, int b);
extern void cIDBase_restartAnim(void *p);
extern void CustomIDWork_Initialize(void *p, void *w);
extern void CustomIDWork_SetDisp(void *p, int f);
extern void SetCustomIDDispOneOrAll_1F4778(void *p, int n, int f);
extern void Panel_hideIcons(void *p);
extern void func_001EDC28(void *p, int n);
extern void func_001ED700(void *p, int n, int f);
extern void func_001EE2A8(void *p, int n);
extern void func_001EE2C8(void *p, int n);
extern void SetCustomIDDispOneOrAll_1EE1C0(void *p, int n, int f);
extern void CustomIDWork_SetMessNo(void *p, int n);
extern void CustomIDWork_setDispAllButEight(void *p, int a, int b);
extern void func_001ED490(void *p, int a);
extern void func_003A52F0(void *dst, int val, int n);
extern cRoomSaveData D_005E9CB8[ROOMSAVE_PAGE_NUM];

#define COLISEUMEM_ELEM_NUM       0x6F
#define DOGRACE_UI_ELEM_NUM       6
#define DOGRACE_LIST_ELEM_NUM     0x1D
#define DOGRACE_RESULT_ELEM_NUM   0x2D

/* The four displays built here: a cIDBase at 0x10 and the CustomIDWork
 * elements it animates from 0x60. */
typedef struct ColiseumEmDisp {
    char unk000[0x10];
    cIDBaseObj id;                      /* 0x010 */
    char unk058[0x60 - 0x10 - sizeof(cIDBaseObj)];
    CustomIDWork elem[COLISEUMEM_ELEM_NUM];     /* 0x060 */
} ColiseumEmDisp;                       /* 0x3624 as far as it is known */

typedef struct DogRaceUi {
    char unk000[0x10];
    cIDBaseObj id;                      /* 0x010 */
    char unk058[0x60 - 0x10 - sizeof(cIDBaseObj)];
    CustomIDWork elem[DOGRACE_UI_ELEM_NUM];     /* 0x060 */
    char unk348[0x350 - 0x348];
} DogRaceUi;                            /* 0x350 */

typedef struct DogRaceList {
    char unk000[0x10];
    cIDBaseObj id;                      /* 0x010 */
    char unk058[0x60 - 0x10 - sizeof(cIDBaseObj)];
    CustomIDWork elem[DOGRACE_LIST_ELEM_NUM];   /* 0x060 */
    char unkE6C[0xE7C - 0xE6C];
} DogRaceList;                          /* 0xE7C */

typedef struct DogRaceResult {
    char unk000[0x10];
    cIDBaseObj id;                      /* 0x010 */
    char unk058[0x60 - 0x10 - sizeof(cIDBaseObj)];
    CustomIDWork elem[DOGRACE_RESULT_ELEM_NUM]; /* 0x060 */
    char unk162C[0x1630 - 0x162C];
} DogRaceResult;                        /* 0x1630 */

typedef char DogRaceUi_size_check[sizeof(DogRaceUi) == 0x350 ? 1 : -1];
typedef char DogRaceList_size_check[sizeof(DogRaceList) == 0xE7C ? 1 : -1];
typedef char DogRaceResult_size_check[sizeof(DogRaceResult) == 0x1630 ? 1 : -1];

/* Build the 0x6F custom-ID works of a UI object, then show all of them. */







__attribute__((section(".text.InitUiIdWorksAndShowAll")))
void InitUiIdWorksAndShowAll(ColiseumEmDisp *self)
{
    int i;

    cIDBase_initialize(&self->id, 0x15, 0);
    cIDBase_restartAnim(&self->id);
    for (i = 0; i < COLISEUMEM_ELEM_NUM; i++) {
        CustomIDWork_Initialize(&self->elem[i], cIDBase_getIDWork(&self->id, i));
    }
    SetCustomIDDispOneOrAll_1F4778(self, COLISEUMEM_ELEM_NUM, 0);
}

/* Build the 6 custom-ID works of a UI object, then run its three setup steps. */









__attribute__((section(".text.InitDogRaceUiIdWorks")))
void InitDogRaceUiIdWorks(DogRaceUi *self)
{
    int i;

    cIDBase_initialize(&self->id, 0x14, 2);
    cIDBase_restartAnim(&self->id);
    for (i = 0; i < DOGRACE_UI_ELEM_NUM; i++) {
        CustomIDWork_Initialize(&self->elem[i], cIDBase_getIDWork(&self->id, i));
    }
    Panel_hideIcons(self);
    func_001EDC28(self, 0);
    func_001ED700(self, DOGRACE_UI_ELEM_NUM, 0);
}

/* Build the 0x1D custom-ID works of a UI object, run its setup steps, then show all of them. */









__attribute__((section(".text.InitDogRaceListIdWorks")))
void InitDogRaceListIdWorks(DogRaceList *self)
{
    int i;

    cIDBase_initialize(&self->id, 0x14, 1);
    cIDBase_restartAnim(&self->id);
    for (i = 0; i < DOGRACE_LIST_ELEM_NUM; i++) {
        CustomIDWork_Initialize(&self->elem[i], cIDBase_getIDWork(&self->id, i));
    }
    func_001EE2A8(self, 0);
    func_001EE2C8(self, 0);
    CustomIDWork_SetDisp(&self->elem[0], 0);
    SetCustomIDDispOneOrAll_1EE1C0(self, DOGRACE_LIST_ELEM_NUM, 0);
}

/* Build the 0x2D custom-ID works of a UI object, set four message numbers, hide the first work and run two setup steps. */









__attribute__((section(".text.InitDogRaceResultIdWorks")))
void InitDogRaceResultIdWorks(DogRaceResult *self)
{
    int i;

    cIDBase_initialize(&self->id, 0x14, 0);
    cIDBase_restartAnim(&self->id);
    for (i = 0; i < DOGRACE_RESULT_ELEM_NUM; i++) {
        CustomIDWork_Initialize(&self->elem[i], cIDBase_getIDWork(&self->id, i));
    }
    CustomIDWork_SetMessNo(&self->elem[29], 0x101A);
    CustomIDWork_SetMessNo(&self->elem[43], 0x101A);
    CustomIDWork_SetMessNo(&self->elem[30], 0x101B);
    CustomIDWork_SetMessNo(&self->elem[44], 0x101B);
    CustomIDWork_SetDisp(&self->elem[8], 0);
    CustomIDWork_setDispAllButEight(self, DOGRACE_RESULT_ELEM_NUM, 0);
    func_001ED490(self, 0);
}

/* Boot reset: clear the seven pages, the spare page, and forget the current page. */
__attribute__((section(".text.cRoomSave_systemInit")))
void cRoomSave_systemInit(cRoomSave *self) {
    func_003A52F0(D_005E9CB8, 0, sizeof(D_005E9CB8));
    func_003A52F0(&self->spare, 0, sizeof(self->spare));
    self->data = 0;
}
