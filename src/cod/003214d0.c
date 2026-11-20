/* ee-2.9-991111 matched TU. */
#include "godhand/eh.h"

/* __uncatch_exception (exception.cc): mark the current exception as no
 * longer caught; terminate when there is none. */
__attribute__((section(".text.__uncatch_exception")))
void __uncatch_exception(void)
{
    cp_eh_info *info = *__get_eh_info();

    if (info == 0)
        terminate();
    info->caught = 0;
}
