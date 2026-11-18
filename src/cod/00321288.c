/* ee-2.9-991111: __start_cp_handler (exception.cc). */
#include "godhand/eh.h"

__attribute__((section(".text.__start_cp_handler")))
cp_eh_info *__start_cp_handler(void)
{
    cp_eh_info *p = *__get_eh_info();
    p->caught = 1;
    p->handlers++;
    return p;
}
