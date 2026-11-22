__attribute__((section(".text.ac3cnv_search_header")))
int ac3cnv_search_header(unsigned char *p, int n)
{
    int i;

    if (n < 3)
        return 0;
    for (i = 0; i < n; i += 2) {
        if (p[i] == 0x0B && p[i + 1] == 0x77)
            break;
        if (p[i] == 0x77 && p[i + 1] == 0x0B)
            break;
    }
    return i;
}
