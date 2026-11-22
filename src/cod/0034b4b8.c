/* cygnus-2.96 matched TU. */

extern void SFTIM_GetTimeOneFrmVideo(void *h, int *a, int *b);


__attribute__((section(".text.sfadxt_GetTimeOneFrmAudio")))
void sfadxt_GetTimeOneFrmAudio(void *h, int *out, void *p)
{
    int a;
    int b;

    SFTIM_GetTimeOneFrmVideo(h, &a, &b);
    *out = UTY_MulDiv(p, a, b);
}
