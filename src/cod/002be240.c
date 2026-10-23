/* sn-2.95.3-136: load a file, preferring a copy packed in the resident archive at 0x4C0: match the lowercased basename
 * against the archive directory, DMA the hit into IOP heap and load from there; otherwise load from the path. */
extern unsigned char D_0045F039[];
extern char D_0044C088[];

typedef struct PackEnt {
    char name[0x10];
    int ofs;    /* 0x10 */
    int size;   /* 0x14 */
    char pad18[8];
} PackEnt;

typedef struct PackHdr {
    char pad00[8];
    int count;      /* 0x08 */
    char pad0c[4];
    PackEnt ent[1]; /* 0x10 */
} PackHdr;

typedef struct DmaReq {
    unsigned int data;
    unsigned int addr;
    unsigned int size;
    unsigned int mode;
} DmaReq;

typedef struct ArchiveOwner {
    char pad000[0x4C0];
    PackHdr *pack; /* 0x4C0 */
} ArchiveOwner;

extern char *func_003A93A8(char *s, int c);
extern int func_003A6A20(char *fmt, ...);
extern int func_003A5678(const char *a, const char *b);
extern void *sceSifAllocIopHeap(int size);
extern unsigned int func_003B2148(DmaReq *req, int n);
extern int SifDmaStat(unsigned int id);
extern int func_003B5E50(void *iop, int a1, int a2);
extern int func_003B60A0(const char *path, int a1, int a2);

static inline int ctype_tolower(int c) { return (D_0045F039[c] & 1) ? c + 0x20 : c; }

__attribute__((section(".text.func_002BE240")))
int func_002BE240(ArchiveOwner *self, char *path, int a2, int a3)
{
    DmaReq req;
    char *name;
    PackEnt *e;
    int i, n, j;
    char *src;
    void *buf;
    unsigned int id;

    if (self->pack != 0) {
        if ((name = func_003A93A8(path, '/')) == 0 && (name = func_003A93A8(path, '\\')) == 0)
            name = path;
        else
            name++;
        e = self->pack->ent;
        for (i = 0; i < self->pack->count; i++, e++) {
            for (n = 0; name[n] != 0 && name[n] != ';'; n++)
                name[n] = ctype_tolower(name[n]);
            name[n] = 0;
            for (j = 0; e->name[j] != 0; j++)
                e->name[j] = ctype_tolower(e->name[j]);
            if (func_003A5678(name, e->name) == 0) {
                src = (char *)self->pack + e->ofs;
                buf = sceSifAllocIopHeap(e->size);
                if (buf == 0) {
                    func_003A6A20(D_0044C088);
                    break;
                }
                req.data = (unsigned int)src;
                req.addr = (unsigned int)buf;
                req.size = e->size;
                req.mode = 0;
                id = func_003B2148(&req, 1);
                while (SifDmaStat(id) < 0)
                    ;
                return func_003B5E50(buf, a2, a3);
            }
        }
    }
    return func_003B60A0(path, a2, a3);
}
