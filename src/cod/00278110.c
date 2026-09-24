/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */


extern void func_002799B8(char *a0);

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void moveMotion(void *a0);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void cParts_setRotationOrder(void *a0, int a1);
extern int AllocActiveSlot_1FE218(void *a0, void *a1, int a2);
extern int cDamageUnit_AddDamageCollSphere(int a0, int a1, void *a2, float f);
extern void cCollisionSolidManage_CreateUnit(void *a0, void *a1, int a2, float f);
extern void cCollisionSolidManage_CreateSphere(void *a0, void *a1, void *a2, void *a3, float f);

extern int D_00462FC0;
extern char D_00574380[];
extern char D_00447CB8[];
extern char D_00447CC0[];

struct sph { int a; float b; int c; float d; };

__attribute__((section(".text.func_00278110")))
int func_00278110(char *a0, char *a1, void *a2)
{
    char buf[0x20];
    char *s1 = a0;
    int v0;
    int n;
    int base;
    struct sph *q;
    char *p;

    *(int *)(s1 + 0x564) = *(int *)(a1 + 0x28);
    if (func_00279938(s1) == 0) {
        return 0;
    }
    func_0028EBF0(s1, a1, a2);
    *(unsigned char *)(s1 + 0x2F4) = 0;
    *(unsigned char *)(s1 + 0x2F5) = 0;
    *(unsigned char *)(s1 + 0x2F6) = 0;
    *(unsigned char *)(s1 + 0x2F7) = 0;
    *(int *)(s1 + 0x1580) = 0;
    *(int *)(s1 + 0x1584) = 0;
    if (*(int *)(s1 + 0x564) == 0x232) {
        func_002799B8(s1);
    }
    v0 = *(int *)(s1 + 0x304);
    func_002A8578(s1, *(int *)(v0 + 0xC) + v0, *(int *)(v0 + 0x10) + v0, 0.0f, 0, 0, 0);
    moveMotion(s1);
    cModel_calcParts(s1);
    IK_InverseKinematics(s1 + 0x448, s1);
    cModel_calcWorldParts(s1);
    *(unsigned char *)(s1 + 0x616) = 1;
    *(char *)(s1 + 0x531) = -1;
    Forward_001346C8_00134608_1351D8(&D_00462FC0, s1, 0);
    cParts_setRotationOrder(s1, 4);
    *(short *)(s1 + 0x54A) = *(short *)(s1 + 0x548) = 1;
    *(int *)(s1 + 0x670) = 0;
    if (*(int *)(s1 + 0x564) != 0x232) {
        struct sph *r;
        *(int *)(s1 + 0x670) = AllocActiveSlot_1FE218(&D_00574380, s1, 1);
        n = *(unsigned char *)(s1 + 0x2B4);
        *(int *)(buf + 0x0) = n;
        {
            int one = 1;
            if (one < n) {
                base = *(int *)(*(int *)(s1 + 0x278) + 4);
            } else {
                base = 0;
            }
        }
        r = (struct sph *)(buf + 0x10);
        *(int *)(buf + 0x10) = 0;
        *(int *)(buf + 0x14) = 0;
        *(int *)(buf + 0x18) = 0;
        r->d = 1.0f;
        *(int *)(s1 + 0x674) = cDamageUnit_AddDamageCollSphere(
            *(int *)(s1 + 0x670), base + 0x80, r, 0.25f);
    }
    cCollisionSolidManage_CreateUnit(&D_00462FC0, s1, 5, 0.2f);
    q = (struct sph *)(buf + 0x0);
    *(int *)(buf + 0x0) = 0;
    q->b = 0.5f;
    *(int *)(buf + 0x8) = 0;
    q->d = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, s1, s1 + 0x80, q, 0.5f);
    *(void **)(s1 + 0x156C) = func_0014B730(s1, D_00447CB8);
    *(void **)(s1 + 0x1570) = func_0014B730(s1, D_00447CC0);
    p = *(char **)(s1 + 0x156C);
    if (p != 0) {
        *(int *)(p + 0x380) |= 1;
    }
    *(char *)(s1 + 0x617) = 1;
    *(float *)(s1 + 0x1564) = 0.02f;
    *(int *)(s1 + 0x1568) = 0;
    return 1;
}
