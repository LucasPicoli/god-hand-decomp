/* sn-2.95.3-136 matched TU. */
#include "godhand/eh.h"

/* The current exception's info (exception.cc), between __cp_exception_info
 * and __start_cp_handler; the vendor exception.o names it. */
__attribute__((section(".text.__cp_eh_info")))
cp_eh_info *__cp_eh_info(void)
{
    return *__get_eh_info();
}
