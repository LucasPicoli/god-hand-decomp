/* cygnus-2.96: start playback of an MWSFD handle: on a pending start, set up the stream, both channels
 * and the header reader, then reset the play state and buffers and mark it playing. */
#include "godhand/mwsfd.h"
#include "godhand/globals.h"

extern int GetD003EC7E0_3452B0(void);
extern int MWSFCRE_ResetSfdHn(MwsfdHn *);
extern void MWSST_Reset(MwsfdHn *, int);
extern void MWSFTAG_ResetAinfSj(MwsfdHn *);
extern int MWSFTAG_SetAinfSj(MwsfdHn *);
extern void MWSFTAG_InitTagInf(MwsfdHn *);
extern void Obj0000_Init_Fields_B4_B8_BC_Entries(MwsfdHn *);
extern void func_00345D10(MwsfdHn *);
extern void func_00345AF8(MwsfdHn *);
extern void func_00345F48(MwsfdHn *, int);
extern void MWSST_Pause(char *, int);
extern void MWSST_StartSj(char *);

__attribute__((section(".text.mw_sfd_start_ex")))
void mw_sfd_start_ex(MwsfdHn *m)
{
    char *b0 = (char *)&m->slot[0];

    GetD003EC7E0_3452B0();
    if (m->sfd != 0) {
        if (MWSFCRE_ResetSfdHn(m) != 0) {
            MWSFSVM_Error(D_00457EF8);
            return;
        }
        MWSST_Reset(m, 0);
        MWSST_Reset(m, 1);
        MWSFTAG_ResetAinfSj(m);
        if (MWSFTAG_SetAinfSj(m) != 0) {
            MWSFSVM_Error(D_00457F28);
            return;
        }
        MWSFTAG_InitTagInf(m);
        Obj0000_Init_Fields_B4_B8_BC_Entries(m);
    }
    func_00345D10(m);
    func_00345AF8(m);
    func_00345F48(m, m->pause);
    MWSST_Pause(b0, 1);
    MWSST_Pause((char *)&m->slot[1], 1);
    MWSST_StartSj(b0);
    MWSST_StartSj((char *)&m->slot[1]);
    m->unk84 = 0;
    m->latch = 0;
    m->stopReq = 0;
    m->stat = 1;
}
