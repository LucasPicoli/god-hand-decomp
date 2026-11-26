/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */
extern int sftim_IsAudioStagnant(void *h);


#define SFTIM_ERR_STAGNANT  0xFF000222   /* the audio clock stopped advancing */

/* Reports a stagnant audio clock as an error and returns 1, else returns 0. */
__attribute__((section(".text.SFTIM_IsStagnant")))
int SFTIM_IsStagnant(void *h)
{
    int ret = sftim_IsAudioStagnant(h);

    if (ret != 0) {
        func_0034DD70(h, SFTIM_ERR_STAGNANT);
        return 1;
    }
    return ret;
}
