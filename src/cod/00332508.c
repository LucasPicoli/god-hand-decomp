/* cygnus-2.96 matched TU. */

/* DTX: the CRI EE-to-IOP data-transfer client. */

/* Only the field DTX_Init reads; the rest of sceSifClientData is padding here. */
typedef struct {
    char unk00[0x24];
    void *serve;                    /* 0x24 non-zero once the IOP server answered the bind */
} DtxClient;

extern int D_003D84BC;              /* dtx_init_cnt */
extern unsigned int D_003D84A4;     /* the DTX RPC server id */
extern DtxClient D_003D8D40;        /* dtx_clnt */
extern char D_00454270[];           /* "DTX_Init: sceSifBindRpc failed" style message */
extern int sceSifBindRpc(void *cd, unsigned int sid, int mode);
extern void func_003260C8(char *msg);

/* Bind the DTX RPC client on the first call, spinning until the IOP server
 * answers; count every call. A failed bind reports and hangs. */
__attribute__((section(".text.DTX_Init")))
void DTX_Init(void)
{
    int i;
    int end;                        /* the delay loop runs i down to this; a local, so the -1 is set before i */

    if (D_003D84BC == 0) {
        for (;;) {
            if (sceSifBindRpc(&D_003D8D40, D_003D84A4, 0) < 0) {
                func_003260C8(D_00454270);
                for (;;) ;
            }
            if (D_003D8D40.serve != 0) break;
            end = -1;
            for (i = 0xFFFF; i != end; i -= 4) ;
        }
    }
    D_003D84BC++;
}
