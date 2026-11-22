#include "godhand/gameWork.h"
#include "godhand/globals.h"
typedef struct EspSys {
    char pad000[0x41C];
    unsigned char active;
} EspSys;

extern char D_00741DC8[];
extern void EmitterAllKill(void);
extern void EspAllKill(void);
extern void func_003057A0(EspSys *self);
extern void func_00305BC0(EspSys *self);
extern void func_00306A88(void *p);
extern void espSys_effDataRegist(EspSys *self, int id, void *data);
extern void *SearchData(void *name, void *table, int which);
extern void func_00305C10(EspSys *self, void *data);
extern void func_00305C18(EspSys *self, void *data);
extern void func_00306D18(void *p);

__attribute__((section(".text.func_00305A68")))
void func_00305A68(EspSys *self)
{
    void *p;

    self->active = 0;
    EmitterAllKill();
    EspAllKill();
    func_003057A0(self);
    func_00305BC0(self);
    func_00306A88(D_00741DC8);
    espSys_effDataRegist(self, 0, (void *)(D_007474A0.effData->unk14 + (int)D_007474A0.effData));
    espSys_effDataRegist(self, 0x58, (void *)(D_007474A0.effData->unk1C + (int)D_007474A0.effData));
    espSys_effDataRegist(self, 4, (void *)(D_007474A0.effData->unk14 + (int)D_007474A0.effData));
    p = SearchData(D_007474A0.pack, D_00450068, 0);
    if (p != 0) {
        espSys_effDataRegist(self, 1, p);
    }
    p = SearchData(D_007474A0.pack, D_00450070, 0);
    if (p != 0) {
        func_00305C10(self, p);
    }
    p = SearchData(D_007474A0.pack, D_00450078, 0);
    if (p != 0) {
        func_00305C18(self, p);
    }
    func_00306D18(D_00743250);
}
