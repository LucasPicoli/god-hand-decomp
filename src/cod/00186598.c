/* sn-2.95.3-136 matched TU. */

extern float func_0031CF30(void);
extern int Forward30F348_31CFE0(void);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_00186598")))
void func_00186598(void *a0, float x)
{
    char *p;
    float t;
    float r;

    p = (char *)a0;
    if (x > 20.0f) {
        x = 20.0f;
    }
    if (x < 5.0f) {
        x = 5.0f;
    }
    t = x / 20.0f;
    *(float *)(p + 0xE10) = t * 0.09f;
    r = func_0031CF30();
    t = t * 0.034906585f;
    *(float *)(p + 0xE14) = t * r;
    r = func_0031CF30();
    *(float *)(p + 0xE18) = t * r;
    if (Forward30F348_31CFE0() & 1) {
        *(float *)(p + 0xE1C) = 0.0f;
    } else {
        *(float *)(p + 0xE1C) = 3.14159274f;
    }
}
