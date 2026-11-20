#include "godhand/cSnd.h"
extern void System_sendBootRequests(void *);
extern void func_002C9F58(void *);

__attribute__((section(".text.func_002C9D20")))
void func_002C9D20(void *p)
{
    System_sendBootRequests(p);
    func_002C9E78(p);
    func_002C9F58(p);
}
