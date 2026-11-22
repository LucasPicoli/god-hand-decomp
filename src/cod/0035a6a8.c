/* cygnus-2.96 matched TU. */

extern void sftim_CntupHnVbIn(void *p);
extern int GetArrayElemA0C_35A1C8(void *p, int idx);
extern void sftim_UpdateTime(void *p);

__attribute__((section(".text.sftim_HnVbIn")))
void sftim_HnVbIn(void *p)
{
    sftim_CntupHnVbIn(p);
    if (GetArrayElemA0C_35A1C8(p, 0x47) != 1) return;
    sftim_UpdateTime(p);
}
