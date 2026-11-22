/* sn-2.95.3-136 matched TU. */

#include "godhand/cObj.h"
#include "godhand/vu0.h"
#include "godhand/cModel.h"
#include "godhand/cOmBase.h"
#include "godhand/CustomIDWork.h"
#include "godhand/globals.h"

extern void *InitFields_1B6E90(void *self);
extern void func_001B6FB8(void *self);
extern int cMessCommon_isPageEndCode(int code);
extern void cOmThrow_SetParent(void *thrown, void *owner);
extern void SetCustomIDDispOneOrAll_1F29C0(void *self, int sel, int on);
extern void CustomIDWork_SetNumber(CustomIDWork *self, int number);

/* An actor with four VU0 quadwords (0x610, 0x620, 0x640, 0x650) past cObj. */
typedef struct VuFxObj {
    COBJ_FIELDS
    char unk310[0x300];
    cVec vecA;                          /* 0x610 */
    cVec vecB;                          /* 0x620 */
    char unk630[0x10];
    cVec vecC;                          /* 0x640 */
    cVec vecD;                          /* 0x650 */
} VuFxObj;

#define VUFX_OFFSET(field)  ((int)&((VuFxObj *)0)->field)

/* Init the base fields, set the table pointer at 0x214 and clear the four quadwords. Returns self. */
__attribute__((section(".text.cObj_initVuFields610")))
VuFxObj *cObj_initVuFields610(VuFxObj *self) {
    InitFields_1B6E90(self);
    self->vtable = (void *)&D_004282F0;
    VU0_SQC2_VF0(self, VUFX_OFFSET(vecA));
    VU0_SQC2_VF0(self, VUFX_OFFSET(vecB));
    VU0_SQC2_VF0(self, VUFX_OFFSET(vecC));
    VU0_SQC2_VF0(self, VUFX_OFFSET(vecD));
    return self;
}

/* An actor with a state word at 0x600 past cOmBase. */
typedef struct HideObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    int state;                          /* 0x600 */
} HideObj;

/* Hide the actor, clear the state word and drop the hidden bit of flags2. Returns 1. */
__attribute__((section(".text.cModel_hideAndClearState")))
int cModel_hideAndClearState(HideObj *self) {
    func_001B6FB8(self);
    self->base.objFlags = self->base.objFlags | CMODEL_F_HIDDEN;
    self->state = 0;
    self->base.flags2 = self->base.flags2 & ~COMBASE_FLAG_HIDDEN;
    return 1;
}

/* True for a message code with bit 15 set that ends a page or sits in the 0xA000 group. */
__attribute__((section(".text.cMessCommon_isHighCodeEnd")))
int cMessCommon_isHighCodeEnd(unsigned short code) {
    if ((code >> 15) == 0) {
        return 0;
    }
    if (cMessCommon_isPageEndCode(code) != 0) {
        return 1;
    }
    return (code & 0xFF00) == 0xA000;
}

/* Return obj plus the offset stored at slot idx (+0x10 + idx * 4 in obj) when the kind is 3, else obj itself. */
__attribute__((section(".text.cIDBase_getSlotPtr")))
int cIDBase_getSlotPtr(int unused, int obj, unsigned char idx) {
    if (func_00151630((void *)obj) == 3) {
        int slot = obj + idx * 4;
        return *(int *)(slot + 0x10) + obj;
    }
    return obj;
}

/* An actor that can hold a thrown object: the held one at 0x6A0 and the one waiting at 0x6A4 past cOmBase. */
typedef struct ThrowerObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0xC0];
    void *held;                         /* 0x6A0 */
    void *pending;                      /* 0x6A4 */
} ThrowerObj;

/* Make the waiting object the held one, else fetch one, then attach it to self. */
__attribute__((section(".text.cOm_attachThrown")))
void cOm_attachThrown(ThrowerObj *self) {
    void *next = self->pending;
    if (next != 0) {
        self->held = next;
    }
    if (self->held == 0) {
        void *got = func_0012B328(self);
        self->held = got;
        if (got == 0) {
            return;
        }
    }
    cOmThrow_SetParent(self->held, self);
}

/* An ID screen with a number element at 0x348. */
typedef struct IdNumberScreen {
    char unk000[0x348];
    CustomIDWork number;                /* 0x348 */
} IdNumberScreen;

/* Set the number element, then show or hide displays 6 and 5. */
__attribute__((section(".text.CustomID_setNumberAndShow")))
void CustomID_setNumberAndShow(IdNumberScreen *self, int number, int on) {
    CustomIDWork_SetNumber(&self->number, number);
    SetCustomIDDispOneOrAll_1F29C0(self, 6, on);
    SetCustomIDDispOneOrAll_1F29C0(self, 5, on);
}
