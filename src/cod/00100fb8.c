/* sn-2.95.3-136 */
#include "godhand/cloth.h"

/* Static initialisation of the costume cloth sphere tables. */
__attribute__((section(".text.func_00100FB8")))
void func_00100FB8(int init, int priority)
{
    if (priority == 0xFFFF && init) {
        {
            ClothSphere *p = D_00460E00;

            CLOTH_SPHERE_SET(p, 17, 17, 1.0f, 0.15f, 0.0f, -0.2f, 0.0f, 0.0f, -0.2f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 17, 17, 1.0f, 0.15f, 0.0f, -0.3f, 0.0f, 0.0f, -0.3f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 18, 18, 1.0f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 18, 19, 0.66f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 18, 19, 0.33f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 19, 19, 1.0f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 19, 20, 0.33f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 22, 22, 1.0f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 22, 23, 0.66f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 22, 23, 0.33f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 23, 23, 1.0f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 23, 24, 0.33f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
        }

        {
            ClothSphere *p = D_00461040;

            CLOTH_SPHERE_SET(p, 17, 17, 1.0f, 0.17f, 0.0f, -0.18f, 0.0f, 0.0f, -0.18f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 18, 18, 1.0f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 18, 19, 0.66f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 18, 19, 0.33f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 19, 19, 1.0f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 19, 20, 0.33f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 22, 22, 1.0f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 22, 23, 0.66f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 22, 23, 0.33f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 23, 23, 1.0f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 23, 24, 0.33f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
        }

        {
            ClothSphere *p = D_00461250;

            CLOTH_SPHERE_SET(p, 17, 17, 1.0f, 0.15f, 0.0f, -0.15f, 0.0f, 0.0f, -0.15f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 18, 18, 1.0f, 0.115f, 0.02f, 0.04f, 0.0f, 0.02f, 0.04f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 18, 18, 1.0f, 0.12f, 0.02f, 0.04f, -0.05f, 0.02f, 0.04f, -0.05f)
            p++;
            CLOTH_SPHERE_SET(p, 18, 19, 0.1f, 0.1f, 0.01f, 0.0f, 0.0f, 0.01f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 22, 22, 1.0f, 0.115f, -0.02f, 0.04f, 0.0f, -0.02f, 0.04f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 22, 22, 1.0f, 0.115f, -0.02f, 0.04f, -0.05f, -0.02f, 0.04f, -0.05f)
            p++;
            CLOTH_SPHERE_SET(p, 22, 23, 0.1f, 0.1f, -0.01f, 0.0f, 0.0f, -0.01f, 0.0f, 0.0f)
        }

        {
            ClothSphere *p = D_004613A0;

            CLOTH_SPHERE_SET(p, 17, 17, 1.0f, 0.18f, 0.0f, -0.15f, 0.0f, 0.0f, -0.15f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 17, 17, 1.0f, 0.15f, 0.0f, -0.3f, 0.0f, 0.0f, -0.3f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 18, 18, 1.0f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 18, 19, 0.66f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 18, 19, 0.33f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 19, 19, 1.0f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 19, 20, 0.33f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 22, 22, 1.0f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 22, 23, 0.66f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 22, 23, 0.33f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 23, 23, 1.0f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 23, 24, 0.33f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
        }
    }
}
