/* cygnus-2.96: M2VHDEC_InitHn, clear the 0x4D0-byte work area at +0x160 and set its defaults. */
extern void *func_003A52F0(void *dst, int c, int n);

__attribute__((section(".text.M2VHDEC_InitHn")))
void M2VHDEC_InitHn(char *self)
{
    char *w = self + 0x160;

    func_003A52F0(w, 0, 0x4D0);
    *(int *)(w + 0x4C) = 1;
    *(int *)(w + 0x70) = 0;
    *(int *)(w + 0x74) = 0xFF;
    *(int *)(w + 0x78) = 0xFF;
    *(int *)(w + 0x40C) = 0;
    *(int *)(w + 0x410) = 0;
    *(int *)(w + 0x414) = 0;
    *(int *)(w + 0x418) = 0;
    *(int *)(w + 0x41C) = 0;
    *(int *)(w + 0x420) = 0;
    *(int *)(w + 0x428) = 0;
    *(int *)(w + 0x3C8) = 0;
    *(int *)(w + 0x49C) = 0;
    *(int *)(w + 0x4A0) = 0;
    *(int *)(w + 0x4B0) = 0;
    *(int *)(w + 0xD0) = 0;
    *(int *)(w + 0xD4) = 1;
    *(int *)(w + 0x7C) = 0xFF;
    *(int *)(w + 0x4C0) = 0;
}
