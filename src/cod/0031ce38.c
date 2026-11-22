#include "godhand/vu0.h"
#include "godhand/globals.h"

extern void *D_00747A4C;
extern void *SearchData(void *, void *, void *);

__attribute__((section(".text.SearchCameraData")))
void *SearchCameraData(void *key)
{
    void *found = SearchData(D_00747A4C, D_00450ED8, 0);
    if (found == 0)
        return 0;
    return SearchData(found, key, 0);
}
