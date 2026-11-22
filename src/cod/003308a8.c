/* cygnus-2.96 matched TU. */

extern struct S003308A8 { int a_003308A8; int b; } D_00755D40[];

__attribute__((section(".text.allocCvFsHn")))
struct S003308A8 *allocCvFsHn(void)
{
    int i;

    for (i = 0; i < 0x28; i++) {
        if (D_00755D40[i].b == 0) {
            break;
        }
    }
    if (i == 0x28) {
        return 0;
    }
    return &D_00755D40[i];
}
