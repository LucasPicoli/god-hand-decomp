/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_002B2F38")))
int func_002B2F38(char *p)
{
    char *q;

    q = *(char **)(p + 0x8C);
    *(float *)(p + 0x6C) = (float)*(unsigned short *)(q + 2) / 100.0f;
    return 0;
}
