/* cygnus-2.96: func_00324440, stream size; refreshed from the handle while the cached value is the 0x7FFFF800+ marker. */
#include "godhand/globals.h"
typedef struct {
    int pad0;
    int handle;
    int pad8;
    int sectors;
    int size;
} StmSizeCache;

extern void func_0033F130(int msg);
extern void func_00328F70(int handle);
extern int func_00328098(int handle);
extern int func_00328D40(int handle);

__attribute__((section(".text.func_00324440")))
int func_00324440(StmSizeCache *s)
{
    int size;

    if (s == 0) {
        func_0033F130((int)D_00451928);
        return -3;
    }
    size = s->size;
    if (size >= 0x7FFFF800) {
        func_00328F70(s->handle);
        if (func_00328098(s->handle) == 4)
            return -5;
        size = s->size = func_00328D40(s->handle);
    }
    return size;
}
