/* cygnus-2.96 matched TU. */

typedef struct Obj { int stat; } Obj;

__attribute__((section(".text.func_0035D800")))
int func_0035D800(Obj *o)
{
    int lo;
    int r;

    lo = (o->stat < -1);
    do { } while (0);
    r = (o->stat < 2);
    if (r) {
        r = 0;
        if (lo == 0) goto out;
    }
    r = 1;
out:
    return r;
}
