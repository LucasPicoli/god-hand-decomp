/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */

typedef struct Sj { unsigned char *f0; int f4; } Sj;

typedef struct SjIf {
    int pad[6];
    void (*getChunk)(void *sj, int id, unsigned int len, Sj *out);   /* +0x18 */
    void (*ungetChunk)(void *sj, int id, Sj *ck);                    /* +0x1C */
    void (*putChunk)(void *sj, int id, Sj *ck);                      /* +0x20 */
} SjIf;

typedef struct SjObj { SjIf *vt; } SjObj;

extern unsigned char *MPV_SearchDelim(unsigned char *p, int n, unsigned int mask);
extern unsigned int MPV_CheckDelim(unsigned char *p);
extern void func_0033ACA0(Sj *ck, int n, Sj *a, Sj *b);

__attribute__((section(".text.MPV_GoNextDelimSj")))
unsigned int MPV_GoNextDelimSj(SjObj *sj)
{
    Sj ck;
    Sj ck2;
    unsigned char *p;
    unsigned int code;

    while (sj->vt->getChunk(sj, 1, 0x7FFFFFFF, &ck), ck.f4 >= 4) {
        p = MPV_SearchDelim(ck.f0, ck.f4, 0xFFFFFFFF);
        if (p == 0) {
            func_0033ACA0(&ck, ck.f4 - 3, &ck, &ck2);
            sj->vt->putChunk(sj, 0, &ck);
            sj->vt->ungetChunk(sj, 1, &ck2);
        } else {
            code = MPV_CheckDelim(p);
            func_0033ACA0(&ck, p - ck.f0, &ck, &ck2);
            sj->vt->putChunk(sj, 0, &ck);
            sj->vt->ungetChunk(sj, 1, &ck2);
            goto done;
        }
    }
    sj->vt->ungetChunk(sj, 1, &ck);
    code = 0;
done:
    return code;
}
