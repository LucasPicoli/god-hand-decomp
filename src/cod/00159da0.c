/* sn-2.95.3-136 matched TU. */

extern float func_00156508(unsigned int v);
extern void func_00156550(float *dst, void *src);

typedef struct { char b[16]; } T16;

typedef struct QuantBox {
    unsigned char kind;                 /* 0x00 1, 3 or 5 */
    char unk01[3];
    unsigned short *range;              /* 0x04 */
    unsigned char *data;                /* 0x08 */
    char unk0C[4];
    float lo[2];                        /* 0x10 */
    float hi[2];                        /* 0x18 */
} QuantBox;

/* Decode a quantised 2D box into floats. Kind 1 stores bytes scaled by a table pair, kind 3 shorts, kind 5 floats. */
__attribute__((section(".text.QuantBox_decodeBounds")))
void QuantBox_decodeBounds(QuantBox *self)
{
    switch (self->kind) {
    case 0:
        break;
    case 1: {
        unsigned short *r;
        float sx = func_00156508(self->range[0]);
        float sy;
        T16 cp;
        int in[4];
        unsigned char *q;
        unsigned char *q4;
        sy = func_00156508(self->range[1]);
        r = self->range;
        in[0] = r[2];
        r++;    /* no-op pair: gives the range pointer two more references, */
        r--;    /* which is retail's v1/v0 pick for the four fill words */
        in[1] = r[3];
        in[2] = r[4];
        in[3] = r[5];
        cp = *(T16 *)in;
        func_00156550((float *)in, &cp);
        q = self->data;
        q4 = q - 4;
        self->lo[1] = (float)q[1] * sy + sx;
        self->hi[1] = (float)q[2] * ((float *)in)[1] + ((float *)in)[0];
        self->lo[0] = (float)q4[1] * sy + sx;
        self->hi[0] = (float)q4[3] * ((float *)in)[3] + ((float *)in)[2];
        break;
    }
    case 3: {
        unsigned short *d = (unsigned short *)self->data;
        float *r = (float *)self->range;
        unsigned short *e = d - 4;
        self->lo[1] = (float)d[1] * r[1] + r[0];
        self->hi[1] = (float)d[2] * r[3] + r[2];
        self->lo[0] = (float)e[1] * r[1] + r[0];
        self->hi[0] = (float)e[3] * r[5] + r[4];
        break;
    }
    case 5: {
        float *d = (float *)self->data;
        float *e = d - 4;
        self->lo[0] = e[1];
        self->lo[1] = d[1];
        self->hi[0] = e[3];
        self->hi[1] = d[2];
        break;
    }
    }
}
