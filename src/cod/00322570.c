/* ee-2.9-991111 */
#include "godhand/criStm.h"
#include "godhand/ehFrameObj.h"

extern void *memcpy(void *dst, const void *src, unsigned int n);

#define get_cie(f) ((DwarfFde *)((char *)&(f)->CIE_delta - (f)->CIE_delta))
#define next_fde(f) ((DwarfFde *)((char *)(f) + (f)->length + sizeof((f)->length)))

/* __frame_state_for (libgcc frame.c): find the FDE for pc_target, run its
 * CIE's and its own call-frame instructions up to that pc and copy the
 * resulting frame state to state_in; 0 when there is no FDE or the CIE is
 * unknown. */
__attribute__((section(".text.__frame_state_for")))
FrameState *__frame_state_for(void *pc_target, FrameState *state_in)
{
    DwarfFde *f;
    void *insn, *end, *pc;
    CieInfo info;
    FrameStateInternal state;

    f = func_00321F48(pc_target);
    if (f == 0)
        return 0;

    insn = func_00322030(f, &info);
    if (insn == 0)
        return 0;

    func_003A52F0(&state, 0, sizeof(state));
    state.s.retaddr_column = info.ra_regno;
    state.s.eh_ptr = info.eh_ptr;

    end = next_fde(get_cie(f));
    while (insn < end)
        insn = func_00322138(insn, &state, &info, 0);

    insn = f + 1;

    if (info.augmentation[0] == 'z') {
        int i;

        insn = func_00321938(insn, &i);
        insn += i;
    }

    end = next_fde(f);
    pc = f->pc_begin;
    while (insn < end && pc <= pc_target)
        insn = func_00322138(insn, &state, &info, &pc);

    memcpy(state_in, &state.s, sizeof(state.s));
    return state_in;
}
