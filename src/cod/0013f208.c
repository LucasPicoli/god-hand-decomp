/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern void cIDBase_trans(void *);
extern int D_0041DCC8[];
extern void __builtin_delete(void);

__attribute__((section(".text.ForwardIdBaseTransIfValid_13F208")))
void ForwardIdBaseTransIfValid_13F208(void *a0) {
    if (*(int *)((char *)a0 + 0x9C) != 0xFFFF) cIDBase_trans(a0);
}

__attribute__((section(".text.InitPtrField80AndForward_1434D0")))
void InitPtrField80AndForward_1434D0(void *a0, int a1) {
    *(int **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}

__attribute__((section(".text.InitPtrField80AndForward_143AF0")))
void InitPtrField80AndForward_143AF0(void *a0, int a1) {
    *(int **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}
