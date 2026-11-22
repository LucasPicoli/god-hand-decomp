/* cygnus-2.96: AC3LINK_DetachAc3, shuts the stream's decoder down (under the lock) and resets the object. */
extern void ADXT_Stop(char *obj);
extern void Forward33B658_325C60(void);
extern void AC3CNV_Stop(int dec);
extern void AC3CNV_Destroy(int dec);
extern void Forward33B670_325C78(void);
extern void Obj3260_TrampVia0C_00337B30_D220(char *obj, int a1);
extern void Obj3260_TrampVia0C_00337BC8_D250(char *obj);
extern void AC3CNV_Finish(void);

__attribute__((section(".text.AC3LINK_DetachAc3")))
void AC3LINK_DetachAc3(char *obj)
{
    char *st;
    int dec;

    ADXT_Stop(obj);
    st = *(char **)(*(char **)(obj + 4) + 4);
    dec = *(int *)(st + 0xC0);
    if (dec == 0)
        return;
    Forward33B658_325C60();
    AC3CNV_Stop(dec);
    AC3CNV_Destroy(dec);
    *(int *)(st + 0xC0) = 0;
    Forward33B670_325C78();
    Obj3260_TrampVia0C_00337B30_D220(obj, 0);
    Obj3260_TrampVia0C_00337BC8_D250(obj);
    AC3CNV_Finish();
}
