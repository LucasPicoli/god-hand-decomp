/* sn-2.95.3-136 matched TU. */

extern char D_00583EC0[];
extern void func_001FFEB8();
extern void func_001FFF30();
extern void func_0016B1F8();
extern void *D_005FEC68;
extern void func_002BE560(void *, int);
extern void *D_003C3CF0;
extern int EnsureInitThenForward_2A9538_30EE08(void *, int, void *);
extern void *D_003FA62C;
extern void func_003A9498(void *, int, void *);
extern void func_003B5E78(int, int, int, void *, int);
extern void MtxInitRotVec(void *, int, int);
extern void Tramp_func_0030A2B0_001508D8(int, void *, int);

__attribute__((section(".text.cScenario_beginRoomJump_2C4548")))
void cScenario_beginRoomJump_2C4548(int a0, unsigned short a1, int a2, unsigned char a3,
                                  int a4, unsigned char a5)
{
    func_001FFEB8(D_00583EC0, a1, a2, a3, a4, a5);
}

__attribute__((section(".text.cScenario_beginRoomJumpForce")))
void cScenario_beginRoomJumpForce(int a0, unsigned short a1, int a2, unsigned char a3,
                                  int a4, unsigned char a5)
{
    func_001FFF30(D_00583EC0, a1, a2, a3, a4, a5);
}

__attribute__((section(".text.func_0016BC78")))
void func_0016BC78(void *a0) { func_0016B1F8(a0, D_005FEC68); }

__attribute__((section(".text.func_002ACCD8")))
int func_002ACCD8(void *a0) { return func_003A52F0(a0, 0, 0x100); }

__attribute__((section(".text.func_002BE838")))
void func_002BE838(void *a0, int a1, int a2) { func_002BE560((char *)a0 + a2 * 8, a1); }

__attribute__((section(".text.func_002D3220")))
int func_002D3220(void *a0) { return func_003A52F0(a0, 0, 0xC0); }

__attribute__((section(".text.func_0031C8B8")))
void func_0031C8B8(void *a0, int a1) { EnsureInitThenForward_2A9538_30EE08(a0, a1, D_003C3CF0); }

__attribute__((section(".text.func_003A9470")))
void func_003A9470(void *a0, int a1) { func_003A9498(a0, a1, (char *)D_003FA62C + 0x5C); }

__attribute__((section(".text.func_003B60A0")))
void func_003B60A0(int a0, int a1, int a2)
{
    char buf[0x10];
    func_003B5E78(a0, a1, a2, buf, 0);
}

struct buf_00147B60 { char b[0x40]; };
__attribute__((section(".text.VecRotVec")))
void VecRotVec(int a0, int a1, int a2, int a3)
{
    struct buf_00147B60 buf;
    MtxInitRotVec(&buf, a2, a3 & 0xFF);
    Tramp_func_0030A2B0_001508D8(a0, &buf, a1);
}
