/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_001D4918")))
int func_001D4918(char *p)
{
    char *a;
    char *b;
    int va;
    int vb;

    if (*(unsigned short *)(p + 0x17FE) != 2) {
        return 0;
    }
    a = *(char **)(*(char **)(p + 0x17E8));
    b = *(char **)(*(char **)(p + 0x17EC));
    va = *(int *)(a + 0x604);
    vb = *(int *)(b + 0x604);
    if (va == 0) {
        if ((unsigned int)(vb - 9) < 4) {
            goto ret1;
        }
    }
    if (vb != 0) {
        goto ret0;
    }
    if ((unsigned int)(va - 9) >= 4) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}

__attribute__((section(".text.func_001FC210")))
int func_001FC210(void **pp)
{
    unsigned char *p;
    char i;

    p = (unsigned char *)*pp;
    if (p == 0) {
        return -1;
    }
    for (i = 0; i < 10; i++) {
        if (*((unsigned char *)*pp + i + 0x98) == 0x1F) {
            break;
        }
    }
    if (i == 10) {
        return -1;
    }
    return i;
}
