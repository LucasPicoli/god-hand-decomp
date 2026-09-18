/* cygnus-2.96 matched TU. */

/* cygnus-2.96. Twin of the matched func_0035DE38 in src/cod/00323618.c:
   same shape, offset 0x80 instead of 0xB0, and an int field instead of a byte. */

extern int isEffectiveVer();

typedef struct {
    int dummy;
    int *pVer;
} CGObj_t_0035DC08;

typedef struct {
    int word0;
    int word4;
    int word8;
    int wordC;
} CVerData_t_0035DC08;

__attribute__((section(".text.func_0035DC10")))
int func_0035DC10(CGObj_t_0035DC08 *a0, int *a1)
{
    CVerData_t_0035DC08 *s0;
    int v0;

    *a1 = 0;
    s0 = (CVerData_t_0035DC08 *)((char *)a0->pVer + 0x80);
    v0 = isEffectiveVer(a0);
    if (!v0) {
        return 0;
    }
    *a1 = s0->word0;
    return 1;
}
