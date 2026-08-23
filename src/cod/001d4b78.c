/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00568050[];
extern unsigned char D_00568060[];
extern unsigned char D_00568070[];
extern unsigned char D_00568080[];
extern unsigned char D_005680E0[];
extern unsigned char D_005680F0[];

typedef struct Vec4_1D4B78 {
    float x;
    float y;
    float z;
    float w;
} Vec4_1D4B78;








__attribute__((section(".text.func_001D4B78")))
void func_001D4B78(void *p, int id)
{
    Vec4_1D4B78 *q;
    Vec4_1D4B78 *r;

    if (id == 0xFFFF && p != 0) {
        ((Vec4_1D4B78 *)D_00568050)->z = ((Vec4_1D4B78 *)D_00568050)->y = ((Vec4_1D4B78 *)D_00568050)->x = 0.0f;
        ((Vec4_1D4B78 *)D_00568050)->w = 1.0f;
        q = (Vec4_1D4B78 *)D_00568080;
        q->x = -0.25f;
        q->y = 0.12f;
        q->z = 0.0f;
        q->w = 1.0f;
        q++;
        q->x = -0.121999994f;
        q->y = 0.12f;
        q->z = 0.0f;
        q->w = 1.0f;
        q++;
        q->x = 0.006000012f;
        q->y = 0.12f;
        q->z = 0.0f;
        q->w = 1.0f;
        q++;
        q->x = 0.134f;
        q->y = 0.12f;
        q->z = 0.0f;
        q->w = 1.0f;
        q++;
        q->x = 0.26200002f;
        q->y = 0.12f;
        q->z = 0.0f;
        q->w = 1.0f;
        q++;
        ((Vec4_1D4B78 *)D_00568060)->x = 0.08f;
        ((Vec4_1D4B78 *)D_00568060)->y = 0.12f;
        ((Vec4_1D4B78 *)D_00568060)->z = 0.0f;
        ((Vec4_1D4B78 *)D_00568060)->w = 1.0f;
        ((Vec4_1D4B78 *)D_00568070)->x = -0.25f;
        ((Vec4_1D4B78 *)D_00568070)->y = 0.12f;
        ((Vec4_1D4B78 *)D_00568070)->z = 0.0f;
        ((Vec4_1D4B78 *)D_00568070)->w = 1.0f;
        q->x = 0.39000005f;
        q->y = 0.12f;
        q->z = 0.0f;
        q->w = 1.0f;
        ((Vec4_1D4B78 *)D_005680E0)->x = -0.25f;
        ((Vec4_1D4B78 *)D_005680E0)->y = -0.05f;
        ((Vec4_1D4B78 *)D_005680E0)->z = 0.0f;
        ((Vec4_1D4B78 *)D_005680E0)->w = 1.0f;
        r = (Vec4_1D4B78 *)D_005680F0;
        r->x = -0.25f;
        r->y = -0.05f;
        r->z = 0.0f;
        r->w = 1.0f;
        r++;
        r->x = -0.121999994f;
        r->y = -0.05f;
        r->z = 0.0f;
        r->w = 1.0f;
        r++;
        r->x = 0.006000012f;
        r->y = -0.05f;
        r->z = 0.0f;
        r->w = 1.0f;
        r++;
        r->x = 0.134f;
        r->y = -0.05f;
        r->z = 0.0f;
        r->w = 1.0f;
        r++;
        r->x = 0.26200002f;
        r->y = -0.05f;
        r->z = 0.0f;
        r->w = 1.0f;
        r++;
        r->x = 0.39000005f;
        r->y = -0.05f;
        r->z = 0.0f;
        r->w = 1.0f;
    }
}
