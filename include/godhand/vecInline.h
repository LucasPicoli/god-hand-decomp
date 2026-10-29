#ifndef GODHAND_VECINLINE_H
#define GODHAND_VECINLINE_H

/* 4-float compare, guarded 3-float copy and point set shared by the model/object update code. */
static inline int vec4_eq(float *a, float *b)
{
    if (a[0] != b[0] || a[1] != b[1] || a[2] != b[2] || a[3] != b[3])
        return 0;
    return 1;
}

static inline int vec4_ne(float *a, float *b)
{
    return vec4_eq(a, b) ^ 1;
}

static inline void vec3_copy(float *dst, float *src)
{
    if (dst != src) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
}

/* x, y and z; w is left alone. */
static inline void vec3_set(float *v, float x, float y, float z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

/* A point: x, y, z and w = 1. */
static inline void vec4_set_point(float *v, float x, float y, float z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = 1.0f;
}

#endif
