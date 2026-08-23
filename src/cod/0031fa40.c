/* cygnus-2.96 matched TU. */

extern char D_004511A8[];

/* cygnus-2.96 */


__attribute__((section(".text.__rtti_attr")))
void __rtti_attr(char *p, int a, int b, int c)
{
    if (p != 0) {
        *(int *)(p + 0x0) = a;
        *(char **)(p + 0x4) = D_004511A8;
        *(int *)(p + 0x8) = c;
        *(int *)(p + 0xC) = b;
    }
}
