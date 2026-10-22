/* sn-2.95.3-136 */
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

extern void func_00135348(cVec *out, cVec *p, cVec *a, cVec *b, cVec *c);

static __inline__ float cVec_distSq(cVec *a, cVec *b)
{
    return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y)
         + (a->z - b->z) * (a->z - b->z);
}

/* Whether the sphere at center touches the quad a b c d, tested as the triangles a b d and
 * b c d. On a hit the nearer closest point goes to hit (if given). */
__attribute__((section(".text.SphereSquare")))
int SphereSquare(cVec *center, float radius, cVec *a, cVec *b, cVec *c, cVec *d, cVec *hit)
{
    cVec pt[3];                         /* closest points of the two triangles, then the nearer one */
    float d1;
    float d2;

    VU0_SQC2_VF0(pt, 0);
    VU0_SQC2_VF0(pt, sizeof(cVec));
    VU0_SQC2_VF0(pt, 2 * sizeof(cVec));
    func_00135348(&pt[0], center, a, b, d);
    func_00135348(&pt[1], center, b, c, d);
    d1 = cVec_distSq(center, &pt[0]);
    d2 = cVec_distSq(center, &pt[1]);
    if (d1 <= d2) {
        cVec_copy3(&pt[2], &pt[0]);
    } else {
        cVec_copy3(&pt[2], &pt[1]);
        d1 = d2;
    }
    if (!(d1 <= radius * radius)) {
        return 0;
    }
    if (hit != 0) {
        cVec_copy3(hit, &pt[2]);
    }
    return 1;
}
