/* sn-2.95.3-136 matched TU. */

extern float D_005FEE00[];
extern short D_003F2060[];
extern int Obj0000_Get_D_0076A7A4_3756F0(void);

/* sn-2.95.3-136 matched TU. */






__attribute__((section(".text.func_00373FF0")))
void func_00373FF0(char *p, int idx, float x)
{
    float t;

    if (*(int *)p == 0) {
        return;
    }
    t = x * D_005FEE00[idx] / 127.0f;
    t = t * *(float *)((char *)&D_005FEE00[idx] + 12) / 127.0f;
    if (Obj0000_Get_D_0076A7A4_3756F0() == 2) {
        t = t * *(float *)(p + 0x34);
    }
    t = t * *(float *)(p + 0x2C);
    if (t >= 127.0f) {
        t = 127.0f;
    }
    func_0032A9F0(*(int *)p, D_003F2060[(int)t]);
    *(float *)(p + 0x14) = x;
}
