extern void func_0037D820(void *self);
extern void func_00378070(void *p);

__attribute__((section(".text.vregFadeControl")))
void vregFadeControl(unsigned short *self)
{
    unsigned short f = self[0];
    if ((f & 0x40) == 0)
        return;
    if (*(short *)((char *)self + 0x30) == *(short *)((char *)self + 0x32)) {
        self[0] = f | 0x20;
        func_0037D820(self);
        return;
    }
    func_00378070((char *)self + 0x30);
    self[3] = self[3] | 0x9;
}
