/* sn-2.95.3-136 matched TU. */

/* compiler: sn-2.95.3-136 ; extra keys: as: "sn" */
__attribute__((section(".text.func_001509A0")))
void func_001509A0(char *base)
{
    char *q;
    int i;

    *(int *)(base + 0x3C) = 0;
    q = base + 0x3BF80;
    i = 0x280;
    do {
        *(unsigned long *)(q - 0x40) = 0x70000002;
        *(int *)(q - 0x38) = 0;
        *(int *)(q - 0x34) = 0x50000002;
        *(unsigned long *)(q - 0x30) = 0x1000000000008001UL;
        *(unsigned long *)(q - 0x28) = 0xE;
        *(unsigned long *)(q - 0x20) = 0xFF;
        *(unsigned long *)(q - 0x18) = 0x3F;
        *(int *)(q - 0xB8) = 0x11000000;
        *(unsigned long *)(q - 0x98) = 0x50;
        *(unsigned long *)(q - 0x90) = 0;
        *(unsigned long *)(q - 0x88) = 0x51;
        *(unsigned long *)(q - 0x78) = 0x52;
        *(unsigned long *)(q - 0xB0) = 0x1000000000008004UL;
        *(unsigned long *)(q - 0xA8) = 0xE;
        *(unsigned long *)(q - 0x70) = 0;
        *(unsigned long *)(q - 0x68) = 0x53;
        *(unsigned long *)(q - 0x58) = 0;
        *(int *)(q - 0x48) = 0;
        *(unsigned long *)(q + 0x80) = 0x70000002;
        *(int *)(q + 0x88) = 0;
        *(int *)(q + 0x8C) = 0x50000002;
        *(unsigned long *)(q + 0x90) = 0x1000000000008001UL;
        *(unsigned long *)(q + 0x98) = 0xE;
        *(unsigned long *)(q + 0xA0) = 0xFF;
        *(unsigned long *)(q + 0xA8) = 0x3F;
        *(int *)(q + 0x8) = 0x11000000;
        *(unsigned long *)(q + 0x28) = 0x50;
        *(unsigned long *)(q + 0x30) = 0;
        *(unsigned long *)(q + 0x38) = 0x51;
        *(unsigned long *)(q + 0x48) = 0x52;
        *(unsigned long *)(q + 0x10) = 0x1000000000008004UL;
        *(unsigned long *)(q + 0x18) = 0xE;
        *(unsigned long *)(q + 0x50) = 0;
        *(unsigned long *)(q + 0x58) = 0x53;
        *(unsigned long *)(q + 0x68) = 0;
        *(int *)(q + 0x78) = 0;
        q -= 0x180;
    } while (--i);
}
