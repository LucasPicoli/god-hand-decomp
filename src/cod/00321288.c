/* ee-2.9-991111: __start_cp_handler (exception.cc). */
#include "godhand/eh.h"
extern cp_eh_info **func_00320360(void);

__attribute__((section(".text.__start_cp_handler")))
cp_eh_info *__start_cp_handler(void)
{
    cp_eh_info *p = *func_00320360();
    p->caught = 1;
    p->handlers++;
    return p;
}
