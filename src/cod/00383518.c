/* sn-2.95.3-136 matched TU. */

extern void PhaseObj_updatePhase(unsigned char *);
extern void ListCtl_stepSlot(unsigned char *);
extern void func_00383B60(unsigned char *, int, int);
extern void func_00383E40(unsigned char *);

__attribute__((section(".text.func_00383518")))
void func_00383518(unsigned char *arg, int arg1)
{
    switch (arg[4]) {
    case 0:
        PhaseObj_updatePhase(arg);
        break;
    case 1:
        ListCtl_stepSlot(arg);
        break;
    case 2:
    case 3:
        func_00383B60(arg, arg1, (unsigned char)(arg[4] - 2));
        break;
    case 4:
        func_00383E40(arg);
        break;
    }
}
