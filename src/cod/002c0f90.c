/* sn-2.95.3-136: func_002C0F90, cSceAtManager init (four SearchData unit tables linked into the free lists). */
#include "godhand/gameWork.h"

typedef struct {
    char pad0[0x36];
    unsigned short f36;
    char pad38;
    unsigned char f39;
    char pad3A[0x9C - 0x3A];
} AtUnit;

typedef struct {
    char pad0[4];
    unsigned short ver;
    unsigned short count;
} AtHdr;

typedef struct {
    AtHdr *h0;
    AtUnit *u0;
    AtHdr *h1;
    AtUnit *u1;
    AtHdr *h2;
    AtUnit *u2;
    AtHdr *h3;
    AtUnit *u3;
    int lists[16];
    int f60;
    char f64;
    int f68;
    int f6C;
    int f70;
} AtMgr;

extern char D_0044C210[];
extern char D_0044C218[];
extern char D_0044C220[];
extern char D_0044C228[];

extern void cSceAtManager_initFreeList(void *self, unsigned int *lists, int n);
extern AtHdr *SearchData(int pack, char *name, int flag);
extern void cSceAtManager_linkUnit(char *self, int *list, int *u);
extern void func_002C12C8(char *self);
extern void cSceAtManager_initUnitStates(void *self);

__attribute__((section(".text.func_002C0F90")))
void func_002C0F90(AtMgr *self)
{
    AtHdr *h;
    int i;
    int j;

    self->u0 = 0;
    self->u1 = 0;
    cSceAtManager_initFreeList(self, self->lists, 16);
    h = SearchData((int)D_007474A0.pack, D_0044C210, 0);
    self->h0 = h;
    if (h != 0 && h->ver == 0x100) {
        self->u0 = (AtUnit *)((char *)h + 0x10);
        for (i = h->count - 1; i >= 0; i--)
            cSceAtManager_linkUnit(self, &self->lists[self->u0[i].f39], &self->u0[i]);
    }
    h = SearchData((int)D_007474A0.pack, D_0044C218, 0);
    self->h1 = h;
    if (h != 0 && h->ver == 0x100) {
        self->u1 = (AtUnit *)((char *)h + 0x10);
        for (j = 0; j < self->h1->count; j++) {
            self->u1[j].f36 += 0x80;
            cSceAtManager_linkUnit(self, &self->lists[self->u1[j].f39], &self->u1[j]);
        }
    }
    h = SearchData((int)D_007474A0.pack, D_0044C220, 0);
    self->h2 = h;
    if (h != 0 && h->ver == 0x100) {
        self->u2 = (AtUnit *)((char *)h + 0x10);
        for (j = h->count - 1; j >= 0; j--) {
            self->u2[j].f36 += 0x100;
            cSceAtManager_linkUnit(self, &self->lists[self->u2[j].f39], &self->u2[j]);
        }
    }
    h = SearchData((int)D_007474A0.pack, D_0044C228, 0);
    self->h3 = h;
    if (h != 0 && h->ver == 0x100) {
        self->u3 = (AtUnit *)((char *)h + 0x10);
        for (j = h->count - 1; j >= 0; j--) {
            self->u3[j].f36 += 0x180;
            cSceAtManager_linkUnit(self, &self->lists[self->u3[j].f39], &self->u3[j]);
        }
    }
    func_002C12C8(self);
    cSceAtManager_initUnitStates(self);
    self->f60 = 0;
    self->f68 = 0;
    self->f6C = 0;
    self->f70 = 0;
    self->f64 = 0;
}
