#include "godhand/heapArena.h"
#include "godhand/criStm.h"
#include "godhand/objFactory.h"
#include "godhand/objCtor.h"
extern int D_00747A34;

__attribute__((section(".text.ForwardInitBuffer_313F30")))
void *ForwardInitBuffer_313F30(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x8A0, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x8A0);
    return func_0018CEA0(s0);
}

__attribute__((section(".text.ForwardInitBuffer_313FA0")))
void *ForwardInitBuffer_313FA0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x8A0, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x8A0);
    return func_0018DC58(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314010")))
void *ForwardInitBuffer_314010(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return func_0018EA10(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314080")))
void *ForwardInitBuffer_314080(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x610, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x610);
    return func_0018EC98(s0);
}

__attribute__((section(".text.ForwardInitBuffer_3140F0")))
void *ForwardInitBuffer_3140F0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x8F0, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x8F0);
    return func_0018EEA8(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314160")))
void *ForwardInitBuffer_314160(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x920, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x920);
    return cEm_constructWithRecords(s0);
}

__attribute__((section(".text.ForwardInitBuffer_3141D0")))
void *ForwardInitBuffer_3141D0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0xFA0, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0xFA0);
    return InitObjSlots_1901C8(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314240")))
void *ForwardInitBuffer_314240(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return InitObjSlots_191AB0(s0);
}

__attribute__((section(".text.ForwardInitBuffer_3142B0")))
void *ForwardInitBuffer_3142B0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x8F0, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x8F0);
    return InitObjSlots_191D38(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314320")))
void *ForwardInitBuffer_314320(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x6B0, 0x10, &D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x6B0);
    return InitObjSlots_191FA0(s0);
}
