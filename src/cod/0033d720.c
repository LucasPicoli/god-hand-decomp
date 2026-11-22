/* cygnus-2.96: ADXB decode step: report the parsed header and set up the decoder, then at the end of
 * the data apply the replay hook, flush and call the end callback. */
typedef struct AdxDec {
    char pad0[0x10];
    int n;              /* 0x10 */
    char pad14[0xC];
    short *a;           /* 0x20 */
    short *b;           /* 0x24 */
} AdxDec;

typedef struct AdxbObj AdxbObj;

struct AdxbObj {
    char pad0[4];
    int stat;                                           /* 0x04 */
    AdxDec *dec;                                     /* 0x08 */
    char pad0C[0x68 - 0x0C];
    int hdr68;                                          /* 0x68 */
    int hdr6C;                                          /* 0x6C */
    int hdr70;                                          /* 0x70 */
    char pad74[4];
    int (*hdrcb)(int obj, int *a, int *b, int *c);      /* 0x78 */
    int hdrobj;                                         /* 0x7C */
    void (*endcb)(int obj, int a, int b);               /* 0x80 */
    int endobj;                                         /* 0x84 */
    char pad88[8];
    int end90;                                          /* 0x90 */
    int end94;                                          /* 0x94 */
    char pad98[0xE8 - 0x98];
    int replay;                                         /* 0xE8 */
};

extern int Obj33F8_GetWord_C_FA68(AdxDec *dec);
extern void ADXPD_ExecHndl(AdxDec *dec);
extern void ADXPD_Reset(AdxDec *dec);
extern void ADXB_EvokeDecode(AdxbObj *adx);
extern void ADXB_EndDecode(AdxbObj *adx);
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void (*D_003E9D4C)(AdxbObj *adx, int v, short *a, short *b);

__attribute__((section(".text.ADXB_ExecOneAdx")))
void ADXB_ExecOneAdx(AdxbObj *adx)
{
    AdxDec *dec;
    int i;

    if (adx->stat == 1 && Obj33F8_GetWord_C_FA68(adx->dec) == 0) {
        adx->hdrcb(adx->hdrobj, &adx->hdr68, &adx->hdr6C, &adx->hdr70);
        ADXB_EvokeDecode(adx);
        adx->stat = 2;
    }
    if (adx->stat != 2)
        return;
    ADXPD_ExecHndl(adx->dec);
    if (Obj33F8_GetWord_C_FA68(adx->dec) != 3)
        return;
    if (adx->replay != 0) {
        dec = adx->dec;
        Forward33B658_33E678();
        for (i = 0; i < dec->n * 32; i++)
            D_003E9D4C(adx, dec->a[i], &dec->a[i], &dec->b[i]);
        Forward33B670_33E690();
    }
    ADXB_EndDecode(adx);
    ADXPD_Reset(adx->dec);
    adx->endcb(adx->endobj, adx->end94, adx->end90);
    adx->stat = 3;
}
