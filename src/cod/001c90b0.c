/* sn-2.95.3-136 matched TU. */

extern int ClearField5B4IfFlagUnset_1B76B0();
extern int CustomIDWork_SetNumber();
extern int SetFlagOnEntries7C_1D51B8();
extern int cIDBase_release();
extern int cIDBase_trans();

/* clone */



__attribute__((section(".text.func_001C90B0")))
void func_001C90B0(void *a0) {
    if (ClearField5B4IfFlagUnset_1B76B0(a0))
        func_001B76D8(a0);
}

/* clone */


__attribute__((section(".text.func_001D5780")))
void func_001D5780(void *a0) { CustomIDWork_SetNumber((char *)a0 + 0x250); }

/* clone */


__attribute__((section(".text.func_001D6A30")))
void func_001D6A30(void *a0) { CustomIDWork_SetNumber((char *)a0 + 0xD74); }

/* clone */


__attribute__((section(".text.func_001D6A50")))
void func_001D6A50(void *a0) { CustomIDWork_SetNumber((char *)a0 + 0xE6C); }

/* clone */


__attribute__((section(".text.func_001D6BC0")))
int func_001D6BC0(void *a0, void *a1) {
    return SetFlagOnEntries7C_1D51B8(a0, 32, a1);
}

/* clone */


__attribute__((section(".text.func_001D6C70")))
int func_001D6C70(void *a0, void *a1) {
    return SetFlagOnEntries7C_1D51B8(a0, 31, a1);
}

/* clone */


__attribute__((section(".text.func_001DD180")))
void func_001DD180(void *a0) { cIDBase_release((char *)a0 + 0x10); }

/* clone */


__attribute__((section(".text.func_001DD1F8")))
void func_001DD1F8(void *a0) { cIDBase_trans((char *)a0 + 0x10); }

/* clone */


__attribute__((section(".text.func_001DD238")))
void func_001DD238(void *a0) { CustomIDWork_SetNumber((char *)a0 + 0x820); }

/* clone */


__attribute__((section(".text.func_001DEDA8")))
void func_001DEDA8(void *a0) { cIDBase_release((char *)a0 + 0x10); }
