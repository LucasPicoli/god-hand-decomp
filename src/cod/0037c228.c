extern void func_0037C6A0(void *slot);
extern void SndMix_calcVoiceLevel(void *slot);

__attribute__((section(".text.func_0037C228")))
void func_0037C228(char *dst, char *src)
{
    *(short *)(dst + 0x30) = 0x7F00;
    *(short *)(dst + 0x32) = 0;
    *(short *)(dst + 0x34) = 0;
    *(short *)(dst + 0x36) = 0;
    *(short *)(dst + 0x38) = *(unsigned short *)(src + 0x30);
    *(short *)(dst + 0x3A) = *(unsigned short *)(src + 0x32);
    if (src[0xD] & 8)
        func_0037C6A0(dst);
    *(short *)(dst + 0x26) = *(unsigned short *)(src + 0x18);
    *(short *)(dst + 0x28) = *(unsigned short *)(src + 0x1A);
    SndMix_calcVoiceLevel(dst);
}
