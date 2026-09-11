/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */




__attribute__((section(".text.func_003B3958")))
int func_003B3958(void *sd, int cmd, int mode, void *send, int ssize,
                  void *recv, int rsize, void *endfunc, void *efarg, int nowait)
{
    int i;
    int d;
    int err;

    d = 1;
    i = 0;
    do {
        err = (unsigned int)func_003B3128(sd, cmd, mode, send, ssize, recv,
                                          rsize, endfunc, efarg) >> 31;
        if (err == 0)
            break;
        if (nowait)
            break;
        DelayThread(d * 1000);
        if (d < 127)
            d = d * 2;
        i++;
    } while (i < 101);
    return err;
}
