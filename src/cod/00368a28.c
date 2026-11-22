#define MPS_DELIM_PACK    0x10000
#define MPS_DELIM_SYSHDR  0x20000
#define MPS_DELIM_PES     0x40000
#define MPS_DELIM_END     0x80000

__attribute__((section(".text.MPS_CheckDelim")))
int MPS_CheckDelim(const unsigned char *p)
{
    unsigned char c;

    if (p[0] == 0 && p[1] == 0 && p[2] == 1) {
        c = p[3];
        switch (c) {
        case 0xBA:
            return MPS_DELIM_PACK;
        case 0xBB:
            return MPS_DELIM_SYSHDR;
        case 0xB9:
            return MPS_DELIM_END;
        default:
            if (c >= 0xBC)
                return MPS_DELIM_PES;
            break;
        }
    }
    return 0;
}
