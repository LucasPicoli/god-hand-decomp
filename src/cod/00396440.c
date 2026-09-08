/* ee-2.9-991111 matched TU. */

typedef unsigned long u_long;
typedef struct { u_long r[5]; } sceGsDispEnv;
typedef struct { u_long r[2]; } sceGifTag;
typedef struct {
    sceGsDispEnv disp[2];
    sceGifTag    giftag0;
    unsigned char pad0[0x160];
    sceGifTag    giftag1;
} sceGsDBuffDc;
extern int sceGsPutDispEnv(sceGsDispEnv *disp);
extern int sceGsPutDrawEnv(sceGifTag *giftag);
__attribute__((section(".text.sceGsSwapDBuff")))
int sceGsSwapDBuff(sceGsDBuffDc *db, int id)
{
    int r;
    id = id & 1;
    sceGsPutDispEnv(&db->disp[id]);
    if (id) {
        r = sceGsPutDrawEnv(&db->giftag1);
    } else {
        r = sceGsPutDrawEnv(&db->giftag0);
    }
    return r;
}
