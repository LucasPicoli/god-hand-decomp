extern int D_00747A80;
extern int cModel_isClip(void *);

__attribute__((section(".text.func_001020F0")))
int func_001020F0(void *p)
{
    if (D_00747A80 < 0)
        return 1;
    return cModel_isClip(p) != 0;
}
