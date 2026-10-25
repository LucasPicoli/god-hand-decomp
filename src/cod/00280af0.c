extern volatile int D_003C814C;
extern int D_003C80C8;
extern int SleepThread(void);
extern volatile int D_003C80FC;
extern int Obj33C8_GetShort_24(int a0);
extern int Obj33C8_GetField_28(int a0);
extern int Obj33C8_GetField_30(int a0);
extern int Obj33C8_GetField_34(int a0);
extern int Obj33C8_GetByte_D(int a0);
extern int Obj3270_Tramp_0033D040_7728(void);

__attribute__((section(".text.NoOp_280AF0")))
void NoOp_280AF0(void) {}

__attribute__((section(".text.NoOp_280B58")))
void NoOp_280B58(void) {}

__attribute__((section(".text.NoOp_282D68")))
void NoOp_282D68(void) {}

__attribute__((section(".text.NoOp_282E48")))
void NoOp_282E48(void) {}

__attribute__((section(".text.NoOp_282E50")))
void NoOp_282E50(void) {}

__attribute__((section(".text.NoOp_282EB8")))
void NoOp_282EB8(void) {}

__attribute__((section(".text.ClearBytes2F4To2F7_283170")))
void ClearBytes2F4To2F7_283170(char *a0) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 0;
    a0[0x2F6] = 0;
    a0[0x2F7] = 0;
}

__attribute__((section(".text.SetBytes2F4Mode1_283188")))
void SetBytes2F4Mode1_283188(char *a0, char a1) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 1;
    a0[0x2F6] = 0;
    a0[0x2F7] = a1;
}

__attribute__((section(".text.SetBytes2F4Mode2_2831B0")))
void SetBytes2F4Mode2_2831B0(char *a0, char a1) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 2;
    a0[0x2F6] = 0;
    a0[0x2F7] = a1;
}

__attribute__((section(".text.SetBytes2F4Mode4_283240")))
void SetBytes2F4Mode4_283240(char *a0) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 4;
    a0[0x2F6] = 0;
    a0[0x2F7] = 0;
}

__attribute__((section(".text.SetBytes2F4Mode5_283258")))
void SetBytes2F4Mode5_283258(char *a0) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 5;
    a0[0x2F6] = 0;
    a0[0x2F7] = 0;
}

__attribute__((section(".text.SetBytes2F4Mode7_283270")))
void SetBytes2F4Mode7_283270(char *a0, char a1) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 7;
    a0[0x2F6] = 0;
    a0[0x2F7] = a1;
}

__attribute__((section(".text.SetBytes2F4Mode8_283288")))
void SetBytes2F4Mode8_283288(char *a0, char a1) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 8;
    a0[0x2F6] = 0;
    a0[0x2F7] = a1;
}

__attribute__((section(".text.SetBytes2F4Mode11_283360")))
void SetBytes2F4Mode11_283360(char *a0, char a1) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 0xB;
    a0[0x2F6] = 0;
    a0[0x2F7] = a1;
}

__attribute__((section(".text.SetBytes2F4Mode10_2833C0")))
void SetBytes2F4Mode10_2833C0(char *a0, char a1) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 0xA;
    a0[0x2F6] = 0;
    a0[0x2F7] = a1;
}

__attribute__((section(".text.Forward33F130_3248D8")))
int Forward33F130_3248D8(int a0, int a1) { return func_0033F130(a1); }

__attribute__((section(".text.Forward335A18_324C78")))
int Forward335A18_324C78(int a0) { return func_00335A18(a0); }

__attribute__((section(".text.Forward324D88_324E70")))
int Forward324D88_324E70(void) { return func_00324D88(D_003C814C, D_003C80C8); }

__attribute__((section(".text.SleepThread_3252E0")))
void SleepThread_3252E0(void) { SleepThread(); }

extern int Forward33B568_33B658(void);
extern int Forward33B5C8_33B670(void);

__attribute__((section(".text.Forward33B658_325C60")))
void Forward33B658_325C60(void) { Forward33B568_33B658(); }

__attribute__((section(".text.Forward33B670_325C78")))
void Forward33B670_325C78(void) { Forward33B5C8_33B670(); }

__attribute__((section(".text.Forward325C98_325DC0")))
int Forward325C98_325DC0(int a0) { return func_00325C98(a0); }

__attribute__((section(".text.Forward33F690_325DD8")))
int Forward33F690_325DD8(int a0) { return func_0033F690(a0); }

__attribute__((section(".text.SetFlagAndForward_325EF8")))
void SetFlagAndForward_325EF8(void) {
  D_003C80FC = 1;
  SleepThread_3252E0();
}

__attribute__((section(".text.GetVia4_Obj33C8_GetShort_24_327800")))
int GetVia4_Obj33C8_GetShort_24_327800(char *a0) { return Obj33C8_GetShort_24(*(int*)(a0 + 4)); }

__attribute__((section(".text.GetVia4_Obj33C8_GetField_28_7818_327818")))
int GetVia4_Obj33C8_GetField_28_7818_327818(char *a0) { return Obj33C8_GetField_28(*(int*)(a0 + 4)); }

__attribute__((section(".text.GetVia4_Obj33C8_GetField_30_7860_327860")))
int GetVia4_Obj33C8_GetField_30_7860_327860(char *a0) { return Obj33C8_GetField_30(*(int*)(a0 + 4)); }

__attribute__((section(".text.GetVia4_Obj33C8_GetField_34_7878_327878")))
int GetVia4_Obj33C8_GetField_34_7878_327878(char *a0) { return Obj33C8_GetField_34(*(int*)(a0 + 4)); }

__attribute__((section(".text.GetVia4_Obj33C8_GetByte_D_327950")))
int GetVia4_Obj33C8_GetByte_D_327950(char *a0) { return Obj33C8_GetByte_D(*(int*)(a0 + 4)); }

__attribute__((section(".text.Forward33CFB8_327970")))
int Forward33CFB8_327970(int *a0) { return func_0033CFB8(a0[1]); }

extern void AdxbLoop_storeLoopInfo(int a0);

__attribute__((section(".text.Forward33CFF8_327988")))
void Forward33CFF8_327988(int *a0) { AdxbLoop_storeLoopInfo(a0[1]); }

__attribute__((section(".text.Forward330C88_328C58")))
int Forward330C88_328C58(void) { return func_00330C88(); }

__attribute__((section(".text.Forward326800_32B4C8")))
int Forward326800_32B4C8(int *a0) { return func_00326800(a0[1]); }

__attribute__((section(".text.Tramp_Obj3270_Tramp_0033D040_7728_32BB20")))
int Tramp_Obj3270_Tramp_0033D040_7728_32BB20(void) { return Obj3270_Tramp_0033D040_7728(); }

__attribute__((section(".text.Forward32BC98_32BD90")))
int Forward32BC98_32BD90(int a0, int a1) { return func_0032BC98(a0, a1, 0, 0xFFFFF); }

__attribute__((section(".text.Forward32D868_32DA08")))
int Forward32D868_32DA08(int a0, int a1, int a2) { return MwPly_openByName(a0, a1, a2, 0, 0xFFFFF); }

__attribute__((section(".text.ForwardField3ByOffset_32ED48")))
int ForwardField3ByOffset_32ED48(int *a0, int a1, int a2) { a0 += a1; return func_0032A9F0(a0[3], a2); }
