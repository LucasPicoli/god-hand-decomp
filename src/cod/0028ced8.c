/* sn-2.95.3-136 matched TU. */

extern int AddActiveEntry_1FECE0(void *a0, int a1, int a2);
extern char D_005864E0[];

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_0028CED8")))
void func_0028CED8(void *a0) {
    char *s1 = (char *)a0;
    switch (*(int *)(s1 + 0x564)) {
    case 0x279: {
        int v = *(int *)(s1 + 0x304);
        AddActiveEntry_1FECE0(D_005864E0, 0x27A, *(int *)(v + 0x6C) + v);
    }
    /* fallthrough */
    case 0x252: {
        int v = *(int *)(s1 + 0x304);
        AddActiveEntry_1FECE0(D_005864E0, 0x253, *(int *)(v + 0x5C) + v);
        {
            int w = *(int *)(s1 + 0x304);
            AddActiveEntry_1FECE0(D_005864E0, 0x369, *(int *)(w + 0x60) + w);
        }
        break;
    }
    case 0x256: {
        int v = *(int *)(s1 + 0x304);
        AddActiveEntry_1FECE0(D_005864E0, 0x257, *(int *)(v + 0x58) + v);
        break;
    }
    case 0x21E: {
        int v = *(int *)(s1 + 0x304);
        AddActiveEntry_1FECE0(D_005864E0, 0x36C, *(int *)(v + 0x70) + v);
        break;
    }
    case 0x213:
    case 0x217: {
        int v = *(int *)(s1 + 0x304);
        AddActiveEntry_1FECE0(D_005864E0, 0x36F, *(int *)(v + 0x64) + v);
        {
            int w = *(int *)(s1 + 0x304);
            AddActiveEntry_1FECE0(D_005864E0, 0x37A, *(int *)(w + 0x64) + w);
        }
        break;
    }
    case 0x22F: {
        int v = *(int *)(s1 + 0x304);
        AddActiveEntry_1FECE0(D_005864E0, 0x370, *(int *)(v + 0x74) + v);
        break;
    }
    case 0x21B: {
        int v = *(int *)(s1 + 0x304);
        AddActiveEntry_1FECE0(D_005864E0, 0x37F, *(int *)(v + 0x78) + v);
        break;
    }
    case 0x22D: {
        int v = *(int *)(s1 + 0x304);
        AddActiveEntry_1FECE0(D_005864E0, 0x37F, *(int *)(v + 0x78) + v);
        break;
    }
    case 0x208:
    case 0x20A:
    case 0x20C:
    case 0x20E:
    case 0x210:
    case 0x215:
    default:
        break;
    }
}
