typedef struct XformNode {
    char unk00[4];
    unsigned char flags;        /* 0x04 bit 0: has a local transform, bit 1: parent isn't the world matrix */
    char unk05[3];
    float (*parent)[4];         /* 0x08 */
    char unk0C[4];
    float local[4][4];          /* 0x10 */
    float ofs[4];               /* 0x50 */
    float rot[4];               /* 0x60 */
    float (*mtx)[4];            /* 0x70 */
    char unk74[0xC];
    float world_mtx[4][4];      /* 0x80 */
    float *pos;                 /* 0xC0 */
} XformNode;

extern float capVu0LengthSq(float *v);
extern void MtxInitRotVec(void *m, float *v, unsigned int a2);
extern void CopyVec3ToField30_147C40(void *m, float *v);

__attribute__((section(".text.func_002BB2D8")))
void func_002BB2D8(XformNode *n)
{
    long t;

    if (capVu0LengthSq(n->ofs) != 0.0f || capVu0LengthSq(n->rot) != 0.0f) {
        n->flags |= 1;
        t = n->flags;
        if ((t >> 1) % 2UL == 1) {
            n->mtx = n->world_mtx;
            n->pos = n->world_mtx[3];
        } else {
            n->pos = n->local[3];
            n->mtx = n->local;
        }
    } else {
        n->flags &= ~1;
        n->pos = n->parent[3];
        n->mtx = n->parent;
    }
    MtxInitRotVec(n->local, n->rot, 0);
    CopyVec3ToField30_147C40(n->local, n->ofs);
}
