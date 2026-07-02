/* cygnus-2.96 matched TU. */

typedef struct Obj Obj;
struct Obj { int x0; int x4; int x8; int xc; int x10; };

__attribute__((section(".text.func_00290000")))
Obj* func_00290000(Obj *o) {
    *(int *)((char *)o + 0x0) = 0;
    *(int *)((char *)o + 0xC) = -1;
    *(int *)((char *)o + 0x4) = 0;
    *(int *)((char *)o + 0x8) = 0;
    *(char *)((char *)o + 0x10) = 0;
    return o;
}
