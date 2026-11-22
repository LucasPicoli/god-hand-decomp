/* cygnus-2.96: sfmpv_DecodeSomePic, decode chunks until stopped (+0x60), an error, or no more data;
 * then flush. Returns the last error. */
extern int sfmpv_GetActiveSize(char *self, int *data, int *len, int *arg);
extern int sfmpv_DecodeOneUnit(char *self, int data, int len, int arg, int *more);
extern void sfmpv_UpdateFlowCnt(char *self);

__attribute__((section(".text.sfmpv_DecodeSomePic")))
int sfmpv_DecodeSomePic(char *self)
{
    int data, len, arg, more;
    int r = 0;

    while (*(int *)(self + 0x60) == 0) {
        r = sfmpv_GetActiveSize(self, &data, &len, &arg);
        if (r != 0)
            break;
        r = sfmpv_DecodeOneUnit(self, data, len, arg, &more);
        if (r != 0)
            break;
        if (more == 0)
            break;
    }
    sfmpv_UpdateFlowCnt(self);
    return r;
}
