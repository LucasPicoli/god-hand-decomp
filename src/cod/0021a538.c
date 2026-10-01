/* SN ProDG ee-gcc 2.95.3 matched TU. */
/* src/cod/0021a5.c — func_0021A538: player action / move-state dispatcher.
 *
 * The second-largest function in the binary (22,552 B / 5,638 insns).
 * It is the per-frame state machine that drives the player/character
 * object (`arg0`) through its action and move states.  Observed layout
 * of the fields it touches on `arg0`:
 *
 *   0x304  move-data table pointer (sub-object holding per-move frame
 *          offsets at 0x12C..0x6C0, e.g. 0x1DC/0x1E4 hit windows)
 *   0x564  current action-state id (the dispatch key; 0x200..0x27E)
 *   0x5F0  state timer (counts down; a handful of states do a float
 *          round-trip on it via cvt.s.w / cvt.w.s)
 *   0x5F4  per-state sub-phase flag        0x5FC / 0x60C  scratch
 *   0x600/0x604/0x608  float params (angle / speed / scale)
 *   0x16D4 status-flag bitfield (|=0x400 on entry)
 *   0x16E4 float status param
 *   0x186A action sub-mode byte
 *   0x2F6/0x2F7 input/option byte flags
 *
 * Dispatch is via 13 jump tables (reconstructed below as switch()es):
 * a 125-way table on (state - 0x202) at the head, a 116-way table on
 * (state - 0x20B), a 59-way table on (state - 0x200), and eleven small
 * 5-8-way sub-dispatches selected by `Forward30F348_31CFE0() % N` (an input /
 * RNG poll).  Helpers it leans on:
 *
 *   StoreMotionParamsBoth_2609A8(actor, anim, a, b)  set animation / pose for a state
 *   cCoreSave_getGameLevel(&D_00569B70) the game level, 1..5; ==5 picks the
 *                                     hardest level's variant in many branches
 *   Forward30F348_31CFE0()                   poll input / RNG bits (masked &1,
 *                                     or used as the % N sub-selector)
 *   CheckSlotsShort2FEAndSetByte1864_262A10(actor)              per-frame pre-update
 *   Obj0000_Get_D_00747A94_2DB6B0()                   fetch a global system object
 *
 * Clean-C body under the NON_MATCHING guard.  The default `us`
 * build compiles the `#else INCLUDE_ASM` branch, which pulls the
 * byte-exact retail carve (the full ELF sha256 is unchanged).  The
 * `us-nm` build (`-DNON_MATCHING`, scripts/score_nm.sh) compiles the
 * clean-C body and scores it into progress/report.nm.json; an exact
 * re-match is still owed.  First pass produced by m2c (the jump tables
 * were reassembled so they recover as switch()es) and cleaned into the
 * project's house-style typed offset casts; semantics of the named
 * helpers above are inferred from call shape, not yet fully verified.
 */
/* This function's 13 jump tables (D_00437150..D_00437580 in
 * asm/data/cod/31B580.rodata.s) reference in-function labels by name (the
 * first entry of each table). The monolithic exported those labels via
 * macro.inc's global `jlabel`; carving the function into its own TU means
 * the carve must re-export them or the rodata fails to link. Select macro.inc
 * here so `jlabel` stays global. The final ELF is --strip-all, so label
 * visibility cannot perturb the retail bytes / sha256. */
#define INCLUDE_ASM_USE_MACRO_INC 1
#include "include_asm.h"
#include "godhand/cCoreSave.h"

typedef signed char        s8;
typedef unsigned char      u8;
typedef signed short       s16;
typedef unsigned short     u16;
typedef signed int         s32;
typedef unsigned int       u32;
typedef signed long long   s64;
typedef unsigned long long u64;
typedef float              f32;
typedef double             f64;

#ifdef NON_MATCHING
__attribute__((section(".text.func_0021A538")))
void func_0021A538(void *arg0) {
    s32 sp0;
    s32 sp4;
    s32 var_a1_4;
    s32 var_a1_5;
    s32 var_a1_6;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_a2_4;
    s32 var_a2_5;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_s5;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 var_f20;
    s32 temp_a0_11;
    s32 temp_a0_2;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a0_6;
    s32 temp_a0_7;
    s32 temp_a0_8;
    s32 temp_a0_9;
    s32 temp_a1_150;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_s0_2;
    s32 temp_v0_147;
    s32 temp_v0_152;
    s32 temp_v0_166;
    s32 temp_v0_167;
    s32 temp_v0_168;
    s32 temp_v0_169;
    s32 temp_v0_19;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1_100;
    s32 temp_v1_101;
    s32 temp_v1_104;
    s32 temp_v1_13;
    s32 temp_v1_15;
    s32 temp_v1_19;
    s32 temp_v1_27;
    s32 temp_v1_32;
    s32 temp_v1_35;
    s32 temp_v1_48;
    s32 temp_v1_50;
    s32 temp_v1_58;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a1_3;
    s32 var_s0;
    s32 var_s6;
    s32 var_v0;
    s32 var_v0_10;
    s32 var_v0_11;
    s32 var_v0_12;
    s32 var_v0_13;
    s32 var_v0_14;
    s32 var_v0_15;
    s32 var_v0_16;
    s32 var_v0_17;
    s32 var_v0_18;
    s32 var_v0_19;
    s32 var_v0_20;
    s32 var_v0_21;
    s32 var_v0_22;
    s32 var_v0_23;
    s32 var_v0_24;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v0_7;
    s32 var_v0_8;
    s32 var_v0_9;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    u16 temp_v1_103;
    u32 temp_a0_10;
    u32 temp_a0_3;
    u32 temp_a1;
    u32 temp_a1_100;
    u32 temp_a1_101;
    u32 temp_a1_102;
    u32 temp_a1_103;
    u32 temp_a1_104;
    u32 temp_a1_105;
    u32 temp_a1_106;
    u32 temp_a1_107;
    u32 temp_a1_10;
    u32 temp_a1_110;
    u32 temp_a1_111;
    u32 temp_a1_112;
    u32 temp_a1_113;
    u32 temp_a1_114;
    u32 temp_a1_115;
    u32 temp_a1_116;
    u32 temp_a1_117;
    u32 temp_a1_118;
    u32 temp_a1_119;
    u32 temp_a1_11;
    u32 temp_a1_120;
    u32 temp_a1_121;
    u32 temp_a1_122;
    u32 temp_a1_123;
    u32 temp_a1_124;
    u32 temp_a1_125;
    u32 temp_a1_126;
    u32 temp_a1_127;
    u32 temp_a1_128;
    u32 temp_a1_129;
    u32 temp_a1_12;
    u32 temp_a1_130;
    u32 temp_a1_131;
    u32 temp_a1_132;
    u32 temp_a1_133;
    u32 temp_a1_134;
    u32 temp_a1_135;
    u32 temp_a1_136;
    u32 temp_a1_137;
    u32 temp_a1_138;
    u32 temp_a1_139;
    u32 temp_a1_13;
    u32 temp_a1_140;
    u32 temp_a1_141;
    u32 temp_a1_142;
    u32 temp_a1_143;
    u32 temp_a1_144;
    u32 temp_a1_145;
    u32 temp_a1_146;
    u32 temp_a1_147;
    u32 temp_a1_148;
    u32 temp_a1_149;
    u32 temp_a1_14;
    u32 temp_a1_15;
    u32 temp_a1_16;
    u32 temp_a1_17;
    u32 temp_a1_18;
    u32 temp_a1_19;
    u32 temp_a1_20;
    u32 temp_a1_21;
    u32 temp_a1_22;
    u32 temp_a1_23;
    u32 temp_a1_24;
    u32 temp_a1_25;
    u32 temp_a1_26;
    u32 temp_a1_27;
    u32 temp_a1_28;
    u32 temp_a1_29;
    u32 temp_a1_2;
    u32 temp_a1_30;
    u32 temp_a1_31;
    u32 temp_a1_32;
    u32 temp_a1_33;
    u32 temp_a1_34;
    u32 temp_a1_35;
    u32 temp_a1_36;
    u32 temp_a1_37;
    u32 temp_a1_38;
    u32 temp_a1_39;
    u32 temp_a1_3;
    u32 temp_a1_40;
    u32 temp_a1_41;
    u32 temp_a1_42;
    u32 temp_a1_43;
    u32 temp_a1_44;
    u32 temp_a1_45;
    u32 temp_a1_46;
    u32 temp_a1_47;
    u32 temp_a1_48;
    u32 temp_a1_49;
    u32 temp_a1_4;
    u32 temp_a1_50;
    u32 temp_a1_51;
    u32 temp_a1_52;
    u32 temp_a1_53;
    u32 temp_a1_54;
    u32 temp_a1_55;
    u32 temp_a1_56;
    u32 temp_a1_57;
    u32 temp_a1_58;
    u32 temp_a1_59;
    u32 temp_a1_5;
    u32 temp_a1_60;
    u32 temp_a1_61;
    u32 temp_a1_62;
    u32 temp_a1_63;
    u32 temp_a1_64;
    u32 temp_a1_65;
    u32 temp_a1_66;
    u32 temp_a1_67;
    u32 temp_a1_68;
    u32 temp_a1_69;
    u32 temp_a1_6;
    u32 temp_a1_70;
    u32 temp_a1_71;
    u32 temp_a1_72;
    u32 temp_a1_73;
    u32 temp_a1_74;
    u32 temp_a1_75;
    u32 temp_a1_76;
    u32 temp_a1_77;
    u32 temp_a1_78;
    u32 temp_a1_79;
    u32 temp_a1_7;
    u32 temp_a1_80;
    u32 temp_a1_81;
    u32 temp_a1_82;
    u32 temp_a1_83;
    u32 temp_a1_84;
    u32 temp_a1_85;
    u32 temp_a1_86;
    u32 temp_a1_87;
    u32 temp_a1_88;
    u32 temp_a1_89;
    u32 temp_a1_8;
    u32 temp_a1_90;
    u32 temp_a1_91;
    u32 temp_a1_92;
    u32 temp_a1_93;
    u32 temp_a1_94;
    u32 temp_a1_95;
    u32 temp_a1_96;
    u32 temp_a1_97;
    u32 temp_a1_98;
    u32 temp_a1_99;
    u32 temp_a1_9;
    u32 temp_hi;
    u32 temp_hi_10;
    u32 temp_hi_11;
    u32 temp_hi_12;
    u32 temp_hi_13;
    u32 temp_hi_14;
    u32 temp_hi_15;
    u32 temp_hi_16;
    u32 temp_hi_17;
    u32 temp_hi_2;
    u32 temp_hi_3;
    u32 temp_hi_4;
    u32 temp_hi_5;
    u32 temp_hi_6;
    u32 temp_hi_7;
    u32 temp_hi_8;
    u32 temp_hi_9;
    u32 temp_s0;
    u32 temp_v0_63;
    u32 temp_v1;
    u32 var_a0;
    u32 var_a0_2;
    u32 var_a1;
    u32 var_a1_2;
    u32 var_s0_2;
    u32 var_s0_3;
    u32 var_v0_2;
    u8 temp_v0;
    void *temp_a0;
    void *temp_a1_108;
    void *temp_a1_109;
    void *temp_a3;
    void *temp_a3_2;
    void *temp_a3_3;
    void *temp_a3_4;
    void *temp_a3_5;
    void *temp_a3_6;
    void *temp_a3_7;
    void *temp_fp;
    void *temp_v0_100;
    void *temp_v0_101;
    void *temp_v0_102;
    void *temp_v0_103;
    void *temp_v0_104;
    void *temp_v0_105;
    void *temp_v0_106;
    void *temp_v0_107;
    void *temp_v0_108;
    void *temp_v0_109;
    void *temp_v0_10;
    void *temp_v0_110;
    void *temp_v0_111;
    void *temp_v0_112;
    void *temp_v0_113;
    void *temp_v0_114;
    void *temp_v0_115;
    void *temp_v0_116;
    void *temp_v0_117;
    void *temp_v0_118;
    void *temp_v0_119;
    void *temp_v0_11;
    void *temp_v0_120;
    void *temp_v0_121;
    void *temp_v0_122;
    void *temp_v0_123;
    void *temp_v0_124;
    void *temp_v0_125;
    void *temp_v0_126;
    void *temp_v0_127;
    void *temp_v0_128;
    void *temp_v0_129;
    void *temp_v0_12;
    void *temp_v0_130;
    void *temp_v0_131;
    void *temp_v0_132;
    void *temp_v0_133;
    void *temp_v0_134;
    void *temp_v0_135;
    void *temp_v0_136;
    void *temp_v0_137;
    void *temp_v0_138;
    void *temp_v0_139;
    void *temp_v0_13;
    void *temp_v0_140;
    void *temp_v0_141;
    void *temp_v0_142;
    void *temp_v0_143;
    void *temp_v0_144;
    void *temp_v0_145;
    void *temp_v0_146;
    void *temp_v0_148;
    void *temp_v0_149;
    void *temp_v0_14;
    void *temp_v0_150;
    void *temp_v0_151;
    void *temp_v0_153;
    void *temp_v0_154;
    void *temp_v0_155;
    void *temp_v0_156;
    void *temp_v0_157;
    void *temp_v0_158;
    void *temp_v0_159;
    void *temp_v0_15;
    void *temp_v0_160;
    void *temp_v0_161;
    void *temp_v0_162;
    void *temp_v0_163;
    void *temp_v0_164;
    void *temp_v0_165;
    void *temp_v0_16;
    void *temp_v0_17;
    void *temp_v0_18;
    void *temp_v0_20;
    void *temp_v0_21;
    void *temp_v0_22;
    void *temp_v0_23;
    void *temp_v0_24;
    void *temp_v0_25;
    void *temp_v0_26;
    void *temp_v0_27;
    void *temp_v0_28;
    void *temp_v0_29;
    void *temp_v0_30;
    void *temp_v0_31;
    void *temp_v0_32;
    void *temp_v0_33;
    void *temp_v0_34;
    void *temp_v0_35;
    void *temp_v0_36;
    void *temp_v0_37;
    void *temp_v0_38;
    void *temp_v0_39;
    void *temp_v0_40;
    void *temp_v0_41;
    void *temp_v0_42;
    void *temp_v0_43;
    void *temp_v0_44;
    void *temp_v0_45;
    void *temp_v0_46;
    void *temp_v0_47;
    void *temp_v0_48;
    void *temp_v0_49;
    void *temp_v0_4;
    void *temp_v0_50;
    void *temp_v0_51;
    void *temp_v0_52;
    void *temp_v0_53;
    void *temp_v0_54;
    void *temp_v0_55;
    void *temp_v0_56;
    void *temp_v0_57;
    void *temp_v0_58;
    void *temp_v0_59;
    void *temp_v0_5;
    void *temp_v0_60;
    void *temp_v0_61;
    void *temp_v0_62;
    void *temp_v0_64;
    void *temp_v0_65;
    void *temp_v0_66;
    void *temp_v0_67;
    void *temp_v0_68;
    void *temp_v0_69;
    void *temp_v0_6;
    void *temp_v0_70;
    void *temp_v0_71;
    void *temp_v0_72;
    void *temp_v0_73;
    void *temp_v0_74;
    void *temp_v0_75;
    void *temp_v0_76;
    void *temp_v0_77;
    void *temp_v0_78;
    void *temp_v0_79;
    void *temp_v0_7;
    void *temp_v0_80;
    void *temp_v0_81;
    void *temp_v0_82;
    void *temp_v0_83;
    void *temp_v0_84;
    void *temp_v0_85;
    void *temp_v0_86;
    void *temp_v0_87;
    void *temp_v0_88;
    void *temp_v0_89;
    void *temp_v0_8;
    void *temp_v0_90;
    void *temp_v0_91;
    void *temp_v0_92;
    void *temp_v0_93;
    void *temp_v0_94;
    void *temp_v0_95;
    void *temp_v0_96;
    void *temp_v0_97;
    void *temp_v0_98;
    void *temp_v0_99;
    void *temp_v0_9;
    void *temp_v1_102;
    void *temp_v1_10;
    void *temp_v1_11;
    void *temp_v1_12;
    void *temp_v1_14;
    void *temp_v1_16;
    void *temp_v1_17;
    void *temp_v1_18;
    void *temp_v1_20;
    void *temp_v1_21;
    void *temp_v1_22;
    void *temp_v1_23;
    void *temp_v1_24;
    void *temp_v1_25;
    void *temp_v1_26;
    void *temp_v1_28;
    void *temp_v1_29;
    void *temp_v1_2;
    void *temp_v1_30;
    void *temp_v1_31;
    void *temp_v1_33;
    void *temp_v1_34;
    void *temp_v1_36;
    void *temp_v1_37;
    void *temp_v1_38;
    void *temp_v1_39;
    void *temp_v1_3;
    void *temp_v1_40;
    void *temp_v1_41;
    void *temp_v1_42;
    void *temp_v1_43;
    void *temp_v1_44;
    void *temp_v1_45;
    void *temp_v1_46;
    void *temp_v1_47;
    void *temp_v1_49;
    void *temp_v1_4;
    void *temp_v1_51;
    void *temp_v1_52;
    void *temp_v1_53;
    void *temp_v1_54;
    void *temp_v1_55;
    void *temp_v1_56;
    void *temp_v1_57;
    void *temp_v1_59;
    void *temp_v1_5;
    void *temp_v1_60;
    void *temp_v1_61;
    void *temp_v1_62;
    void *temp_v1_63;
    void *temp_v1_64;
    void *temp_v1_65;
    void *temp_v1_66;
    void *temp_v1_67;
    void *temp_v1_68;
    void *temp_v1_69;
    void *temp_v1_6;
    void *temp_v1_70;
    void *temp_v1_71;
    void *temp_v1_72;
    void *temp_v1_73;
    void *temp_v1_74;
    void *temp_v1_75;
    void *temp_v1_76;
    void *temp_v1_77;
    void *temp_v1_78;
    void *temp_v1_79;
    void *temp_v1_7;
    void *temp_v1_80;
    void *temp_v1_81;
    void *temp_v1_82;
    void *temp_v1_83;
    void *temp_v1_84;
    void *temp_v1_85;
    void *temp_v1_86;
    void *temp_v1_87;
    void *temp_v1_88;
    void *temp_v1_89;
    void *temp_v1_8;
    void *temp_v1_90;
    void *temp_v1_91;
    void *temp_v1_92;
    void *temp_v1_93;
    void *temp_v1_94;
    void *temp_v1_95;
    void *temp_v1_96;
    void *temp_v1_97;
    void *temp_v1_98;
    void *temp_v1_99;
    void *temp_v1_9;
    void *var_s1;
    void *var_s3;

    var_s5 = 1;
    var_s6 = 0x4E2;
    temp_fp = Obj0000_Get_D_00747A94_2DB6B0();
    (*(u8 *)((u8 *)(arg0) + 0x186A)) = 2;
    (*(s32 *)((u8 *)(arg0) + 0x16D4)) = (s32) ((*(s32 *)((u8 *)(arg0) + 0x16D4)) | 0x400);
    sp0 = 0;
    CheckSlotsShort2FEAndSetByte1864_262A10(arg0);
    sp4 = 0;
    if ((*(s32 *)((u8 *)(arg0) + 0x564)) == 0x23B) {
        (*(f32 *)((u8 *)(arg0) + 0x16E4)) = 60.0f;
    }
    temp_v0 = (*(u8 *)((u8 *)(arg0) + 0x2F6));
    switch (temp_v0) {                              /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        (*(s32 *)((u8 *)(arg0) + 0x1864)) = 0U;
        temp_v0_2 = Obj0000_Get_Byte_17C3_NZ_2_276468(arg0);
        (*(s32 *)((u8 *)(arg0) + 0x5F4)) = 0;
        (*(s32 *)((u8 *)(arg0) + 0x5FC)) = 0;
        (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0xF;
        (*(f32 *)((u8 *)(arg0) + 0x608)) = 1.0f;
        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
        temp_v0_3 = (*(s32 *)((u8 *)(arg0) + 0x564));
        (*(f32 *)((u8 *)(arg0) + 0x604)) = 0.0f;
        temp_v1 = temp_v0_3 - 0x202;
        (*(s32 *)((u8 *)(arg0) + 0x60C)) = 0;
        if (temp_v1 < 0x7DU) {
            switch (temp_v0_3) {                    /* switch 2 */
            case 0x23B:                             /* switch 2 */
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                temp_v0_4 = (*(s32 *)((u8 *)(arg0) + 0x304));
                if (Forward30F348_31CFE0() & 1) {
                    var_v1 = (*(s32 *)((u8 *)(temp_v0_4) + 0x1AC));
                    var_a0 = (*(s32 *)((u8 *)(temp_v0_4) + 0x1B0));
                } else {
                    var_v1 = (*(s32 *)((u8 *)(temp_v0_4) + 0x150));
                    var_a0 = (*(s32 *)((u8 *)(temp_v0_4) + 0x154));
                }
                var_s3 = var_v1 + temp_v0_4;
                var_s1 = var_a0 + temp_v0_4;
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) > 2.89f) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 1, 0x37);
                    temp_v0_5 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_5) + 0x144)) + temp_v0_5;
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_5) + 0x148)) + temp_v0_5;
                }
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) > 4.0f) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    if (!(Forward30F348_31CFE0() & 1)) {
                        StoreMotionParamsBoth_2609A8(arg0, 0xF, 0, 0x37);
                        temp_v0_6 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s3 = (*(s32 *)((u8 *)(temp_v0_6) + 0x19C)) + temp_v0_6;
                        (*(s32 *)((u8 *)(arg0) + 0x5F4)) = 1;
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_6) + 0x1A0)) + temp_v0_6;
                    } else {
                        temp_v0_7 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_v1_2 = (*(s32 *)((u8 *)(temp_v0_7) + 0x18C));
                        var_a0_2 = (*(s32 *)((u8 *)(temp_v0_7) + 0x190));
block_689:
                        var_s3 = var_v1_2 + (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = var_a0_2 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    }
                }
                break;
            case 0x204:                             /* switch 2 */
                (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x1E;
                temp_hi = Forward30F348_31CFE0(temp_a0) % 5U;
                switch (temp_hi) {                  /* switch 7 */
                default:                            /* switch 7 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 2, 0x37);
                    temp_v0_8 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1 = (*(s32 *)((u8 *)(temp_v0_8) + 0x1DC));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_8) + 0x1E4)) + temp_v0_8;
                    var_s3 = temp_a1 + temp_v0_8;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1E4));
block_100:
                        var_s1 = var_v0 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    }
                    break;
                case 1:                             /* switch 7 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 7, 0x37);
                    temp_v0_9 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_2 = (*(s32 *)((u8 *)(temp_v0_9) + 0x1FC));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_9) + 0x204)) + temp_v0_9;
                    var_s3 = temp_a1_2 + temp_v0_9;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x204));
                        goto block_100;
                    }
                    break;
                case 2:                             /* switch 7 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v0_10 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_3 = (*(s32 *)((u8 *)(temp_v0_10) + 0x20C));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_10) + 0x214)) + temp_v0_10;
                    var_s3 = temp_a1_3 + temp_v0_10;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x214));
                        goto block_100;
                    }
                    break;
                case 3:                             /* switch 7 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v0_11 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_4 = (*(s32 *)((u8 *)(temp_v0_11) + 0x21C));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_11) + 0x224)) + temp_v0_11;
                    var_s3 = temp_a1_4 + temp_v0_11;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x224));
                        goto block_100;
                    }
                    break;
                case 4:                             /* switch 7 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v0_12 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_5 = (*(s32 *)((u8 *)(temp_v0_12) + 0x22C));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_12) + 0x234)) + temp_v0_12;
                    var_s3 = temp_a1_5 + temp_v0_12;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x234));
                        goto block_100;
                    }
                    break;
                }
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) > 4.0f) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    if (Forward30F348_31CFE0() & 1) {
                        temp_v0_13 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_6 = (*(s32 *)((u8 *)(temp_v0_13) + 0x194));
                        var_s3 = (*(s32 *)((u8 *)(temp_v0_13) + 0x18C)) + temp_v0_13;
                        var_s1 = temp_a1_6 + temp_v0_13;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_2 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_2) + 0x194)) + temp_v1_2;
                        }
                    } else {
                        StoreMotionParamsBoth_2609A8(arg0, 0xF, 0, 0x37);
                        temp_v0_14 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_7 = (*(s32 *)((u8 *)(temp_v0_14) + 0x1A4));
                        var_s3 = (*(s32 *)((u8 *)(temp_v0_14) + 0x19C)) + temp_v0_14;
                        var_s1 = temp_a1_7 + temp_v0_14;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_2 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1A4));
block_430:
                            var_s1 = var_v0_2 + (*(s32 *)((u8 *)(arg0) + 0x304));
                        }
block_431:
                        (*(s32 *)((u8 *)(arg0) + 0x5F4)) = 1;
                    }
                }
                break;
            case 0x202:                             /* switch 2 */
            case 0x203:                             /* switch 2 */
            case 0x216:                             /* switch 2 */
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) < 2.89f) {
                    temp_hi_2 = Forward30F348_31CFE0(arg0) % 3U;
                    switch (temp_hi_2) {            /* switch 8; irregular */
                    case 1:                         /* switch 8 */
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 2, 0x37);
                        temp_v0_15 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_a1 = (*(s32 *)((u8 *)(temp_v0_15) + 0x6A4));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_15) + 0x6A8)) + temp_v0_15;
                        var_s3 = var_a1 + temp_v0_15;
block_117:
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_3 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_3) + 0x6AC)) + temp_v1_3;
                        }
                        break;
                    default:                        /* switch 8 */
                    case 0:                         /* switch 8 */
                        if (cCoreSave_getGameLevel(&D_00569B70) >= 2) {
                            StoreMotionParamsBoth_2609A8(arg0, 0x14, 2, 0x37);
                            temp_v0_16 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_a1_2 = (*(s32 *)((u8 *)(temp_v0_16) + 0x6F8));
                            var_s3 = (*(s32 *)((u8 *)(temp_v0_16) + 0x6F4)) + temp_v0_16;
                            var_s1 = var_a1_2 + temp_v0_16;
block_143:
                            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                temp_v1_4 = (*(s32 *)((u8 *)(arg0) + 0x304));
                                var_s1 = (*(s32 *)((u8 *)(temp_v1_4) + 0x6FC)) + temp_v1_4;
                            }
                        } else {
                            StoreMotionParamsBoth_2609A8(arg0, 0x14, 2, 0x37);
                            temp_v0_17 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_a1 = (*(s32 *)((u8 *)(temp_v0_17) + 0x6A8));
                            var_s3 = (*(s32 *)((u8 *)(temp_v0_17) + 0x6A4)) + temp_v0_17;
                            var_s1 = var_a1 + temp_v0_17;
                            goto block_117;
                        }
                        break;
                    case 2:                         /* switch 8 */
                        StoreMotionParamsBoth_2609A8(arg0, 0x3C, 2, 0x3E);
                        temp_v0_18 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x32;
                        var_s3 = (*(s32 *)((u8 *)(temp_v0_18) + 0x6B0)) + temp_v0_18;
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_18) + 0x6B4)) + temp_v0_18;
                        break;
                    }
                } else {
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_hi_3 = Forward30F348_31CFE0() % 3U;
                    if (temp_hi_3 >= 2U) {
                        if (temp_hi_3 == 2) {
                            temp_v0_19 = cCoreSave_getGameLevel(&D_00569B70);
                            if ((temp_v0_19 == 1) || (temp_v0_19 <= 0) || (temp_v0_19 >= 6)) {
                                goto block_125;
                            }
                            StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                            temp_v0_20 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            temp_a1_8 = (*(s32 *)((u8 *)(temp_v0_20) + 0x6E0));
                            var_s3 = (*(s32 *)((u8 *)(temp_v0_20) + 0x6DC)) + temp_v0_20;
                            var_s1 = temp_a1_8 + temp_v0_20;
                            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                temp_v1_5 = (*(s32 *)((u8 *)(arg0) + 0x304));
                                var_s1 = (*(s32 *)((u8 *)(temp_v1_5) + 0x6E4)) + temp_v1_5;
                            }
                            (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0xF;
                        } else {
                            goto block_126;
                        }
                    } else {
block_125:
block_126:
                        StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x3E);
                        temp_v0_21 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s3 = (*(s32 *)((u8 *)(temp_v0_21) + 0x69C)) + temp_v0_21;
                        (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x32;
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_21) + 0x6A0)) + temp_v0_21;
                    }
                    if ((*(s32 *)((u8 *)(arg0) + 0x564)) == 0x216) {
                        if (Forward30F348_31CFE0() & 1) {
                            temp_v0_22 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            temp_a1_9 = (*(s32 *)((u8 *)(temp_v0_22) + 0x6D4));
                            var_s3 = (*(s32 *)((u8 *)(temp_v0_22) + 0x6D0)) + temp_v0_22;
                            var_s1 = temp_a1_9 + temp_v0_22;
                            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                temp_v1_6 = (*(s32 *)((u8 *)(arg0) + 0x304));
                                var_s1 = (*(s32 *)((u8 *)(temp_v1_6) + 0x6D8)) + temp_v1_6;
                            }
                            StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                            (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x8C;
                        }
                    }
                }
                break;
            case 0x229:                             /* switch 2 */
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) < 2.89f) {
                    if (Forward30F348_31CFE0() & 1) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 2, 0x37);
                        temp_v0_23 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_10 = (*(s32 *)((u8 *)(temp_v0_23) + 0x730));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_23) + 0x734)) + temp_v0_23;
                        var_s3 = temp_a1_10 + temp_v0_23;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_7 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_7) + 0x738)) + temp_v1_7;
                        }
                    } else {
block_142:
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 2, 0x37);
                        temp_v0_24 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_a1_2 = (*(s32 *)((u8 *)(temp_v0_24) + 0x6F4));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_24) + 0x6F8)) + temp_v0_24;
                        var_s3 = var_a1_2 + temp_v0_24;
                        goto block_143;
                    }
                } else if (Forward30F348_31CFE0() & 1) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x3E);
                    temp_v0_25 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_a1_3 = 0x32;
                    var_v1_3 = (*(s32 *)((u8 *)(temp_v0_25) + 0x69C));
                    var_a0_3 = (*(s32 *)((u8 *)(temp_v0_25) + 0x6A0));
block_234:
                    var_s3 = var_v1_3 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    (*(s32 *)((u8 *)(arg0) + 0x5F0)) = var_a1_3;
                    var_s1 = var_a0_3 + (*(s32 *)((u8 *)(arg0) + 0x304));
                } else {
block_147:
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v0_26 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_11 = (*(s32 *)((u8 *)(temp_v0_26) + 0x6DC));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_26) + 0x6E0)) + temp_v0_26;
                    var_s3 = temp_a1_11 + temp_v0_26;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_8 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_8) + 0x6E4)) + temp_v1_8;
                    }
block_307:
                    (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0xF;
                }
                break;
            case 0x22A:                             /* switch 2 */
            case 0x24B:                             /* switch 2 */
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) < 2.89f) {
                    goto block_142;
                }
                if (Forward30F348_31CFE0() & 1) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x3E);
                    temp_v0_27 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_a1_3 = 0x32;
                    var_v1_3 = (*(s32 *)((u8 *)(temp_v0_27) + 0x69C));
                    var_a0_3 = (*(s32 *)((u8 *)(temp_v0_27) + 0x6A0));
                    goto block_234;
                }
                goto block_147;
            case 0x213:                             /* switch 2 */
            case 0x217:                             /* switch 2 */
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 2, 0x3E);
                temp_v0_28 = (*(s32 *)((u8 *)(arg0) + 0x304));
                temp_a1_12 = (*(s32 *)((u8 *)(temp_v0_28) + 0x2F60));
                var_s1 = (*(s32 *)((u8 *)(temp_v0_28) + 0x2F64)) + temp_v0_28;
                var_s3 = temp_a1_12 + temp_v0_28;
                temp_a0_2 = (*(s32 *)((u8 *)(arg0) + 0x708));
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    temp_v1_9 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_s1 = (*(s32 *)((u8 *)(temp_v1_9) + 0x2F68)) + temp_v1_9;
                    if (temp_a0_2 != 0) {
                        Obj1D00_SetState_7_C_a1(temp_a0_2, 1);
                    }
                } else if (temp_a0_2 != 0) {
                    Obj1D00_SetState_7_C_a1(temp_a0_2, 0);
                }
                break;
            case 0x242:                             /* switch 2 */
                if (Forward30F348_31CFE0(temp_a0) & 1) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v0_29 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_13 = (*(s32 *)((u8 *)(temp_v0_29) + 0x3604));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_29) + 0x3608)) + temp_v0_29;
                    var_s3 = temp_a1_13 + temp_v0_29;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_3 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x360C));
block_170:
                        var_s1 = var_v0_3 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    }
block_171:
                    (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x37;
                } else {
block_172:
                    Set_Fields_1884_1894_2609F8(arg0, 0x1E, 2, 0x3E);
                    StoreMotionParams_2609E0(arg0, 0x14, 0, 0x37);
                    temp_v0_30 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_14 = (*(s32 *)((u8 *)(temp_v0_30) + 0x3660));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_30) + 0x365C)) + temp_v0_30;
                    var_s1 = temp_a1_14 + temp_v0_30;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_10 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_10) + 0x3664)) + temp_v1_10;
                    }
                    (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x50;
                }
                break;
            case 0x243:                             /* switch 2 */
                if (Forward30F348_31CFE0(temp_a0) & 1) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x37);
                    temp_v0_31 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_15 = (*(s32 *)((u8 *)(temp_v0_31) + 0x3678));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_31) + 0x367C)) + temp_v0_31;
                    var_s3 = temp_a1_15 + temp_v0_31;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_11 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_11) + 0x3680)) + temp_v1_11;
                    }
                    (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x20;
                } else {
                    if (Forward30F348_31CFE0() & 1) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                        temp_v0_32 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_16 = (*(s32 *)((u8 *)(temp_v0_32) + 0x3604));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_32) + 0x3608)) + temp_v0_32;
                        var_s3 = temp_a1_16 + temp_v0_32;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_3 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x360C));
                            goto block_170;
                        }
                        goto block_171;
                    }
                    goto block_172;
                }
                break;
            case 0x244:                             /* switch 2 */
                if (Forward30F348_31CFE0(temp_a0) & 1) {
                    StoreMotionParams_2609E0(arg0, 0x14, 0, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 0x14, 2, 0x4E);
                    temp_v0_33 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_17 = (*(s32 *)((u8 *)(temp_v0_33) + 0x3688));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_33) + 0x3684)) + temp_v0_33;
                    var_s1 = temp_a1_17 + temp_v0_33;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_4 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x368C));
block_479:
                        var_s1 = var_v0_4 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    }
block_480:
                    (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x3C;
                } else {
                    if (Forward30F348_31CFE0(arg0) & 1) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x37);
                        temp_v0_34 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_18 = (*(s32 *)((u8 *)(temp_v0_34) + 0x366C));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_34) + 0x3670)) + temp_v0_34;
                        var_s3 = temp_a1_18 + temp_v0_34;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_3 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x3674));
                            goto block_170;
                        }
                        goto block_171;
                    }
                    goto block_172;
                }
                break;
            case 0x21A:                             /* switch 2 */
            case 0x21C:                             /* switch 2 */
            case 0x21D:                             /* switch 2 */
            case 0x21E:                             /* switch 2 */
            case 0x22C:                             /* switch 2 */
            case 0x22E:                             /* switch 2 */
            case 0x22F:                             /* switch 2 */
            case 0x248:                             /* switch 2 */
            case 0x249:                             /* switch 2 */
            case 0x24C:                             /* switch 2 */
            case 0x24E:                             /* switch 2 */
            case 0x25A:                             /* switch 2 */
                if (!(Forward30F348_31CFE0(temp_a0) & 3) && ((*(s32 *)((u8 *)(arg0) + 0x6F0)) == 0)) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v0_35 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_19 = (*(s32 *)((u8 *)(temp_v0_35) + 0x1134));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_35) + 0x1138)) + temp_v0_35;
                    var_s3 = temp_a1_19 + temp_v0_35;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_12 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_12) + 0x113C)) + temp_v1_12;
                    }
                    goto block_307;
                }
                var_s0 = 1;
                temp_hi_4 = Forward30F348_31CFE0() % 3U;
                switch (temp_hi_4) {                /* switch 9; irregular */
                default:                            /* switch 9 */
                case 0:                             /* switch 9 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v0_36 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_20 = (*(s32 *)((u8 *)(temp_v0_36) + 0x114C));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_36) + 0x1150)) + temp_v0_36;
                    var_s3 = temp_a1_20 + temp_v0_36;
                    var_v0_5 = 0x32;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_6 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1154));
block_473:
                        var_s1 = var_v0_6 + (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_v0_5 = 0x32;
                    }
                    break;
                case 1:                             /* switch 9 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v0_37 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_21 = (*(s32 *)((u8 *)(temp_v0_37) + 0x1158));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_37) + 0x115C)) + temp_v0_37;
                    var_s3 = temp_a1_21 + temp_v0_37;
                    var_v0_5 = 0x32;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_6 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1160));
                        goto block_473;
                    }
                    break;
                case 2:                             /* switch 9 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v0_38 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_22 = (*(s32 *)((u8 *)(temp_v0_38) + 0x1164));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_38) + 0x1168)) + temp_v0_38;
                    var_s3 = temp_a1_22 + temp_v0_38;
                    var_v0_5 = 0x32;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_6 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x116C));
                        goto block_473;
                    }
                    break;
                }
block_474:
                (*(s32 *)((u8 *)(arg0) + 0x5F4)) = var_s0;
                (*(s32 *)((u8 *)(arg0) + 0x5F0)) = var_v0_5;
                break;
            case 0x21B:                             /* switch 2 */
            case 0x22D:                             /* switch 2 */
                if (Forward30F348_31CFE0(temp_a0) & 1) {
                    if ((*(s32 *)((u8 *)(arg0) + 0x6F0)) == 0) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                        temp_v0_39 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_23 = (*(s32 *)((u8 *)(temp_v0_39) + 0x1504));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_39) + 0x1508)) + temp_v0_39;
                        var_s3 = temp_a1_23 + temp_v0_39;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_7 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x150C));
block_622:
                            var_s1 = var_v0_7 + (*(s32 *)((u8 *)(arg0) + 0x304));
                        }
block_623:
                        (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x1E;
                    } else {
                        goto block_194;
                    }
                } else {
block_194:
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v0_40 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_24 = (*(s32 *)((u8 *)(temp_v0_40) + 0x114C));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_40) + 0x1150)) + temp_v0_40;
                    var_s3 = temp_a1_24 + temp_v0_40;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_8 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1154));
block_464:
                        var_s1 = var_v0_8 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    }
block_465:
                    (*(s32 *)((u8 *)(arg0) + 0x5F4)) = 1;
                    (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x32;
                }
                break;
            case 0x225:                             /* switch 2 */
            case 0x24D:                             /* switch 2 */
                temp_v1_13 = Forward30F348_31CFE0(temp_a0) & 3;
                switch (temp_v1_13) {               /* switch 10; irregular */
                default:                            /* switch 10 */
                case 0:                             /* switch 10 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v0_41 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_25 = (*(s32 *)((u8 *)(temp_v0_41) + 0x3CC8));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_41) + 0x3CCC)) + temp_v0_41;
                    var_s3 = temp_a1_25 + temp_v0_41;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_14 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_14) + 0x3CD0)) + temp_v1_14;
                    }
                    (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x23;
                    break;
                case 1:                             /* switch 10 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v0_42 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_26 = (*(s32 *)((u8 *)(temp_v0_42) + 0x3CD4));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_42) + 0x3CD8)) + temp_v0_42;
                    var_s3 = temp_a1_26 + temp_v0_42;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_4 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x3CDC));
                        goto block_479;
                    }
                    goto block_480;
                case 2:                             /* switch 10 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x3E);
                    temp_v0_43 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_27 = (*(s32 *)((u8 *)(temp_v0_43) + 0x3D10));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_43) + 0x3D14)) + temp_v0_43;
                    var_s3 = temp_a1_27 + temp_v0_43;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x3D18));
block_488:
                        var_s1 = var_v0_9 + (*(s32 *)((u8 *)(arg0) + 0x304));
block_489:
                    }
block_490:
                    (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x14;
                    break;
                case 3:                             /* switch 10 */
                    StoreMotionParams_2609E0(arg0, 0x14, 0, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 0x14, 0, 0x3E);
                    temp_v0_44 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_28 = (*(s32 *)((u8 *)(temp_v0_44) + 0x3D20));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_44) + 0x3D1C)) + temp_v0_44;
                    var_s1 = temp_a1_28 + temp_v0_44;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x3D24));
                        goto block_488;
                    }
                    goto block_490;
                }
                break;
            case 0x252:                             /* switch 2 */
                temp_v1_15 = Forward30F348_31CFE0(temp_a0) & 3;
                switch (temp_v1_15) {               /* switch 11; irregular */
                case 1:                             /* switch 11 */
                    sp4 = (*(s32 *)((u8 *)(arg0) + 0x734));
                    StoreMotionParams_2609E0(arg0, 0x14, 0, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 0x14, 0, 0x3E);
                    var_s6 = 0xAA;
                    temp_v0_45 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    sp0 = 2;
                    var_s5 = 0xF;
                    temp_a1_29 = (*(s32 *)((u8 *)(temp_v0_45) + 0x2544));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_45) + 0x2540)) + temp_v0_45;
                    var_s1 = temp_a1_29 + temp_v0_45;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_s5 = 0x10;
                        var_v0_10 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x2548));
block_224:
                        var_s1 = var_v0_10 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    }
                    break;
                default:                            /* switch 11 */
                case 0:                             /* switch 11 */
                    sp4 = (*(s32 *)((u8 *)(arg0) + 0x734));
                    StoreMotionParams_2609E0(arg0, 0x14, 0, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 0x14, 0, 0x3E);
                    var_s6 = 0xAA;
                    temp_v0_46 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    sp0 = 2;
                    var_s5 = 0xD;
                    temp_a1_30 = (*(s32 *)((u8 *)(temp_v0_46) + 0x2538));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_46) + 0x2534)) + temp_v0_46;
                    var_s1 = temp_a1_30 + temp_v0_46;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_s5 = 0xE;
                        var_v0_10 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x253C));
                        goto block_224;
                    }
                    break;
                case 2:                             /* switch 11 */
                    StoreMotionParams_2609E0(arg0, 0x14, 0, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 0x14, 0, 0x3E);
                    temp_v0_47 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_31 = (*(s32 *)((u8 *)(temp_v0_47) + 0x2574));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_47) + 0x2570)) + temp_v0_47;
                    var_s1 = temp_a1_31 + temp_v0_47;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_10 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x2578));
                        goto block_224;
                    }
                    break;
                case 3:                             /* switch 11 */
                    StoreMotionParams_2609E0(arg0, 0x14, 0, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 0x14, 0, 0x3E);
                    temp_v0_48 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_32 = (*(s32 *)((u8 *)(temp_v0_48) + 0x2568));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_48) + 0x2564)) + temp_v0_48;
                    var_s1 = temp_a1_32 + temp_v0_48;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_10 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x256C));
                        goto block_224;
                    }
                    break;
                }
                (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x32;
                if (Obj0000_IsSet_Field_15F4_Bit_1000_12C530(temp_fp) != 0) {
                    if (Forward30F348_31CFE0() & 1) {
                        StoreMotionParamsBoth_2609A8(arg0, 5, 3, 0x37);
                        temp_v0_49 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_v1_4 = (*(s32 *)((u8 *)(temp_v0_49) + 0x257C));
                        var_a0_4 = (*(s32 *)((u8 *)(temp_v0_49) + 0x2580));
                    } else {
                        StoreMotionParamsBoth_2609A8(arg0, 5, 3, 0x37);
                        temp_v0_50 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_v1_4 = (*(s32 *)((u8 *)(temp_v0_50) + 0x2584));
                        var_a0_4 = (*(s32 *)((u8 *)(temp_v0_50) + 0x2588));
                    }
                    var_s3 = var_v1_4 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x32;
                    var_s1 = var_a0_4 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    (*(s32 *)((u8 *)(arg0) + 0x5F4)) = 0;
                }
                break;
            case 0x207:                             /* switch 2 */
                if (Forward30F348_31CFE0(temp_a0) & 3) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 8, 0x37);
                    temp_v0_51 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_33 = (*(s32 *)((u8 *)(temp_v0_51) + 0x1610));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_51) + 0x1614)) + temp_v0_51;
                    var_s3 = temp_a1_33 + temp_v0_51;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_4 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1618));
                        goto block_479;
                    }
                    goto block_480;
                }
            case 0x205:                             /* switch 2 */
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                temp_v0_52 = (*(s32 *)((u8 *)(arg0) + 0x304));
                var_a1_3 = 0xF;
                var_v1_3 = (*(s32 *)((u8 *)(temp_v0_52) + 0x15DC));
                var_a0_3 = (*(s32 *)((u8 *)(temp_v0_52) + 0x15E0));
                goto block_234;
            case 0x241:                             /* switch 2 */
                temp_s0 = Forward30F348_31CFE0(temp_a0) % 3U;
                temp_a0_3 = (func_0012C4F0(temp_fp) == 0) ? temp_s0 : 2U;
                switch (temp_a0_3) {                /* switch 12; irregular */
                case 1:                             /* switch 12 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x3C);
                    temp_v0_53 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_34 = (*(s32 *)((u8 *)(temp_v0_53) + 0x3A4C));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_53) + 0x3A50)) + temp_v0_53;
                    var_s3 = temp_a1_34 + temp_v0_53;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x3A54));
                        goto block_488;
                    }
                    goto block_490;
                default:                            /* switch 12 */
                case 0:                             /* switch 12 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x3E);
                    temp_v0_54 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_35 = (*(s32 *)((u8 *)(temp_v0_54) + 0x3A40));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_54) + 0x3A44)) + temp_v0_54;
                    var_s3 = temp_a1_35 + temp_v0_54;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_11 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x3A48));
block_452:
                        var_s1 = var_v0_11 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    }
block_453:
                    (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x19;
                    break;
                case 2:                             /* switch 12 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x3E);
                    temp_v0_55 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_36 = (*(s32 *)((u8 *)(temp_v0_55) + 0x3A58));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_55) + 0x3A5C)) + temp_v0_55;
                    var_s3 = temp_a1_36 + temp_v0_55;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x3A60));
                        goto block_488;
                    }
                    goto block_490;
                }
                break;
            case 0x224:                             /* switch 2 */
                if ((*(u8 *)((u8 *)(arg0) + 0x2F7)) == 0) {
                    if (Forward30F348_31CFE0(temp_a0, 0x28) & 1) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x37);
                        temp_v0_56 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_37 = (*(s32 *)((u8 *)(temp_v0_56) + 0x18C4));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_56) + 0x18C8)) + temp_v0_56;
                        var_s3 = temp_a1_37 + temp_v0_56;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x18CC));
                            goto block_488;
                        }
                        goto block_490;
                    }
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 8, 0x37);
                    temp_v0_57 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_38 = (*(s32 *)((u8 *)(temp_v0_57) + 0x1610));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_57) + 0x1614)) + temp_v0_57;
                    var_s3 = temp_a1_38 + temp_v0_57;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_4 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1618));
                        goto block_479;
                    }
                    goto block_480;
                }
                StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x37);
                temp_v0_58 = (*(s32 *)((u8 *)(arg0) + 0x304));
                temp_a1_39 = (*(s32 *)((u8 *)(temp_v0_58) + 0x18D0));
                var_s1 = (*(s32 *)((u8 *)(temp_v0_58) + 0x18D4)) + temp_v0_58;
                var_s3 = temp_a1_39 + temp_v0_58;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x18D8));
                    goto block_488;
                }
                goto block_490;
            case 0x206:                             /* switch 2 */
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) < 4.0f) {
                    if (Forward30F348_31CFE0(temp_a0) & 1) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                        temp_v0_59 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_40 = (*(s32 *)((u8 *)(temp_v0_59) + 0x1860));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_59) + 0x1864)) + temp_v0_59;
                        var_s3 = temp_a1_40 + temp_v0_59;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_12 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1868));
                            goto block_260;
                        }
                    } else {
                        StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x3E);
                        temp_v0_60 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_41 = (*(s32 *)((u8 *)(temp_v0_60) + 0x1878));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_60) + 0x187C)) + temp_v0_60;
                        var_s3 = temp_a1_41 + temp_v0_60;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_12 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1880));
block_260:
                            var_s1 = var_v0_12 + (*(s32 *)((u8 *)(arg0) + 0x304));
                        }
                    }
                    (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0xD;
                } else if (Forward30F348_31CFE0(temp_a0) & 1) {
                    StoreMotionParams_2609E0(arg0, 0xF, 5, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 0xF, 4, 0x37);
                    temp_v0_61 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_42 = (*(s32 *)((u8 *)(temp_v0_61) + 0x1888));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_61) + 0x1884)) + temp_v0_61;
                    var_s1 = temp_a1_42 + temp_v0_61;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_16 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_16) + 0x188C)) + temp_v1_16;
                    }
                    (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x1C;
                } else {
                    StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x3E);
                    temp_v0_62 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_43 = (*(s32 *)((u8 *)(temp_v0_62) + 0x186C));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_62) + 0x1870)) + temp_v0_62;
                    var_s3 = temp_a1_43 + temp_v0_62;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_17 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_17) + 0x1874)) + temp_v1_17;
                    }
                    goto block_307;
                }
                break;
            case 0x209:                             /* switch 2 */
                var_s6 = 0x61;
                sp4 = (*(s32 *)((u8 *)(arg0) + 0x704));
                temp_v0_63 = Forward30F348_31CFE0(temp_a0);
                sp0 = 2;
                temp_hi_5 = temp_v0_63 % 5U;
                switch (temp_hi_5) {                /* switch 13 */
                default:                            /* switch 13 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x32, 0x16, 0x37);
                    temp_v0_64 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_44 = (*(s32 *)((u8 *)(temp_v0_64) + 0x347C));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_64) + 0x3480)) + temp_v0_64;
                    var_s3 = temp_a1_44 + temp_v0_64;
                    var_s5 = 1;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_s5 = 2;
                        var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x3484));
                        goto block_488;
                    }
                    goto block_489;
                case 1:                             /* switch 13 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x32, 0x16, 0x37);
                    temp_v0_65 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_45 = (*(s32 *)((u8 *)(temp_v0_65) + 0x3488));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_65) + 0x348C)) + temp_v0_65;
                    var_s3 = temp_a1_45 + temp_v0_65;
                    var_s5 = 3;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_s5 = 4;
                        var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x3490));
                        goto block_488;
                    }
                    goto block_489;
                case 2:                             /* switch 13 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x32, 0x16, 0x44);
                    temp_v0_66 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_46 = (*(s32 *)((u8 *)(temp_v0_66) + 0x3494));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_66) + 0x3498)) + temp_v0_66;
                    var_s3 = temp_a1_46 + temp_v0_66;
                    var_s5 = 5;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_s5 = 6;
                        var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x349C));
                        goto block_488;
                    }
                    goto block_489;
                case 3:                             /* switch 13 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x32, 0x17, 0x44);
                    temp_v0_67 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_47 = (*(s32 *)((u8 *)(temp_v0_67) + 0x34AC));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_67) + 0x34B0)) + temp_v0_67;
                    var_s3 = temp_a1_47 + temp_v0_67;
                    var_s5 = 9;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_s5 = 0xA;
                        var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x34B4));
                        goto block_488;
                    }
                    goto block_489;
                case 4:                             /* switch 13 */
                    StoreMotionParams_2609E0(arg0, 0x1E, 0x16, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 0x32, 0x16, 0x44);
                    temp_v0_68 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_48 = (*(s32 *)((u8 *)(temp_v0_68) + 0x34E0));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_68) + 0x34DC)) + temp_v0_68;
                    var_s1 = temp_a1_48 + temp_v0_68;
                    var_s5 = 0x11;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_18 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s5 = 0x12;
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_18) + 0x34E4)) + temp_v1_18;
                    }
                    (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x4B;
                    (*(f32 *)((u8 *)(arg0) + 0x604)) = 75.0f;
                    break;
                }
                break;
            case 0x21F:                             /* switch 2 */
                var_s6 = 0x77;
                var_s5 = 3;
                sp0 = 2;
                sp4 = (*(s32 *)((u8 *)(arg0) + 0x704));
                if ((*(s32 *)((u8 *)(arg0) + 0x16D4)) & 0x100000) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0x1A, 0x37);
                    temp_v0_69 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_49 = (*(s32 *)((u8 *)(temp_v0_69) + 0x35AC));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_69) + 0x35B0)) + temp_v0_69;
                    var_s3 = temp_a1_49 + temp_v0_69;
                    var_s5 = 0x19;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_s5 = 0x1A;
                        var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x35B4));
                        goto block_488;
                    }
                    goto block_489;
                }
                temp_v1_19 = Forward30F348_31CFE0(temp_a0) & 3;
                if (temp_v1_19 != 1) {
                    if (temp_v1_19 != 0) {
                        if (temp_v1_19 != sp0) {
                            if (temp_v1_19 != 3) {
                                goto block_289;
                            }
                            StoreMotionParams_2609E0(arg0, 0x14, 0, 0x37);
                            Set_Fields_1884_1894_2609F8(arg0, 0x28, 0x1A, 0x37);
                            temp_v0_70 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            temp_a1_50 = (*(s32 *)((u8 *)(temp_v0_70) + 0x3568));
                            var_s3 = (*(s32 *)((u8 *)(temp_v0_70) + 0x3564)) + temp_v0_70;
                            var_s1 = temp_a1_50 + temp_v0_70;
                            var_s5 = 0xF;
                            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                var_s5 = 0x10;
                                var_v0_13 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x356C));
                                goto block_299;
                            }
                            goto block_300;
                        }
                        StoreMotionParams_2609E0(arg0, 0x23, 0x16, 0x37);
                        Set_Fields_1884_1894_2609F8(arg0, 0x23, 0x1A, 0x37);
                        temp_v0_71 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_51 = (*(s32 *)((u8 *)(temp_v0_71) + 0x3530));
                        var_s3 = (*(s32 *)((u8 *)(temp_v0_71) + 0x352C)) + temp_v0_71;
                        var_s1 = temp_a1_51 + temp_v0_71;
                        var_s5 = 6;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_s5 = 7;
                            var_v0_13 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x3534));
block_299:
                            var_s1 = var_v0_13 + (*(s32 *)((u8 *)(arg0) + 0x304));
                        }
block_300:
                        (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x28;
                    } else {
block_289:
                        StoreMotionParamsBoth_2609A8(arg0, 0x32, 0x16, 0x37);
                        temp_v0_72 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_52 = (*(s32 *)((u8 *)(temp_v0_72) + 0x3514));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_72) + 0x3518)) + temp_v0_72;
                        var_s3 = temp_a1_52 + temp_v0_72;
                        if (cCoreSave_getGameLevel(&D_00569B70) != 5) {
                            var_s5 = 2;
                        } else {
                            var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x351C));
                            goto block_488;
                        }
                        goto block_489;
                    }
                } else {
                    StoreMotionParamsBoth_2609A8(arg0, 0x32, 0x16, 0x37);
                    temp_v0_73 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_53 = (*(s32 *)((u8 *)(temp_v0_73) + 0x3520));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_73) + 0x3524)) + temp_v0_73;
                    var_s3 = temp_a1_53 + temp_v0_73;
                    var_s5 = 4;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_s5 = 5;
                        var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x3528));
                        goto block_488;
                    }
                    goto block_489;
                }
                break;
            case 0x208:                             /* switch 2 */
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                temp_v0_74 = (*(s32 *)((u8 *)(arg0) + 0x304));
                temp_a2 = (*(s32 *)((u8 *)(arg0) + 0x700));
                var_s3 = (*(s32 *)((u8 *)(temp_v0_74) + 0x15DC)) + temp_v0_74;
                (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0xF;
                var_s1 = (*(s32 *)((u8 *)(temp_v0_74) + 0x15E0)) + temp_v0_74;
                if (temp_a2 != 0) {
                    if (Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(temp_a2, 0xF, temp_a2) == 0) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                        temp_v0_75 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_54 = (*(s32 *)((u8 *)(temp_v0_75) + 0x1E74));
                        var_s3 = (*(s32 *)((u8 *)(temp_v0_75) + 0x1E70)) + temp_v0_75;
                        var_s1 = temp_a1_54 + temp_v0_75;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_20 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_20) + 0x1E78)) + temp_v1_20;
                        }
                        SetOrientByType_26AF20(arg0, (*(s32 *)((u8 *)(arg0) + 0x700)), 1);
                    }
                }
                goto block_307;
            case 0x20F:                             /* switch 2 */
                var_a1_4 = 2;
block_324:
                StoreMotionParamsBoth_2609A8(arg0, var_a1_4, 2, 0x37);
                temp_v0_76 = (*(s32 *)((u8 *)(arg0) + 0x304));
                temp_a1_55 = (*(s32 *)((u8 *)(temp_v0_76) + 0xDB0));
                var_s1 = (*(s32 *)((u8 *)(temp_v0_76) + 0xDB4)) + temp_v0_76;
                var_s3 = temp_a1_55 + temp_v0_76;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    temp_v1_21 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_s1 = (*(s32 *)((u8 *)(temp_v1_21) + 0xDB8)) + temp_v1_21;
                }
                break;
            case 0x210:                             /* switch 2 */
            case 0x211:                             /* switch 2 */
            case 0x226:                             /* switch 2 */
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) < 4.0f) {
                    if (Forward30F348_31CFE0(temp_a0) & 1) {
                        StoreMotionParamsBoth_2609A8(arg0, 0xF, 2, 0x37);
                        temp_v0_77 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_56 = (*(s32 *)((u8 *)(temp_v0_77) + 0xE24));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_77) + 0xE28)) + temp_v0_77;
                        var_s3 = temp_a1_56 + temp_v0_77;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_22 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_22) + 0xE2C)) + temp_v1_22;
                        }
                    } else {
                        StoreMotionParamsBoth_2609A8(arg0, 0xF, 2, 0x37);
                        temp_v0_78 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_57 = (*(s32 *)((u8 *)(temp_v0_78) + 0xE30));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_78) + 0xE34)) + temp_v0_78;
                        var_s3 = temp_a1_57 + temp_v0_78;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_23 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_23) + 0xE38)) + temp_v1_23;
                        }
                    }
                } else if (Forward30F348_31CFE0(temp_a0) & 1) {
                    StoreMotionParams_2609E0(arg0, 5, 0, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 5, 2, 0x37);
                    temp_v0_79 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_58 = (*(s32 *)((u8 *)(temp_v0_79) + 0xE04));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_79) + 0xE00)) + temp_v0_79;
                    var_s1 = temp_a1_58 + temp_v0_79;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_24 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_24) + 0xE08)) + temp_v1_24;
                    }
                } else {
                    StoreMotionParams_2609E0(arg0, 5, 0, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 5, 2, 0x37);
                    temp_v0_80 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_59 = (*(s32 *)((u8 *)(temp_v0_80) + 0xDF8));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_80) + 0xDF4)) + temp_v0_80;
                    var_s1 = temp_a1_59 + temp_v0_80;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_25 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_25) + 0xDFC)) + temp_v1_25;
                    }
                }
                break;
            case 0x270:                             /* switch 2 */
            case 0x271:                             /* switch 2 */
            case 0x272:                             /* switch 2 */
            case 0x273:                             /* switch 2 */
            case 0x274:                             /* switch 2 */
                var_a1_4 = 5;
                if (!(Forward30F348_31CFE0(temp_a0) & 1)) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x186B)) == 3) {
                        var_a1_4 = 5;
                        goto block_323;
                    }
                    StoreMotionParamsBoth_2609A8(arg0, 0x3C, 2, 0x38);
                    temp_v0_81 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_60 = (*(s32 *)((u8 *)(temp_v0_81) + 0x2218));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_81) + 0x221C)) + temp_v0_81;
                    var_s3 = temp_a1_60 + temp_v0_81;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_26 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_26) + 0x2220)) + temp_v1_26;
                    }
                } else {
block_323:
                    goto block_324;
                }
                break;
            case 0x20A:                             /* switch 2 */
            case 0x20D:                             /* switch 2 */
            case 0x245:                             /* switch 2 */
            case 0x247:                             /* switch 2 */
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) < 2.89f) {
                    temp_v1_27 = Forward30F348_31CFE0(arg0) & 3;
                    switch (temp_v1_27) {           /* switch 14; irregular */
                    case 1:                         /* switch 14 */
                        temp_v1_28 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_61 = (*(s32 *)((u8 *)(temp_v1_28) + 0x8D8));
                        var_s3 = temp_a1_61 + temp_v1_28;
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_28) + 0x8DC)) + temp_v1_28;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_29 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_29) + 0x8E0)) + temp_v1_29;
                        }
                        var_a3 = 0x3C;
block_347:
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, var_a3);
                        break;
                    case 3:                         /* switch 14 */
                        temp_v1_30 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_62 = (*(s32 *)((u8 *)(temp_v1_30) + 0x8CC));
                        var_s3 = temp_a1_62 + temp_v1_30;
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_30) + 0x8D0)) + temp_v1_30;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_31 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_31) + 0x8D4)) + temp_v1_31;
                        }
                        var_a3 = 0x37;
                        goto block_347;
                    default:                        /* switch 14 */
                    case 0:                         /* switch 14 */
                        StoreMotionParamsBoth_2609A8(arg0, 0xF, 2, 0x3E);
                        temp_v0_82 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_63 = (*(s32 *)((u8 *)(temp_v0_82) + 0x93C));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_82) + 0x940)) + temp_v0_82;
                        var_s3 = temp_a1_63 + temp_v0_82;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_14 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x944));
                            goto block_362;
                        }
                        break;
                    case 2:                         /* switch 14 */
                        StoreMotionParamsBoth_2609A8(arg0, 0xF, 2, 0x37);
                        temp_v0_83 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_64 = (*(s32 *)((u8 *)(temp_v0_83) + 0x918));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_83) + 0x91C)) + temp_v0_83;
                        var_s3 = temp_a1_64 + temp_v0_83;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_14 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x920));
                            goto block_362;
                        }
                        break;
                    }
                } else {
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v1_32 = Forward30F348_31CFE0() & 3;
                    switch (temp_v1_32) {           /* switch 15; irregular */
                    case 1:                         /* switch 15 */
                        temp_v0_84 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s3 = (*(s32 *)((u8 *)(temp_v0_84) + 0x8CC)) + temp_v0_84;
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_84) + 0x8D0)) + temp_v0_84;
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_14 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x8D4));
block_362:
                            var_s1 = var_v0_14 + (*(s32 *)((u8 *)(arg0) + 0x304));
                        }
                        break;
                    default:                        /* switch 15 */
                    case 0:                         /* switch 15 */
                        temp_v0_85 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s3 = (*(s32 *)((u8 *)(temp_v0_85) + 0x8CC)) + temp_v0_85;
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_85) + 0x8D0)) + temp_v0_85;
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_14 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x8D4));
                            goto block_362;
                        }
                        break;
                    case 2:                         /* switch 15 */
                        temp_v1_33 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_65 = (*(s32 *)((u8 *)(temp_v1_33) + 0x924));
                        var_s3 = temp_a1_65 + temp_v1_33;
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_33) + 0x928)) + temp_v1_33;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_14 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x92C));
                            goto block_362;
                        }
                        break;
                    case 3:                         /* switch 15 */
                        StoreMotionParamsBoth_2609A8(arg0, 0xF, 0xC, 0x37);
                        temp_v0_86 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_66 = (*(s32 *)((u8 *)(temp_v0_86) + 0x930));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_86) + 0x934)) + temp_v0_86;
                        var_s3 = temp_a1_66 + temp_v0_86;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_14 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x938));
                            goto block_362;
                        }
                        break;
                    }
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x2F7)) == 1) {
                    var_s6 = 0x4E2;
                    if (Forward30F348_31CFE0() & 1) {
                        StoreMotionParamsBoth_2609A8(arg0, 0xF, 2, 0x3E);
                        temp_v0_87 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_67 = (*(s32 *)((u8 *)(temp_v0_87) + 0x940));
                        var_s3 = (*(s32 *)((u8 *)(temp_v0_87) + 0x93C)) + temp_v0_87;
                        var_s1 = temp_a1_67 + temp_v0_87;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_15 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x944));
                            goto block_369;
                        }
                    } else {
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                        temp_v0_88 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_68 = (*(s32 *)((u8 *)(temp_v0_88) + 0x8D0));
                        var_s3 = (*(s32 *)((u8 *)(temp_v0_88) + 0x8CC)) + temp_v0_88;
                        var_s1 = temp_a1_68 + temp_v0_88;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_15 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x8D4));
block_369:
                            var_s1 = var_v0_15 + (*(s32 *)((u8 *)(arg0) + 0x304));
                        }
                    }
                }
                if (((*(f32 *)((u8 *)(arg0) + 0x760)) > 0.5235988f) && ((Forward30F348_31CFE0() % 3U) == 0)) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x3E);
                    temp_v0_89 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_69 = (*(s32 *)((u8 *)(temp_v0_89) + 0x8F4));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_89) + 0x8F0)) + temp_v0_89;
                    var_s1 = temp_a1_69 + temp_v0_89;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_34 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_34) + 0x8F8)) + temp_v1_34;
                    }
                }
                if (cCoreSave_getGameLevel(&D_00569B70) >= 2) {
                    if (Forward30F348_31CFE0() & 1) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
block_428:
                        temp_a1_70 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x8E8));
                        var_s3 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x8E4)) + (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = temp_a1_70 + (*(s32 *)((u8 *)(arg0) + 0x304));
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_2 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x8EC));
                            goto block_430;
                        }
                        goto block_431;
                    }
                }
                break;
            case 0x218:                             /* switch 2 */
            case 0x246:                             /* switch 2 */
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) < 6.25f) {
                    temp_v1_35 = Forward30F348_31CFE0() & 1;
                    switch (temp_v1_35) {           /* switch 16; irregular */
                    case 2:                         /* switch 16 */
                        temp_v1_36 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_71 = (*(s32 *)((u8 *)(temp_v1_36) + 0x3B54));
                        var_s3 = temp_a1_71 + temp_v1_36;
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_36) + 0x3B58)) + temp_v1_36;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_37 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_37) + 0x3B5C)) + temp_v1_37;
                        }
                        var_a2 = 3;
                        break;
                    default:                        /* switch 16 */
                    case 1:                         /* switch 16 */
                        temp_v1_38 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_72 = (*(s32 *)((u8 *)(temp_v1_38) + 0xCC8));
                        var_s3 = temp_a1_72 + temp_v1_38;
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_38) + 0xCCC)) + temp_v1_38;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_39 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_39) + 0xCD0)) + temp_v1_39;
                        }
                        var_a2 = 0;
                        break;
                    }
                    StoreMotionParamsBoth_2609A8(arg0, 0x1E, var_a2, 0x3E);
                } else {
                    StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x3E);
                    temp_v0_90 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_73 = (*(s32 *)((u8 *)(temp_v0_90) + 0x908));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_90) + 0x90C)) + temp_v0_90;
                    var_s3 = temp_a1_73 + temp_v0_90;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_40 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_40) + 0x910)) + temp_v1_40;
                    }
                }
                if (((cCoreSave_getGameLevel(&D_00569B70) >= 2) && (Forward30F348_31CFE0() & 1)) || ((*(u8 *)((u8 *)(arg0) + 0x2F7)) != 0)) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x28, 0x29, 0x3E);
                    temp_v0_91 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_74 = (*(s32 *)((u8 *)(temp_v0_91) + 0x3B4C));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_91) + 0x3B48)) + temp_v0_91;
                    var_s1 = temp_a1_74 + temp_v0_91;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_41 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_41) + 0x3B50)) + temp_v1_41;
                    }
                }
                break;
            case 0x278:                             /* switch 2 */
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) < 6.25f) {
                    temp_hi_6 = Forward30F348_31CFE0(arg0) % 3U;
                    switch (temp_hi_6) {            /* switch 17; irregular */
                    case 1:                         /* switch 17 */
                        temp_v1_42 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_75 = (*(s32 *)((u8 *)(temp_v1_42) + 0x8CC));
                        var_s3 = temp_a1_75 + temp_v1_42;
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_42) + 0x8D0)) + temp_v1_42;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_43 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_43) + 0x8D4)) + temp_v1_43;
                        }
                        StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x37);
                        break;
                    case 2:                         /* switch 17 */
                        temp_v1_44 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_76 = (*(s32 *)((u8 *)(temp_v1_44) + 0xCC8));
                        var_s3 = temp_a1_76 + temp_v1_44;
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_44) + 0xCCC)) + temp_v1_44;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_45 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_45) + 0xCD0)) + temp_v1_45;
                        }
                        var_a2_2 = 0;
block_414:
                        StoreMotionParamsBoth_2609A8(arg0, 0x1E, var_a2_2, 0x3E);
                        break;
                    default:                        /* switch 17 */
                    case 0:                         /* switch 17 */
                        temp_v1_46 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_77 = (*(s32 *)((u8 *)(temp_v1_46) + 0x93C));
                        var_s3 = temp_a1_77 + temp_v1_46;
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_46) + 0x940)) + temp_v1_46;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_47 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_47) + 0x944)) + temp_v1_47;
                        }
                        var_a2_2 = 2;
                        goto block_414;
                    }
                } else {
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v1_48 = Forward30F348_31CFE0() & 1;
                    if ((temp_v1_48 == 0) || (temp_v1_48 != 1)) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x3E);
                        temp_v0_92 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_78 = (*(s32 *)((u8 *)(temp_v0_92) + 0x908));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_92) + 0x90C)) + temp_v0_92;
                        var_s3 = temp_a1_78 + temp_v0_92;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_16 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x910));
                            goto block_421;
                        }
                    } else {
                        StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0xC, 0x3E);
                        temp_v0_93 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_79 = (*(s32 *)((u8 *)(temp_v0_93) + 0x930));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_93) + 0x934)) + temp_v0_93;
                        var_s3 = temp_a1_79 + temp_v0_93;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_16 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x938));
block_421:
                            var_s1 = var_v0_16 + (*(s32 *)((u8 *)(arg0) + 0x304));
                        }
                    }
                }
                if (((cCoreSave_getGameLevel(&D_00569B70) >= 2) && (Forward30F348_31CFE0() & 1)) || ((*(u8 *)((u8 *)(arg0) + 0x2F7)) != 0)) {
                    if (Forward30F348_31CFE0() & 1) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                        goto block_428;
                    }
                    StoreMotionParamsBoth_2609A8(arg0, 0x28, 0x29, 0x3E);
                    temp_v0_94 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_80 = (*(s32 *)((u8 *)(temp_v0_94) + 0x2010));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_94) + 0x200C)) + temp_v0_94;
                    var_s1 = temp_a1_80 + temp_v0_94;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_49 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_49) + 0x2014)) + temp_v1_49;
                    }
                }
                break;
            case 0x279:                             /* switch 2 */
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) < 6.25f) {
                    temp_v1_50 = Forward30F348_31CFE0() & 1;
                    switch (temp_v1_50) {           /* switch 18; irregular */
                    case 1:                         /* switch 18 */
                        temp_v1_51 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_81 = (*(s32 *)((u8 *)(temp_v1_51) + 0xCC8));
                        var_s3 = temp_a1_81 + temp_v1_51;
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_51) + 0xCD0)) + temp_v1_51;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_52 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_52) + 0xCD4)) + temp_v1_52;
                        }
                        StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x3E);
                        break;
                    default:                        /* switch 18 */
                    case 0:                         /* switch 18 */
                        temp_v1_53 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_82 = (*(s32 *)((u8 *)(temp_v1_53) + 0x2018));
                        var_s3 = temp_a1_82 + temp_v1_53;
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_53) + 0x201C)) + temp_v1_53;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_54 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_54) + 0x2020)) + temp_v1_54;
                        }
                        StoreMotionParams_2609E0(arg0, 0x1E, 0, 0x37);
                        Set_Fields_1884_1894_2609F8(arg0, 0x1E, 0, 0x3E);
                        break;
                    }
                } else {
                    StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x3E);
                    temp_v0_95 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_83 = (*(s32 *)((u8 *)(temp_v0_95) + 0x908));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_95) + 0x910)) + temp_v0_95;
                    var_s3 = temp_a1_83 + temp_v0_95;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_55 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_55) + 0x914)) + temp_v1_55;
                    }
                }
                break;
            case 0x20B:                             /* switch 2 */
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) < 2.89f) {
                    var_s0 = Forward30F348_31CFE0(temp_a0, 0x14) & 1;
                    if ((var_s0 == 0) || (var_s0 != 1)) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x3E);
                        temp_v0_96 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_84 = (*(s32 *)((u8 *)(temp_v0_96) + 0x1DB4));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_96) + 0x1DB8)) + temp_v0_96;
                        var_s3 = temp_a1_84 + temp_v0_96;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_11 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1DBC));
                            goto block_452;
                        }
                        goto block_453;
                    }
                    StoreMotionParamsBoth_2609A8(arg0, 0xA, 0, 0x37);
                    temp_v0_97 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_85 = (*(s32 *)((u8 *)(temp_v0_97) + 0x1DFC));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_97) + 0x1E00)) + temp_v0_97;
                    var_s3 = temp_a1_85 + temp_v0_97;
                    if (cCoreSave_getGameLevel(&D_00569B70) != 5) {
                        var_v0_5 = 0x28;
                    } else {
                        temp_v1_56 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_56) + 0x1E04)) + temp_v1_56;
                        var_v0_5 = 0x28;
                    }
                    goto block_474;
                }
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x3C);
                temp_v0_98 = (*(s32 *)((u8 *)(arg0) + 0x304));
                temp_a1_86 = (*(s32 *)((u8 *)(temp_v0_98) + 0x1E08));
                var_s1 = (*(s32 *)((u8 *)(temp_v0_98) + 0x1E0C)) + temp_v0_98;
                var_s3 = temp_a1_86 + temp_v0_98;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    temp_v1_57 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_s1 = (*(s32 *)((u8 *)(temp_v1_57) + 0x1E10)) + temp_v1_57;
                }
                (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x2D;
                break;
            case 0x20C:                             /* switch 2 */
                if (Forward30F348_31CFE0(temp_a0) & 1) {
                    StoreMotionParamsBoth_2609A8(arg0, 0xA, 0, 0x3D);
                    temp_v0_99 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_87 = (*(s32 *)((u8 *)(temp_v0_99) + 0x1F00));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_99) + 0x1F04)) + temp_v0_99;
                    var_s3 = temp_a1_87 + temp_v0_99;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_8 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1F08));
                        goto block_464;
                    }
                    goto block_465;
                }
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                temp_v0_100 = (*(s32 *)((u8 *)(arg0) + 0x304));
                temp_a1_88 = (*(s32 *)((u8 *)(temp_v0_100) + 0x1EF0));
                var_s1 = (*(s32 *)((u8 *)(temp_v0_100) + 0x1EF4)) + temp_v0_100;
                var_s3 = temp_a1_88 + temp_v0_100;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1EF8));
                    goto block_488;
                }
                goto block_490;
            case 0x24F:                             /* switch 2 */
                var_s0 = 1;
                temp_hi_7 = Forward30F348_31CFE0(temp_a0) % 3U;
                switch (temp_hi_7) {                /* switch 19; irregular */
                default:                            /* switch 19 */
                case 0:                             /* switch 19 */
                    StoreMotionParamsBoth_2609A8(arg0, 0xA, 0, 0x3D);
                    temp_v0_101 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_89 = (*(s32 *)((u8 *)(temp_v0_101) + 0x1F00));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_101) + 0x1F04)) + temp_v0_101;
                    var_s3 = temp_a1_89 + temp_v0_101;
                    var_v0_5 = 0x32;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_6 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1F08));
                        goto block_473;
                    }
                    goto block_474;
                case 1:                             /* switch 19 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v0_102 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_90 = (*(s32 *)((u8 *)(temp_v0_102) + 0x1EF0));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_102) + 0x1EF4)) + temp_v0_102;
                    var_s3 = temp_a1_90 + temp_v0_102;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1EF8));
                        goto block_488;
                    }
                    goto block_490;
                case 2:                             /* switch 19 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    temp_v0_103 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_91 = (*(s32 *)((u8 *)(temp_v0_103) + 0x1F4C));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_103) + 0x1F50)) + temp_v0_103;
                    var_s3 = temp_a1_91 + temp_v0_103;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_4 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1F54));
                        goto block_479;
                    }
                    goto block_480;
                }
                break;
            case 0x20E:                             /* switch 2 */
                temp_hi_8 = Forward30F348_31CFE0(temp_a0) % 3U;
                switch (temp_hi_8) {                /* switch 20; irregular */
                case 1:                             /* switch 20 */
                    StoreMotionParams_2609E0(arg0, 0xA, 0, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 0x14, 2, 0x3E);
                    temp_v0_104 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_92 = (*(s32 *)((u8 *)(temp_v0_104) + 0x2FE4));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_104) + 0x2FE0)) + temp_v0_104;
                    var_s1 = temp_a1_92 + temp_v0_104;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_7 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x2FE8));
                        goto block_622;
                    }
                    goto block_623;
                default:                            /* switch 20 */
                case 0:                             /* switch 20 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x3E);
                    temp_v0_105 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_93 = (*(s32 *)((u8 *)(temp_v0_105) + 0x2FD4));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_105) + 0x2FD8)) + temp_v0_105;
                    var_s3 = temp_a1_93 + temp_v0_105;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_9 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x2FDC));
                        goto block_488;
                    }
                    goto block_490;
                case 2:                             /* switch 20 */
                    StoreMotionParams_2609E0(arg0, 0x14, 2, 0x3E);
                    Set_Fields_1884_1894_2609F8(arg0, 0x14, 2, 0x3E);
                    temp_v0_106 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_94 = (*(s32 *)((u8 *)(temp_v0_106) + 0x3004));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_106) + 0x3000)) + temp_v0_106;
                    var_s1 = temp_a1_94 + temp_v0_106;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_17 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x3008));
block_617:
                        var_s1 = var_v0_17 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    }
block_619:
                    (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x32;
                    break;
                }
                break;
            case 0x250:                             /* switch 2 */
            case 0x251:                             /* switch 2 */
                StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x37);
                temp_v1_58 = Forward30F348_31CFE0() & 3;
                switch (temp_v1_58) {               /* switch 21; irregular */
                default:                            /* switch 21 */
                case 0:                             /* switch 21 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x3C, 0, 0x3E);
                    temp_v0_107 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_107) + 0x1974)) + temp_v0_107;
                    temp_v1_59 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    if (Forward30F348_31CFE0() & 1) {
                        var_v0_18 = (*(s32 *)((u8 *)(temp_v1_59) + 0x197C));
                    } else {
                        var_v0_18 = (*(s32 *)((u8 *)(temp_v1_59) + 0x1980));
                    }
block_509:
                    var_s1 = var_v0_18 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    break;
                case 1:                             /* switch 21 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x3C, 0, 0x3E);
                    temp_v0_108 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_108) + 0x19D0)) + temp_v0_108;
                    temp_v1_60 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    if (Forward30F348_31CFE0() & 1) {
                        var_v0_18 = (*(s32 *)((u8 *)(temp_v1_60) + 0x19D4));
                    } else {
                        var_v0_18 = (*(s32 *)((u8 *)(temp_v1_60) + 0x19DC));
                    }
                    goto block_509;
                case 2:                             /* switch 21 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x3C, 0, 0x3E);
                    temp_v0_109 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_109) + 0x19E0)) + temp_v0_109;
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_109) + 0x19E4)) + temp_v0_109;
                    break;
                case 3:                             /* switch 21 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x3C, 0, 0x3C);
                    temp_v0_110 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_95 = (*(s32 *)((u8 *)(temp_v0_110) + 0x924));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_110) + 0x928)) + temp_v0_110;
                    var_s3 = temp_a1_95 + temp_v0_110;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_18 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x92C));
                        goto block_509;
                    }
                    break;
                }
                if ((cCoreSave_getGameLevel(&D_00569B70) >= 2) && !(Forward30F348_31CFE0() & 3) && ((*(f32 *)((u8 *)(arg0) + 0x618)) < 4.84f)) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x32, 0x1B, 0x45);
                    var_s6 = 0x4E2;
                    temp_v0_111 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_96 = (*(s32 *)((u8 *)(temp_v0_111) + 0x19EC));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_111) + 0x19E8)) + temp_v0_111;
                    (*(f32 *)((u8 *)(arg0) + 0x604)) = 35.0f;
                    var_s1 = temp_a1_96 + temp_v0_111;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_61 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        (*(f32 *)((u8 *)(arg0) + 0x604)) = 25.0f;
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_61) + 0x19F0)) + temp_v1_61;
                    }
                }
                break;
            case 0x260:                             /* switch 2 */
                temp_hi_9 = Forward30F348_31CFE0(temp_a0) % 5U;
                switch (temp_hi_9) {                /* switch 22 */
                default:                            /* switch 22 */
                    StoreMotionParams_2609E0(arg0, 0x46, 0x30, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 0x46, 0x30, 0x3E);
                    temp_v0_112 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_97 = (*(s32 *)((u8 *)(temp_v0_112) + 0x3084));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_112) + 0x3080)) + temp_v0_112;
                    var_s1 = temp_a1_97 + temp_v0_112;
                    if (cCoreSave_getGameLevel(&D_00569B70) >= 5) {
                        temp_v1_62 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_62) + 0x3088)) + temp_v1_62;
                    }
                    var_v0_19 = 0x28;
                    break;
                case 1:                             /* switch 22 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x46, 0x31, 0x3E);
                    temp_v0_113 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_98 = (*(s32 *)((u8 *)(temp_v0_113) + 0x30CC));
                    var_s3 = temp_a1_98 + temp_v0_113;
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_113) + 0x30D0)) + temp_v0_113;
                    if (cCoreSave_getGameLevel(&D_00569B70) >= 5) {
                        temp_v1_63 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_63) + 0x30D4)) + temp_v1_63;
                    }
                    var_v0_19 = 0xF;
                    break;
                case 2:                             /* switch 22 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x46, 0x30, 0x3E);
                    temp_v0_114 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_99 = (*(s32 *)((u8 *)(temp_v0_114) + 0x308C));
                    var_s3 = temp_a1_99 + temp_v0_114;
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_114) + 0x3090)) + temp_v0_114;
                    if (cCoreSave_getGameLevel(&D_00569B70) >= 5) {
                        temp_v1_64 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_64) + 0x3094)) + temp_v1_64;
                    }
                    var_v0_19 = 0x1E;
                    break;
                case 3:                             /* switch 22 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x46, 0x31, 0x3E);
                    temp_v0_115 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_100 = (*(s32 *)((u8 *)(temp_v0_115) + 0x30A4));
                    var_s3 = temp_a1_100 + temp_v0_115;
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_115) + 0x30A8)) + temp_v0_115;
                    if (cCoreSave_getGameLevel(&D_00569B70) >= 5) {
                        temp_v1_65 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_65) + 0x30AC)) + temp_v1_65;
                    }
                    var_v0_19 = 0x1E;
                    break;
                case 4:                             /* switch 22 */
                    StoreMotionParams_2609E0(arg0, 0x46, 0x30, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 0x46, 0x31, 0x3E);
                    temp_v0_116 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_101 = (*(s32 *)((u8 *)(temp_v0_116) + 0x30B4));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_116) + 0x30B0)) + temp_v0_116;
                    var_s1 = temp_a1_101 + temp_v0_116;
                    if (cCoreSave_getGameLevel(&D_00569B70) >= 5) {
                        temp_v1_66 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_66) + 0x30B8)) + temp_v1_66;
                    }
                    var_v0_19 = 0x32;
                    break;
                }
                (*(s32 *)((u8 *)(arg0) + 0x5F0)) = var_v0_19;
                (*(f32 *)((u8 *)(arg0) + 0x604)) = 30.0f;
                if ((cCoreSave_getGameLevel(&D_00569B70) >= 2) && !(Forward30F348_31CFE0() & 3) && ((*(f32 *)((u8 *)(arg0) + 0x618)) < 4.84f)) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x46, 0x1B, 0x45);
                    var_s6 = 0x4E2;
                    temp_v0_117 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_102 = (*(s32 *)((u8 *)(temp_v0_117) + 0x30DC));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_117) + 0x30D8)) + temp_v0_117;
                    (*(f32 *)((u8 *)(arg0) + 0x604)) = 35.0f;
                    var_s1 = temp_a1_102 + temp_v0_117;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_67 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        (*(f32 *)((u8 *)(arg0) + 0x604)) = 25.0f;
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_67) + 0x30E0)) + temp_v1_67;
                    }
                }
                break;
            case 0x264:                             /* switch 2 */
                if (Forward30F348_31CFE0(temp_a0) & 1) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x50, 0x33, 0x3E);
                    temp_v0_118 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_103 = (*(s32 *)((u8 *)(temp_v0_118) + 0x328C));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_118) + 0x3290)) + temp_v0_118;
                    var_s3 = temp_a1_103 + temp_v0_118;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_68 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_68) + 0x3294)) + temp_v1_68;
                    }
                } else {
                    StoreMotionParamsBoth_2609A8(arg0, 0x50, 0x36, 0x3E);
                    temp_v0_119 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_104 = (*(s32 *)((u8 *)(temp_v0_119) + 0x32B8));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_119) + 0x32BC)) + temp_v0_119;
                    var_s3 = temp_a1_104 + temp_v0_119;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_69 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_69) + 0x32C0)) + temp_v1_69;
                    }
                }
block_575:
                (*(f32 *)((u8 *)(arg0) + 0x604)) = 30.0f;
                break;
            case 0x265:                             /* switch 2 */
                if ((*(s32 *)((u8 *)(arg0) + 0x16D4)) & 0x20000000) {
                    temp_hi_10 = Forward30F348_31CFE0(temp_a0) % 3U;
                    switch (temp_hi_10) {           /* switch 23; irregular */
                    case 1:                         /* switch 23 */
                        StoreMotionParamsBoth_2609A8(arg0, 0x28, 0x39, 0x37);
                        temp_v0_120 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_105 = (*(s32 *)((u8 *)(temp_v0_120) + 0x38FC));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_120) + 0x3900)) + temp_v0_120;
                        var_s3 = temp_a1_105 + temp_v0_120;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_70 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_70) + 0x3904)) + temp_v1_70;
                        }
                        break;
                    default:                        /* switch 23 */
                    case 0:                         /* switch 23 */
                        StoreMotionParamsBoth_2609A8(arg0, 0x50, 0x39, 0x3E);
                        temp_v0_121 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_106 = (*(s32 *)((u8 *)(temp_v0_121) + 0x38F0));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_121) + 0x38F4)) + temp_v0_121;
                        var_s3 = temp_a1_106 + temp_v0_121;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_71 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_71) + 0x38F8)) + temp_v1_71;
                        }
                        break;
                    case 2:                         /* switch 23 */
                        StoreMotionParamsBoth_2609A8(arg0, 0x50, 0x39, 0x37);
                        temp_v0_122 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_107 = (*(s32 *)((u8 *)(temp_v0_122) + 0x391C));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_122) + 0x3920)) + temp_v0_122;
                        var_s3 = temp_a1_107 + temp_v0_122;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_72 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_72) + 0x3924)) + temp_v1_72;
                        }
                        break;
                    }
                } else {
                    temp_hi_11 = Forward30F348_31CFE0(temp_a0) % 3U;
                    switch (temp_hi_11) {           /* switch 24; irregular */
                    case 1:                         /* switch 24 */
                        StoreMotionParamsBoth_2609A8(arg0, 0x50, 0x39, 0x3E);
                        temp_a1_108 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s3 = (*(s32 *)((u8 *)(temp_a1_108) + 0x37D0)) + temp_a1_108;
                        temp_v1_73 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_a0_4 = (*(s32 *)((u8 *)(arg0) + 0x744));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_73) + 0x37D4)) + temp_v1_73;
                            if (temp_a0_4 != 0) {
                                ForwardAnimParamPairByIndex_27EA50(temp_a0_4, 0xA);
                            }
                        } else {
                            temp_a0_5 = (*(s32 *)((u8 *)(arg0) + 0x744));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_73) + 0x37D4)) + temp_v1_73;
                            if (temp_a0_5 != 0) {
                                ForwardAnimParamPairByIndex_27EA50(temp_a0_5, 9);
                            }
                        }
                        break;
                    default:                        /* switch 24 */
                    case 0:                         /* switch 24 */
                        StoreMotionParamsBoth_2609A8(arg0, 0x50, 0x38, 0x37);
                        temp_a1_109 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s3 = (*(s32 *)((u8 *)(temp_a1_109) + 0x37A0)) + temp_a1_109;
                        temp_v1_74 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_a0_6 = (*(s32 *)((u8 *)(arg0) + 0x744));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_74) + 0x37A8)) + temp_v1_74;
                            if (temp_a0_6 != 0) {
                                ForwardAnimParamPairByIndex_27EA50(temp_a0_6, 8);
                            }
                        } else {
                            temp_a0_7 = (*(s32 *)((u8 *)(arg0) + 0x744));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_74) + 0x37A4)) + temp_v1_74;
                            if (temp_a0_7 != 0) {
                                ForwardAnimParamPairByIndex_27EA50(temp_a0_7, 7);
                            }
                        }
                        break;
                    case 2:                         /* switch 24 */
                        StoreMotionParams_2609E0(arg0, 0x50, 0x38, 0x37);
                        Set_Fields_1884_1894_2609F8(arg0, 0x78, 0x39, 0x3E);
                        temp_v1_75 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s3 = (*(s32 *)((u8 *)(temp_v1_75) + 0x37DC)) + temp_v1_75;
                        temp_v1_76 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_a0_8 = (*(s32 *)((u8 *)(arg0) + 0x744));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_76) + 0x37E4)) + temp_v1_76;
                            if (temp_a0_8 != 0) {
                                ForwardAnimParamPairByIndex_27EA50(temp_a0_8, 0xC);
                            }
                        } else {
                            temp_a0_9 = (*(s32 *)((u8 *)(arg0) + 0x744));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_76) + 0x37E0)) + temp_v1_76;
                            if (temp_a0_9 != 0) {
                                ForwardAnimParamPairByIndex_27EA50(temp_a0_9, 0xB);
                            }
                        }
                        break;
                    }
                }
                goto block_575;
            case 0x220:                             /* switch 2 */
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) > 4.0f) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x28, 0xD, 0x3E);
                    temp_v0_123 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_v1_2 = (*(s32 *)((u8 *)(temp_v0_123) + 0x1C44));
                    var_a0_2 = (*(s32 *)((u8 *)(temp_v0_123) + 0x1C48));
                    goto block_689;
                }
                StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x3E);
                temp_v0_124 = (*(s32 *)((u8 *)(arg0) + 0x304));
                temp_a1_110 = (*(s32 *)((u8 *)(temp_v0_124) + 0x1C30));
                var_s1 = (*(s32 *)((u8 *)(temp_v0_124) + 0x1C34)) + temp_v0_124;
                var_s3 = temp_a1_110 + temp_v0_124;
                var_s6 = 0x58;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    var_s5 = 0x4D;
block_594:
                    var_s1 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1C38)) + (*(s32 *)((u8 *)(arg0) + 0x304));
                } else {
                    var_s5 = 0x4C;
                }
                break;
            case 0x221:                             /* switch 2 */
                StoreMotionParamsBoth_2609A8(arg0, 0x32, 0, 0x3E);
                if ((*(s32 *)((u8 *)(arg0) + 0x16D0)) & 0x10000000) {
                    (*(u8 *)((u8 *)(arg0) + 0x17C3)) = 1U;
                } else {
                    (*(u8 *)((u8 *)(arg0) + 0x17C3)) = 0U;
                }
                Obj0000_Get_Byte_17C3_NZ_2_276468(arg0);
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) > 4.0f) {
                    if (Forward30F348_31CFE0() & 1) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x32, 0, 0x3E);
                        temp_v0_125 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_v1_2 = (*(s32 *)((u8 *)(temp_v0_125) + 0x1C28));
                        var_a0_2 = (*(s32 *)((u8 *)(temp_v0_125) + 0x1C2C));
                        goto block_689;
                    }
                    StoreMotionParamsBoth_2609A8(arg0, 0x32, 0, 0x3E);
                    temp_v0_126 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_111 = (*(s32 *)((u8 *)(temp_v0_126) + 0x1CC4));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_126) + 0x1CC8)) + temp_v0_126;
                    var_s3 = temp_a1_111 + temp_v0_126;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_77 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_77) + 0x1CCC)) + temp_v1_77;
                    }
                } else if (Forward30F348_31CFE0() & 1) {
                    temp_v1_78 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_112 = (*(s32 *)((u8 *)(temp_v1_78) + 0x1CB8));
                    var_s3 = temp_a1_112 + temp_v1_78;
                    var_s1 = (*(s32 *)((u8 *)(temp_v1_78) + 0x1CBC)) + temp_v1_78;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_79 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_79) + 0x1CC0)) + temp_v1_79;
                    }
                } else {
                    StoreMotionParamsBoth_2609A8(arg0, 0x32, 0, 0x3E);
                    temp_v0_127 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_113 = (*(s32 *)((u8 *)(temp_v0_127) + 0x1C30));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_127) + 0x1C34)) + temp_v0_127;
                    var_s3 = temp_a1_113 + temp_v0_127;
                    var_s6 = 0x58;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_s5 = 0xAF;
                        goto block_594;
                    }
                    var_s5 = 0xAE;
                }
                break;
            case 0x222:                             /* switch 2 */
                if ((*(f32 *)((u8 *)(arg0) + 0x618)) > 4.0f) {
                    StoreMotionParamsBoth_2609A8(arg0, 0x3C, 0xD, 0x3E);
                    temp_v0_128 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_v1_2 = (*(s32 *)((u8 *)(temp_v0_128) + 0x1C44));
                    var_a0_2 = (*(s32 *)((u8 *)(temp_v0_128) + 0x1C4C));
                    goto block_689;
                }
                StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0x22, 0x37);
                temp_v0_129 = (*(s32 *)((u8 *)(arg0) + 0x304));
                temp_a1_114 = (*(s32 *)((u8 *)(temp_v0_129) + 0x1C70));
                var_s1 = (*(s32 *)((u8 *)(temp_v0_129) + 0x1C74)) + temp_v0_129;
                var_s3 = temp_a1_114 + temp_v0_129;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    temp_v1_80 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_s1 = (*(s32 *)((u8 *)(temp_v1_80) + 0x1C78)) + temp_v1_80;
                }
                break;
            case 0x223:                             /* switch 2 */
                (*(f32 *)((u8 *)(arg0) + 0x604)) = 30.0f;
                if ((Forward30F348_31CFE0(temp_a0) & 1) && ((*(s32 *)((u8 *)(arg0) + 0x6F4)) != 0)) {
                    temp_hi_12 = Forward30F348_31CFE0() % 3U;
                    switch (temp_hi_12) {           /* switch 25; irregular */
                    case 1:                         /* switch 25 */
                        StoreMotionParamsBoth_2609A8(arg0, 0x28, 0x2E, 0x3E);
                        temp_v0_130 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_115 = (*(s32 *)((u8 *)(temp_v0_130) + 0x2D94));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_130) + 0x2D98)) + temp_v0_130;
                        var_s3 = temp_a1_115 + temp_v0_130;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_17 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x2D9C));
                            goto block_617;
                        }
                        break;
                    default:                        /* switch 25 */
                    case 0:                         /* switch 25 */
                        temp_v1_81 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_116 = (*(s32 *)((u8 *)(temp_v1_81) + 0x2DB8));
                        var_s3 = temp_a1_116 + temp_v1_81;
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_81) + 0x2DBC)) + temp_v1_81;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_82 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_82) + 0x2DC0)) + temp_v1_82;
                        }
                        StoreMotionParams_2609E0(arg0, 0x1E, 0x2B, 0x37);
                        Set_Fields_1884_1894_2609F8(arg0, 0x1E, 0x2B, 0x3E);
                        break;
                    case 2:                         /* switch 25 */
                        StoreMotionParamsBoth_2609A8(arg0, 0x28, 0x2E, 0x3E);
                        temp_v0_131 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_117 = (*(s32 *)((u8 *)(temp_v0_131) + 0x2DA0));
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_131) + 0x2DA4)) + temp_v0_131;
                        var_s3 = temp_a1_117 + temp_v0_131;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            var_v0_17 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x2DA8));
                            goto block_617;
                        }
                        break;
                    }
                    goto block_619;
                }
                if (Forward30F348_31CFE0() & 1) {
                    StoreMotionParams_2609E0(arg0, 0x1E, 0x2F, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 0x1E, 0x2F, 0x3E);
                    temp_v0_132 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_118 = (*(s32 *)((u8 *)(temp_v0_132) + 0x2D80));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_132) + 0x2D7C)) + temp_v0_132;
                    var_s1 = temp_a1_118 + temp_v0_132;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_17 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x2D84));
                        goto block_617;
                    }
                    goto block_619;
                }
                StoreMotionParamsBoth_2609A8(arg0, 0x28, 0x2F, 0x3E);
                temp_v0_133 = (*(s32 *)((u8 *)(arg0) + 0x304));
                temp_a1_119 = (*(s32 *)((u8 *)(temp_v0_133) + 0x2E00));
                var_s1 = (*(s32 *)((u8 *)(temp_v0_133) + 0x2E04)) + temp_v0_133;
                var_s3 = temp_a1_119 + temp_v0_133;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    var_v0_7 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x2E08));
                    goto block_622;
                }
                goto block_623;
            case 0x275:                             /* switch 2 */
            case 0x276:                             /* switch 2 */
                if (!((*(f32 *)((u8 *)(arg0) + 0x618)) < 9.0f)) {
                    if ((*(s32 *)((u8 *)(arg0) + 0x16D4)) & 0x80) {
                        temp_v1_83 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_120 = (*(s32 *)((u8 *)(temp_v1_83) + 0x22EC));
                        var_s3 = temp_a1_120 + temp_v1_83;
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_83) + 0x22F0)) + temp_v1_83;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_84 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_84) + 0x22F4)) + temp_v1_84;
                        }
                        var_a2_3 = 0xA;
                        goto block_660;
                    }
                    temp_v1_85 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_121 = (*(s32 *)((u8 *)(temp_v1_85) + 0x2324));
                    var_s3 = temp_a1_121 + temp_v1_85;
                    var_s1 = (*(s32 *)((u8 *)(temp_v1_85) + 0x2328)) + temp_v1_85;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_86 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_86) + 0x232C)) + temp_v1_86;
                    }
                    StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0xA, 0x3E);
                } else {
                    var_s0_2 = Forward30F348_31CFE0(temp_a0) % 3U;
                    if ((*(s32 *)((u8 *)(arg0) + 0x16D4)) & 0x80) {
                        var_s0_2 = (Forward30F348_31CFE0() & 1) ? 3U : 1U;
                    }
                    temp_a2_2 = (*(s32 *)((u8 *)(arg0) + 0x16D4));
                    var_s0_3 = (temp_a2_2 & 0x10000) ? 1U : ((temp_a2_2 & 0x100) ? 1U : var_s0_2);
                    if (temp_a2_2 & 0x200) {
                        var_s0_3 = (temp_a2_2 & 0x80) ? 3U : 1U;
                    }
                    if ((*(f32 *)((u8 *)(arg0) + 0x760)) > 0.7853982f) {
                        if (!(temp_a2_2 & 0x10380)) {
                            temp_v0_134 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s3 = (*(s32 *)((u8 *)(temp_v0_134) + 0x2310)) + temp_v0_134;
                            var_s1 = (*(s32 *)((u8 *)(temp_v0_134) + 0x2314)) + temp_v0_134;
                            StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0x2A, 0x39);
                        } else {
                            goto block_635;
                        }
                    } else {
block_635:
                        switch (var_s0_3) {         /* switch 26; irregular */
                        case 1:                     /* switch 26 */
                            temp_v1_87 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            temp_a1_122 = (*(s32 *)((u8 *)(temp_v1_87) + 0x22C8));
                            var_s3 = temp_a1_122 + temp_v1_87;
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_87) + 0x22CC)) + temp_v1_87;
                            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                temp_v1_88 = (*(s32 *)((u8 *)(arg0) + 0x304));
                                var_s1 = (*(s32 *)((u8 *)(temp_v1_88) + 0x22D0)) + temp_v1_88;
                            }
                            var_a1_5 = 0x1E;
                            var_a2_4 = 0x26;
block_652:
                            StoreMotionParamsBoth_2609A8(arg0, var_a1_5, var_a2_4, 0x38);
                            break;
                        case 3:                     /* switch 26 */
                            temp_v1_89 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            temp_a1_123 = (*(s32 *)((u8 *)(temp_v1_89) + 0x2318));
                            var_s3 = temp_a1_123 + temp_v1_89;
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_89) + 0x231C)) + temp_v1_89;
                            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                temp_v1_90 = (*(s32 *)((u8 *)(arg0) + 0x304));
                                var_s1 = (*(s32 *)((u8 *)(temp_v1_90) + 0x2320)) + temp_v1_90;
                            }
                            var_a2_3 = 0;
block_660:
                            StoreMotionParamsBoth_2609A8(arg0, 0x32, var_a2_3, 0x3E);
                            break;
                        default:                    /* switch 26 */
                        case 0:                     /* switch 26 */
                            temp_v1_91 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            temp_a1_124 = (*(s32 *)((u8 *)(temp_v1_91) + 0x22BC));
                            var_s3 = temp_a1_124 + temp_v1_91;
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_91) + 0x22C0)) + temp_v1_91;
                            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                temp_v1_92 = (*(s32 *)((u8 *)(arg0) + 0x304));
                                var_s1 = (*(s32 *)((u8 *)(temp_v1_92) + 0x22C4)) + temp_v1_92;
                            }
                            var_a1_5 = 0x1E;
                            var_a2_4 = 0x27;
                            goto block_652;
                        case 2:                     /* switch 26 */
                            temp_v1_93 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            temp_a1_125 = (*(s32 *)((u8 *)(temp_v1_93) + 0x22D4));
                            var_s3 = temp_a1_125 + temp_v1_93;
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_93) + 0x22D8)) + temp_v1_93;
                            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                temp_v1_94 = (*(s32 *)((u8 *)(arg0) + 0x304));
                                var_s1 = (*(s32 *)((u8 *)(temp_v1_94) + 0x22DC)) + temp_v1_94;
                            }
                            var_a1_5 = 0x32;
                            var_a2_4 = 0x28;
                            goto block_652;
                        }
                    }
                }
                (*(f32 *)((u8 *)(arg0) + 0x604)) = 35.0f;
                break;
            case 0x256:                             /* switch 2 */
                temp_hi_13 = Forward30F348_31CFE0(temp_a0) % 6U;
                switch (temp_hi_13) {               /* switch 27 */
                default:                            /* switch 27 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x3E);
                    temp_a3 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_s3 = (*(s32 *)((u8 *)(temp_a3) + 0x2A8C)) + temp_a3;
                    var_s1 = (*(s32 *)((u8 *)(temp_a3) + 0x2A90)) + temp_a3;
                    if ((*(s32 *)((u8 *)(arg0) + 0x16D4)) & 0x04000000) {
                        var_s1 = (*(s32 *)((u8 *)(temp_a3) + 0x2A94)) + temp_a3;
                    }
                    break;
                case 1:                             /* switch 27 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x3E);
                    temp_a3_2 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_s3 = (*(s32 *)((u8 *)(temp_a3_2) + 0x2A98)) + temp_a3_2;
                    var_s1 = (*(s32 *)((u8 *)(temp_a3_2) + 0x2A9C)) + temp_a3_2;
                    if ((*(s32 *)((u8 *)(arg0) + 0x16D4)) & 0x04000000) {
                        var_s1 = (*(s32 *)((u8 *)(temp_a3_2) + 0x2AA0)) + temp_a3_2;
                    }
                    break;
                case 3:                             /* switch 27 */
                    StoreMotionParams_2609E0(arg0, 0x28, 0, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 0x28, 0, 0x3E);
                    temp_a3_3 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_s3 = (*(s32 *)((u8 *)(temp_a3_3) + 0x2AB0)) + temp_a3_3;
                    var_s1 = (*(s32 *)((u8 *)(temp_a3_3) + 0x2AB4)) + temp_a3_3;
                    if ((*(s32 *)((u8 *)(arg0) + 0x16D4)) & 0x04000000) {
                        var_s1 = (*(s32 *)((u8 *)(temp_a3_3) + 0x2AB8)) + temp_a3_3;
                    }
                    break;
                case 4:                             /* switch 27 */
                    if (cCoreSave_getGameLevel(&D_00569B70) >= 3) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x28, 0x11, 0x4E);
                        temp_a3_4 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s3 = (*(s32 *)((u8 *)(temp_a3_4) + 0x2ABC)) + temp_a3_4;
                        var_s1 = (*(s32 *)((u8 *)(temp_a3_4) + 0x2AC0)) + temp_a3_4;
                        if ((*(s32 *)((u8 *)(arg0) + 0x16D4)) & 0x04000000) {
                            var_s1 = (*(s32 *)((u8 *)(temp_a3_4) + 0x2AC4)) + temp_a3_4;
                        }
                    } else {
block_677:
                        StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x3E);
                        temp_a3_5 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s3 = (*(s32 *)((u8 *)(temp_a3_5) + 0x2AA4)) + temp_a3_5;
                        var_s1 = (*(s32 *)((u8 *)(temp_a3_5) + 0x2AA8)) + temp_a3_5;
                        if ((*(s32 *)((u8 *)(arg0) + 0x16D4)) & 0x04000000) {
                            var_s1 = (*(s32 *)((u8 *)(temp_a3_5) + 0x2AAC)) + temp_a3_5;
                        }
                    }
                    break;
                case 2:                             /* switch 27 */
                    goto block_677;
                case 5:                             /* switch 27 */
                    if ((*(s32 *)((u8 *)(arg0) + 0x564)) == 0x256) {
                        StoreMotionParams_2609E0(arg0, 0x28, 0, 0x37);
                        Set_Fields_1884_1894_2609F8(arg0, 0x28, 0, 0x3E);
                        temp_a3_6 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s3 = (*(s32 *)((u8 *)(temp_a3_6) + 0x2AE4)) + temp_a3_6;
                        var_s1 = (*(s32 *)((u8 *)(temp_a3_6) + 0x2AE8)) + temp_a3_6;
                        if ((*(s32 *)((u8 *)(arg0) + 0x16D4)) & 0x04000000) {
                            var_s1 = (*(s32 *)((u8 *)(temp_a3_6) + 0x2AEC)) + temp_a3_6;
                        }
                    } else {
block_691:
                        StoreMotionParams_2609E0(arg0, 0x14, 0, 0x37);
                        Set_Fields_1884_1894_2609F8(arg0, 0x14, 0, 0x37);
                        temp_a3_7 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s3 = (*(s32 *)((u8 *)(temp_a3_7) + 0x2B70)) + temp_a3_7;
                        var_s1 = (*(s32 *)((u8 *)(temp_a3_7) + 0x2B74)) + temp_a3_7;
                        if ((*(s32 *)((u8 *)(arg0) + 0x16D4)) & 0x04000000) {
                            var_s1 = (*(s32 *)((u8 *)(temp_a3_7) + 0x2B78)) + temp_a3_7;
                        }
                    }
                    break;
                }
                break;
            case 0x27E:                             /* switch 2 */
                temp_hi_14 = Forward30F348_31CFE0(temp_a0) % 6U;
                switch (temp_hi_14) {               /* switch 28 */
                default:                            /* switch 28 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x3E);
                    temp_v0_135 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_v1_2 = (*(s32 *)((u8 *)(temp_v0_135) + 0x2A8C));
                    var_a0_2 = (*(s32 *)((u8 *)(temp_v0_135) + 0x2A94));
                    goto block_689;
                case 1:                             /* switch 28 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x3E);
                    temp_v0_136 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_v1_2 = (*(s32 *)((u8 *)(temp_v0_136) + 0x2A98));
                    var_a0_2 = (*(s32 *)((u8 *)(temp_v0_136) + 0x2AA0));
                    goto block_689;
                case 2:                             /* switch 28 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x3E);
                    temp_v0_137 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_v1_2 = (*(s32 *)((u8 *)(temp_v0_137) + 0x2AA4));
                    var_a0_2 = (*(s32 *)((u8 *)(temp_v0_137) + 0x2AAC));
                    goto block_689;
                case 3:                             /* switch 28 */
                    StoreMotionParams_2609E0(arg0, 0x28, 0, 0x37);
                    Set_Fields_1884_1894_2609F8(arg0, 0x28, 0, 0x3E);
                    temp_v0_138 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_v1_2 = (*(s32 *)((u8 *)(temp_v0_138) + 0x2AB0));
                    var_a0_2 = (*(s32 *)((u8 *)(temp_v0_138) + 0x2AB8));
                    goto block_689;
                case 4:                             /* switch 28 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x28, 0x11, 0x4E);
                    temp_v0_139 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_v1_2 = (*(s32 *)((u8 *)(temp_v0_139) + 0x2ABC));
                    var_a0_2 = (*(s32 *)((u8 *)(temp_v0_139) + 0x2AC4));
                    goto block_689;
                case 5:                             /* switch 28 */
                    goto block_691;
                }
                break;
            case 0x25B:                             /* switch 2 */
                temp_hi_15 = Forward30F348_31CFE0(temp_a0) % 7U;
                switch (temp_hi_15) {               /* switch 29 */
                default:                            /* switch 29 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x37);
                    temp_v0_140 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_126 = (*(s32 *)((u8 *)(temp_v0_140) + 0x2CAC));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_140) + 0x2CB0)) + temp_v0_140;
                    var_s3 = temp_a1_126 + temp_v0_140;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_20 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x2CB4));
block_711:
                        var_s1 = var_v0_20 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    }
                    break;
                case 1:                             /* switch 29 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x37);
                    temp_v0_141 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_127 = (*(s32 *)((u8 *)(temp_v0_141) + 0x2CB8));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_141) + 0x2CBC)) + temp_v0_141;
                    var_s3 = temp_a1_127 + temp_v0_141;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_20 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x2CC0));
                        goto block_711;
                    }
                    break;
                case 2:                             /* switch 29 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x37);
                    temp_v0_142 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_128 = (*(s32 *)((u8 *)(temp_v0_142) + 0x2CE8));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_142) + 0x2CEC)) + temp_v0_142;
                    var_s3 = temp_a1_128 + temp_v0_142;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_20 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x2CF0));
                        goto block_711;
                    }
                    break;
                case 3:                             /* switch 29 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x37);
                    temp_v0_143 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_129 = (*(s32 *)((u8 *)(temp_v0_143) + 0x2CDC));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_143) + 0x2CE0)) + temp_v0_143;
                    var_s3 = temp_a1_129 + temp_v0_143;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_21 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x2CF0));
block_705:
                        var_s1 = var_v0_21 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    }
block_706:
                    (*(f32 *)((u8 *)(arg0) + 0x1770)) = 15.0f;
                    break;
                case 4:                             /* switch 29 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x37);
                    temp_v0_144 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_130 = (*(s32 *)((u8 *)(temp_v0_144) + 0x2D24));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_144) + 0x2D28)) + temp_v0_144;
                    var_s3 = temp_a1_130 + temp_v0_144;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_21 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x2D2C));
                        goto block_705;
                    }
                    goto block_706;
                case 5:                             /* switch 29 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x37);
                    temp_v0_145 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_131 = (*(s32 *)((u8 *)(temp_v0_145) + 0x2CC4));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_145) + 0x2CC8)) + temp_v0_145;
                    var_s3 = temp_a1_131 + temp_v0_145;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_20 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x2CCC));
                        goto block_711;
                    }
                    break;
                case 6:                             /* switch 29 */
                case 7:                             /* switch 29 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0, 0x37);
                    temp_v0_146 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_132 = (*(s32 *)((u8 *)(temp_v0_146) + 0x2CD0));
                    var_s1 = (*(s32 *)((u8 *)(temp_v0_146) + 0x2CD4)) + temp_v0_146;
                    var_s3 = temp_a1_132 + temp_v0_146;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_20 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x2CD8));
                        goto block_711;
                    }
                    break;
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x17C3)) == 0) {

                }
                break;
            }
        } else {
        case 0x212:                                 /* switch 2 */
        case 0x214:                                 /* switch 2 */
        case 0x215:                                 /* switch 2 */
        case 0x219:                                 /* switch 2 */
        case 0x227:                                 /* switch 2 */
        case 0x228:                                 /* switch 2 */
        case 0x22B:                                 /* switch 2 */
        case 0x230:                                 /* switch 2 */
        case 0x231:                                 /* switch 2 */
        case 0x232:                                 /* switch 2 */
        case 0x233:                                 /* switch 2 */
        case 0x234:                                 /* switch 2 */
        case 0x235:                                 /* switch 2 */
        case 0x236:                                 /* switch 2 */
        case 0x237:                                 /* switch 2 */
        case 0x238:                                 /* switch 2 */
        case 0x239:                                 /* switch 2 */
        case 0x23A:                                 /* switch 2 */
        case 0x23C:                                 /* switch 2 */
        case 0x23D:                                 /* switch 2 */
        case 0x23E:                                 /* switch 2 */
        case 0x23F:                                 /* switch 2 */
        case 0x240:                                 /* switch 2 */
        case 0x24A:                                 /* switch 2 */
        case 0x253:                                 /* switch 2 */
        case 0x254:                                 /* switch 2 */
        case 0x255:                                 /* switch 2 */
        case 0x257:                                 /* switch 2 */
        case 0x258:                                 /* switch 2 */
        case 0x259:                                 /* switch 2 */
        case 0x25C:                                 /* switch 2 */
        case 0x25D:                                 /* switch 2 */
        case 0x25E:                                 /* switch 2 */
        case 0x25F:                                 /* switch 2 */
        case 0x261:                                 /* switch 2 */
        case 0x262:                                 /* switch 2 */
        case 0x263:                                 /* switch 2 */
        case 0x266:                                 /* switch 2 */
        case 0x267:                                 /* switch 2 */
        case 0x268:                                 /* switch 2 */
        case 0x269:                                 /* switch 2 */
        case 0x26A:                                 /* switch 2 */
        case 0x26B:                                 /* switch 2 */
        case 0x26C:                                 /* switch 2 */
        case 0x26D:                                 /* switch 2 */
        case 0x26E:                                 /* switch 2 */
        case 0x26F:                                 /* switch 2 */
        case 0x277:                                 /* switch 2 */
        case 0x27A:                                 /* switch 2 */
        case 0x27B:                                 /* switch 2 */
        case 0x27C:                                 /* switch 2 */
        case 0x27D:                                 /* switch 2 */
            temp_v0_147 = cCoreSave_getGameLevel(&D_00569B70);
            if ((temp_v0_147 == 1) || (temp_v0_147 <= 0) || (temp_v0_147 >= 6)) {
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                if (Forward30F348_31CFE0() & 1) {
                    goto block_27;
                }
                temp_v0_148 = (*(s32 *)((u8 *)(arg0) + 0x304));
                temp_a1_133 = (*(s32 *)((u8 *)(temp_v0_148) + 0x154));
                var_s3 = (*(s32 *)((u8 *)(temp_v0_148) + 0x150)) + temp_v0_148;
                var_s1 = temp_a1_133 + temp_v0_148;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    var_v0_22 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x158));
                    goto block_29;
                }
            } else {
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                temp_hi_16 = Forward30F348_31CFE0() % 3U;
                switch (temp_hi_16) {               /* switch 3; irregular */
                case 1:                             /* switch 3 */
                    temp_v0_149 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_134 = (*(s32 *)((u8 *)(temp_v0_149) + 0x154));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_149) + 0x150)) + temp_v0_149;
                    var_s1 = temp_a1_134 + temp_v0_149;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_22 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x158));
block_29:
                        var_s1 = var_v0_22 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    }
                    break;
                case 2:                             /* switch 3 */
block_27:
                    temp_a1_135 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1B0));
                    var_s3 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1AC)) + (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_s1 = temp_a1_135 + (*(s32 *)((u8 *)(arg0) + 0x304));
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_22 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1B4));
                        goto block_29;
                    }
                    break;
                default:                            /* switch 3 */
                case 0:                             /* switch 3 */
                    StoreMotionParamsBoth_2609A8(arg0, 0xF, 0, 0x37);
                    temp_v0_150 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_136 = (*(s32 *)((u8 *)(temp_v0_150) + 0x130));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_150) + 0x12C)) + temp_v0_150;
                    var_s1 = temp_a1_136 + temp_v0_150;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        var_v0_22 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x134));
                        goto block_29;
                    }
                    break;
                }
            }
            if (((*(s32 *)((u8 *)(arg0) + 0x564)) == 0x214) && (Forward30F348_31CFE0() & 1)) {
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0x11, 0x4E);
                temp_v0_151 = (*(s32 *)((u8 *)(arg0) + 0x304));
                temp_a1_137 = (*(s32 *)((u8 *)(temp_v0_151) + 0x1B1C));
                var_s3 = (*(s32 *)((u8 *)(temp_v0_151) + 0x1B18)) + temp_v0_151;
                var_s1 = temp_a1_137 + temp_v0_151;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    temp_v1_95 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_s1 = (*(s32 *)((u8 *)(temp_v1_95) + 0x1B20)) + temp_v1_95;
                }
            }
            if (Forward30F348_31CFE0() & 1) {
                temp_v0_152 = (*(s32 *)((u8 *)(arg0) + 0x564));
                (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x1E;
                temp_a0_10 = temp_v0_152 - 0x200;
                if (temp_a0_10 < 0x3BU) {
                    switch (temp_v0_152) {          /* switch 4 */
                    case 0x200:                     /* switch 4 */
                    case 0x227:                     /* switch 4 */
                        if ((u8) (*(u8 *)((u8 *)(arg0) + 0x186B)) >= 5U) {
                            StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                            temp_v0_153 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            temp_a1_138 = (*(s32 *)((u8 *)(temp_v0_153) + 0x220));
                            var_s3 = (*(s32 *)((u8 *)(temp_v0_153) + 0x21C)) + temp_v0_153;
                            var_s1 = temp_a1_138 + temp_v0_153;
                            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                var_v0_23 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x224));
block_61:
                                var_s1 = var_v0_23 + (*(s32 *)((u8 *)(arg0) + 0x304));
                            }
                        }
                        break;
                    case 0x201:                     /* switch 4 */
                    case 0x228:                     /* switch 4 */
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                        temp_v0_154 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        temp_a1_139 = (*(s32 *)((u8 *)(temp_v0_154) + 0x230));
                        var_s3 = (*(s32 *)((u8 *)(temp_v0_154) + 0x22C)) + temp_v0_154;
                        var_s1 = temp_a1_139 + temp_v0_154;
                        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                            temp_v1_96 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            var_s1 = (*(s32 *)((u8 *)(temp_v1_96) + 0x234)) + temp_v1_96;
                        }
                        if (((u8) (*(u8 *)((u8 *)(arg0) + 0x186B)) >= 5U) && (Rnd() & 1)) {
                            if (Forward30F348_31CFE0() & 1) {
                                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                                temp_v0_155 = (*(s32 *)((u8 *)(arg0) + 0x304));
                                temp_a1_140 = (*(s32 *)((u8 *)(temp_v0_155) + 0x220));
                                var_s3 = (*(s32 *)((u8 *)(temp_v0_155) + 0x21C)) + temp_v0_155;
                                var_s1 = temp_a1_140 + temp_v0_155;
                                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                    var_v0_23 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x224));
                                    goto block_61;
                                }
                            } else {
                                StoreMotionParamsBoth_2609A8(arg0, 0x14, 7, 0x37);
                                temp_v0_156 = (*(s32 *)((u8 *)(arg0) + 0x304));
                                temp_a1_141 = (*(s32 *)((u8 *)(temp_v0_156) + 0x200));
                                var_s3 = (*(s32 *)((u8 *)(temp_v0_156) + 0x1FC)) + temp_v0_156;
                                var_s1 = temp_a1_141 + temp_v0_156;
                                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                    var_v0_23 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x204));
                                    goto block_61;
                                }
                            }
                        }
                        break;
                    case 0x204:                     /* switch 4 */
                    case 0x23A:                     /* switch 4 */
                        temp_hi_17 = Forward30F348_31CFE0() % 5U;
                        switch (temp_hi_17) {       /* switch 5 */
                        default:                    /* switch 5 */
                            StoreMotionParamsBoth_2609A8(arg0, 0x14, 2, 0x37);
                            temp_v0_157 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            temp_a1_142 = (*(s32 *)((u8 *)(temp_v0_157) + 0x1E0));
                            var_s3 = (*(s32 *)((u8 *)(temp_v0_157) + 0x1DC)) + temp_v0_157;
                            var_s1 = temp_a1_142 + temp_v0_157;
                            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                var_v0_23 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x1E4));
                                goto block_61;
                            }
                            break;
                        case 1:                     /* switch 5 */
                            StoreMotionParamsBoth_2609A8(arg0, 0x14, 7, 0x37);
                            temp_v0_158 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            temp_a1_143 = (*(s32 *)((u8 *)(temp_v0_158) + 0x200));
                            var_s3 = (*(s32 *)((u8 *)(temp_v0_158) + 0x1FC)) + temp_v0_158;
                            var_s1 = temp_a1_143 + temp_v0_158;
                            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                var_v0_23 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x204));
                                goto block_61;
                            }
                            break;
                        case 2:                     /* switch 5 */
                            StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                            temp_v0_159 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            temp_a1_144 = (*(s32 *)((u8 *)(temp_v0_159) + 0x210));
                            var_s3 = (*(s32 *)((u8 *)(temp_v0_159) + 0x20C)) + temp_v0_159;
                            var_s1 = temp_a1_144 + temp_v0_159;
                            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                var_v0_23 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x214));
                                goto block_61;
                            }
                            break;
                        case 3:                     /* switch 5 */
                            StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                            temp_v0_160 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            temp_a1_145 = (*(s32 *)((u8 *)(temp_v0_160) + 0x220));
                            var_s3 = (*(s32 *)((u8 *)(temp_v0_160) + 0x21C)) + temp_v0_160;
                            var_s1 = temp_a1_145 + temp_v0_160;
                            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                var_v0_23 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x224));
                                goto block_61;
                            }
                            break;
                        case 4:                     /* switch 5 */
                            StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                            temp_v0_161 = (*(s32 *)((u8 *)(arg0) + 0x304));
                            temp_a1_146 = (*(s32 *)((u8 *)(temp_v0_161) + 0x230));
                            var_s3 = (*(s32 *)((u8 *)(temp_v0_161) + 0x22C)) + temp_v0_161;
                            var_s1 = temp_a1_146 + temp_v0_161;
                            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                                var_v0_23 = (*(s32 *)((u8 *)((*(s32 *)((u8 *)(arg0) + 0x304))) + 0x234));
                                goto block_61;
                            }
                            break;
                        }
                        break;
                    }
                }
            }
            if ((*(f32 *)((u8 *)(arg0) + 0x618)) > 2.89f) {
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 1, 0x37);
                temp_v0_162 = (*(s32 *)((u8 *)(arg0) + 0x304));
                temp_a1_147 = (*(s32 *)((u8 *)(temp_v0_162) + 0x148));
                var_s3 = (*(s32 *)((u8 *)(temp_v0_162) + 0x144)) + temp_v0_162;
                var_s1 = temp_a1_147 + temp_v0_162;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    temp_v1_97 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    var_s1 = (*(s32 *)((u8 *)(temp_v1_97) + 0x14C)) + temp_v1_97;
                }
            }
            if ((*(f32 *)((u8 *)(arg0) + 0x618)) > 4.0f) {
                StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                if (Forward30F348_31CFE0() & 1) {
                    temp_v0_163 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_148 = (*(s32 *)((u8 *)(temp_v0_163) + 0x190));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_163) + 0x18C)) + temp_v0_163;
                    var_s1 = temp_a1_148 + temp_v0_163;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_98 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_98) + 0x194)) + temp_v1_98;
                    }
                } else {
                    StoreMotionParamsBoth_2609A8(arg0, 0xF, 0, 0x37);
                    temp_v0_164 = (*(s32 *)((u8 *)(arg0) + 0x304));
                    temp_a1_149 = (*(s32 *)((u8 *)(temp_v0_164) + 0x1A0));
                    var_s3 = (*(s32 *)((u8 *)(temp_v0_164) + 0x19C)) + temp_v0_164;
                    var_s1 = temp_a1_149 + temp_v0_164;
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        temp_v1_99 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s1 = (*(s32 *)((u8 *)(temp_v1_99) + 0x1A4)) + temp_v1_99;
                    }
                    (*(s32 *)((u8 *)(arg0) + 0x5F4)) = 1;
                }
                temp_v1_100 = (*(s32 *)((u8 *)(arg0) + 0x564));
                switch (temp_v1_100) {              /* switch 6; irregular */
                case 0x227:                         /* switch 6 */
                    if (Forward30F348_31CFE0() & 1) {
                        temp_v0_165 = (*(s32 *)((u8 *)(arg0) + 0x304));
                        var_s3 = (*(s32 *)((u8 *)(temp_v0_165) + 0x6B8)) + temp_v0_165;
                        var_s1 = (*(s32 *)((u8 *)(temp_v0_165) + 0x6C0)) + temp_v0_165;
                        StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x3F);
                        (*(s32 *)((u8 *)(arg0) + 0x5F0)) = 0x32;
                        (*(f32 *)((u8 *)(arg0) + 0x608)) = 2.0f;
                    }
                    break;
                }
            } else {
            }
        }
        var_f20 = 1.0f;
        temp_v0_166 = cCoreSave_getGameLevel(&D_00569B70);
        switch (temp_v0_166) {                      /* switch 30 */
        case 5:                                     /* switch 30 */
            break;
        default:                                    /* switch 30 */
        case 1:                                     /* switch 30 */
            var_f20 = 0.75f;
            break;
        case 2:                                     /* switch 30 */
            var_f20 = 0.8f;
            break;
        case 3:                                     /* switch 30 */
        case 4:                                     /* switch 30 */
            var_f20 = 0.9f;
            break;
        }
        temp_v1_101 = (*(s32 *)((u8 *)(arg0) + 0x564));
        if ((temp_v1_101 < 0x245) && (temp_v1_101 >= 0x242)) {
            var_f20 = 1.0f;
        }
        (*(s32 *)((u8 *)(arg0) + 0x5F0)) = (s32) ((f32) (*(s32 *)((u8 *)(arg0) + 0x5F0)) * var_f20);
        func_002A8578(arg0, var_s3, var_s1, 0xA, 0);
        temp_v1_102 = (*(s32 *)((u8 *)(arg0) + 0x304));
        var_v0_24 = var_s6 ^ 0x4E2;
        if (var_s3 == ((*(s32 *)((u8 *)(temp_v1_102) + 0x2218)) + temp_v1_102)) {
            temp_v0_167 = (*(s32 *)((u8 *)(arg0) + 0x564));
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                switch (temp_v0_167) {              /* switch 31 */
                case 0x270:                         /* switch 31 */
                    var_a2_5 = 0x10;
                    goto block_740;
                case 0x271:                         /* switch 31 */
                    var_a2_5 = 0x12;
                    goto block_740;
                case 0x272:                         /* switch 31 */
                    var_a2_5 = 0x16;
                    goto block_740;
                case 0x273:                         /* switch 31 */
                    var_a2_5 = 0x14;
                    goto block_740;
                case 0x274:                         /* switch 31 */
                    var_a2_5 = 0xE;
                    goto block_740;
                }
            } else {
                switch (temp_v0_167) {              /* switch 32 */
                case 0x270:                         /* switch 32 */
                    var_a2_5 = 0xF;
block_740:
                    InitRenderStruct_2A8608(arg0, 0xC8, var_a2_5, 0);
                    break;
                case 0x271:                         /* switch 32 */
                    var_a2_5 = 0x11;
                    goto block_740;
                case 0x272:                         /* switch 32 */
                    var_a2_5 = 0x15;
                    goto block_740;
                case 0x273:                         /* switch 32 */
                    var_a2_5 = 0x13;
                    goto block_740;
                case 0x274:                         /* switch 32 */
                    InitRenderStruct_2A8608(arg0, 0xC8, 0xD, 0);
                    break;
                }
            }
            var_v0_24 = var_s6 ^ 0x4E2;
        }
        if (var_v0_24 != 0) {
            InitRenderStruct_2A8608(arg0, var_s6, var_s5, 0);
        }
        (*(f32 *)((u8 *)(arg0) + 0x600)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x104));
        (*(u8 *)((u8 *)(arg0) + 0x2F6)) = (u8) ((*(u8 *)((u8 *)(arg0) + 0x2F6)) + 1);
        /* fallthrough */
    case 1:                                         /* switch 1 */
        temp_f1 = (*(f32 *)((u8 *)(arg0) + 0x604));
        if (temp_f1 > 0.0f) {
            (*(s32 *)((u8 *)(arg0) + 0x16D0)) = (s32) ((*(s32 *)((u8 *)(arg0) + 0x16D0)) | 0x800000);
            (*(f32 *)((u8 *)(arg0) + 0x604)) = (f32) (temp_f1 - (*(f32 *)((u8 *)(arg0) + 0x5A8)));
        }
        temp_v0_168 = (*(s32 *)((u8 *)(arg0) + 0x5F0));
        if (temp_v0_168 != 0) {
            temp_s0_2 = (*(s32 *)((u8 *)(arg0) + 0xF0));
            (*(s32 *)((u8 *)(arg0) + 0x5F0)) = (s32) (temp_v0_168 - 1);
            temp_f0 = Turn_dest(temp_s0_2, (*(s32 *)((u8 *)(Obj0000_Get_D_00747A94_2DB6B0()) + 0xF0)), (*(f32 *)((u8 *)(arg0) + 0x600)), (*(f32 *)((u8 *)(arg0) + 0x5A8)) * 0.19634955f);
            temp_f1_2 = (*(f32 *)((u8 *)(arg0) + 0x600)) + temp_f0;
            (*(f32 *)((u8 *)(arg0) + 0x600)) = temp_f1_2;
            (*(f32 *)((u8 *)(arg0) + 0x600)) = Adjust_theta(temp_f1_2);
            temp_f1_3 = (*(f32 *)((u8 *)(arg0) + 0x104)) + temp_f0;
            (*(f32 *)((u8 *)(arg0) + 0x104)) = temp_f1_3;
            (*(f32 *)((u8 *)(arg0) + 0x104)) = Adjust_theta(temp_f1_3);
        }
        if (moveMotion(arg0) == 0) {
            (*(f32 *)((u8 *)(arg0) + 0x338)) = (f32) ((*(f32 *)((u8 *)(arg0) + 0x338)) * (*(f32 *)((u8 *)(arg0) + 0x608)));
            AddScaledVecToField_100_14F9F0(arg0, 0x3F800000);
            AddScaledXfmVecToField_F0_14F928(arg0, 0x3F800000);
        default:                                    /* switch 1 */
            if ((*(s32 *)((u8 *)(arg0) + 0x5F4)) == 0) {
                if ((*(s32 *)((u8 *)(arg0) + 0x564)) == 0x222) {
                    temp_v1_103 = (*(u16 *)((u8 *)(arg0) + 0x3AC));
                    if (temp_v1_103 & 2) {
                        (*(u16 *)((u8 *)(arg0) + 0x3AC)) = (u16) (temp_v1_103 & 0xFFFD);
                        (*(u8 *)((u8 *)(arg0) + 0x1865)) = 2;
                        (*(f32 *)((u8 *)(arg0) + 0x17D4)) = 6.0f;
                    }
                }
                if ((*(s32 *)((u8 *)(arg0) + 0x5F4)) != 0) {
                    goto block_761;
                }
            } else {
block_761:
                temp_v0_169 = (*(s32 *)((u8 *)(arg0) + 0x564));
                switch (temp_v0_169) {              /* switch 33 */
                case 0x250:                         /* switch 33 */
                case 0x251:                         /* switch 33 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    if ((*(u16 *)((u8 *)(arg0) + 0x3AC)) & 2) {
                        var_a1_6 = 0x28;
block_777:
                        var_a3_2 = 0x3E;
block_778:
                        StoreMotionParamsBoth_2609A8(arg0, var_a1_6, 0, var_a3_2);
                    }
                    break;
                case 0x260:                         /* switch 33 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    if ((*(u16 *)((u8 *)(arg0) + 0x3AC)) & 2) {
                        var_a1_6 = 0x28;
                        goto block_777;
                    }
                    break;
                case 0x20B:                         /* switch 33 */
                    StoreMotionParamsBoth_2609A8(arg0, 0xA, 0, 0x37);
                    if ((*(u16 *)((u8 *)(arg0) + 0x3AC)) & 2) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x3E);
                    }
                    break;
                case 0x20C:                         /* switch 33 */
                case 0x24F:                         /* switch 33 */
                    StoreMotionParamsBoth_2609A8(arg0, 0xA, 0, 0x3D);
                    if ((*(u16 *)((u8 *)(arg0) + 0x3AC)) & 2) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x3E);
                    }
                    break;
                case 0x220:                         /* switch 33 */
                case 0x221:                         /* switch 33 */
                case 0x222:                         /* switch 33 */
                    StoreMotionParamsBoth_2609A8(arg0, 5, 0, 0x3D);
                    if ((*(u16 *)((u8 *)(arg0) + 0x3AC)) & 2) {
                        var_a1_6 = 0x14;
                        var_a3_2 = 0x3F;
                        goto block_778;
                    }
                    break;
                case 0x278:                         /* switch 33 */
                case 0x279:                         /* switch 33 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x28, 0, 0x3E);
                    if ((*(u16 *)((u8 *)(arg0) + 0x3AC)) & 2) {
                        var_a1_6 = 0x14;
                        var_a3_2 = 0x37;
                        goto block_778;
                    }
                    break;
                case 0x256:                         /* switch 33 */
                case 0x27E:                         /* switch 33 */
                    StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    if ((*(u16 *)((u8 *)(arg0) + 0x3AC)) & 2) {
                        var_a1_6 = 0x14;
                        goto block_777;
                    }
                    break;
                default:                            /* switch 33 */
                    StoreMotionParamsBoth_2609A8(arg0, 0xF, 0, 0x3D);
                    if ((*(u16 *)((u8 *)(arg0) + 0x3AC)) & 2) {
                        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37);
                    }
                    break;
                }
            }
            if ((*(s32 *)((u8 *)(arg0) + 0x564)) == 0x208) {
                temp_a0_11 = (*(s32 *)((u8 *)(arg0) + 0x700));
                if ((temp_a0_11 != 0) && (Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(temp_a0_11) == 0)) {
                    (*(s32 *)((u8 *)(arg0) + 0x16D0)) = (s32) ((*(s32 *)((u8 *)(arg0) + 0x16D0)) | 0x80000000);
                }
            }
            if ((*(s32 *)((u8 *)(arg0) + 0x564)) == 0x224) {
                temp_a1_150 = (*(s32 *)((u8 *)(arg0) + 0x704));
                if (temp_a1_150 != 0) {
                    if ((*(u16 *)((u8 *)(arg0) + 0x3AC)) & 2) {
                        SetOrientByType_26AF20(arg0, temp_a1_150, 9);
                    } else {
                        SetOrientByType_26AF20(arg0, temp_a1_150, 8);
                    }
                    if (((*(u16 *)((u8 *)(arg0) + 0x3AC)) & 0x10) && (Forward30F348_31CFE0() & 1) && (cCoreSave_getGameLevel(&D_00569B70) >= 2)) {
                        (*(u8 *)((u8 *)(arg0) + 0x2F6)) = 0U;
                        (*(u8 *)((u8 *)(arg0) + 0x2F7)) = 1U;
                    }
                }
                (*(u16 *)((u8 *)(arg0) + 0x3AC)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x3AC)) & 0xFFED);
            }
            func_00260B30(arg0);
            if ((cCoreSave_getGameLevel(&D_00569B70) >= 3) && ((*(u16 *)((u8 *)(arg0) + 0x3AC)) & 0x10)) {
                if (Obj0000_IsSet_Field_15F4_Bit_1000_12C530(temp_fp) != 0) {
                    goto block_799;
                }
                if ((*(s32 *)((u8 *)(arg0) + 0x564)) == 0x25B) {
                    (*(s32 *)((u8 *)(arg0) + 0x1864)) = 0U;
                }
                if (((*(s32 *)((u8 *)(arg0) + 0x1864)) != 0) || (func_00262AA8(arg0) == 0)) {
                    goto block_804;
                }
            } else {
block_804:
                if ((*(s32 *)((u8 *)(arg0) + 0x5FC)) != 0) {
                    (*(s32 *)((u8 *)(arg0) + 0x16D4)) = (s32) ((*(s32 *)((u8 *)(arg0) + 0x16D4)) & 0xFFFFFBFF);
                }
                temp_v1_104 = (*(s32 *)((u8 *)(arg0) + 0x564));
                if (temp_v1_104 != 0x260) {
                    if ((temp_v1_104 >= 0x260) && (temp_v1_104 < 0x266)) {
                        if (temp_v1_104 >= 0x264) {
                            goto block_810;
                        }
                    }
                } else {
block_810:
                    (*(u16 *)((u8 *)(arg0) + 0x3AC)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x3AC)) & 0xFEFF);
                }
            }
        } else {
            AddScaledVecToField_100_14F9F0(arg0, 0x3F800000);
            AddScaledXfmVecToField_F0_14F928(arg0, 0x3F800000);
            if (Obj0000_IsSet_Field_15F4_Bit_1000_12C530(temp_fp) == 0) {
                func_002705D8(arg0);
            } else {
block_799:
                (*(u8 *)((u8 *)(arg0) + 0x2F7)) = 0U;
                (*(u8 *)((u8 *)(arg0) + 0x2F5)) = 0x6C;
                (*(u8 *)((u8 *)(arg0) + 0x2F4)) = 0;
                (*(u8 *)((u8 *)(arg0) + 0x2F6)) = 0U;
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("nonmatching", func_0021A538);
/* Re-export the jump-table head labels the .rodata tables reference across
 * the .o boundary (the labels.inc-assembled carve marks `jlabel`s local). */
__asm__(
    ".globl .L0021B1C8\n"
    ".globl .L0021A8A4\n"
    ".globl .L0021AA68\n"
    ".globl .L0021AF4C\n"
    ".globl .L0021C5CC\n"
    ".globl .L0021DFF4\n"
    ".globl .L0021EF2C\n"
    ".globl .L0021F18C\n"
    ".globl .L0021F334\n"
    ".globl .L0021F5DC\n"
    ".globl .L0021F6B4\n"
    ".globl .L0021F72C\n"
    ".globl .L0021F9D8\n"
);
#endif
