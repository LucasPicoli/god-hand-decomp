/* cygnus-2.96 matched TU. */
extern void func_0033BE80(void);
extern int D_00760D80; /* Reset word; no other observed retail references. */
extern int D_00760D84; /* Callback ID for "MWSFSVR_VsyncThrdProc". */
extern int D_00760D88; /* Callback ID for "MWSFSVR_IdleThrdProc". */
extern int D_00760D8C; /* Callback ID for "MWSFSVR_MainThrdProc". */

/* Initialize the server manager and reset the Sofdec callback registration IDs. */
__attribute__((section(".text.MWSFSVM_Init")))
void MWSFSVM_Init(void)
{
    func_0033BE80();
    D_00760D80 = 0;
    D_00760D84 = 0;
    D_00760D88 = 0;
    D_00760D8C = 0;
}
