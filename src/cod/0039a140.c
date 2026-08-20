/* ee-2.9-991111 matched TU. */

extern void func_0039C3E8(int a0, int a1, int a2);
extern void func_003B1F28(char *fmt, ...);
extern char D_0045E490[];
extern char D_0045E4D0[];
extern char D_0045E510[];

/* ee-2.9-991111 matched TU. */










__attribute__((section(".text.func_0039A140")))
int func_0039A140(char *a0)
{
    char *s1;
    char *s0;
    int s2;
    int s3;

    s3 = 0;
    s2 = 1;
    s1 = a0;
    s0 = *(char **)(s1 + 0x40);
    *(int *)(s0 + 0x0) = 0;
    if ((*(int *)(s0 + 0xEC) & 0x3F) != 0) {
        func_0039C3E8((int)s0, (int)&D_0045E490, *(int *)(s0 + 0xEC));
        return -1;
    }
    if (*(int *)(s0 + 0x878) != 0) {
        func_003B1F28(D_0045E4D0);
        return -1;
    }
    *(int *)(s0 + 0x834) = 0;
    do {
        if (s3 != -1) {
            do {
                s2 = func_003A0E28(s0);
                if (s2 < 0) return -1;
                if (s2 == 0) break;
                if (*(int *)(s0 + 0x184) == *(int *)(s0 + 0xE8)) break;
            } while (*(int *)(s0 + 0x858) != 0);
        }
        switch (s2) {
        case 0:
            func_0039B810(s1);
            *(int *)(s0 + 0x0) = 1;
            break;
        case 1:
            *(int *)(s0 + 0xBC) = 0;
            *(int *)(s0 + 0xB8) = 0;
            *(int *)(s0 + 0xB4) = 0;
            s3 = func_0039AC10(s1, 0, *(int *)(s0 + 0xA8));
            *(int *)(s0 + 0xB4) = *(int *)(s0 + 0xB4) + 1;
            break;
        case 2:
            s3 = func_0039AC10(s1, *(int *)(s0 + 0xB8), *(int *)(s0 + 0xAC));
            *(int *)(s0 + 0xB8) = *(int *)(s0 + 0xB8) + 1;
            break;
        case 3:
        case 4:
            s3 = func_0039AC10(s1, *(int *)(s0 + 0xBC), *(int *)(s0 + 0xB0));
            *(int *)(s0 + 0xBC) = *(int *)(s0 + 0xBC) + 1;
            break;
        }
        if (*(int *)(s0 + 0x878) != 0) {
            func_003B1F28(D_0045E510);
            return -1;
        }
        if (*(int *)(s0 + 0x834) != 0) return 1;
    } while (*(int *)(s0 + 0x0) == 0);
    return 1;
}
