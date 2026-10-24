/* include/godhand/cVec.h - the game's vector class, as statement macros.
 *
 * The SN C++ code uses an inline VU0 vector class whose operators go through
 * stack temporaries: each result is built in a temporary, copied to the
 * operator's return slot, then copied to its destination. These macros
 * rebuild those operators from vu0.h, one bare block each, with real cVec
 * locals for the temporaries. They are macros, not inline functions, for the
 * reason EM_PHASE_RUN is: an inline function moves registers.
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

/* Vec v; (the default constructor: all four components zero) */
#define CVEC_ZERO(v)            VU0_SQC2_VF0_MEM(&(v), 0)

/* d = a - b; (operator- into its return slot, then operator=, xyz only) */
#define CVEC_SET_SUB(d, a, b)                                   \
    {                                                           \
        cVec ret_;                                              \
        cVec tmp_;                                              \
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

#endif /* GODHAND_CVEC_H */
