typedef struct {
    int v[7];
} SfdIfInfo;

typedef struct SfdIf SfdIf;
typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void (*fC)(SfdIf *);
} SfdIfVtbl;
struct SfdIf {
    SfdIfVtbl *vt;
};

typedef struct {
    int handle;
    SfdIf *iface;
    SfdIfInfo info;
} SfdIfReq;

typedef struct {
    char pad[0x2004];
    SfdIfReq *req;
} SfdIfObj;

extern SfdIfInfo D_00760D90;
extern int ReturnK_003EE2BC_00358A38_358A38(void);
extern int func_0034B270(int);
extern int func_0034B2C8(SfdIfObj *);
extern int Obj0000_Set_D_003EE2C0_34B290(int);
extern void IntrNest_leave(void);

__attribute__((section(".text.func_0034B198")))
int func_0034B198(SfdIfObj *o)
{
    SfdIfReq *r = o->req;
    int h = r->handle;
    SfdIf *iface = r->iface;

    if (h == 0) {
        return 0;
    }
    D_00760D90 = r->info;
    if (ReturnK_003EE2BC_00358A38_358A38() != 1) {
        h = func_0034B270(h);
    } else {
        func_0034B2C8(o);
        h = Obj0000_Set_D_003EE2C0_34B290(h);
    }
    iface->vt->fC(iface);
    IntrNest_leave();
    return h;
}
