typedef void (*HandlerFn)(void *, unsigned int, unsigned int, unsigned int);

__attribute__((section(".text.SFXA_MakeAlp3110Tbl")))
void SFXA_MakeAlp3110Tbl(char *self, int unused, void *arg)
{
    unsigned char x = *(unsigned char *)(self + 0x14);
    unsigned char y = *(unsigned char *)(self + 0x15);
    unsigned char z = *(unsigned char *)(self + 0x16);
    HandlerFn fn = *(HandlerFn *)(self + 0x1C);

    if (fn != 0)
        fn(arg, x, y, z);
}

__attribute__((section(".text.SFXA_MakeAlp3211Tbl")))
void SFXA_MakeAlp3211Tbl(char *self, int unused, void *arg)
{
    unsigned char x = *(unsigned char *)(self + 0x14);
    unsigned char y = *(unsigned char *)(self + 0x15);
    unsigned char z = *(unsigned char *)(self + 0x16);
    HandlerFn fn = *(HandlerFn *)(self + 0x20);

    if (fn != 0)
        fn(arg, x, y, z);
}
