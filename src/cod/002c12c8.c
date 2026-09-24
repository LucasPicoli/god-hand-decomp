/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 candidate. */

typedef struct Entry {
    char pad0[8];
    short type;
    signed char idx;
    char pad1;
    short x;
    short y;
    short z;
    unsigned short ang;
} Entry;

typedef struct Table {
    unsigned int count;
    Entry ent[1];
} Table;

extern char D_007474A0[];
extern char D_0044C230[];
extern Table *SearchData(int a0, char *a1, int a2);
extern int FindEntityByTypeIndex_2C2AE0(void *a0, int a1);

extern void cSceAtUnit_AtInit(void *u, int a1, int a2, int a3, int t0);
extern void cSceAtUnit_AreaSet(void *u, float *v, int n, float f12, float f13);
extern void func_002C3040(void *a0, void *a1, void *a2);

static __inline__ void SetVec4(float *d, float x, float y, float z)
{
    d[0] = x;
    d[1] = y;
    d[2] = z;
    d[3] = 1.0f;
}

__attribute__((section(".text.func_002C12C8")))
void func_002C12C8(char *self)
{
    char **slots;
    int *r;
    unsigned int i;
    Table *tbl;
    char **s;
    unsigned int j;
    unsigned int n;
    float v[4];
    char *g;

    slots = (char **)(self + 0x74);
    r = (int *)slots;
    for (i = 0; i < 8; i++) {
        *r = 0;
        r++;
    }

    g = D_007474A0;
    tbl = SearchData(*(int *)(g + 0x5AC), D_0044C230, 0);
    if (tbl == 0) {
        return;
    }
    n = 0;
    j = 0;
    if (tbl->count == 0) {
        return;
    }
    s = slots;
    do {
        char *u;
        char *g2;
        int t;
        Entry *e;
        short a;

        if (n >= 8) {
            return;
        }
        if (FindEntityByTypeIndex_2C2AE0(self, j) != 0) {
            goto next;
        }
        u = func_0030F550(0x9C);
        *s = u;
        if (u == 0) {
            return;
        }
        e = &tbl->ent[j];
        g2 = D_007474A0;
        t = *(unsigned short *)(g2 + 0x5B0);
        if (e->type == t && e->idx == j) {
            goto next;
        }
        cSceAtUnit_AtInit(u, 1, 3, 2, 0x31);
        a = e->ang + 0xB4;
        if (a > 0xB4) {
            a = a - 0x168;
        }
        (*s)[0x45] = a / 2;
        n++;
        (*s)[0x46] = 0x28;
        SetVec4(v, (float)e->x * 0.01f, (float)e->y * 0.01f, (float)e->z * 0.01f);
        cSceAtUnit_AreaSet(*s, v, 1, 3.0f, 3.0f);
        (*s)[0x79] = j;
        func_002C3040(self, self + 0x30, *s);
        s++;
    next:
        j++;
    } while (j < tbl->count);
}
