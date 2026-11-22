/* include/godhand/objFactory.h - the object factory and the allocators it calls.
 *
 * func_0030FE68 builds an actor from its id: a switch picks the allocator,
 * each allocator takes zeroed heap memory and runs one constructor
 * (objCtor.h), then the factory stamps the serial and the id and binds the
 * data pack.
 */
#ifndef GODHAND_OBJFACTORY_H
#define GODHAND_OBJFACTORY_H

#include "godhand/cObj.h"

/* The 0x360-byte actor whose vtable is D_00450CE8: a cObj with two vectors
 * and a flag byte. */
typedef struct cObjVec2 {
    cObj base;                          /* 0x000 */
    cVec unk310;                        /* 0x310 */
    char unk320[0xC];
    unsigned char unk32C;               /* 0x32C */
    char unk32D[0x13];
    cVec unk340;                        /* 0x340 */
    char unk350[0x10];
} cObjVec2;                             /* 0x360 */
typedef char cObjVec2_size_check[sizeof(cObjVec2) == 0x360 ? 1 : -1];

extern unsigned char D_003C3D18;        /* serial stamped into each new actor (cObj.unk2FC) */
extern cVtEnt D_0044B840[];            /* cObjTestSet's method table (CreateObjectWithVtableA) */
extern cVtEnt D_00450B98[];            /* objDummy's method table (CreateObjectWithVtableB) */
extern cVtEnt D_00450B28[];            /* dbObj's method table (CreateObjectWithVtableC) */
extern cVtEnt D_00450C38[];            /* objCock's method table (func_003184E0) */

/* 0xFFFF is the "no data" id. */
static __inline__ int validId(int d)
{
    return d != 0xFFFF;
}

int func_0030FB70(int id, int dataId);
cObj *func_0030FAC8(int id, int dataId);
void *func_0030FB20(int id, cObj *obj);
cObj *func_0030FE68(int id, int dataId);
void *func_00312AB0(int id, int dataId);
cObj *func_00312B00(int id, int dataId);

cObjVec2 *func_00312E88(void);
void *AllocAndInitSystem_312F00(void);
void *func_00312F70(void);
void *func_00313030(void);
void *AllocZeroedAndInit_3130E0(void);
void *func_00313150(void);
void *func_00313210(void);
void *func_003132D0(void);
void *func_00313390(void);
void *func_00313450(void);
void *AllocAndInitObjVtable_313510(void);
void *AllocAndSetupObj_313580(void);
void *AllocZeroedAndInitVtable_3135F0(void);
void *AllocZeroedAndSetupObj_313660(void);
void *AllocAndInitObjVtableFull_3136D0(void);
void *ForwardInitBuffer_313740(void);
void *ForwardInitVtable214Buffer_3137B0(void);
void *ForwardInitBuffer_313820(void);
void *ForwardInitBuffer_313890(void);
void *ForwardInitObj28B0Buffer_313900(void);
void *ForwardSetupBuffer_28E018_313970(void);
void *CreateObjectWithVtableA(void);
void *ForwardInitBuffer_313A60(void);
void *ForwardInitBuffer_313AD0(void);
void *ForwardInitBuffer_313B40(void);
void *ForwardInitBuffer_313BB0(void);
void *ForwardInitBuffer_313C20(void);
void *ForwardInitBuffer_313C90(void);
void *ForwardInitBuffer_313D00(void);
void *ForwardInitBuffer_313D70(void);
void *ForwardInitBuffer_313DE0(void);
void *AllocZeroedBlock_313E50(void);
void *ForwardInitBuffer_313EC0(void);
void *ForwardInitBuffer_313F30(void);
void *ForwardInitBuffer_313FA0(void);
void *ForwardInitBuffer_314010(void);
void *ForwardInitBuffer_314080(void);
void *ForwardInitBuffer_3140F0(void);
void *ForwardInitBuffer_314160(void);
void *ForwardInitBuffer_3141D0(void);
void *ForwardInitBuffer_314240(void);
void *ForwardInitBuffer_3142B0(void);
void *ForwardInitBuffer_314320(void);
void *ForwardInitBuffer_314390(void);
void *ForwardInitBuffer_314400(void);
void *ForwardInitBuffer_314470(void);
void *ForwardInitBuffer_3144E0(void);
void *ForwardInitBuffer_314550(void);
void *ForwardInitBuffer_3145C0(void);
void *ForwardInitBuffer_314630(void);
void *ForwardInitBuffer_3146A0(void);
void *ForwardInitBuffer_314710(void);
void *ForwardInitBuffer_314780(void);
void *ForwardInitBuffer_3147F0(void);
void *AllocZeroAndInit_9E0_314860(void);
void *ForwardInitBuffer_3148D0(void);
void *ForwardInitBuffer_314940(void);
void *ForwardInitBuffer_3149B0(void);
void *ForwardInitBuffer_314A20(void);
void *ForwardInitBuffer_314A90(void);
void *ForwardInitBuffer_314B00(void);
void *ForwardInitBuffer_314B70(void);
void *ForwardInitBuffer_314BE0(void);
void *ForwardInitBuffer_314C50(void);
void *ForwardInitBuffer_314CC0(void);
void *ForwardInitBuffer_314D30(void);
void *ForwardInitBuffer_314DA0(void);
void *ForwardInitBuffer_314E10(void);
void *ForwardInitBuffer_314E80(void);
void *ForwardInitBuffer_314EF0(void);
void *ForwardInitBuffer_314F60(void);
void *ForwardInitBuffer_314FD0(void);
void *ForwardInitObjVtableBuffer_315040(void);
void *ForwardSetObjVtableBuffer_3150B0(void);
void *ForwardInitObjVu0Block_315120(void);
void *ForwardInitVu0ObjBlock_315190(void);
void *ForwardInitVu0ObjData_315200(void);
void *ForwardInitObjVu0Array_315270(void);
void *AllocZeroedAndInitObjSlots_3152E0(void);
void *AllocZeroedAndInitObjSlots_315350(void);
void *AllocZeroedAndInitObjSlots_3153C0(void);
void *AllocZeroedAndInitObjSlots_315430(void);
void *AllocZeroedAndInitObjSlots_3154A0(void);
void *AllocZeroedAndInitObjSlots_315510(void);
void *AllocZeroedAndSetupFields214And620_315580(void);
void *AllocZeroedAndInitVu0SlotArray4_3155F0(void);
void *AllocZeroedAndInitVu0SlotArray5_315660(void);
void *AllocZeroedAndInitVu0SlotArray5B_3156D0(void);
void *AllocZeroedAndInitVu0SlotArray4B_315740(void);
void *AllocZeroedAndInitObjSlots_3157B0(void);
void *AllocZeroedAndInitObjSlotsB_315820(void);
void *AllocZeroedAndForwardInit1A25A0_315890(void);
void *ForwardInit1A3A98_315900(void);
void *ForwardInit1A3D10_315970(void);
void *ForwardInit1A42E8_3159E0(void);
void *ForwardInit1A5100_315A50(void);
void *ForwardInit1A5FD8_315AC0(void);
void *ForwardInit1A6D68_315B30(void);
void *ForwardInit1A7788_315BA0(void);
void *ForwardInit1A8150_315C10(void);
void *ForwardInit1A8348_315C80(void);
void *ForwardInit1A86F8_315CF0(void);
void *ForwardInit1A88B0_315D60(void);
void *ForwardInit1A9688_315DD0(void);
void *ForwardInit1A9858_315E40(void);
void *ForwardInit1ABD40_315EB0(void);
void *ForwardInit1ADB88_315F20(void);
void *ForwardInit1AE798_315F90(void);
void *ForwardInit1B0290_316000(void);
void *ForwardInit1B0B70_316070(void);
void *ForwardInit1B0CE8_3160E0(void);
void *ForwardInit1C9140_316150(void);
void *ForwardInitObject_3161C0(void);
void *ForwardInitObject_316230(void);
void *ForwardInitObject_3162A0(void);
void *ForwardInitObject_316310(void);
void *ForwardInitObject_316380(void);
void *ForwardInitObject_3163F0(void);
void *ForwardInitObject_316460(void);
void *ForwardInitObject_3164D0(void);
void *ForwardInitObject_316540(void);
void *ForwardInitObject_3165B0(void);
void *ForwardInitObject_316620(void);
void *ForwardInitObject_316690(void);
void *ForwardInitObject_316700(void);
void *ForwardInitObject_316770(void);
void *ForwardInitObject_3167E0(void);
void *ForwardInitObject_316850(void);
void *ForwardInitObject_3168C0(void);
void *ForwardInitObject_316930(void);
void *ForwardInitObject_3169A0(void);
void *ForwardInitObject_316A10(void);
void *AllocZeroedAndForward_316A80(void);
void *AllocZeroedAndForward_316AF0(void);
void *AllocZeroedAndForward_316B60(void);
void *AllocZeroedAndForward_316BD0(void);
void *AllocZeroedAndForward_316C40(void);
void *AllocZeroedAndForward_316CB0(void);
void *AllocZeroedAndForward_316D20(void);
void *AllocZeroedAndForward_316D90(void);
void *AllocZeroedAndForward_316E00(void);
void *AllocZeroedAndForward_316E70(void);
void *AllocZeroedAndForward_316EE0(void);
void *AllocZeroedAndForward_316F50(void);
void *AllocZeroedAndForward_316FC0(void);
void *AllocZeroedAndForward_317030(void);
void *AllocZeroedAndForward_3170A0(void);
void *AllocZeroedAndForward_317110(void);
void *AllocZeroedAndForward_317180(void);
void *AllocZeroedAndForward_3171F0(void);
void *AllocZeroedAndForward_317260(void);
void *AllocZeroedAndForward_3172D0(void);
void *AllocZeroedAndForwardInit179D58_317340(void);
void *AllocAndInit8E0_3173B0(void);
void *AllocAndInit1DB0_317420(void);
void *Setup_0x780_17C4A8_317490(void);
void *AllocAndInit8A0_317500(void);
void *AllocAndInit6B0_317570(void);
void *AllocAndInit680_3175E0(void);
void *AllocInitObj17E0F8_317650(void);
void *AllocInitObj17E828_3176C0(void);
void *AllocInitObj17EA98_317730(void);
void *AllocInitObj17EC08_3177A0(void);
void *AllocInitObj17EE40_317810(void);
void *AllocInitObj17F270_317880(void);
void *AllocInitObj17F4E0_3178F0(void);
void *AllocInitObj17FB48_317960(void);
void *AllocInitObj1808E8_3179D0(void);
void *AllocInitObj181638_317A40(void);
void *AllocInitObj181838_317AB0(void);
void *AllocInitObj1825E0_317B20(void);
void *AllocInitObj182888_317B90(void);
void *AllocInitObj183348_317C00(void);
void *AllocInitObj1835A0_317C70(void);
void *AllocInitObj183848_317CE0(void);
void *func_00317D50(void);
void *CreateObjectWithVtableB(void);
void *AllocInitObj3184E0_317F00(void);
void *CreateObjectWithVtableC(void);
void *func_00318138(void);
void *func_003181A8(void);

#endif
