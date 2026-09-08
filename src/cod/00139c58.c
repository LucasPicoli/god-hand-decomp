extern int D_0041D8F8[];
extern int D_0041DCC8[];

__attribute__((section(".text.SetField35CAndForward_139C58")))
void SetField35CAndForward_139C58(int *a0, int a1) {
    *(int **)((char *)a0 + 0x35C) = D_0041D8F8;
    if (a1 & 1) {
        __builtin_delete();
    }
}

__attribute__((section(".text.ForwardIfField94FlagSet_13C168")))
void ForwardIfField94FlagSet_13C168(int *a0) {
    unsigned char x = *(unsigned char *)((char *)a0 + 0x94);
    if (((x ^ 1) & 1) == 0) {
        cIDBase_trans();
    }
}

__attribute__((section(".text.SetField80DCC8AndForward_13C198")))
void SetField80DCC8AndForward_13C198(int *a0, int a1) {
    *(int **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}

__attribute__((section(".text.InitVtableAndForwardField_13C528")))
void InitVtableAndForwardField_13C528(int *a0, int a1) {
    *(int **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}

__attribute__((section(".text.InitVtableAndForwardField2_13C798")))
void InitVtableAndForwardField2_13C798(int *a0, int a1) {
    *(int **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}
