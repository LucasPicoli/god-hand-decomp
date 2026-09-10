/* cygnus-2.96 matched TU. */

typedef struct Tag { int f0; int f4; int f8; } Tag;
typedef struct H { char pad0[8]; Tag tag; } H;

extern int sfxzmv_SetTagGrp(H *h);

__attribute__((section(".text.SFXZ_SetTagInf")))
int SFXZ_SetTagInf(H *h, int a, int b)
{
    Tag *t;

    t = &h->tag;
    t->f0 = 1;
    t->f4 = a;
    t->f8 = b;
    return sfxzmv_SetTagGrp(h);
}
