/* cygnus-2.96 matched TU. */

/* cygnus-2.96 candidate: sfbuf_DestroySjSub */

typedef struct SjBuf {
    unsigned char d[116];
} SjBuf;

typedef struct Sj Sj;

typedef struct SjIf {
    void *f0;
    void *f4;
    void *f8;
    void (*fC)(Sj *sj);
} SjIf;

struct Sj {
    SjIf *vt;
};

typedef struct SjSlot {
    int f0;
    Sj *sj;
} SjSlot;

__attribute__((section(".text.func_0034BD98")))
void func_0034BD98(char *p, int no)
{
    SjBuf *e = (SjBuf *)(p + 0x1310);
    char *b = (char *)&e[no];
    SjSlot *s = (SjSlot *)(b + 0x10);
    int st = *(int *)b;
    if (st == 5) {
        if (s->sj != 0) {
            s->sj->vt->fC(s->sj);
            s->sj = 0;
        }
    }
}
