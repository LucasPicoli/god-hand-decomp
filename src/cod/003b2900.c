/* ee-2.9-991111 */
#include "godhand/eeKernel.h"
#include "godhand/sif.h"

#define UNCACHED(p) ((void *)((unsigned int)(p) | 0x20000000))

/* Set up the RPC layer once: the packet tables, the four RPC command
 * handlers, and on first boot the init command to the IOP. mode is not read. */
__attribute__((section(".text.sceSifInitRpc")))
void sceSifInitRpc(int mode)
{
    sceSifCmdHdr *cmd;

    func_003B63A0();
    if (D_003FAE54 != 0) {
        EIntr();
        return;
    }
    D_003FAE54 = 1;
    EIntr();
    func_003B21D0();
    func_003B63A0();
    D_0077FF40.pktTable = UNCACHED(D_0077E740);
    D_0077FF40.pktTableLen = SIF_RPC_TABLE_LEN;
    D_0077FF40.unk0C = 0;
    D_0077FF40.unk10 = 0;
    D_0077FF40.rdataTable = UNCACHED(D_0077EF40);
    D_0077FF40.rdataTableLen = SIF_RPC_TABLE_LEN;
    D_0077FF40.clientTable = UNCACHED(D_0077F740);
    D_0077FF40.clientTableLen = SIF_RPC_TABLE_LEN;
    D_0077FF40.rdataTableIdx = 0;
    D_0077FF40.pid = 1;
    func_003B2488(SIF_CMD_RPC_END, _request_end, &D_0077FF40);
    func_003B2488(SIF_CMD_RPC_BIND, func_003B2E78, &D_0077FF40);
    func_003B2488(SIF_CMD_RPC_CALL, _request_call, &D_0077FF40);
    func_003B2488(SIF_CMD_RPC_RDATA, func_003B2D10, &D_0077FF40);
    EIntr();
    if (SifGetReg(SIF_SYSREG_RPCINIT) != 0) {
        return;
    }
    cmd = (sceSifCmdHdr *)&D_0077E740[64];
    cmd->opt = 1;
    sceSifSendCmd(SIF_CMD_INIT_CMD, cmd, 16, 0, 0, 0);
    while (func_003B2058(0) == 0) {
    }
    SifSetReg(SIF_SYSREG_RPCINIT, 1);
}
