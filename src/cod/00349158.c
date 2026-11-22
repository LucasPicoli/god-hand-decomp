/* cygnus-2.96 matched TU. */

extern void mwlSfdExecDecSvrPrep(void *);
extern void func_003490B0(void *);
extern void mwsfd_CheckFsErr(void *);
extern void func_003466F0(void *);

__attribute__((section(".text.mwSfdExecDecSvrHndl")))
int mwSfdExecDecSvrHndl(void *p)
{
    switch (*(int *)((char *)p + 4)) {
    case 1:
        mwlSfdExecDecSvrPrep(p);
        break;
    case 2:
        func_003490B0(p);
        break;
    case 0:
    case 3:
    case 4:
        break;
    }
    mwsfd_CheckFsErr(p);
    func_003466F0(p);
    return 0;
}
