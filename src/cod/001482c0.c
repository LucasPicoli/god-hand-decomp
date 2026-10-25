/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/cModel.h"
#include "godhand/vu0.h"
#include "godhand/cVec.h"

extern char D_0042CAC8[];
extern void cModel_setTextureExchange(void *model, int set, int rec, int flag);
extern void *cModel_getMeshPtr_14B730(void *obj, char *name);
extern float capVu0LengthSq(void *v);

#define EM_NO_TEX_SWAP      0x251
#define EM_FLAGS2_SWAPPED   0x10
#define EM_FLAG254_TEXHIDE  0x10000000

/* The flag word at 0x254 and the texture set at 0x284 are inside cEm00's unnamed gap. */
#define EM_FLAGS254(self)   (*(unsigned int *)((char *)(self) + 0x254))
#define EM_TEXSET(self)     (*(int *)((char *)(self) + 0x284))





/* For enemy 0x251: flag the swapped state, hide the texture, swap in the
 * resource record 0x60 and show the named mesh. */
__attribute__((section(".text.cEm00_swapTextureAndShowMesh")))
void cEm00_swapTextureAndShowMesh(cEm00 *self)
{
    cModelNode *mesh;

    if ((self->emNo ^ EM_NO_TEX_SWAP) == 0) {
        self->emFlags2 |= EM_FLAGS2_SWAPPED;
        EM_FLAGS254(self) |= EM_FLAG254_TEXHIDE;
        cModel_setTextureExchange(self, EM_TEXSET(self), EM_RES_REC(self->resource, 0x60), 0);
        mesh = cModel_getMeshPtr_14B730(self, D_0042CAC8);
        if (mesh != 0)
            mesh->dispFlags &= ~CMODEL_NODE_HIDE;
    }
}

extern float func_003A18F0(float x);    /* cos */
extern float func_003A19F8(float x);    /* sin */

/* Build the rotation about the z axis for angle a: a 4x4 matrix of floats
 * with cos and sin in the top left 2x2 block, 1.0 at [10] and zeros elsewhere. */
__attribute__((section(".text.Mtx4_setRotZ")))
void Mtx4_setRotZ(float *m, float a)
{
    m[0] = func_003A18F0(a);
    m[1] = -func_003A19F8(a);
    m[2] = 0.0f;
    m[3] = 0.0f;
    m[4] = func_003A19F8(a);
    m[5] = func_003A18F0(a);
    m[10] = 1.0f;
    m[6] = 0.0f;
    m[7] = 0.0f;
    m[8] = 0.0f;
    m[9] = 0.0f;
    m[11] = 0.0f;
    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 0.0f;
}

/* True when the distance between the points a and b is below the sum of the
 * two radii (compared as squares). */
__attribute__((section(".text.Sphere_overlapTest")))
int Sphere_overlapTest(cVec *a, cVec *b, float ra, float rb)
{
    cVec d;
    CVEC_TEMPS;

    CVEC_ZERO(d);
    CVEC_SET_SUB(d, b, a);
    return capVu0LengthSq(&d) < (ra + rb) * (ra + rb);
}
