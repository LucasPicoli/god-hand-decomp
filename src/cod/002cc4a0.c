/* cygnus-2.96 matched TU. */
#include "godhand/cSnd.h"

typedef struct {
  short f0;
  short f2;
  int f4;
} Obj;

/* Marks a recent-call ring entry as empty. */
__attribute__((section(".text.func_002CC4A0")))
void func_002CC4A0(cSndSeRecent *r) {
  r->b = -1;
  r->a = -1;
  r->tick = 0;
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
