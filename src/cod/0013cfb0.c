extern int D_0041DCC8[];
extern char D_00464080;

__attribute__((section(".text.SetField80AndForward_13CFB0")))
void SetField80AndForward_13CFB0(int *a0, int a1) {
    *(int **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}

__attribute__((section(".text.SetField80AndForwardAlt_13D150")))
void SetField80AndForwardAlt_13D150(int *a0, int a1) {
    *(int **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}

__attribute__((section(".text.SetField80AddrAndForward_13F270")))
void SetField80AddrAndForward_13F270(int a0, int a1) {
    *(int*)((char*)a0 + 0x80) = (int)&D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}

__attribute__((section(".text.SetField80AddrAndForwardAlt_140B58")))
void SetField80AddrAndForwardAlt_140B58(int a0, int a1) {
    *(int*)((char*)a0 + 0x80) = (int)&D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}

__attribute__((section(".text.ForwardIfSentinel_141AC8")))
void ForwardIfSentinel_141AC8(int a0, int a1) {
    if (a1 != 0xFFFF) {
        return;
    }
    if (a0 == 0) {
        return;
    }
    func_00141678(&D_00464080);
}

__attribute__((section(".text.Forward141AC8_141AF8")))
void Forward141AC8_141AF8(void) {
    ForwardIfSentinel_141AC8(1, 0xFFFF);
}
