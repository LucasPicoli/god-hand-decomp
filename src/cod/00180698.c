/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00567FC0[];
extern unsigned char D_00567FF0[];
extern unsigned char D_00568020[];

typedef struct Vec4_180698 {
    float x;
    float y;
    float z;
    float w;
} Vec4_180698;





__attribute__((section(".text.func_00180698")))
void func_00180698(void *p, int id)
{
    Vec4_180698 *a;
    Vec4_180698 *b;
    Vec4_180698 *c;

    if (id == 0xFFFF && p != 0) {
        a = (Vec4_180698 *)D_00567FC0;
        b = (Vec4_180698 *)D_00567FF0;
        c = (Vec4_180698 *)D_00568020;
        a->x = -0.14290756f;
        a->y = 0.92530376f;
        a->z = 1.0292904f;
        a->w = 1.0f;
        b->x = -0.23296654f;
        b->y = 0.82637846f;
        b->z = 0.594337f;
        b->w = 1.0f;
        c->x = -0.053616516f;
        c->y = 1.0752624f;
        c->z = 0.76550144f;
        c->w = 1.0f;
        a++;
        b++;
        c++;
        a->x = 0.0f;
        a->y = 1.3699962f;
        a->z = 0.0f;
        a->w = 1.0f;
        b->x = 0.0f;
        b->y = 0.858702f;
        b->z = 0.0f;
        b->w = 1.0f;
        c->x = 0.0f;
        c->y = 2.136283f;
        c->z = 0.0f;
        c->w = 1.0f;
        a++;
        b++;
        c++;
        a->x = -0.1688257f;
        a->y = 0.33272955f;
        a->z = -0.013700835f;
        a->w = 1.0f;
        b->x = -0.35513958f;
        b->y = 0.44095743f;
        b->z = -0.33239797f;
        b->w = 1.0f;
        c->x = -0.01876229f;
        c->y = 0.121649444f;
        c->z = -0.009215338f;
        c->w = 1.0f;
    }
}
