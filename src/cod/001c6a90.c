/* sn-2.95.3-136 matched TU. */

extern void func_001C7138(void *self);
extern void func_001C7310(void *self);
extern void cOmSub_setReverse(void *self, int on);

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct SubInit {
    unsigned char kind;                 /* 0x00 */
    char unk01;
    unsigned char zero2;                /* 0x02 */
    unsigned char arg;                  /* 0x03 */
    char unk04[0x2C];
    float scale;                        /* 0x30 */
    char unk34[0x5C];
    Vec3 posA;                          /* 0x90 */
    char unk9C[4];
    Vec3 posB;                          /* 0xA0 */
    char unkAC[0x84];
    float sizeA;                        /* 0x130 */
    float sizeB;                        /* 0x134 */
    float sizeC;                        /* 0x138 */
    float sizeD;                        /* 0x13C */
} SubInit;

/* Initialise a sub-object: byte header, scale from the unsigned count, two positions, two sizes (each stored twice), then run the two setup calls and clear the reverse flag. */
__attribute__((section(".text.SubInit_init")))
void SubInit_init(SubInit *self, unsigned int count, Vec3 *a, Vec3 *b, float w, float h, int arg)
{
    Vec3 *dst;

    self->arg = arg;
    self->zero2 = 0;
    self->kind = 0;
    self->scale = (float)count;
    dst = &self->posA;
    if (dst != a) {
        self->posA.x = a->x;
        dst->y = a->y;
        dst->z = a->z;
    }
    dst = &self->posB;
    if (dst != b) {
        self->posB.x = b->x;
        dst->y = b->y;
        dst->z = b->z;
    }
    self->sizeC = w;
    self->sizeD = h;
    self->sizeA = w;
    self->sizeB = h;
    func_001C7138(self);
    func_001C7310(self);
    cOmSub_setReverse(self, 0);
}
