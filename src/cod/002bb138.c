/* ee-2.9-991111 matched TU. */

typedef struct { int f0; int f4; } Hn;


__attribute__((section(".text.func_002BB138")))
int func_002BB138(void)
{
    Hn *h = func_002BB068();
    if (h == 0) return 0;
    return h->f4;
}
