/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 candidate. */

extern void InitFields_1B6E90(void *);
extern int D_004275C8;

__attribute__((section(".text.func_001A7788")))
void *func_001A7788(unsigned char *a0)
{
    unsigned char *p;
    unsigned int i;

    InitFields_1B6E90(a0);
    *(int **)(a0 + 0x214) = &D_004275C8;
    p = a0 + 0x600;
    for (i = 0; i < 0x10; i++) {
        p[i] = 0xFF;
    }
    a0[0x611] = 0;
    a0[0x610] = 0;
    a0[0x612] = 0;
    a0[0x615] = 0;
    a0[0x614] = 0;
    return a0;
}
