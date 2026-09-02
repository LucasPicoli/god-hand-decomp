/* ee-2.9-991111 matched TU. */

extern void func_003B2E38(void *p);
extern void func_003B7898(int a, void (*f)(void *), void *p);

typedef struct {
    int pad00[2];
    int f08;              /* 0x08 */
} sceSifServeHdr;

typedef struct {
    int   pad00[5];
    int   f14;            /* 0x14 */
    int   pad18;
    int   f1C;            /* 0x1C */
    int   f20;            /* 0x20 */
    int   f24;            /* 0x24 */
    int   f28;            /* 0x28 */
} sceSifRpcPkt;



extern int isceSifSendCmd(unsigned int fid, void *pkt, int size,
                          void *src, void *dest, int len);



__attribute__((section(".text.func_003B2E78")))
void func_003B2E78(sceSifRpcPkt *cd, void *q)
{
    sceSifRpcPkt *p;
    sceSifServeHdr *sd;

    p = func_003B2B90(q);
    {
        int t1 = cd->f14;
        int t2 = cd->f1C;
        p->f14 = t1;
        p->f1C = t2;
    }
    p->f20 = 0x80000009;
    sd = func_003B2DE8(cd->f20, q);
    if (sd == 0) {
        p->f24 = 0;
        p->f28 = 0;
    } else {
        p->f24 = (int)sd;
        p->f28 = sd->f08;
    }
    if (isceSifSendCmd(0x80000008, p, 0x40, 0, 0, 0) == 0) {
        func_003B7898(0x800, func_003B2E38, p);
    }
}
