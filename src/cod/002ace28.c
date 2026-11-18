/* sn-2.95.3-136 matched TU. */
#include "godhand/eh.h"

extern void *D_003C3CF0;
extern int _MemoryAlloc(void *, int, void *);

/* __get_eh_info: the address of the current thread's exception info. */
__attribute__((section(".text.__get_eh_info")))
cp_eh_info **__get_eh_info(void) {
    return &(*get_eh_context)()->info;
}

__attribute__((section(".text.cIDManager_getTexAddr_2ACE28")))
int cIDManager_getTexAddr_2ACE28(void *a0, void *a1) {
    return cIDManager_getTexAddr(a0, 1, a1);
}

__attribute__((section(".text.func_0030F550")))
int func_0030F550(void *a0) {
    return _MemoryAlloc(a0, 0x10, D_003C3CF0);
}
