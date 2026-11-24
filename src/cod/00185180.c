extern void func_001851C0(void *, unsigned int);

__attribute__((section(".text.func_00185180")))
void func_00185180(unsigned char *self)
{
    if (self[0x65B] != 0)
        return;
    func_001851C0(self, 4);
    self[0x65B] = 1;
}
