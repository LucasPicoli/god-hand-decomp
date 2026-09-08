/* ee-2.9-991111 matched TU. */

typedef struct {
    unsigned char pad00[0x1C];
    char *fpacket;      /* 0x1C */
    int   fpacket_max;  /* 0x20 */
} sceSifRpcServerData;



__attribute__((section(".text._sceRpcGetFPacket2")))
void *_sceRpcGetFPacket2(sceSifRpcServerData *q, int i)
{
    if (i < 0 || i >= q->fpacket_max) {
        return func_003B2B90(q);
    }
    return q->fpacket + i * 64;
}
