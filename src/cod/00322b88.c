/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */



__attribute__((section(".text.func_00322BD8")))
int func_00322BD8(int a0, int a1, int a2, int a3, int t0, int t1) {
    return func_00322C68(a0, a1, a2, 0, 0, 0, 0xFFFFF, a3, t0, t1, 0);
}

/* cygnus-2.96 matched TU. */



__attribute__((section(".text.func_00322B88")))
int func_00322B88(int a0, int a1, int a2, int a3, int t0, int t1) {
    return func_00322C68(a0, 0, 0, a1, a2, 0, 0xFFFFF, a3, t0, t1, 0);
}

/* cygnus-2.96 matched TU — CRI libadxe, recovered from recvx-decomp (CC0). */

typedef signed int Sint32;
typedef unsigned int Uint32;
extern Sint32 D_007561C0[];   /* dtx_sbuf */
extern char   D_003D8D40;     /* dtx_cd (sceSifClientData; pass &) */
extern Sint32 D_007562C0[];   /* dtx_rbuf */
extern void func_003B3128(void *cd, int rno, int mode, void *sbuf, int ssize,
                          void *rbuf, int rsize, void *efunc, void *epara);  /* sceSifCallRpc */

__attribute__((section(".text.dtx_create_rmt")))
Sint32 dtx_create_rmt(Sint32 a, Sint32 b, Sint32 c, Sint32 d) {
    D_007561C0[0] = a;
    D_007561C0[1] = b;
    D_007561C0[2] = c;
    D_007561C0[3] = d;
    func_003B3128(&D_003D8D40, 2, 0, D_007561C0, sizeof(Sint32) * 4, D_007562C0, sizeof(Sint32), 0, 0);
    return D_007562C0[0];
}
