/* cygnus-2.96 matched TU. */

typedef struct E { void (*fn)(void *arg, void *s); void *arg; int count; } E;
extern E D_003EE340;

__attribute__((section(".text.SFXLIB_Error")))
void SFXLIB_Error(void *a, void *b, void *s)
{
    E *e;
    void (*fn)(void *arg, void *s);
    void *arg;

    e = &D_003EE340;
    e->count++;
    fn = e->fn;
    arg = e->arg;
    if (fn != 0) {
        fn(arg, s);
    }
}
