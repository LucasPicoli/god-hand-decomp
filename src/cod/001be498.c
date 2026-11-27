/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/cCamera.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"
#include "godhand/capVu0.h"
#include "godhand/mtx.h"

extern float fRand1_1(void);
extern float fRand0_1(void);
extern void Obj0000_Set_Byte_54(void *a0, int a1);
extern void Obj0000_Set_Field_50_173998(void *rec, void *value);
extern void ForwardVec3At30_147C60(void *a0, float *a1);
extern void func_00147C88(void *a0, void *a1, int a2);
extern void CopyVec3ToField20_173908(char *a0, float *a1);
extern void CopyVec3ToField30_173938(char *a0, float *a1);
extern void CopyVec3ToField40_173968(char *a0, float *a1);

/* sn-2.95.3-136 */







#define ORBIT_RADIUS     26.0f
#define ORBIT_BLEND_RATE 0.1f           /* part of the old position kept per unit of speedRate */
#define ORBIT_TURN_STEP  0.012271847f   /* pi / 256 */
#define ORBIT_HALF_TURN  3.1415927f

typedef struct OrbitFrame {
    float mtx[16];
    cVec at;
    cVec diff;
    cVec work;
} OrbitFrame;

#define ORBITFRAME_OFFSET(field) ((int)&((OrbitFrame *)0)->field)

/* Moves the object toward the orbit point at angle around the anchor, blending the old
 * position by speedRate, and turns it pi/256 per unit of speedRate toward the anchor.
 * The work address is bound before the volatile zero-and-subtract block, as retail
 * forms it there and reads it after. */
__attribute__((section(".text.func_002495E0")))
void func_002495E0(cEm00 *self, float angle)
{
    OrbitFrame f;
    float keep, one;
    cVec *work;

    VU0_SQC2_VF0_MEM(&f.at, 0);
    keep = self->speedRate * ORBIT_BLEND_RATE;
    one = 1.0f;
    keep = one - keep;
    work = &f.work;
    VU0_ZERO_VSUB_XYZ_MEM(&f.work, 0, self->pos, &D_005850B0);
    VU0_LQC2(4, work, 0);
    VU0_SQC2(4, &f, ORBITFRAME_OFFSET(diff));
    f.at.x = f.diff.x;
    f.at.y = f.diff.y;
    f.at.z = f.diff.z;
    angle = Adjust_theta(capVu0Atan2(f.diff.x, f.diff.z) + angle);
    MtxInitRotY(f.mtx, angle);
    f.at.x = 0.0f;
    f.at.y = 0.0f;
    f.at.z = ORBIT_RADIUS;
    cVec_applyMatrix(&f.at, f.mtx);
    VU0_VADD_XYZ_IP(&f.at, 0, &D_005850B0);
    one = one - keep;
    self->pos->x = self->pos->x * keep + f.at.x * one;
    self->pos->z = self->pos->z * keep + f.at.z * one;
    self->rot.y += Turn_dest_dir(self->rot.y, Adjust_theta(angle + ORBIT_HALF_TURN),
                                  self->speedRate * ORBIT_TURN_STEP);
    self->rot.y = Adjust_theta(self->rot.y);
}

inline static void cp40(char *a0, float *a1, float *src)
{
  float *v0 = (float *) (a0 + 0x40);
  if (v0 != a1)
  {
    *((float *) (a0 + 0x40)) = src[0];
    v0++;   /* no-op pair: keeps the 0x48 load below the 0x4 store, as retail */
    v0--;
    v0[1] = src[1];
    v0[2] = src[2];
  }
}

/* Flags part a1 of the owner (0x278 table, 0x2B4 count) with 8 and 0x10, copies the two
 * vectors a2 and a3 with small random jitter, and sets up the effect slot at
 * 0x600 + a1 * 0x60 from them with unit scale and a 3.0 scale vector. */
__attribute__((section(".text.func_001BE498"))) void func_001BE498(char *a0, int a1, float *a2, float *a3)
{
  __attribute__((aligned(16))) unsigned char frame[0x50];
  float *new_var;
  int obj1;
  int obj2;
  int obj3;
  int b1;
  int b2;
  int b3;
  unsigned char ok1;
  unsigned char ok2;
  unsigned char ok3;
  char *elem;
  char *src;
  float neg;
  float *w;
  int off;
  ok1 = (*((int *) frame) = (b1 = *((unsigned char *) (a0 + 0x2B4))), (a1 >= 0) && (a1 < b1));
  if (ok1)
  {
    obj1 = *((int *) ((*((int *) (a0 + 0x278))) + (a1 * 4)));
  }
  else
  {
    obj1 = 0;
  }
  *((int *) (obj1 + 0x154)) |= 8;
  ok2 = (*((int *) frame) = (b2 = *((unsigned char *) (a0 + 0x2B4))), (a1 >= 0) && (a1 < b2));
  if (ok2)
  {
    obj2 = *((int *) ((*((int *) (a0 + 0x278))) + (a1 * 4)));
  }
  else
  {
    obj2 = 0;
  }
  *((int *) (obj2 + 0x154)) |= 0x10;
  new_var = (float *) (frame + 0x14);
  VU0_LQC2(4, a2, 0);
  VU0_SQC2(4, frame, 0x10);
  VU0_LQC2(4, a3, 0);
  VU0_SQC2(4, frame, 0x20);
  *((float *) (frame + 0x10)) += fRand1_1() * 0.05f;
  *new_var += fRand0_1() * 0.2f;
  *((float *) (frame + 0x18)) += fRand1_1() * 0.05f;
  *((float *) (frame + 0x20)) += fRand1_1() * 0.1f;
  *((float *) (frame + 0x24)) += fRand1_1() * 0.1f;
  *((float *) (frame + 0x28)) += fRand1_1() * 0.1f;
  ok3 = (*((int *) frame) = (b3 = *((unsigned char *) (a0 + 0x2B4))), (a1 >= 0) && (a1 < b3));
  if (ok3)
  {
    obj3 = *((int *) ((*((int *) (a0 + 0x278))) + (a1 * 4)));
  }
  else
  {
    obj3 = 0;
  }
  src = (char *) (obj3 + 0x80);
  off = a1 * 0x60;
  elem = a0 + off;
  elem = elem + 0x600;
  neg = -0.02f;
  Obj0000_Set_Byte_54(elem, 1);
  Obj0000_Set_Field_50_173998(elem, src);
  ForwardVec3At30_147C60(elem, (float *) src);
  func_00147C88(elem + 0x10, src, 0);
  CopyVec3ToField20_173908(elem, (float *) (frame + 0x10));
  CopyVec3ToField30_173938(elem, (float *) (frame + 0x20));
  {
    float *v = (float *) (frame + 0x30);
    v[0] = 1.0f;
    v[1] = 1.0f;
    v[2] = 1.0f;
    v[3] = 1.0f;
    CopyVec3ToField40_173968(elem, v);
  }
  w = (float *) (frame + 0x40);
  *((float *) (elem + 0x58)) = neg;
  {
    float *v = (float *) (frame + 0x30);
    v[0] = 3.0f;
    v[2] = (v[1] = 3.0f);
    v[3] = 1.0f;
    a1++;
    a1--;
    VU0_LQC2(4, v, 0);
    VU0_SQC2(4, frame, 0x40);
    cp40((a0 + (a1 * 0x60)) + 0x600, w, (float *) (frame + 0x40));
  }
}
