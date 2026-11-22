/* cygnus-2.96: CRI stream handle pool (0x336E88..). */

#include "godhand/criStm.h"
#include "godhand/globals.h"

extern void SJRMT_Destroy(void *p);
extern void SJX_Destroy(void *sjx);
extern int Tramp_sceSifFreeSysMemory_3B5A50(void *p);
extern void *sceSifAllocIopHeap(int size);
extern void *SJUNI_CreateRmt(int mode, char *buf, int size);
extern StmObj *func_0033A190(int mode, char *buf, int size);
extern void *SJX_Create(StmObj *obj, void *uni, int mode);

__attribute__((section(".text.PS2RNA_SetupVoice")))
void PS2RNA_SetupVoice(int a, int b)
{
    int n;

    if (a < 0) {
        func_003260C8(D_00455398, a);
        return;
    }
    if (b < 0) {
        func_003260C8(D_004553C8, b);
        return;
    }
    n = a * 2 + b;
    if (n > 32) {
        func_003260C8(D_004553F8, 32);
        return;
    }
    D_003E0708 = n;
    D_003E0730 = a;
    D_003E0734 = b;
    D_003E070C = n * 0x4100;
    D_003E0710 = 1;
}

__attribute__((section(".text.func_00336F48")))
void func_00336F48(void)
{
    StmEnt *e;
    char *buf;
    int i;

    if (D_003E0710 == 0) {
        D_003E0708 = 16;
        D_003E070C = 0x41000;
    }
    if (D_003E0714 == 0) {
        D_003E0714 = sceSifAllocIopHeap(D_003E070C + 0x40);
        if (D_003E0714 == 0) {
            func_003260C8(D_00455438, D_003E070C + 0x40);
            for (;;);
        }
        func_003260C8(D_00455480, D_003E070C + 0x40, D_003E0714);
        D_003E0718 = (char *)(((int)D_003E0714 + 0x40) & ~0x3F);
        D_003E071C = 1;
    }
    func_003A52F0(D_003E0768, 0, 0x300);
    buf = D_003E0718;
    for (i = 0; i < D_003E0708; i++) {
        e = &D_003E0768[i];
        e->used = 0;
        if ((int)buf & 0x3F) {
            func_003260C8(D_004554B0);
            for (;;);
        }
        e->f4 = SJUNI_CreateRmt(1, buf, 0x100);
        buf += 0x100;
        if (e->f4 == 0) {
            func_003260C8(D_004554E0);
            for (;;);
        }
        if ((int)buf & 0x3F) {
            func_003260C8(D_00455518);
            for (;;);
        }
        e->obj = func_0033A190(1, D_003E0A68 + i * 0x100, 0x100);
        if (e->obj == 0) {
            func_003260C8(D_00455548);
            for (;;);
        }
        e->buf = buf;
        e->bufSize = 0x4000;
        e->obj->vt->setBuf(e->obj, 0, &e->buf);
        buf += 0x4000;
        e->sjx = SJX_Create(e->obj, e->f4, 1);
        if (e->sjx == 0) {
            func_003260C8(D_00455580);
            for (;;);
        }
    }
}

__attribute__((section(".text.ps2rna_finish_psj")))
void ps2rna_finish_psj(void)
{
    StmEnt *e;
    void *p;
    int i;

    for (i = 0; i < D_003E0708; i++) {
        e = &D_003E0768[i];
        p = e->f4;
        if (p != 0) {
            SJRMT_Destroy(p);
        }
        if (e->obj != 0) {
            e->obj->vt->destroy(e->obj);
        }
        if (e->sjx != 0) {
            SJX_Destroy(e->sjx);
        }
        func_003A52F0(&D_003E0768[i], 0, sizeof(StmEnt));
    }
    if (D_003E071C == 1) {
        Tramp_sceSifFreeSysMemory_3B5A50(D_003E0714);
        D_003E0714 = 0;
        D_003E071C = 0;
    }
}

/* Claim the first free stream pool entry and return it, or 0 when the pool is full. */
__attribute__((section(".text.CriStm_allocEntry")))
StmEnt *CriStm_allocEntry(void)
{
    StmEnt *e = 0;
    int i;

    for (i = 0; i < D_003E0708; i++) {
        e = &D_003E0768[i];
        if (e->used == 0) {
            break;
        }
    }
    if (i == D_003E0708) {
        return 0;
    }
    e->used = 1;
    return e;
}
