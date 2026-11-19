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
 * Shapes the bytes depend on: most operators bind their arguments first,
 * then their return-slot pointer, then copy through that pointer by name.
 * CVEC_PUT and CVEC_ASSIGN_VEC bind this first; each macro's comment says
 * which pointer it binds first. The return-slot pointer (r_) exists only
 * for the self-check, and the order of a_, b_, r_ decides which registers
 * they get. The copy can't be a helper call (vec3_copy, cVec_copy3): those
 * compare and read through their own parameters and don't match.
 */
#ifndef GODHAND_CVEC_H
#define GODHAND_CVEC_H

#include "godhand/cVecType.h"
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

/* d = *s; (operator= with the argument pointer bound first, compared against
 * &d, then read through it; xyz only, skipped when d is *s) */
#define CVEC_ASSIGN(d, s)                                       \
    {                                                           \
        cVec *s_ = (s);                                         \
                                                                \
        if (&(d) != s_) {                                       \
            (d).x = s_->x;                                      \
            (d).y = s_->y;                                      \
            (d).z = s_->z;                                      \
        }                                                       \
    }

/* *dp = v; (operator= with this bound, compared against &v, v copied by name, xyz only) */
#define CVEC_PUT(dp, v)                                         \
    {                                                           \
        cVec *d_ = (dp);                                        \
                                                                \
        if (d_ != &(v)) {                                       \
            d_->x = (v).x;                                      \
            d_->y = (v).y;                                      \
            d_->z = (v).z;                                      \
        }                                                       \
    }

/* d = v; (operator= with the argument bound before this: &v is only used for the
 * self-check, the copy reads v by name, xyz only) */
#define CVEC_ASSIGN_ARG(d, v)                                   \
    {                                                           \
        cVec *s_ = &(v);                                        \
        cVec *d_ = &(d);                                        \
                                                                \
        if (d_ != s_) {                                         \
            d_->x = (v).x;                                      \
            d_->y = (v).y;                                      \
            d_->z = (v).z;                                      \
        }                                                       \
    }

/* d = s; (operator= on d with a named vector s: this is &d, compared against &s before
 * the copy, xyz only) */
#define CVEC_ASSIGN_VEC(d, s)                                   \
    {                                                           \
        cVec *d_ = &(d);                                        \
                                                                \
        if (d_ != &(s)) {                                       \
            d_->x = (s).x;                                      \
            d_->y = (s).y;                                      \
            d_->z = (s).z;                                      \
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

/* a + b; (operator+ into the return slot, for a caller that reads ret_) */
#define CVEC_ADD(a, b)                                          \
    {                                                           \
        cVec *a_ = (a);                                         \
        cVec *b_ = (b);                                         \
                                                                \
        VU0_LQC2(4, a_, 0);                                     \
        VU0_SQC2_MEM(4, &tmp_, 0);                              \
        VU0_VADD_XYZ_IP(&tmp_, 0, b_);                          \
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


/* Vec v(fx, fy, fz); (the three-float constructor in place, w = 1). */
#define CVEC_INIT_XYZ(v, fx, fy, fz)                            \
    {                                                           \
        cVec *v_ = &(v);                                        \
                                                                \
        v_->x = (fx);                                           \
        v_->y = (fy);                                           \
        v_->z = (fz);                                           \
        v_->w = 1.0f;                                           \
    }

/* d = m * *a; (a matrix times a vector: a copy of *a transformed in place by
 * sceVu0ApplyMatrix, returned through its return slot, then operator=, xyz
 * only). The caller declares sceVu0ApplyMatrix (sceVu0.h). */
#define CVEC_SET_APPLY(d, m, a)                                 \
    {                                                           \
        cVec *a_ = (a);                                         \
        void *m_ = (m);                                         \
        cVec *t_ = &tmp_;                                       \
        cVec *r_ = &ret_;                                       \
                                                                \
        VU0_LQC2(4, a_, 0);                                     \
        VU0_SQC2_MEM(4, &tmp_, 0);                              \
        sceVu0ApplyMatrix(t_, m_, t_);                          \
        VU0_LQC2(4, t_, 0);                                     \
        VU0_SQC2_MEM(4, &ret_, 0);                              \
        if (&(d) != r_) {                                       \
            (d).x = ret_.x;                                     \
            (d).y = ret_.y;                                     \
            (d).z = ret_.z;                                     \
        }                                                       \
    }

/* cVec d(*s); (the copy constructor into a local: the whole quadword) */
#define CVEC_COPY(d, s)                                         \
    {                                                           \
        cVec *s_ = (s);                                         \
                                                                \
        VU0_LQC2(4, s_, 0);                                     \
        VU0_SQC2_MEM(4, &(d), 0);                               \
    }

#endif /* GODHAND_CVEC_H */
