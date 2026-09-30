/* sn-2.95.3-136 matched TU. */

extern void func_002E0DE8();
extern int GetSoundEntryStatus_375EF8();
extern char D_0045BD90[], D_0045BDA0[], D_0045BDA8[], D_0045BDB8[], D_0045BDE8[];

__attribute__((section(".text.func_0037B518")))
void func_0037B518(unsigned char *a0)
{
    int st;
    func_002E0DE8(3, 4, 8, D_0045BD90);
    st = GetSoundEntryStatus_375EF8(*(int *)(a0 + 0xC));
    if (st == 0) {
        func_002E0DE8(0xC, 4, 0xF, D_0045BDA0);
        return;
    }
    if (st & 1)
        func_002E0DE8(0xC, 4, 0xD, D_0045BDA8);
    if (st & 2)
        func_002E0DE8(0xC, 4, 0xC, D_0045BDB8);
    if (st & 4)
        func_002E0DE8(0x10, 4, 0xD, D_0045BDE8);
}
