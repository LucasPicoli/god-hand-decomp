/* sn-2.95.3-136 matched TU. */

extern void func_002D65D0(void *a0, void *a1);
extern void func_002D65A0(void *a0, int a1);
extern void func_002D6838(void *a0, int a1, int a2);

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_001F5510")))
void func_001F5510(char *p, int a, int b)
{
    float v;
    float t;

    func_002D65D0(p + 0x30D0, &v);
    t = (float)b / (float)a;
    if (t > 1.0f) {
        t = 1.0f;
    }
    func_002D65A0(p + 0x31C8, (int)(v * t));
    func_002D6838(p + 0x2F5C, -3, 0x10);
    func_002D6838(p + 0x2FD8, 3, 0x10);
}
