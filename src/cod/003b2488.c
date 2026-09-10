/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */
#include "godhand/gp.h"

typedef struct {
    void *func;
    void *data;
    void *gp;
} SifCmdHandlerData;

typedef struct {
    char pad0[0xC];
    SifCmdHandlerData *sys_cmd_handlers;
    int sys_cmd_handlers_max;
    SifCmdHandlerData *usr_cmd_handlers;
    int usr_cmd_handlers_max;
} SifCmdData;

extern SifCmdData D_0077E518;

__attribute__((section(".text.func_003B2488")))
void func_003B2488(unsigned int fid, void *func, void *data)
{
    if (fid & 0x80000000) {
        D_0077E518.sys_cmd_handlers[fid & 0x7FFFFFFF].func = func;
        D_0077E518.sys_cmd_handlers[fid & 0x7FFFFFFF].data = data;
        D_0077E518.sys_cmd_handlers[fid & 0x7FFFFFFF].gp = GetGp();
    } else {
        D_0077E518.usr_cmd_handlers[fid].func = func;
        D_0077E518.usr_cmd_handlers[fid].data = data;
        D_0077E518.usr_cmd_handlers[fid].gp = GetGp();
    }
}
