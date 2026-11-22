extern int func_003A5148(int, int, int);

__attribute__((section(".text.appendUd")))
void appendUd(char *object, void *source, int count)
{
    char *header = object + 0x14C;
    int offset = *(int *)(header + 8);
    int size = *(int *)(header + 4);
    void *base = *(void **)header;
    int remaining = size - offset;
    if (count < remaining)
        remaining = count;
    *(int *)(header + 8) = offset + remaining;
    func_003A5148((int)((char *)base + offset), (int)source, remaining);
}
