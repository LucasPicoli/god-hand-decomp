/* cygnus-2.96: drops one reference and calls the release hook when the count reaches zero. */
typedef struct RefObj {
    int f00;
    void (*release)(struct RefObj *o);
} RefObj;

typedef struct {
    int f00;
    int refs;
} RefCount;

extern RefCount *Obj0000_Get_Ptr_D_003EE088_Scaled_8_348920(void *key);
extern RefObj *func_00348938(void *key);

__attribute__((section(".text.MWSST_Finish")))
void MWSST_Finish(void *key)
{
    RefCount *r = Obj0000_Get_Ptr_D_003EE088_Scaled_8_348920(key);
    RefObj *o = func_00348938(key);

    if (o != 0 && r->refs != 0) {
        if (--r->refs == 0) {
            if (o->release != 0) {
                o->release(o);
            }
        }
    }
}
