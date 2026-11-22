extern void Thunk_func_0033B658(void *);
extern int sfmpv_AddReadSub(int, int, int);
extern void Thunk_func_0033B670(void *);

__attribute__((section(".text.SFMPV_AddRead")))
int SFMPV_AddRead(int first, int second, int third)
{
    char guard[16];
    int result;
    Thunk_func_0033B658(guard);
    result = sfmpv_AddReadSub(first, second, third);
    Thunk_func_0033B670(guard);
    return result;
}
