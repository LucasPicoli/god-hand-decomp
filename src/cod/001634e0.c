/* sn-2.95.3-136 matched TU. */

extern void func_00163598(char *);
extern void func_00163840(char *);

__attribute__((section(".text.func_001634E0")))
void func_001634E0(char *s)
{
    switch (s[0x5B]) {
    case 0:
        *(int *)(*(char **)(s + 0xE0) + 0x2C) |= 0x8000000;
        s[0x5C] = 0;
        *(unsigned char *)(s + 0x5B) += 1;
        break;
    case 1:
        if ((unsigned char)(*(unsigned char *)(s + 0xF0) + 1) < 2) {
            *(unsigned char *)(s + 0x5B) += 1;
        } else {
            func_00163598(s);
        }
        break;
    case 2:
        func_00163840(s);
        break;
    case 3:
        *(unsigned char *)(s + 0x5B) += 1;
        break;
    case 4:
        s[0x5B] = 0;
        *(unsigned char *)(s + 0x5A) += 1;
        break;
    }
}
