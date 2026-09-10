/* cygnus-2.96 matched TU. */

struct SVM { void (*fn)(int); int arg; };
extern struct SVM D_00758860[];
extern void Forward33B568_33B658(void);
extern void Forward33B5C8_33B670(void);

__attribute__((section(".text.SVM_SetCbBdr")))
void SVM_SetCbBdr(int i, void (*fn)(int), int arg)
{
    Forward33B568_33B658();
    *(void (**)(int))(i * 8 + (int)D_00758860) = fn;
    D_00758860[i].arg = arg;
    Forward33B5C8_33B670();
}
