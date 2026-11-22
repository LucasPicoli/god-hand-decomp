extern void *func_00348938(void *);

__attribute__((section(".text.MWSST_DestroyCoreHn")))
void MWSST_DestroyCoreHn(void *key, void *argument)
{
    void *object;
    void (*method)(void *);
    object = func_00348938(key);
    if (argument == 0)
        return;
    if (object == 0)
        return;
    method = *(void (**)(void *))((char *)object + 0x10);
    if (method == 0)
        return;
    method(argument);
}
