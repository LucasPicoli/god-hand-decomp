/* ee-2.9-991111 matched TU. */

extern int GetMemorySize(void);
extern int InitTLB(void);


__attribute__((section(".text.func_003B7C18")))
int func_003B7C18(void)
{
    if (GetMemorySize() == 0x2000000) {
        return func_003B7C58();
    }
    return InitTLB();
}
