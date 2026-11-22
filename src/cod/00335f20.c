#include "godhand/globals.h"
typedef struct FsCacheEnt {
    int unk00;
    char *name;
    int sum;
    int unk0C;
    int unk10;
    int unk14;
    int loaded;
    int unk1C;
} FsCacheEnt;

typedef struct FsCacheCtl {
    char pad00[2];
    unsigned char active;
    char pad03[0x14 - 3];
    int unk14;
    int unk18;
    int unk1C;
    int cur;
    int num;
    void *handle;
    int unk2C;
    char pad30[8];
    FsCacheEnt ent[1];
} FsCacheCtl;

extern unsigned int strlen(const char *s);
extern void func_00335D40(char *fmt, ...);
extern int func_003282D0(void *h);
extern int func_00327FA8(void *h);
extern int func_00327E18(void *h, char *name, int a, int b, int c);
extern void func_00328448(void *h, int a);
extern int func_00328C80(void *h, int a, int b);
extern int func_003280D8(void *h, int a);
extern int func_003281C8(void *h);

__attribute__((section(".text.func_00335F20")))
void func_00335F20(FsCacheCtl *self)
{
    FsCacheEnt *e = &self->ent[self->cur];
    char *name;
    unsigned int len;
    unsigned int i;
    int sum;

    if (self->num > 0) {
        func_003282D0(self->handle);
        func_00327FA8(self->handle);
        name = e->name;
        len = strlen(name);
        sum = 0;
        for (i = 0; i < len; i++) {
            sum += (unsigned char)name[i];
        }
        if (sum != e->sum) {
            func_00335D40(D_00455000, e->name, len, sum);
            return;
        }
        func_00327E18(self->handle, e->name, e->unk0C, e->unk10, e->unk14);
        func_00328448(self->handle, e->unk14);
        self->unk2C = e->unk14;
        e->unk1C = 0;
        self->active = 0;
        func_00328C80(self->handle, self->unk14, self->unk18);
        func_003280D8(self->handle, 0);
        func_003281C8(self->handle);
        self->active = 1;
        e->loaded = 1;
    }
}
