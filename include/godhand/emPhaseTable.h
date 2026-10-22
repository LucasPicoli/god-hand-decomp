#ifndef GODHAND_EMPHASETABLE_H
#define GODHAND_EMPHASETABLE_H

/* Enemy/gimmick phase table: one pointer-to-member handler per phase, indexed by the phase byte
 * (0x2F4 or 0x2F5 in the work). index >= 0 is a virtual slot in the vtable found at tableOff;
 * otherwise the handler address sits at +4. adjust is the this-pointer delta. */
typedef struct EmPhaseEnt {
    short adjust;                       /* 0x00 */
    short index;                        /* 0x02 */
    short tableOff;                     /* 0x04 */
    short unk06;
} EmPhaseEnt;
typedef struct EmPhaseTable { EmPhaseEnt e[1]; } EmPhaseTable;

/* Run the handler of phase entry `no` of table `t` on `self`. It is a macro in a bare
 * block because an inline function and a do { } while (0) both move registers; this
 * form builds byte-identical to the open-coded body. `no` is evaluated twice, as retail
 * reads the phase byte twice. The caller includes godhand/cModel.h for cVtEnt8. */
#define EM_PHASE_RUN(t, self, no)                                                   \
    {                                                                               \
        EmPhaseEnt *e_;                                                             \
        void (*fn_)(char *);                                                        \
        cVtEnt8 entry_;                                                             \
        int slot_;                                                                  \
        int index_;                                                                 \
        int adjust_;                                                                \
        int delta_;                                                                 \
                                                                                    \
        slot_ = (no) * sizeof(EmPhaseEnt);                                          \
        e_ = (EmPhaseEnt *)((char *)(t) + slot_);                                   \
        index_ = e_->index;                                                         \
        if (index_ >= 0) {                                                          \
            entry_ = (*(cVtEnt8 **)((char *)(self) + e_->tableOff))[index_ - 1];    \
            fn_ = (void (*)(char *))entry_.pfn;                                     \
        } else {                                                                    \
            fn_ = *(void (**)(char *))((char *)(t) + slot_ + 4);                    \
        }                                                                           \
        adjust_ = (t)->e[(no)].adjust;                                              \
        if (index_ >= 0) {                                                          \
            delta_ = entry_.delta + adjust_;                                        \
        } else {                                                                    \
            delta_ = adjust_;                                                       \
        }                                                                           \
        fn_((char *)(self) + delta_);                                               \
    }

#endif /* GODHAND_EMPHASETABLE_H */
