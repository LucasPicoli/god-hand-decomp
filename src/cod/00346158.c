/* cygnus-2.96 */

extern int Forward328098_349B88(void *);
extern int SFD_TermSupply(void *);

__attribute__((section(".text.mwPlyChkSupply")))
void mwPlyChkSupply(char *self)
{
    void *object = *(void **)(self + 0x40);
    void *other = *(void **)(self + 0x3C);
    if (object == 0)
        return;
    if (Forward328098_349B88(object) != 3)
        return;
    SFD_TermSupply(other);
}
