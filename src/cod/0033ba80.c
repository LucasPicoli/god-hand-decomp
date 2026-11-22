/* cygnus-2.96: func_0033BA80, register a callback in the [8][6] callback table; a null name
 * falls back to the default label. */
typedef struct {
    void *func;
    void *obj;
    void *name;
} CallbackEnt;

extern CallbackEnt D_00758620[8][6];
extern char D_00455F70[];
extern char D_00455F98[];
extern char D_00455FC0[];
extern char D_00455EF0[];
extern void SVM_CallErr1(const char *msg);

__attribute__((section(".text.func_0033BA80")))
void func_0033BA80(unsigned int grp, unsigned int no, void *func, void *obj, void *name)
{
    CallbackEnt *cb;

    if (no >= 6) {
        SVM_CallErr1(D_00455F70);
        return;
    }
    if (grp >= 8) {
        SVM_CallErr1(D_00455F98);
        return;
    }
    cb = &D_00758620[grp][no];
    if (cb->func != 0)
        SVM_CallErr1(D_00455FC0);
    cb->func = func;
    cb->obj = obj;
    if (name != 0)
        cb->name = name;
    else
        cb->name = D_00455EF0;
}
