/* sn-2.95.3-136 */
/* func_003BBEC0: basic_string<char>::rfind(c, pos) (sn-2.95.3-136) */
#include "godhand/StdString.h"

#define STDSTRING_NPOS 0xFFFFFFFFU

static __inline__ int stdChar_eq(const char *c1, const char *c2)
{
    return *c1 == *c2;
}

/* Last index of c at or before pos, npos if none. */
__attribute__((section(".text.func_003BBEC0")))
unsigned int func_003BBEC0(StdString *self, char c, unsigned int pos)
{
    unsigned int xpos;

    if (1 > STDSTRING_REP(self)->len)
        return STDSTRING_NPOS;
    xpos = STDSTRING_REP(self)->len - 1;
    if (xpos > pos)
        xpos = pos;
    for (++xpos; xpos-- > 0;)
        if (stdChar_eq(&self->dat[xpos], &c))
            return xpos;
    return STDSTRING_NPOS;
}
