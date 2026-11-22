extern int SdeStrStatusGetByWorkId(int a0);
extern void *SdeStrExeOpen(void);

__attribute__((section(".text.SdeStrPlay")))
int SdeStrPlay(short id)
{
    int st;
    char *node;

    st = SdeStrStatusGetByWorkId(id);
    if (st & 8)
        return -1;
    node = SdeStrExeOpen();
    if (node == 0)
        return -1;
    *(short *)(node + 0xC) = id;
    *(short *)(node + 0) = 1;
    node[8] = 0x10;
    node[9] = 2;
    *(short *)(node + 0xA) = 2;
    *(int *)(node + 4) = 0;
    return 0;
}
