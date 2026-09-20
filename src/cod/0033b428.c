/* cygnus-2.96 matched TU. */

typedef signed char Sint8;
typedef short Sint16;
typedef int Sint32;

typedef struct _sj_obj {
    struct _sj_vtbl *vtbl;
} SJ_OBJ, *SJ;

typedef struct sjx_obj {
    Sint8 used;
    Sint8 rsv;
    Sint16 xid;
    SJ sjsrc;
    SJ sjdst;
    Sint32 lin;
    void *iopsjx;
} SJX_OBJ, *SJX;

extern SJX_OBJ D_003E8DE8[32];
extern char D_00455E20[];


extern int DTX_CallUrpc(int cmd, void *in, int nin, void *out, int nout);
extern void func_003260C8();

__attribute__((section(".text.SJX_Create")))
SJX SJX_Create(SJ sjsrc, SJ sjdst, Sint32 lin)
{
    SJX sjx;
    Sint32 i;
    Sint32 buf[4];

    for (i = 0; i < 32; i++) {
        sjx = &D_003E8DE8[i];
        if (sjx->used == 0) {
            break;
        }
    }
    if (i == 32) {
        return 0;
    }
    func_003A52F0(sjx, 0, sizeof(SJX_OBJ));
    sjx->sjsrc = sjsrc;
    sjx->lin = lin;
    sjx->sjdst = sjdst;
    buf[0] = (Sint32)sjsrc;
    buf[1] = (Sint32)sjdst;
    buf[2] = lin;
    buf[3] = (Sint32)sjx;
    sjx->iopsjx = (void *)DTX_CallUrpc(0, buf, 4, buf, 1);
    if (sjx->iopsjx == 0) {
        func_003260C8(D_00455E20);
        return 0;
    }
    sjx->used = 1;
    return sjx;
}
