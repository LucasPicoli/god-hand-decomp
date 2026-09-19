/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */

typedef struct ErrInf { int w[5]; } ErrInf;
typedef struct H { int f0; ErrInf err; } H;

extern int Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(H *h);
extern void M2VERR_SetCode(int a, int b);

__attribute__((section(".text.M2V_GetErrInf")))
void M2V_GetErrInf(H *h, ErrInf *out)
{
    if (Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(h) != 0) {
        M2VERR_SetCode(0, 0xFF030204);
        return;
    }
    *out = h->err;
}
