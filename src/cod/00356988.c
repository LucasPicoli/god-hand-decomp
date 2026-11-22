extern void viBufFlush(void *);

__attribute__((section(".text.SFMPVP_Flush")))
void SFMPVP_Flush(char *self, int value)
{
    char *base = *(char **)(self + 0x1FC0);
    char *slot = base + 0x1128;
    if (*(int *)(slot + 0x1C) != 1) {
        viBufFlush(base + 0x1198);
        *(int *)(slot + 0x1C) = 1;
        *(int *)(slot + 0x20) = value;
    }
}
