/* sn-2.95.3-136: menu state dispatcher; states 1 and 2 share a handler indexed by state - 1. */
extern void MixChan_stepPad(char *self, void *pad);
extern void func_003822D0(char *self, void *pad, unsigned char idx);
extern void MenuCtl_toggleSndMute(char *self, void *pad);

__attribute__((section(".text.func_00381EA0")))
void func_00381EA0(char *self, void *pad)
{
    unsigned char state = self[4];

    switch (state) {
    case 0:
        MixChan_stepPad(self, pad);
        break;
    case 1:
    case 2:
        func_003822D0(self, pad, state - 1);
        break;
    case 3:
        MenuCtl_toggleSndMute(self, pad);
        break;
    }
}
