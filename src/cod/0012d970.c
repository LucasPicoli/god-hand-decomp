/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"


extern int D_0041D5A8;
extern int D_0041D558;

typedef struct { char b[0x10]; } Blob16;

/* Hit record with six 16-byte blobs: place the owner, two positions, two extents and the blobs, tag each blob with the no-link value 0xFFFF and mark the record ready. */
__attribute__((section(".text.cHitRec_constructSixBlob")))
void *cHitRec_constructSixBlob(char *self, char *obj, int flags, float *v1, float *v2, float *ext,
                    char *b1, char *b2, char *b3, char *b4, char *b5, char *b6)
{
    char *p;
    int i;
    float x;
    float y;
    float z;

    *(int *)(self + 0x5C) = (int)&D_0041D5A8;
    *(int *)(self + 0x8) = 0;
    VU0_SQC2_VF0(self, 0x10);
    VU0_SQC2_VF0(self, 0x20);
    *(int *)(self + 0x58) = 0;
    *(int *)(self + 0x30) = 0;
    *(int *)(self + 0x0) = 0;
    *(int *)(self + 0x54) = 0;
    func_003A52F0(self + 0x34, 0, 0x20);
    *(int *)(self + 0x5C) = (int)&D_0041D558;
    VU0_SQC2_VF0(self, 0x60);
    VU0_SQC2_VF0(self, 0x70);
    VU0_SQC2_VF0(self, 0x80);
    VU0_SQC2_VF0(self, 0x90);
    VU0_SQC2_VF0(self, 0xA0);
    p = self + 0x110;
    i = 7;
    do {
        VU0_SQC2_VF0(p, 0x0);
        i--;
        p += 0x10;
    } while (i != -1);
    *(int *)(self + 0x58) = flags;
    *(int *)(self + 0x4) = 2;
    *(int *)(self + 0x30) = (int)obj;
    {
        float *d = (float *)(self + 0x60);
        float *s = *(float **)(obj + 0xF0);
        if (d != s) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }
    }
    {
        float *d = (float *)(self + 0x70);
        if (d != v1) { d[0] = v1[0]; d[1] = v1[1]; d[2] = v1[2]; }
    }
    {
        float *d = (float *)(self + 0x80);
        float *s = (float *)(obj + 0x100);
        if (d != s) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }
    }
    {
        float *d = (float *)(self + 0x90);
        if (d != v2) { d[0] = v2[0]; d[1] = v2[1]; d[2] = v2[2]; }
    }
    x = ext[0];
    if (x < 0.0f) x = -x;
    *(float *)(self + 0xA0) = x;
    y = ext[1];
    if (y < 0.0f) y = -y;
    *(float *)(self + 0xA4) = y;
    z = ext[2];
    if (z < 0.0f) z = -z;
    *(float *)(self + 0xA8) = z;
    *(Blob16 *)(self + 0xB0) = *(Blob16 *)b1;
    *(unsigned short *)(self + 0xB8) = 0xFFFF;
    *(char *)(self + 0xBB) = 0;
    *(char *)(self + 0xBA) = 0;
    *(Blob16 *)(self + 0xC0) = *(Blob16 *)b2;
    *(unsigned short *)(self + 0xC8) = 0xFFFF;
    *(char *)(self + 0xCB) = 0;
    *(char *)(self + 0xCA) = 0;
    *(Blob16 *)(self + 0xD0) = *(Blob16 *)b3;
    *(unsigned short *)(self + 0xD8) = 0xFFFF;
    *(char *)(self + 0xDB) = 0;
    *(char *)(self + 0xDA) = 0;
    *(Blob16 *)(self + 0xE0) = *(Blob16 *)b4;
    *(unsigned short *)(self + 0xE8) = 0xFFFF;
    *(char *)(self + 0xEB) = 0;
    *(char *)(self + 0xEA) = 0;
    *(Blob16 *)(self + 0xF0) = *(Blob16 *)b5;
    *(unsigned short *)(self + 0xF8) = 0xFFFF;
    *(char *)(self + 0xFB) = 0;
    *(char *)(self + 0xFA) = 0;
    *(Blob16 *)(self + 0x100) = *(Blob16 *)b6;
    *(unsigned short *)(self + 0x108) = 0xFFFF;
    *(char *)(self + 0x10B) = 0;
    *(char *)(self + 0x10A) = 0;
    *(int *)(self + 0x8) = *(int *)(self + 0x8) | 5;
    return self;
}
