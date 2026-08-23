/* ee-2.9-991111 matched TU. */

extern int D_003F8580[];

/* ee-2.9-991111 */


__attribute__((section(".text.func_00397100")))
int func_00397100(unsigned int i)
{
    if (i < 0xA) {
        return *(int *)(i * 4 + (int)&D_003F8580[4]);
    }
    return 0;
}
