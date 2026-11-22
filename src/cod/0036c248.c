extern void *mpvlib_SearchFreeHn(void);
extern void func_0036C438(void *, int);
extern void *mpvlib_InitHn(void *);
extern int func_0036C670(void *);

__attribute__((section(".text.MPV_Create")))
void *MPV_Create(void)
{
    void *object = mpvlib_SearchFreeHn();
    if (object == 0)
        return 0;
    func_0036C438(object, 0x40C);
    object = mpvlib_InitHn(object);
    *(int *)((char *)object + 0x3B4) = func_0036C670(object);
    return object;
}
