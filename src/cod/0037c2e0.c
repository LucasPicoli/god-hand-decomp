extern short SdeVregRndPchGet(void *);
extern void SdeVregOutPchCalc(void *);

__attribute__((section(".text.vregPchSet")))
void vregPchSet(char *dst, char *src)
{
    *(short *)(dst + 0x46) = SdeVregRndPchGet(src + 0x20);
    *(unsigned short *)(dst + 0x48) = *(unsigned short *)(src + 0x3C);
    *(unsigned short *)(dst + 0x2E) = *(unsigned short *)(src + 0x1E);
    SdeVregOutPchCalc(dst);
}
