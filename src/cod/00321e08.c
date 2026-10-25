/* ee-2.9-991111: func_00321E08, libgcc frame.c frame_init: counts the object's FDEs, sorts them
 * into a single array and records the covered pc range. */
typedef struct Fde Fde;

typedef struct FrameObject {
    void *pc_begin;                     /* 0x00 */
    void *pc_end;                       /* 0x04 */
    Fde *fde_begin;               /* 0x08 */
    Fde **fde_array;              /* 0x0C */
    unsigned int count;                 /* 0x10 */
} FrameObject;

typedef struct FdeVector {
    Fde **array;
    unsigned int count;
} FdeVector;

typedef struct FdeAccumulator {
    FdeVector linear;
    FdeVector erratic;
} FdeAccumulator;

extern void *func_003A7C70(unsigned int n);
extern unsigned int func_00321D38(Fde *f);
extern void func_00321D80(Fde *f, FdeAccumulator *accu, void **beg_ptr, void **end_ptr);
extern Fde **end_fde_sort(FdeAccumulator *accu, unsigned int count);

static inline void start_fde_sort(FdeAccumulator *accu, unsigned int count)
{
    accu->linear.array = (Fde **)func_003A7C70(sizeof(Fde *) * count);
    accu->erratic.array = (Fde **)func_003A7C70(sizeof(Fde *) * count);
    accu->linear.count = 0;
    accu->erratic.count = 0;
}

__attribute__((section(".text.func_00321E08")))
void func_00321E08(FrameObject *ob)
{
    unsigned int count;
    FdeAccumulator accu;
    void *pc_begin, *pc_end;

    if (ob->fde_array) {
        Fde **p = ob->fde_array;
        for (count = 0; *p; ++p)
            count += func_00321D38(*p);
    } else
        count = func_00321D38(ob->fde_begin);

    ob->count = count;

    start_fde_sort(&accu, count);
    pc_begin = (void *)(unsigned int)-1;
    pc_end = 0;

    if (ob->fde_array) {
        Fde **p = ob->fde_array;
        for (; *p; ++p)
            func_00321D80(*p, &accu, &pc_begin, &pc_end);
    } else
        func_00321D80(ob->fde_begin, &accu, &pc_begin, &pc_end);

    ob->fde_array = end_fde_sort(&accu, count);
    ob->pc_begin = pc_begin;
    ob->pc_end = pc_end;
}
