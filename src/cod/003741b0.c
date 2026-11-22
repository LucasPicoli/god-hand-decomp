extern void ADXT_SetReloadTime(int, int, int, float);

__attribute__((section(".text.func_003741B0")))
void func_003741B0(int *self, float scale)
{
    int object = self[0];
    if (object == 0)
        return;
    if (scale == 0.0f)
        ADXT_SetReloadTime(object, self[4], self[3], 2.0f);
    else
        ADXT_SetReloadTime(object, self[4], self[3], scale);
}
