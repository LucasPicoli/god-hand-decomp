/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libmpeg 3.0.2, error.o :: _sceMpegErrorBdec */

typedef unsigned int u_int;

extern char D_0045E610[];                     /* the error message */
extern void func_0039C390(void *m, const char *msg);   /* _sceMpegError */
struct cbp { int reason; int pad[7]; };
extern int  func_0039AB20(void *p, struct cbp *q);       /* _sceMpegDispatchMpegCallback */
extern int  func_003B63A0(void);                       /* DIntr */
extern int  func_003B63F0(void);                       /* EIntr */

__attribute__((section(".text._sceMpegErrorBdec")))
void _sceMpegErrorBdec(void *m)
{
    struct cbp cb;
    int oldstat;

    func_0039C390(m, D_0045E610);
    cb.reason = 2;
    func_0039AB20(*(void **)((char *)m + 0x868), &cb);
    *(volatile u_int *)0x10002010 = 0x40000000;
    cb.reason = 3;
    func_0039AB20(*(void **)((char *)m + 0x868), &cb);
    oldstat = func_003B63A0();
    *(volatile u_int *)0x1000F590 = *(volatile u_int *)0x1000F520 | 0x10000;
    *(volatile u_int *)0x1000B000 = 0;
    *(volatile u_int *)0x1000F590 = *(volatile u_int *)0x1000F520 & 0xFFFEFFFF;
    if (oldstat)
        func_003B63F0();
    *(volatile u_int *)0x1000B020 = 0;
}
