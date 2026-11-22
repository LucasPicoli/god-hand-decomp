/* cygnus-2.96 */

extern void func_00348E18(void *);
extern void mwsfsvr_StartSfd(void *);

__attribute__((section(".text.mwsfsvr_StartPlayback")))
void mwsfsvr_StartPlayback(char *object)
{
    int *state = (int *)(object + 0x2A4);
    if (*(int *)(object + 0x284) == 1 || *state == 1)
        func_00348E18(object);
    else
        mwsfsvr_StartSfd(object);
}
