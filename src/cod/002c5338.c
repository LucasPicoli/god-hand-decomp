/* sn-2.95.3-136 */
#include "godhand/gameWork.h"
#include "godhand/sceVu0.h"

/* The part at 0x1C of D_005FEB00: func_002D50C0's class, derived; its vtable pointer is at 0x30. */
typedef struct StaticPart {
    char unk00[0x30];
    char *vtbl;                         /* 0x30 */
} StaticPart;

/* The file-scope object at D_005FEB00. */
typedef struct StaticObj {
    cVec unk00;                         /* 0x00 */
    char unk10[0xC];
    StaticPart part;                    /* 0x1C */
} StaticObj;

extern StaticObj D_005FEB00;
extern char D_0044D1A8[];               /* the derived class's vtable */

/* The derived constructor: the base constructor, then the derived vtable. */
static __inline__ void StaticPart_construct(StaticPart *self)
{
    func_002D50C0(self);
    self->vtbl = D_0044D1A8;
}

/* The object's constructor: a zeroed vector, then the part at 0x1C. */
static __inline__ void StaticObj_construct(StaticObj *self)
{
    cVec_zero(&self->unk00);
    StaticPart_construct(&self->part);
}

/* Static initializer: constructs D_005FEB00 at the default priority. */
__attribute__((section(".text.func_002C5338")))
void func_002C5338(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize != 0) {
        StaticObj_construct(&D_005FEB00);
    }
}
