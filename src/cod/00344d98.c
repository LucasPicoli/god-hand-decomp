/* cygnus-2.96: mwsffrm_SetSudDatInf, look up the payload of the source block at +0x38 into dst +0x88/+0x8C. */
typedef struct {
    char *data;
    int size;
} SrcBlock;

extern void SUD_SearchSudDat(char *data, int size, int *out, int *outLen);

__attribute__((section(".text.mwsffrm_SetSudDatInf")))
void mwsffrm_SetSudDatInf(void *unused, char *src, char *dst)
{
    int ptr = 0;
    SrcBlock *b = *(SrcBlock **)(src + 0x38);
    int size = b->size;
    char *data = b->data;
    int len = 0;

    *(int *)(dst + 0x88) = 0;
    *(int *)(dst + 0x8C) = 0;
    if (data != 0 && size >= 5)
        SUD_SearchSudDat(data + 4, size - 4, &ptr, &len);
    if (ptr != 0 && len > 0) {
        *(int *)(dst + 0x88) = ptr;
        *(int *)(dst + 0x8C) = len;
    }
}
