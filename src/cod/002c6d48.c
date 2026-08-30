/* sn-2.95.3-136 matched TU. */

extern int cIDManager_getTexAddr(void *a0, int a1, int a2);
extern void *D_003C2388;

/* sn-2.95.3-136 matched TU. */


extern void func_002C6550(void *a0, int a1, float u0, float v0, float u1, float v1,
                          float s0, float t0, float s1, float t1, void *a2);



__attribute__((section(".text.func_002C6D48")))
void func_002C6D48(void *a0, int a1, void *a2, short a3, float u0, float v0, float u1, float v1, int t0) {
    void *s1 = a0;
    void *s2 = a2;
    int tex;
    int m;

    m = (unsigned short)t0;
    if (a3 == 0) {
        tex = cIDManager_getTexAddr(D_003C2388, 1, 0x1C);
    } else {
        tex = cIDManager_getTexAddr(D_003C2388, m, a3 + 1);
    }
    if (tex == 0) {
        tex = cIDManager_getTexAddr(D_003C2388, 1, 0x1C);
    }
    switch (a1) {
    case 0:
        func_002C6550(s1, tex, u0, v0, u1, v1, 0.0f, 0.0f, 0.25f, 0.25f, s2);
        break;
    case 1:
        func_002C6550(s1, tex, u0, v0, u1, v1, 0.25f, 0.0f, 0.5f, 0.25f, s2);
        break;
    case 2:
        func_002C6550(s1, tex, u0, v0, u1, v1, 0.5f, 0.0f, 0.75f, 0.25f, s2);
        break;
    case 3:
        func_002C6550(s1, tex, u0, v0, u1, v1, 0.75f, 0.0f, 1.0f, 0.25f, s2);
        break;
    case 4:
        func_002C6550(s1, tex, u0, v0, u1, v1, 0.0f, 0.25f, 0.25f, 0.5f, s2);
        break;
    case 5:
        func_002C6550(s1, tex, u0, v0, u1, v1, 0.25f, 0.25f, 0.5f, 0.5f, s2);
        break;
    case 6:
        func_002C6550(s1, tex, u0, v0, u1, v1, 0.5f, 0.25f, 0.75f, 0.5f, s2);
        break;
    case 7:
        func_002C6550(s1, tex, u0, v0, u1, v1, 0.75f, 0.25f, 1.0f, 0.5f, s2);
        break;
    case 8:
        func_002C6550(s1, tex, u0, v0, u1, v1, 0.0f, 0.5f, 0.25f, 0.75f, s2);
        break;
    case 9:
        func_002C6550(s1, tex, u0, v0, u1, v1, 0.25f, 0.5f, 0.5f, 0.75f, s2);
        break;
    case -1:
        func_002C6550(s1, tex, u0, v0, u1, v1, 0.5f, 0.75f, 0.75f, 1.0f, s2);
        break;
    case -2:
        func_002C6550(s1, tex, u0, v0, u1, v1, 0.5f, 0.5f, 0.75f, 0.75f, s2);
        break;
    case -3:
        func_002C6550(s1, tex, u0, v0, u1, v1, 0.75f, 0.5f, 1.0f, 0.75f, s2);
        break;
    default:
        func_002C6550(s1, tex, u0, v0, u1, v1, 0.75f, 0.5f, 1.0f, 0.75f, s2);
        break;
    }
}
