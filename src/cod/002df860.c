/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/sceVu0.h"

extern void MtxInitRotY(void *a0, float angle);
extern void func_00104010(void *self, void *work, void *model);

#define EM_CLOTH_DRIFT_FIRST  0x270     /* enemy numbers 0x270..0x274 */
#define EM_CLOTH_DRIFT_LAST   0x274

/* The cloth state an enemy passes in; only the drift vector is named. */
typedef struct EmCloth {
    char unk00[0x60];
    cVec drift;                         /* 0x60 sideways push, turned with the enemy */
} EmCloth;

/* Steps an enemy's cloth; enemies 0x270 to 0x274 first get a small push turned to their heading. */
__attribute__((section(".text.EmClothMove")))
void EmClothMove(int emNo, cEm00 *self, void *model, EmCloth *cloth)
{
    float mtx[4][4];
    cVec drift;

    if (self == 0 || model == 0 || cloth == 0) {
        return;
    }
    cVec_zero(&drift);
    if (emNo <= EM_CLOTH_DRIFT_LAST) {
        if (emNo >= EM_CLOTH_DRIFT_FIRST) {
            MtxInitRotY(mtx, self->rot.y);
            drift.x = 0.02f;
            drift.y = 0.02f;
            drift.z = -0.02f;
            cVec_applyMatrix(&drift, mtx);
            cVec_copy3(&cloth->drift, &drift);
        }
    }
    func_00104010(self, cloth, model);
}
