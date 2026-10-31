/* include/godhand/cVec.h - the game's vector class, as statement macros.
 *
 * The SN C++ code uses an inline VU0 vector class whose operators go through
 * stack temporaries: each result is built in a temporary, copied to the
 * operator's return slot, then copied to its destination. SN gives a
 * function one return slot and one temporary and reuses them for every
 * operator in it, so a function that uses these macros declares them once,
 * with CVEC_TEMPS, where retail's stack order puts them among its cVec
 * locals. The macros rebuild the operators from vu0.h, one bare block each.
 * They are macros, not inline functions, for the reason EM_PHASE_RUN is: an
 * inline function moves registers.
 *
 * Shapes the bytes depend on: an operator binds its arguments first, then
 * its return-slot pointer, then copies through that pointer by name. The
 * pointer (r_) exists only for the self-check, and the order of a_, b_, r_
 * decides which registers they get. The copy can't be a helper call
 * (vec3_copy, cVec_copy3): those compare and read through their own
 * parameters and don't match.
 */
#ifndef GODHAND_CVEC_H
#define GODHAND_CVEC_H

#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

/* The return slot and the temporary every operator in the function shares. */
#define CVEC_TEMPS              cVec ret_; cVec tmp_

/* Vec v; (the default constructor: all four components zero) */
#define CVEC_ZERO(v)            VU0_SQC2_VF0_MEM(&(v), 0)

/* d = ret_; (operator= from the return slot, xyz only, skipped when d is the slot) */
#define CVEC_FROM_RET(d)                                        \
    {                                                           \
        cVec *r_ = &ret_;                                       \
                                                                \
        if (&(d) != r_) {                                       \
            (d).x = ret_.x;                                     \
            (d).y = ret_.y;                                     \
            (d).z = ret_.z;                                     \
        }                                                       \
    }

/* a - b; (operator- into the return slot, for a caller that passes &ret_ on) */
#define CVEC_SUB(a, b)                                          \
    {                                                           \
        cVec *a_ = (a);                                         \
        cVec *b_ = (b);                                         \
                                                                \
        VU0_ZERO_VSUB_XYZ_MEM(&tmp_, 0, a_, b_);                \
        VU0_LQC2(4, &tmp_, 0);                                  \
        VU0_SQC2_MEM(4, &ret_, 0);                              \
    }

/* d = a - b; (operator- into the return slot, then operator=, xyz only) */
#define CVEC_SET_SUB(d, a, b)                                   \
    {                                                           \
        cVec *a_ = (a);                                         \
        cVec *b_ = (b);                                         \
        cVec *r_ = &ret_;                                       \
                                                                \
        VU0_ZERO_VSUB_XYZ_MEM(&tmp_, 0, a_, b_);                \
        VU0_LQC2(4, &tmp_, 0);                                  \
        VU0_SQC2_MEM(4, &ret_, 0);                              \
        if (&(d) != r_) {                                       \
            (d).x = ret_.x;                                     \
            (d).y = ret_.y;                                     \
            (d).z = ret_.z;                                     \
        }                                                       \
    }

/* v *= s; (operator*= by a scalar, xyz) */
#define CVEC_MUL_SCALAR(v, s)   VU0_VSCALE_XYZ_MEM(&(v), 0, s)

/* v += *b; (operator+=, xyz) */
#define CVEC_ADD_TO(v, b)       VU0_VADD_XYZ_IP(&(v), 0, b)

/* *dst = v; (the whole quadword, as the copy constructor makes it) */
#define CVEC_STORE(dst, v)                                      \
    {                                                           \
        VU0_LQC2(4, &(v), 0);                                   \
        VU0_SQC2(4, dst, 0);                                    \
    }


/* Vec v(fx, fy, fz); (the three-float constructor in place, w = 1). As an
 * inline function the arguments go through registers and 0.0 components are
 * no longer stored from $zero. */
#define CVEC_INIT_XYZ(v, fx, fy, fz)                            \
    {                                                           \
        cVec *v_ = &(v);                                        \
                                                                \
        v_->x = (fx);                                           \
        v_->y = (fy);                                           \
        v_->z = (fz);                                           \
        v_->w = 1.0f;                                           \
    }

#endif /* GODHAND_CVEC_H */
