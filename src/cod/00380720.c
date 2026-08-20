/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_00380720")))
void func_00380720(void *self, int a, int b, int *hh, int *mm, int *ss, int *cc)
{
    int v;

    if (a <= 0) {
        v = 0;
        if (b <= 0) {
            goto done;
        }
    }
    v = (int)((float)b / (float)a * 100.0f);
done:
    *hh = v / 360000;
    *mm = v / 6000 - *hh * 60;
    *ss = v / 100 - *hh * 3600 - *mm * 60;
    *cc = v % 100;
}
