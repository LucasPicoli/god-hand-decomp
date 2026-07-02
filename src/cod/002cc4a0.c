/* cygnus-2.96 matched TU. */

typedef struct {
  short f0;
  short f2;
  int f4;
} Obj;

__attribute__((section(".text.func_002CC4A0")))
void func_002CC4A0(Obj *o) {
  o->f2 = -1;
  o->f0 = -1;
  o->f4 = 0;
}

typedef struct {
  char pad[0x1fc0];
  void *ptr;
} OuterObj;

typedef struct {
  char pad[0x7c];
  int field;
} InnerObj;

__attribute__((section(".text.func_003554D8")))
void func_003554D8(OuterObj *o) {
  InnerObj *inner = o->ptr;
  inner->field = 1;
}
