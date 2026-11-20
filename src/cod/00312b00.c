/* sn-2.95.3-136: object factory: construct by id, assign serial/id, bind or load its data, flag the meshes (0x312B00). */
#include "godhand/heapArena.h"
#include "godhand/cDataManager.h"
#include "godhand/cObj.h"
#include "godhand/FileLoadRec.h"
#include "godhand/objFactory.h"
extern cModelNode *cModel_getMeshPtr(cModel *self, int n);
extern int cModel_getMeshNum(cModel *self);

__attribute__((section(".text.func_00312B00")))
cObj *func_00312B00(int id, int dataId)
{
    cObj *obj;
    void *d;
    void *r;
    int i;

    switch (id) {
    case 0:
    case 0x1100:
    case 0x1200:
    case 0xFF01:
    case 0xFF02:
    case 0xFFFF:
        obj = 0;
        break;
    case 0x101:
        obj = func_00312F70();
        break;
    case 0x212:
        obj = func_00313210();
        break;
    case 0x253:
        obj = func_003132D0();
        break;
    case 0x257:
    case 0x628:
        obj = func_00313390();
        break;
    case 0x36E:
        obj = func_00318138();
        break;
    case 0x374:
        obj = func_00318138();
        break;
    default:
        obj = func_003181A8();
        break;
    }
    if (!obj)
        return 0;
    obj->unk2FC = D_003C3D18;
    D_003C3D18++;
    cObj_setId(obj, id);
    obj->createId = id;
    if (func_003078E0(id) != -1) {
        d = cDataManager_useDataAddress(&D_005864E0, id);
        if (d) {
            obj->pack = d;
            obj->arena = &D_00754220;
        } else {
            r = cDataManager_loadWait(&D_00580D20, obj->actorId, &D_00754220, 1);
            obj->arena = &D_00754220;
            obj->objFlags |= COBJ_F_PACK_LOADED;
            obj->pack = r;
            if (!r) {
                delObj(obj);
                obj = 0;
            }
        }
    } else if (validId(dataId)) {
        d = cDataManager_useDataAddress(&D_005864E0, dataId);
        if (d) {
            obj->pack = d;
            obj->arena = &D_00754220;
        } else {
            r = cDataManager_loadWait(&D_00580D20, dataId, &D_00754220, 1);
            obj->arena = &D_00754220;
            obj->objFlags |= COBJ_F_PACK_LOADED;
            obj->pack = r;
            if (!r) {
                delObj(obj);
                obj = 0;
            }
        }
    }
    if (obj) {
        /* i steps twice per pass, so only the even meshes get the flag. Retail does the same. */
        for (i = 0; i < cModel_getMeshNum((cModel *)obj); i++)
            *(int *)((char *)cModel_getMeshPtr((cModel *)obj, i++) + 0x380) |= 0x2000;
        obj->objFlags |= CMODEL_F_HIDDEN;
    }
    return obj;
}
