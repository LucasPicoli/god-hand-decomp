/* cygnus-2.96: start playback of an MWSFD handle: on a pending start, set up the stream, both channels
 * and the header reader, then reset the play state and buffers and mark it playing. */
#include "godhand/mwsfd.h"
#include "godhand/globals.h"

extern int GetD003EC7E0_3452B0(void);
extern int func_00343D68(MwsfdHn *);
extern void func_003487C0(MwsfdHn *, int);
extern void func_00347420(MwsfdHn *);
extern int func_003473A0(MwsfdHn *);
extern void func_00347400(MwsfdHn *);
extern void Obj0000_Init_Fields_B4_B8_BC_Entries(MwsfdHn *);
extern void func_00345D10(MwsfdHn *);
extern void func_00345AF8(MwsfdHn *);
extern void func_00345F48(MwsfdHn *, int);
extern void func_00348550(char *, int);
extern void func_00348440(char *);

__attribute__((section(".text.func_00345BE0")))
void func_00345BE0(MwsfdHn *m)
{
    char *b0 = (char *)&m->slot[0];

    GetD003EC7E0_3452B0();
    if (m->sfd != 0) {
        if (func_00343D68(m) != 0) {
            MWSFSVM_Error(D_00457EF8);
            return;
        }
        func_003487C0(m, 0);
        func_003487C0(m, 1);
        func_00347420(m);
        if (func_003473A0(m) != 0) {
            MWSFSVM_Error(D_00457F28);
            return;
        }
        func_00347400(m);
        Obj0000_Init_Fields_B4_B8_BC_Entries(m);
    }
    func_00345D10(m);
    func_00345AF8(m);
    func_00345F48(m, m->pause);
    func_00348550(b0, 1);
    func_00348550((char *)&m->slot[1], 1);
    func_00348440(b0);
    func_00348440((char *)&m->slot[1]);
    m->unk84 = 0;
    m->latch = 0;
    m->stopReq = 0;
    m->stat = 1;
}
