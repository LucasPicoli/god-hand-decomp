/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_0014B730")))
void *func_0014B730(char *obj, char *name)
{
    long key;
    int i;
    char *n;
    char *p;

    key = 0;
    i = 0;
    if (*name != 0) {
        do {
            key = key | ((long)*name << (i * 8));
            i = i + 1;
            name = name + 1;
            if (i >= 8) {
                break;
            }
        } while (*name != 0);
    }
    n = *(char **)(obj + 0x25C);
    while (n != 0) {
        p = *(char **)(n + 0x414);
        if (*(long *)(p + 8) == key) {
            break;
        }
        n = *(char **)(n + 0x404);
    }
    return n;
}

__attribute__((section(".text.cCoreSave_SetFightingRingClearFlag")))
void cCoreSave_SetFightingRingClearFlag(char *obj, unsigned int bit, int set)
{
    unsigned int w;

    obj = *(char **)obj;
    if (obj == 0) return;
    w = bit >> 5;
    if (w >= 4) return;
    bit = bit & 0x1F;
    w = w * 4;
    if (set) {
        obj = obj + 0xB98;
        obj = obj + w;
        do { } while (0);
        *(unsigned int *)obj = *(unsigned int *)obj | (1 << bit);
    } else {
        obj = obj + 0xB98;
        obj = obj + w;
        do { } while (0);
        *(unsigned int *)obj = *(unsigned int *)obj & ~(1 << bit);
    }
}

__attribute__((section(".text.func_0027DC50")))
void func_0027DC50(char *obj, unsigned int mode)
{
    switch (mode) {
    case 0:
    default:
        obj[0x2F4] = 0;
        obj[0x2F5] = 8;
        obj[0x2F6] = 0;
        obj[0x2F7] = 0;
        break;
    case 1:
        obj[0x2F4] = 0;
        obj[0x2F5] = 8;
        obj[0x2F6] = 2;
        obj[0x2F7] = 0;
        break;
    case 2:
        obj[0x2F4] = 0;
        obj[0x2F5] = 8;
        obj[0x2F6] = 4;
        obj[0x2F7] = 0;
        break;
    case 3:
        obj[0x2F4] = 0;
        obj[0x2F5] = 8;
        obj[0x2F6] = 6;
        obj[0x2F7] = 0;
        break;
    }
}

__attribute__((section(".text.func_002832F8")))
void func_002832F8(char *obj, unsigned int mode)
{
    switch (mode) {
    case 0:
    default:
        obj[0x2F4] = 0;
        obj[0x2F5] = 9;
        obj[0x2F6] = 0;
        obj[0x2F7] = 0;
        break;
    case 1:
        obj[0x2F4] = 0;
        obj[0x2F5] = 9;
        obj[0x2F6] = 2;
        obj[0x2F7] = 0;
        break;
    case 2:
        obj[0x2F4] = 0;
        obj[0x2F5] = 9;
        obj[0x2F6] = 4;
        obj[0x2F7] = 0;
        break;
    case 3:
        obj[0x2F4] = 0;
        obj[0x2F5] = 9;
        obj[0x2F6] = 6;
        obj[0x2F7] = 0;
        break;
    }
}
