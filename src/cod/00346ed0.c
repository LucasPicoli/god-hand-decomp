/* cygnus-2.96: mwsfsfx_SetYcc420plnInfToSfx, fills the request's picture planes: one plane, or Y/U/V (half height chroma) for fmt 3. */
typedef struct {
    int buf;
    int unk4;
    int fmt;
    int width;
    int height;
} PicFrm;

typedef struct {
    int ptr;
    int pitch;
    int lines;
    int pad;
} PicPlane;

typedef struct {
    int unk0;
    PicPlane plane[3];
    char unk34[0x10];
    int width;
    int height;
} PicReq;

typedef struct {
    int ptr[3];
    int pitch[3];
} YccPlane;

extern void mwPlyCalcYccPlane(int buf, int width, int height, YccPlane *out);
extern void func_00346FB0(PicPlane *pl, int ptr, int pitch, int lines);

__attribute__((section(".text.mwsfsfx_SetYcc420plnInfToSfx")))
void mwsfsfx_SetYcc420plnInfToSfx(PicFrm *frm, PicReq *req)
{
    YccPlane ycc;
    int w = frm->width;
    int h = frm->height;
    int fmt = frm->fmt;
    int hh;

    req->width = w;
    req->height = h;
    if (fmt != 3) {
        func_00346FB0(&req->plane[0], frm->buf, w, h);
        return;
    }
    mwPlyCalcYccPlane(frm->buf, w, h, &ycc);
    func_00346FB0(&req->plane[0], ycc.ptr[0], ycc.pitch[0], h);
    hh = h / 2;
    func_00346FB0(&req->plane[1], ycc.ptr[1], ycc.pitch[1], hh);
    func_00346FB0(&req->plane[2], ycc.ptr[2], ycc.pitch[2], hh);
}
