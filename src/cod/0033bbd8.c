/* cygnus-2.96 matched TU. */

struct SVM { void (*fn)(int); int arg; };
extern struct SVM D_00758860[];

__attribute__((section(".text.SVM_GotoSvrBorder")))
void SVM_GotoSvrBorder(int i)
{
    void (*fn)(int);
    fn = *(void (**)(int))(i * 8 + (int)D_00758860);
    if (fn != 0) fn(D_00758860[i].arg);
}
