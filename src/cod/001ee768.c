#include "godhand/cCoreSave.h"
__attribute__((section(".text.ClearFields00And30_1EE768")))
int ClearFields00And30_1EE768(int a0) {
    *(int*)((char*)a0 + 0x30) = 0;
    *(int*)((char*)a0 + 0x0) = 0;
    return a0;
}

__attribute__((section(".text.ClearField00_1F6CE0")))
int ClearField00_1F6CE0(int a0) {
    *(int*)((char*)a0 + 0x0) = 0;
    return a0;
}

__attribute__((section(".text.Clear_Field_00_14_1F8A40")))
int Clear_Field_00_14_1F8A40(int a0) {
    *(int*)((char*)a0 + 0x0) = 0;
    *(int*)((char*)a0 + 0x4) = 0;
    *(int*)((char*)a0 + 0x8) = 0;
    *(int*)((char*)a0 + 0xC) = 0;
    *(int*)((char*)a0 + 0x10) = 0;
    *(int*)((char*)a0 + 0x14) = 0;
    return a0;
}

__attribute__((section(".text.GetSubObjAt180_1F9FF0")))
/* Address of the 0x180 block, or 0 without a record. */
int GetSubObjAt180_1F9FF0(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data == 0) {
        return 0;
    }
    return (int)data->unk180;
}

__attribute__((section(".text.Obj1FA6_Set_Short_1C_1FA638")))
/* Set the level points. */
void Obj1FA6_Set_Short_1C_1FA638(cCoreSave *self, short points)
{
    cCoreSaveData *data = self->data;
    if (data != 0) data->levelPoint = points;
}

__attribute__((section(".text.GetArrayElemAt28_1FA838")))
/* Recent gold pickup `i`, 0 without a record. */
int GetArrayElemAt28_1FA838(cCoreSave *self, int i)
{
    cCoreSaveData *data = self->data;
    if (data == 0) return 0;
    return data->addGold[i];
}

__attribute__((section(".text.GetByteAt134ByIndex_1FAD38")))
/* Stock count `i`, 0 without a record. */
unsigned char GetByteAt134ByIndex_1FAD38(cCoreSave *self, int i)
{
    cCoreSaveData *data = self->data;
    if (data == 0) return 0;
    return data->stock[i];
}
