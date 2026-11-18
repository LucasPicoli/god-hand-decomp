/* ee-2.9-991111 matched TU. */

#include "godhand/eh.h"

__attribute__((section(".text.func_003202A8")))
void *func_003202A8(void *catch_type, void *throw_type, void *obj)
{
  if (func_003A5678((const char *)catch_type, (const char *)throw_type) == 0)
    return obj;
  return 0;
}

__attribute__((section(".text.func_003212C0")))
void *func_003212C0(unsigned int size)
{
  void *p = func_003A7C70(size);
  if (p == 0)
    terminate();
  return p;
}
