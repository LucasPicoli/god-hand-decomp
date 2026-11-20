#include "godhand/heapArena.h"
#include "godhand/criStm.h"
#include "godhand/objFactory.h"
#include "godhand/objCtor.h"
extern int D_00747A34;

__attribute__((section(".text.ForwardInitObject_316230")))
void *ForwardInitObject_316230(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x980, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x980);
    return func_001B2220(s0);
}

__attribute__((section(".text.ForwardInitObject_3162A0")))
void *ForwardInitObject_3162A0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x640, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x640);
    return func_001B24E8(s0);
}

__attribute__((section(".text.ForwardInitObject_316310")))
void *ForwardInitObject_316310(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x770, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x770);
    return func_001B36E0(s0);
}

__attribute__((section(".text.ForwardInitObject_316380")))
void *ForwardInitObject_316380(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x970, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x970);
    return InitVuBlockObject(s0);
}

__attribute__((section(".text.ForwardInitObject_3163F0")))
void *ForwardInitObject_3163F0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return func_001B56D8(s0);
}

__attribute__((section(".text.ForwardInitObject_316460")))
void *ForwardInitObject_316460(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x630, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x630);
    return func_001B6710(s0);
}

__attribute__((section(".text.ForwardInitObject_3164D0")))
void *ForwardInitObject_3164D0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x610, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x610);
    return func_001B8108(s0);
}

__attribute__((section(".text.ForwardInitObject_316540")))
void *ForwardInitObject_316540(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x690, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x690);
    return cObj_initVuFields4AC(s0);
}

__attribute__((section(".text.ForwardInitObject_3165B0")))
void *ForwardInitObject_3165B0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x640, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x640);
    return InitAndClearVuFieldsB(s0);
}

__attribute__((section(".text.ForwardInitObject_316620")))
void *ForwardInitObject_316620(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x630, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x630);
    return func_001B8FF8(s0);
}
