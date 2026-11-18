/* sn-2.95.3-136 matched TU. */

#include "godhand/eh.h"

__attribute__((section(".text.__get_dynamic_handler_chain")))
void ***__get_dynamic_handler_chain(void)
{
  return &(*get_eh_context)()->dynamic_handler_chain;
}
