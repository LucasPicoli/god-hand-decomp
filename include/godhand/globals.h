/* include/godhand/globals.h - game globals whose data is still split asm.
 *
 * Each of these is read by C units but has no owning C unit yet: its bytes
 * still come from the split .data/.rodata/.bss asm. Declare every such global
 * once, here, in address order; when a unit starts owning the data, move the
 * declaration to that unit's header. Types are what the existing users
 * read; a plain char array means only the address is used so far.
 */
#ifndef GODHAND_GLOBALS_H
#define GODHAND_GLOBALS_H

/* .text */
extern char D_003BB168[]; /* nilRep */

/* .data */
extern char D_003BBF80[];
extern char D_003BBFA8[];
extern char D_003BBFD0[];
extern char D_003BBFF8[];
extern char D_003BC020[];
extern char D_003BC0C0[];
extern char D_003BC160[];
extern char D_003BC200[];
extern char D_003BC218[];
extern char D_003BC230[];
extern char D_003BC248[];
extern char D_003BC260[];
extern char D_003BC2C0[];
extern char D_003BC320[];
extern char D_003BC380[];
extern char D_003BC3A8[];
extern char D_003BC3D0[];
extern char D_003BC3F8[];
extern char D_003BC420[];
extern char D_003BC448[];
extern char D_003BC4D0[];
extern char D_003BC558[];
extern char D_003BC5E0[];
extern char D_003BC5F8[];
extern char D_003BC610[];
extern char D_003BC628[];
extern char D_003BC640[];
extern char D_003BC690[];
extern char D_003BC6E0[];
extern float D_003BC730; /* hover offset in the player's frame: x */
extern float D_003BC734; /*                                     y */
extern float D_003BC738; /*                                     z */
extern float D_003BC73C; /* bob amplitude */
extern float D_003BC740; /* bob phase */
extern float D_003BC744; /* bob phase step per frame */
extern char D_003BC770[];
extern char D_003BC7B0[];
extern char D_003BC7B8[];
extern float D_003BC7C0;
extern int D_003BC7D0[]; /* combo table, 0x14 bytes per combo, first word used */
extern char D_003BD0F0[];
extern float D_003BD478;
extern float D_003BD480;
extern float D_003BD488;
extern float D_003BD48C;
extern float D_003BD4A0;
extern unsigned char D_003BD6E0; /* swing direction of element 10: 1 swings up, 0 swings down */
extern char D_003BD6F8[];
extern char D_003BD718[];
extern unsigned char D_003BD758[];
extern float D_003BD860[];
extern float D_003BD870[];
extern float D_003BD890[];
extern char D_003BD8C0[];
extern int D_003BD8D0;
extern float D_003BD9A8[];
extern float D_003BD9D0;
extern float D_003BD9D4;
extern char D_003BDD08[];
extern char D_003BDE50[];
extern float D_003BDE70;
extern float D_003BDE74;
extern float D_003BDE78;
extern float D_003BDE7C;
extern float D_003BDE80;
extern float D_003BDE84;
extern char D_003BDE98[];
extern char D_003BE0B0[];
extern char D_003BE0D8[];
extern char D_003BE168[];
extern char D_003BE528[];
extern char D_003BE548[];
extern char D_003BF0A8[];
extern int*D_003BF0C0[];
extern int D_003BF0D0[];
extern int D_003BF160[]; /* levelPoint thresholds, one per game level */
extern unsigned short D_003BF178[];
extern float D_003BF198[];
extern char D_003BF958[];
extern char D_003BF970[];
extern char D_003BF988[];
extern char D_003BF9A0[];
extern char D_003BF9B8[];
extern char D_003BFA10[];
extern char D_003BFA68[];
extern char D_003BFAD8[];
extern char D_003BFB18[];
extern char D_003BFB48[];
extern char D_003BFB60[];
extern char D_003BFB78[];
extern char D_003BFB90[];
extern char D_003BFBA8[];
extern char D_003BFBF8[];
extern char D_003BFC48[];
extern char D_003BFC98[];
extern char D_003BFCB0[];
extern char D_003BFCC8[];
extern char D_003BFCE0[];
extern char D_003BFCF8[];
extern char D_003BFD50[];
extern char D_003BFDA8[];
extern char D_003BFE18[];
extern char D_003BFE88[];
extern char D_003BFEB0[];
extern char D_003BFF58[];
extern char D_003BFFD0[];
extern char D_003BFFE8[];
extern char D_003C0000[];
extern char D_003C0018[];
extern char D_003C0030[];
extern char D_003C0088[];
extern char D_003C00E0[];
extern char D_003C0138[];
extern char D_003C0160[];
extern char D_003C0188[];
extern char D_003C01B0[];
extern char D_003C01D8[];
extern char D_003C0200[];
extern char D_003C02A0[];
extern char D_003C0340[];
extern char D_003C03F8[];
extern char D_003C0480[];
extern int D_003C0490[];
extern int D_003C04A8[];
extern int D_003C04B8[];
extern int D_003C04D0[];
extern int D_003C04E8[];
extern int D_003C0500[];
extern int D_003C0518[];
extern int D_003C0530[];
extern unsigned char D_003C0548[3]; /* flags of the three event stages already done */
extern char D_003C0550[];
extern float D_003C1190; /* quad bottom edge */
extern int D_003C238C;
extern unsigned short D_003C23A8; /* the wait length the last 0x8700 command set */
extern unsigned D_003C254C; /* the frame colour */
extern int D_003C3100[];
extern int D_003C3104;
extern int D_003C310C;
extern int D_003C3118;
extern char D_003C3560[];
extern unsigned D_003C3B60[8]; /* the debug text colours */
extern unsigned char D_003C3BB0;
extern int D_003C3BB4;
extern int D_003C3BB8;
extern int D_003C3BC0;
extern int D_003C3BC8[];
extern char*D_003C3BF8[];
extern char D_003C3C18[];
extern int*D_003C3CC4;
extern int D_003C3CCC;
extern int D_003C3CF4;
extern int D_003C3CF8;
extern int D_003C3D00;
extern int D_003C3D08;
extern unsigned D_003C3D10[2];
extern long D_003C3D38;
extern long D_003C3D40;
extern long D_003C3D48;
extern unsigned D_003C3D50[64];
extern unsigned D_003C3E50[64];
extern char D_003C3F58[];
extern char D_003C3F68[];
extern char D_003C3FB0[];
extern void*D_003C4030[16]; /* _S_free_list */
extern char*D_003C4074; /* _S_start_free */
extern char*D_003C4078; /* _S_end_free */
extern unsigned char D_003C4408[8]; /* __tiv */
extern unsigned char D_003C4410[8]; /* __tix */
extern unsigned char D_003C4418[8]; /* __til */
extern unsigned char D_003C4420[8]; /* __tii */
extern unsigned char D_003C4428[8]; /* __tis */
extern unsigned char D_003C4430[8]; /* __tib */
extern unsigned char D_003C4438[8]; /* __tic */
extern unsigned char D_003C4440[8]; /* __tiw */
extern unsigned char D_003C4448[8]; /* __tir */
extern unsigned char D_003C4450[8]; /* __tid */
extern unsigned char D_003C4458[8]; /* __tif */
extern unsigned char D_003C4460[8]; /* __tiUi */
extern unsigned char D_003C4468[8]; /* __tiUl */
extern unsigned char D_003C4470[8]; /* __tiUx */
extern unsigned char D_003C4478[8]; /* __tiUs */
extern unsigned char D_003C4480[8]; /* __tiUc */
extern unsigned char D_003C4488[8]; /* __tiSc */
extern int D_003C5298;
extern int D_003C529C;
extern int D_003C7400;
extern int D_003C7408;
extern int D_003C7410;
extern int D_003C7414;
extern int D_003C80A4;
extern int D_003C80A8;
extern long long D_003C8100;
extern volatile int D_003C8144;
extern volatile int D_003C81CC;
extern unsigned char D_003CB9D0[];
extern int D_003CF9D8;
extern int D_003CF9E0;
extern void*D_003CF9EC;
extern int D_003D04B0;
extern int D_003D04B4;
extern int D_003D04B8;
extern int D_003D04BC;
extern int D_003D04C0;
extern int D_003D04CC;
extern int D_003D1400; /* word-sized global; setter Obj3290_SetGlobal_D003D1400          */
extern void*D_003D1404;
extern int D_003D1408;
extern volatile int D_003D140C;
extern int D_003D1414;
extern void*D_003D141C;
extern void*D_003D1424;
extern int D_003D1454;
extern int D_003D1460;
extern int D_003D1464;
extern int D_003D1468;
extern volatile int D_003D1470;
extern int D_003D1474;
extern int D_003D1478;
extern int D_003D147C;
extern int D_003D1E68;
extern volatile int D_003D8400;
extern int D_003D8404;
extern int D_003D8408;
extern volatile int D_003D8448;
extern int D_003D844C;
extern int D_003D8450;
extern volatile unsigned D_003D8460;
extern int D_003D846C;
extern volatile int D_003D8478;
extern volatile int D_003D847C;
extern int D_003D8480;
extern int D_003D8484;
extern volatile int D_003D8488; /* volatile: keeps retail's separate address add before the load */
extern volatile int D_003D848C;
extern int D_003D8490;
extern int D_003D84AC;
extern int D_003D84B8;
extern int D_003D84BC;
extern const char* volatile D_003D90D0; /* "DVCI/PS2EE Ver.2.72 Build:..." banner pointer */
extern int D_003D90D4;
extern int D_003D90D8;
extern int D_003D90DC;
extern int D_003D90E0;
extern void*D_003D90E8[]; /* DVCI function table */
extern char D_003D9C90[];
extern unsigned char D_003D9DD0[];
extern int D_003D9DD4;
extern int D_003D9DD8;
extern char D_003D9DE0[]; /* dvg_ci_root_dir */
extern char D_003D9EE8[];
extern volatile int D_003D9F68;
extern int D_003D9F6C;
extern int D_003D9F70;
extern int D_003D9F74;
extern int D_003D9F78;
extern int D_003DA390;
extern int D_003DA4D0;
extern int D_003DA4D4;
extern int D_003DA5F0;
extern const char* volatile D_003DECF8; /* "MFCI/PS2EE Ver.1.15 Build:..." banner pointer */
extern int D_003DECFC;
extern int D_003DED00;
extern void*D_003DED08[]; /* MFCI function table */
extern int D_003E0724;
extern int D_003E0730;
extern int D_003E0734;
extern int D_003E0738;
extern int D_003E073C;
extern int D_003E0740;
extern int D_003E0748[2];
extern int D_003E0750;
extern int D_003E0754;
extern int D_003E075C;
extern unsigned short D_003E0764;
extern unsigned short D_003E0766;
extern char D_003E0A68[];
extern int D_003E31A8;
extern int D_003E3A80;
extern volatile int D_003E3A88;
extern volatile int D_003E3A90;
extern int D_003E3A98[];
extern int D_003E3AC8;
extern int D_003E3F80[];
extern int D_003E3FB0;
extern int D_003E7FB8[];
extern int D_003E7FE8;
extern int D_003E8C08[];
extern volatile int D_003E8DC8;
extern int D_003E8DCC;
extern int D_003E8DD4;
extern int D_003E8DD8;
extern int D_003E8DDC;
extern int D_003E8DE0;
extern int D_003E906C;
extern char D_003E9070[];
extern int D_003E9944;
extern volatile int D_003E9948; /* lock nesting depth */
extern volatile int D_003E994C; /* lock owner type */
extern int D_003E9950[6];
extern char D_003E9990[];
extern void*D_003E9D18;
extern void*D_003E9D1C;
extern void*D_003E9D20;
extern int D_003E9D3C;
extern void*D_003E9D4C;
extern void*D_003E9D50;
extern int D_003E9D5C;
extern int D_003EADA8;
extern volatile int D_003EADB0;
extern void*D_003EADBC;
extern int D_003EAEC0;
extern int D_003EB708;
extern int D_003EB830;
extern int D_003EB834;
extern int D_003EB838;
extern int D_003EB83C;
extern int D_003EB840;
extern int D_003EB844;
extern int D_003EB848;
extern int D_003EB850; /* boolean flag, Obj33F8_SetFlag_D003EB850_FB68 sets = 1          */
extern int D_003EC454;
extern int D_003EC458;
extern int D_003EC660;
extern int D_003EC668;
extern int D_003EC7D0;
extern int D_003EC7D4;
extern int D_003EC7D8;
extern int D_003EC7DC;
extern unsigned char D_003EC7E0[];
extern int D_003EE078;
extern int D_003EE080;
extern int D_003EE084; /* Scratchpad copy mode: zero uses DMA, nonzero uses the CPU. */
extern int D_003EE098;
extern volatile int D_003EE09C;
extern int D_003EE0A0;
extern int D_003EE0A4;
extern int D_003EE25C;
extern int D_003EE278;
extern int D_003EE2C0;
extern int D_003EE2E8;
extern int D_003EE2EC;
extern int D_003EE2F4;
extern int D_003EE304;
extern int D_003EE314;
extern int D_003EE318;
extern int D_003EE31C;
extern int D_003EE320;
extern int D_003EE328;
extern int D_003EE32C;
extern int D_003EE330;
extern int D_003EE334;
extern int D_003EE804;
extern int D_003EEA6C;
extern volatile int D_003EEA78;
extern int D_003EEA7C;
extern unsigned D_003EEA80;
extern char D_003EEA90[];
extern char D_003EEA98[];
extern char D_003F0298[];
extern unsigned char D_003F1C48[];
extern int D_003F1FF0;
extern unsigned short D_003F215E;
extern int D_003F2160;
extern signed char D_003F21C0[];
extern signed char D_003F21D0[];
extern int D_003F2610[];
extern signed char D_003F2620[];
extern char*D_003F2858[];
extern char*D_003F2870[];
extern void*D_003F2878[];
extern char*D_003F2888[];
extern const char*D_003F28A0[];
extern const char*D_003F28B0[];
extern void*D_003F28C0[];
extern int D_003F28C8[];
extern char D_003F28D0[];
extern const int D_003F5160[];
extern unsigned char D_003F8560[];
extern int D_003F8580[];
extern volatile unsigned*D_003F8590[10];
extern int D_003F85C8;
extern int D_003F85CC;
extern int D_003F8658; /* the pending ncmd */
extern int D_003F865C; /* ncmd_sema_keep_cmd */
extern int D_003F8664; /* the interrupt-lock flag */
extern volatile int D_003F8678; /* _sceCd_ee_read_mode */
extern int D_003F867C; /* the "ncmd rpc not bound" flag */
extern int D_003F8680;
extern int D_003F8688; /* the power-off-callback-installed flag */
extern int D_003F868C; /* _sf_bind */
extern int D_003F8690; /* "scmd rpc not bound" flag */
extern int D_003F8694; /* the "ncmd rpc not bound" flag */
extern volatile int D_003F86A0; /* sceCdCbfunc_num */
extern volatile int D_003F86A4; /* the last callback reason */
extern int D_003F86C0;
extern char D_003F9740[]; /* _sceCd_rd_intr_data */
extern int D_003F9800; /* _sceCd_Read_cur_pos */
extern int D_003F9840[]; /* _sceCd_scmdrdata */
extern int D_003F9C80[]; /* _sceCd_scmdsdata */
extern int D_003FA0C0[]; /* receive buffer */
extern int D_003FA1E8; /* rpc function number */
extern int D_003FA1EC; /* send size */
extern int D_003FA1F0; /* receive size */
extern unsigned D_003FA1F8[];
extern unsigned char D_003FA280[]; /* _defIQM  */
extern unsigned char D_003FA2C0[]; /* _defNIQM */
extern char D_003FA308[]; /* +0x10 = _sce_sdr_transIntr0Hdr */
extern void*D_003FA31C; /* _sce_sdr_transIntr1Hdr */
extern void*D_003FA320; /* _sce_sdr_spu2IntrHdr   */
extern void*D_003FA324; /* _sce_sdr_transIntr0Arg */
extern void*D_003FA328; /* _sce_sdr_transIntr1Arg */
extern void*D_003FA32C; /* _sce_sdr_spu2IntrArg   */
extern void*D_003FA330; /* _sce_sdr_transIntr0Gp  */
extern void*D_003FA334; /* _sce_sdr_transIntr1Gp  */
extern void*D_003FA338; /* _sce_sdr_spu2IntrGp    */
extern int D_003FA990; /* owner thread id */
extern int D_003FA994; /* recursion count */
extern char D_003FA998[];
extern int D_003FA9C0; /* bytes held in the buffer     */
extern char*D_003FA9C4; /* the next free byte           */
extern int D_003FA9C8; /* bytes held in the buffer     */
extern char*D_003FA9CC; /* the next free byte           */
extern char*D_003FADE8; /* __malloc_sbrk_base */
extern char D_003FAE30[];
extern char*D_003FAE44;
extern int D_003FAE48;
extern int D_003FAE4C;
extern int D_003FAE50;
extern int D_003FAEDC;
extern int D_003FAEE4;
extern int D_003FAEE8;
extern int D_003FAEEC;
extern char*D_003FAEF0;
extern int D_003FAEF4;
extern int D_003FAEF8;
extern char*D_003FAEFC;
extern void*D_003FAF00;
extern int D_003FAF08[4];
extern int D_003FAF18; /* semaphore id    */
extern int D_003FAF1C;
extern char D_003FAF20[];
extern int D_003FB6C8[];
extern int D_003FB6E8;
extern int D_003FBE28;
extern int D_003FBE50[];
extern int D_003FBEA8;
extern int D_003FBEBC;
extern int D_003FBEC0;
extern int D_003FC238;
extern int D_003FC240[];
extern int D_003FC50C;
extern int D_003FC7A8;
extern int D_003FC7AC;
extern int D_003FC7B0;
extern void*D_003FC9B4;

/* .sndata */
extern int D_0040A420;

/* .rodata */
extern int D_0041B590;
extern int D_0041B598;
extern int D_0041B638;
extern char D_0041B6A0[];
extern int D_0041B710;
extern char D_0041B730[];
extern char D_0041B7D0[];
extern int D_0041B800;
extern int D_0041C208;
extern int D_0041D2C0;
extern char D_0041D418[];
extern char D_0041D420[];
extern int D_0041D558;
extern int D_0041D580;
extern int D_0041D5D0;
extern int D_0041D5E8;
extern int D_0041D600;
extern int D_0041D618;
extern int D_0041D790;
extern int D_0041D7B8;
extern int D_0041D830;
extern int D_0041D848;
extern int D_0041D860;
extern int D_0041D880;
extern int D_0041D8B8;
extern int D_0041D8D8;
extern int D_0041D920;
extern int D_0041D930;
extern int D_0041D950;
extern char D_0041DBA0[]; /* the follow routine table, one pointer to member per mode */
extern int D_0041DBB0;
extern int D_0041DBD8;
extern int D_0041DC58;
extern int D_0041DCB8;
extern int D_0041DD00;
extern char D_0041DD20[];
extern int D_0041DE80;
extern int D_0041DEC8;
extern int D_0041DF10;
extern int D_0041DF98;
extern int D_0041DFE8;
extern char D_0041E030[];
extern int D_0041E070;
extern char D_0041E090[];
extern int D_0041E0D8;
extern int D_0041E128;
extern int D_0041E170;
extern char D_0041E190[];
extern int D_0041E580;
extern int D_0041E658;
extern int D_0041E6A0;
extern int D_0041E700;
extern int D_0041E830;
extern float D_0041E884;
extern float D_0041E898[];
extern int D_0041E8F8;
extern int D_0041E948;
extern char D_0041E970[];
extern int D_0041E9F0;
extern int D_0041EA80;
extern int D_0041EAD8;
extern int D_0041EB60;
extern char D_0041EB80[];
extern int D_0041EC58;
extern int D_0041ECB8;
extern char D_0041ECC0[];
extern char D_0041ECD8[];
extern char D_0041ED08[];
extern char D_0041ED28[];
extern char D_0041ED48[];
extern int D_0041EE48[];
extern int D_0041EE70[]; /* GS pixel format of each TIM2 image type, from 1 (second table) */
extern int D_0041EE88[]; /* GS pixel format of each TIM2 image type, from 1 */
extern char D_0041F190[];
extern int D_0041F1D0;
extern char D_0041F1F0[];
extern char D_0041F200[];
extern int D_0041F240;
extern char D_0041F378[];
extern char D_0041F388[];
extern int D_0041F3C8;
extern int D_0041F430;
extern char D_0041F5E0[];
extern int D_0041F620;
extern char D_0041F6C8[];
extern int D_0041F708;
extern char D_0041FA90[];
extern char D_0041FB20[];
extern int D_0041FB60;
extern char D_0041FBA0[];
extern char D_0041FBE8[];
extern int D_0041FC28;
extern char D_0041FC50[];
extern char D_0041FC60[];
extern int D_0041FCA0;
extern char D_0041FDF8[];
extern int D_0041FE38;
extern float D_0041FE60[];
extern float D_0041FE78[];
extern char D_0041FF30[];
extern int D_0041FF70;
extern int D_00420070;
extern int D_00420140;
extern int D_00420158;
extern int D_00420228;
extern int D_00420240;
extern unsigned char D_00420310[];
extern unsigned char D_004203F8[];
extern int D_00420410;
extern int D_004204E0;
extern int D_004204F8;
extern unsigned char D_004205C8[];
extern unsigned char D_004205E0[];
extern int D_00420698;
extern int D_004206B0;
extern int D_00420768;
extern int D_00420780;
extern int D_00420838;
extern int D_00420850;
extern int D_00420908;
extern int D_004209D0;
extern unsigned char D_004209E8[];
extern char D_004209F8[];
extern char D_00420A88[];
extern int D_00420D50;
extern int D_00420E18;
extern char D_00420E90[];
extern int D_00420EF0;
extern int D_00420FA0;
extern unsigned char D_00420FA8[];
extern int D_00421098;
extern int D_00421188;
extern char D_004211A0[];
extern int D_00421288;
extern unsigned char D_00421290[];
extern char D_004212B0[];
extern int D_00421398;
extern unsigned char D_004213A0[];
extern int D_00421490;
extern int D_00421578;
extern int D_00421640;
extern int D_00421728;
extern int D_00421810;
extern int D_00421900;
extern int D_004219F0;
extern char D_00421A08[];
extern int D_00421AB8;
extern unsigned char D_00421AD0[];
extern int D_00421BB8;
extern int D_00421C68;
extern int D_00421D30;
extern int D_00421E20;
extern int D_00421EE8;
extern int D_00421FD0;
extern int D_00422098;
extern int D_00422160;
extern int D_00422228;
extern int D_00422240;
extern int D_004222F0;
extern int D_004223B8;
extern int D_00422480;
extern int D_00422548;
extern int D_00422610;
extern char D_004226A8[];
extern int D_00422758;
extern int D_00422820;
extern int D_00422910;
extern int D_004229F8;
extern unsigned char D_00422A10[];
extern char D_00422A20[];
extern char D_00422A58[];
extern int D_00422A80;
extern int D_00422B30;
extern int D_00422C00;
extern int D_00422CE8;
extern int D_00422F68;
extern int D_00423040;
extern int D_00423130;
extern int D_00423218;
extern int D_00423300;
extern int D_004233E8;
extern int D_004234D0;
extern int D_004235B8;
extern int D_004236B8;
extern unsigned char D_004236C0[];
extern int D_004237B0;
extern int D_004238A0;
extern int D_00423990;
extern int D_00423A80;
extern int D_00423B70;
extern int D_00423C58;
extern int D_00423D28;
extern int D_00423DF0;
extern int D_00423F00;
extern char D_00423F20[];
extern int D_00424008;
extern unsigned char D_00424010[];
extern int D_00424040;
extern int D_00424110;
extern char D_004241D8[];
extern char D_004241F0[];
extern char D_004242A0[];
extern int D_00424328;
extern char D_004243D8[];
extern char D_004243F0[];
extern int D_004244C0;
extern int D_004244D8;
extern int D_004245A8;
extern int D_004245C0;
extern char D_00424690[];
extern int D_004246A8;
extern int D_00424778[];
extern int D_00424790[];
extern int D_00424860;
extern int D_00424878;
extern int D_00424948;
extern int D_00424960;
extern int D_00424A30;
extern int D_00424A48;
extern int D_00424B18;
extern int D_00424C18;
extern int D_00424C30;
extern int D_00424D00;
extern int D_00424D18;
extern int D_00424DC8;
extern char D_00424DE0[];
extern int D_00424E18;
extern int D_00424EC8;
extern unsigned char D_00424ED0[];
extern char D_00424EF0[];
extern int D_00424F28;
extern int D_00424FD8;
extern unsigned char D_00424FE0[];
extern int D_00425000;
extern int D_004250B8;
extern int D_004250F0;
extern int D_004251A8;
extern int D_004251C0;
extern int D_00425278;
extern int D_00425360;
extern int D_00425448;
extern int D_00425530;
extern int D_00425618;
extern int D_00425700;
extern int D_004257E8;
extern char D_00425800[];
extern int D_004258D0;
extern unsigned char D_004258D8[];
extern int D_004259C0;
extern int D_00425AA8;
extern int D_00425B78;
extern int D_00425C40;
extern char D_00425D30[];
extern char D_00425DF8[];
extern char D_00425E10[];
extern int D_00425EC8;
extern int D_00425EE0;
extern int D_00425F98;
extern int D_00425FB0;
extern int D_00426080;
extern int D_00426098;
extern int D_00426168;
extern int D_00426180;
extern int D_00426250;
extern int D_00426268;
extern int D_00426338;
extern int D_00426350;
extern unsigned char D_00426420[];
extern int D_00426438;
extern int D_00426508;
extern int D_00426520;
extern int D_004265F0;
extern char D_004266D8[];
extern void*D_004266F0;
extern int D_004267C0;
extern int D_004267F8;
extern int D_004268B0;
extern int D_004268C8;
extern char D_00426998[];
extern int D_004269B0;
extern char D_00426A80[];
extern int D_00426A98;
extern int D_00426B68;
extern int D_00426B80;
extern int D_00426C50;
extern int D_00426C68;
extern int D_00426D38;
extern int D_00426E20;
extern char D_00426E40[];
extern int D_00426F28;
extern unsigned char D_00426F30[];
extern char D_00426F50[];
extern int D_00427038;
extern int D_00427130;
extern int D_00427218;
extern char D_00427230[];
extern int D_004272E0;
extern char D_004272F8[]; /* the class's method table */
extern int D_004273A8;
extern int D_004274B0;
extern int D_00427580;
extern char D_004275A0[]; /* the routine table, one pointer to member per phase */
extern int D_00427678;
extern int D_00427740;
extern int D_00427868;
extern int D_00427930;
extern unsigned char D_00427948[];
extern int D_00427A58;
extern int D_00427B08;
extern int D_00427BD0;
extern char D_00427C50[];
extern int D_00427DA0;
extern int D_00427F10;
extern int D_00427FF8;
extern float D_00428000[]; /* per game level scale, levels past 5 use entry 5 */
extern int D_00428140;
extern int D_00428210;
extern int D_004282D8;
extern int D_004282F0;
extern int D_004283A0;
extern int D_004283D8;
extern int D_00428488;
extern int D_00428570;
extern int D_00428638;
extern char D_00428650[];
extern int D_00428700;
extern int D_00428828;
extern int D_00428840;
extern int D_004288F0;
extern int D_004289D8;
extern int D_004289F0;
extern int D_004289F8;
extern int D_00428A00;
extern int D_00428A08;
extern int D_00428A10;
extern int D_00428A18;
extern int D_00428A20;
extern int D_00428AD0;
extern char D_00428AF0[];
extern int D_00428B58;
extern int D_00428C08;
extern int D_00428CD0;
extern int D_00429178;
extern int D_00429240;
extern char D_00429290[]; /* six unit vectors of the door box */
extern int D_004293A0;
extern char D_004293C0[]; /* six unit vectors of the door box */
extern int D_004294D0;
extern int D_004294F0;
extern int D_004295A0;
extern int D_004296D0;
extern int D_004297A0;
extern int D_00429890;
extern int D_004298B0;
extern int D_00429C38;
extern int D_00429D50;
extern int D_00429DD8;
extern unsigned char D_00429E90[];
extern char D_00429EC8[];
extern int D_00429F78;
extern int D_0042AB48;
extern char D_0042B190[];
extern int D_0042B2F0[];
extern char D_0042B6B8[];
extern char D_0042B6E8[];
extern char D_0042BAC0[];
extern char D_0042BAE0[];
extern char D_0042BB20[];
extern signed char D_0042BBC0[];
extern signed char D_0042BBC8[];
extern signed char D_0042BBD0[];
extern signed char D_0042BBD8[];
extern signed char D_0042BBE0[];
extern signed char D_0042BBE8[];
extern signed char D_0042BBF8[];
extern signed char D_0042BC08[];
extern signed char D_0042BC18[];
extern signed char D_0042BC28[];
extern signed char D_0042BC38[];
extern signed char D_0042BC48[];
extern signed char D_0042BC58[];
extern signed char D_0042BC68[];
extern signed char D_0042BC78[];
extern int D_0042BD40[5];
extern int D_0042BD58[5];
extern int D_0042BDC0[5]; /* local Y per slot */
extern char D_0042BE30[];
extern char D_0042BE90[];
extern char D_0042BF40[];
extern char D_0042C000[];
extern char D_0042C0E0[];
extern char D_0042C2B0[];
extern char D_0042C2D8[];
extern int D_0042C300;
extern int D_0042C308;
extern int D_0042C348;
extern unsigned char D_0042C498[];
extern unsigned char D_0042C4B8[];
extern unsigned char D_0042C4D8[];
extern char D_0042C508[];
extern char D_0042C518[];
extern char D_0042C750[];
extern char D_0042C768[];
extern char D_0042C780;
extern char D_0042C7A0[];
extern char D_0042C7B8[];
extern char D_0042C7D0[];
extern unsigned char D_0042C7F0[];
extern char D_0042CA40[];
extern char D_0042CA48[];
extern char D_0042CA58[];
extern char D_0042CA60[];
extern char D_0042CA68[];
extern char D_0042CA78[];
extern char D_0042CA88[];
extern char D_0042CA90[];
extern char D_0042CA98[];
extern char D_0042CAA0[];
extern char D_0042CAA8[];
extern char D_0042CAB8[];
extern char D_0042CAC8[];
extern int D_0042CAD0;
extern char D_0042FD50[];
extern char D_0042FD58[];
extern char D_004365A8[];
extern char D_004365B0[];
extern unsigned char D_004452D8[];
extern char D_00446600[];
extern char D_00446610[];
extern char D_00446620[];
extern char D_00446628[];
extern char D_00446638[];
extern char D_00446648[];
extern char D_00446650[];
extern char D_00446658[];
extern char D_00446660[];
extern char D_00446668[];
extern char D_00446670[];
extern char D_00446678[];
extern char D_00446680[];
extern char D_004479A0[];
extern int D_00447AB8;
extern char D_00447AD0[];
extern int D_00447B70;
extern const char D_00447B88[]; /* type name */
extern char D_00447B90[];
extern char D_00447B98[];
extern int D_00447C90;
extern const char D_00447CB0[]; /* type name */
extern char D_00447CB8[];
extern char D_00447CC0[];
extern char D_00447D38[];
extern char D_00447D40[];
extern int D_00447E38;
extern int D_00447E50;
extern char D_00447E58[];
extern char D_00447E60[];
extern int D_00447F58;
extern int D_00448010;
extern char D_00448028[];
extern int D_004480C8;
extern int D_004480E0;
extern char D_00448180[];
extern char D_00448188[];
extern int D_00448298;
extern const char D_004482B0[]; /* "cEm66" */
extern char D_004482C8[];
extern char D_004482D0[];
extern int D_00448498;
extern int D_004484B0;
extern char D_00448588[];
extern char D_00448590[];
extern int D_00448688;
extern const char D_004486A0[]; /* type name */
extern char D_00448778[];
extern char D_00448780[];
extern int D_00448878;
extern char D_00448890[];
extern int D_00448930;
extern char D_00448948[];
extern int D_004489E8;
extern const char D_00448A00[]; /* type name */
extern char D_00448C90[];
extern char D_00448C98[];
extern int D_00448D90;
extern const char D_00448DB0[]; /* type name */
extern char D_00448DB8[];
extern char D_00448DC0[];
extern char D_00448DC8[];
extern char D_00448DD0[];
extern char D_00448DD8[];
extern char D_00448DE0[];
extern char D_00448DE8[];
extern char D_00448DF0[];
extern char D_00448E10[];
extern char D_00448E18[];
extern int D_00448F10;
extern const char D_00448F30[]; /* "cEma6" */
extern int D_0044A4F8;
extern int D_0044A510;
extern char D_0044A518[];
extern char D_0044A520[];
extern int D_0044A618;
extern int D_0044A630;
extern int D_0044A660;
extern int D_0044A750;
extern int D_0044A878;
extern char D_0044A890[];
extern char D_0044A960[];
extern char D_0044A9B0[];
extern char D_0044A9B8[];
extern char D_0044A9D0[];
extern char D_0044A9D8[];
extern char D_0044AA10[];
extern char D_0044AA18[];
extern char D_0044AA20[];
extern char D_0044AA28[];
extern char D_0044AA30[];
extern char D_0044AA38[];
extern char D_0044AA40[];
extern char D_0044AA48[];
extern char D_0044AB60[];
extern char D_0044AB68[];
extern char D_0044AB70[];
extern char D_0044AB78[];
extern char D_0044AB80[];
extern char D_0044AB88[];
extern char D_0044AB90[];
extern char D_0044AB98[];
extern char D_0044ABB0[];
extern char D_0044ABB8[];
extern signed char s_Handcart_0044abe0[];
extern char D_0044AC00[]; /* BGM names, one per stage count */
extern char D_0044AC08[];
extern char D_0044AC10[];
extern signed char D_0044AC28[];
extern signed char D_0044AC30[];
extern char D_0044AC48[];
extern char D_0044AC50[];
extern char D_0044AC58[];
extern char D_0044AC60[];
extern char D_0044AC68[];
extern char D_0044ACE0[];
extern char D_0044ACE8[];
extern char D_0044ACF0[];
extern char D_0044AD58[];
extern char D_0044AD60[];
extern int D_0044ADD8[];
extern char D_0044AE28[];
extern int D_0044AEC8;
extern char D_0044AF10[];
extern char D_0044AF20[];
extern char D_0044AF28[];
extern char D_0044AF30[];
extern unsigned char D_0044AF78;
extern char D_0044AF80[];
extern char D_0044AF90[];
extern char D_0044AFA8[];
extern char D_0044AFC0[];
extern char D_0044AFD8[];
extern char D_0044AFF0[];
extern char D_0044B008[];
extern char D_0044B060[];
extern char D_0044B080[]; /* 10 byte string constant */
extern char D_0044B090[];
extern char D_0044B0B0[];
extern char D_0044B0E8[];
extern char D_0044B100[];
extern char D_0044B1E0[]; /* name of the sound data to look up */
extern char D_0044B288[];
extern char D_0044B330[];
extern int D_0044B360[];
extern int D_0044B378[];
extern int D_0044B410[];
extern char D_0044B430[];
extern char D_0044B438[];
extern char D_0044B440[];
extern char D_0044B448[];
extern char D_0044B458[];
extern char D_0044B468[];
extern char D_0044B470[];
extern char D_0044B478[];
extern char D_0044B480[];
extern char D_0044B488[];
extern char D_0044B490[];
extern char D_0044B498[];
extern char D_0044B4A8[];
extern char D_0044B4B0[];
extern char D_0044B4B8[];
extern char D_0044B4D8[];
extern char D_0044B4E0[];
extern char D_0044B4E8[];
extern int D_0044B598;
extern int D_0044B840;
extern int D_0044B8B0;
extern int D_0044BA68;
extern char D_0044BAF8;
extern char D_0044BB20[];
extern char D_0044BCA0[];
extern char D_0044BD60[];
extern int D_0044BDC0;
extern int D_0044BDD8;
extern int D_0044BDF8;
extern int D_0044BE18;
extern int D_0044BE30;
extern int D_0044BE48;
extern int D_0044BE60;
extern int D_0044BE80;
extern int D_0044BEB8;
extern int D_0044BF60;
extern char D_0044C048[];
extern char D_0044C068[];
extern char D_0044C088[];
extern char D_0044C0B8[]; /* file path */
extern char D_0044C0E0[];
extern char D_0044C118[];
extern char D_0044C150[];
extern char D_0044C170[];
extern char D_0044C210[];
extern char D_0044C218[];
extern char D_0044C220[];
extern char D_0044C228[];
extern int D_0044C238;
extern char D_0044C2B8[];
extern char D_0044C2C0[];
extern char D_0044CD20[];
extern char D_0044CD40[];
extern char D_0044CD60[];
extern char D_0044CD80[];
extern char D_0044CDA0[];
extern char D_0044CDA8[];
extern char D_0044CDC8[];
extern char D_0044CDE0[];
extern char D_0044CE00[];
extern char D_0044CE10[];
extern char D_0044CE20[];
extern char D_0044CE28[];
extern char D_0044CE30[];
extern int D_0044CE48[];
extern int D_0044CF00;
extern char D_0044CF68[];
extern char D_0044CF78[];
extern char D_0044CFB8[];
extern char D_0044D010[];
extern char D_0044D018[];
extern unsigned char D_0044D070;
extern char D_0044D078[];
extern char D_0044D088[];
extern char D_0044D0A0[];
extern char D_0044D0B0[];
extern char D_0044D0C0[];
extern char D_0044D0D8[];
extern char D_0044D100[];
extern char D_0044D188[];
extern char D_0044D1A8[]; /* the derived class's vtable */
extern char D_0044D1E8[]; /* the class's method table */
extern int D_0044D200;
extern int D_0044D210;
extern int D_0044D220;
extern char D_0044D260[];
extern char D_0044D268[];
extern int D_0044D3A0;
extern unsigned char D_0044D3B0[];
extern unsigned char D_0044D3C0[];
extern int D_0044D3D8;
extern char D_0044D420[];
extern char D_0044E030[];
extern char D_0044E040[];
extern int D_0044E120;
extern int D_0044E2C8;
extern char D_0044E300[];
extern int D_0044E398;
extern char D_0044E3B0[];
extern char D_0044E3D8[];
extern char D_0044E3F8[];
extern char D_0044E418[];
extern int D_0044E5C8;
extern int D_0044E640;
extern int D_0044E6D0;
extern int D_0044E768;
extern int D_0044E800;
extern int D_0044E808;
extern int D_0044E820;
extern int D_0044E8B0;
extern char D_0044E8C8[];
extern char D_0044E960[];
extern int D_0044E9F8;
extern int D_0044EA08;
extern int D_0044EA10;
extern int D_0044EAA0;
extern int D_0044EAB8;
extern int D_0044EB48;
extern char D_0044EB50[];
extern int D_0044EB70;
extern int D_0044EC00;
extern int D_0044EC08;
extern int D_0044EC28;
extern int D_0044EC68;
extern int D_0044ECF8;
extern char D_0044ED00[]; /* "esp20: model[%d] data not found." */
extern char D_0044ED28[]; /* "esp20: model create failed." */
extern char D_0044ED48[]; /* "esp20: model initial failed." */
extern char D_0044ED68[]; /* "esp20: TYPE invalid." */
extern char D_0044ED80[]; /* "esp20: EFF_TEX setup failed." */
extern char D_0044EDA0[]; /* "esp20: model setup failed." */
extern int D_0044EDC0;
extern int D_0044EDE8;
extern int D_0044EEC8;
extern char D_0044EED0[];
extern char D_0044EEE8[];
extern int D_0044EF08;
extern int D_0044EF98;
extern int D_0044EFA0;
extern int D_0044F030;
extern char D_0044F038[];
extern char D_0044F058[];
extern int D_0044F108;
extern int D_0044F258;
extern int D_0044F270;
extern int D_0044F300;
extern int D_0044F398;
extern int D_0044F3A0;
extern int D_0044F430;
extern int D_0044F448;
extern int D_0044F4E0;
extern int D_0044F590;
extern int D_0044F628;
extern int D_0044F630;
extern int D_0044F6C0;
extern int D_0044F770;
extern int D_0044F868;
extern int D_0044F880;
extern int D_0044F910;
extern int D_0044FA38;
extern int D_0044FAD0;
extern int D_0044FB60;
extern int D_0044FBA8;
extern int D_0044FBB8;
extern char D_0044FC10[];
extern int D_0044FC38;
extern int D_0044FC98;
extern char D_0044FD58[];
extern int D_0044FDB8;
extern int D_0044FDC8;
extern int D_0044FDD8;
extern int D_0044FDE8;
extern int D_0044FDF8;
extern int D_0044FE88;
extern char D_0044FEA0[];
extern char D_0044FEA8[];
extern char D_0044FEB8[];
extern char D_0044FEC8[];
extern char D_0044FED8[];
extern char D_0044FEE0[];
extern char D_0044FEF0[];
extern char D_0044FF00[];
extern char D_0044FF10[];
extern char D_0044FF20[];
extern char D_0044FF30[];
extern char D_0044FF40[];
extern char D_0044FF50[];
extern char D_0044FF60[];
extern char D_0044FF70[];
extern char D_0044FF80[];
extern char D_0044FF90[];
extern char D_0044FFA0[];
extern char D_0044FFB0[];
extern char D_0044FFC0[];
extern char D_0044FFD0[];
extern char D_0044FFE0[];
extern char D_0044FFF0[];
extern char D_00450000[];
extern char D_00450010[];
extern char D_00450048[];
extern char D_00450068[];
extern char D_00450070[];
extern char D_00450078[];
extern int D_00450080;
extern int D_00450098;
extern int D_004501D0[];
extern char D_004504D8[];
extern char D_00450518[];
extern char D_00450530[];
extern char D_00450808[];
extern char D_00450840[];
extern char D_00450870[];
extern char D_004508B0[];
extern char D_00450AF8[]; /* "obj     %d" */
extern int D_00450B98;
extern int D_00450C08;
extern int D_00450C18;
extern int D_00450CA8;
extern int D_00450D58;
extern char D_00450D80[];
extern char D_00450D90[];
extern char D_00450DA8[];
extern char D_00450E88[];
extern char D_00450EC0[];
extern char D_00450ED8[];
extern char D_00450EF0[];
extern char D_00450EF8[];
extern char D_00450F00[];
extern char D_00450F08[];
extern char D_00450F38[]; /* "out of memory" */
extern int D_00450FC0;
extern int D_00450FF0;
extern int D_00451008;
extern int D_00451020;
extern int D_00451038;
extern char D_00451048[];
extern char D_00451060[];
extern char D_00451078[];
extern char D_00451090[];
extern char D_004510A0[];
extern int D_004510B0;
extern const char D_004510D0[]; /* "v" */
extern const char D_004510D8[]; /* "x" */
extern const char D_004510E0[]; /* "l" */
extern const char D_004510E8[]; /* "i" */
extern const char D_004510F0[]; /* "s" */
extern const char D_004510F8[]; /* "b" */
extern const char D_00451100[]; /* "c" */
extern const char D_00451108[]; /* "w" */
extern const char D_00451110[]; /* "r" */
extern const char D_00451118[]; /* "d" */
extern const char D_00451120[]; /* "f" */
extern const char D_00451128[]; /* "Ui" */
extern const char D_00451130[]; /* "Ul" */
extern const char D_00451138[]; /* "Ux" */
extern const char D_00451140[]; /* "Us" */
extern const char D_00451148[]; /* "Uc" */
extern const char D_00451150[]; /* "Sc" */
extern char D_00451158[];
extern char D_00451168[];
extern char D_00451178[];
extern char D_00451188[];
extern char D_004511A8[];
extern char D_004511B8[];
extern char D_004511C8[];
extern char D_004511E0[];
extern char D_004511F8[];
extern char D_00451210[];
extern char D_00451228[];
extern char D_00451240[];
extern char D_00451258[];
extern int D_00451270;
extern int D_00451288;
extern char D_004512A0[];
extern int D_004512B0;
extern char D_004512C0[];
extern char D_004512C8[];
extern char D_004513F8[];
extern char D_00451438[];
extern char D_00451468[];
extern char D_00451490[];
extern char D_004514C0[];
extern char D_00451658[];
extern char D_00451718[];
extern char D_00451740[];
extern char D_00451770[];
extern char D_00451798[];
extern int D_00451800;
extern int D_00451828;
extern int D_00451858;
extern int D_00451880;
extern char D_004518B0[];
extern char D_004518D8[];
extern char D_00451928[];
extern const signed char D_004519F0[];
extern char D_00451B10[];
extern char D_00451B20[];
extern char D_00451B30[];
extern char D_00451B48[];
extern char D_00451D78[];
extern int D_00451ED0;
extern int D_00451F00;
extern char D_00452010[];
extern int D_00452038;
extern char D_00452060[];
extern char D_00452088[];
extern char D_004520D8[];
extern char D_00452108[];
extern char D_00452138[];
extern char D_00452198[];
extern char D_004521C8[];
extern char D_004521F8[];
extern const char D_00452228[];
extern char D_00452258[];
extern char D_00452288[];
extern int D_004522B8;
extern char D_004522E8[];
extern char D_00452318[];
extern char D_00452348[];
extern const char D_004523D8[];
extern const char D_00452408[];
extern char D_00452438[];
extern char D_004524D0[];
extern const char D_00452500[];
extern char D_00452560[];
extern char D_00452630[];
extern char D_00452688[];
extern char D_00452748[];
extern char D_00452778[];
extern char D_004527A0[];
extern char D_00452830[];
extern char D_00452860[];
extern char D_00452890[];
extern char D_00452980[];
extern char D_00452990[];
extern char D_004529A0[];
extern char D_004529F8[];
extern char D_00452A20[];
extern char D_00452A48[];
extern char D_00452A78[];
extern char D_00452AA8[];
extern char D_00452B20[];
extern int D_00452B48;
extern char D_00452B98[];
extern char D_00452BC0[];
extern char D_00452BF8[];
extern char D_00452C20[];
extern int D_00452C98;
extern int D_00452D10;
extern char D_00452D78[];
extern char D_00452DB0[];
extern char D_00452DE8[];
extern char D_00452E20[];
extern char D_00452E58[];
extern char D_00452FB0[]; /* "E2003052111 : NULL pointer is passed." */
extern char D_00452FD8[]; /* "E2003052113 : The parameter 'trno' is out of range." */
extern char D_00453078[];
extern const char D_00453128[];
extern const char D_00453150[];
extern const char D_00453178[];
extern char D_004531C8[];
extern char D_004531F0[];
extern const char D_00453218[];
extern const char D_00453238[];
extern const char D_00453280[];
extern const char D_004532A0[];
extern const char D_004532B8[];
extern char D_004532D8[];
extern char D_004532F8[];
extern int D_00453310;
extern int D_00453330;
extern int D_00453348;
extern int D_00453368;
extern int D_00453380;
extern int D_004533A0;
extern const char D_00453D80[];
extern char D_00453E90[];
extern int D_00453EB0;
extern int D_00453ED0;
extern int D_00453F98;
extern char D_00454098[];
extern char D_004540B8[];
extern int D_00454110;
extern char D_00454150[];
extern char D_00454170[];
extern char D_004542F8[];
extern char D_00454328[];
extern char D_00454350[];
extern char D_00454380[];
extern char D_004543A8[];
extern char D_004543D0[];
extern char D_00454400[];
extern char D_00454428[];
extern char D_00454470[];
extern char D_00454490[];
extern char D_004544B8[];
extern char D_004544E0[];
extern char D_004544E8[];
extern char D_004544F0[];
extern char D_004544F8[];
extern char D_00454510[];
extern char D_00454528[];
extern char D_00454540[];
extern char D_00454570[];
extern char D_00454588[];
extern char D_00454598[];
extern char D_004545B0[];
extern char D_004545B8[];
extern char D_004545E0[];
extern char D_00454610[];
extern char D_00454640[];
extern char D_00454668[];
extern char D_00454878[];
extern char D_004548A0[];
extern char D_004548C8[];
extern char D_004548F8[];
extern char D_00454920[];
extern const char D_00454978[];
extern const char D_00454998[];
extern char D_004549C0[];
extern char D_004549D8[];
extern const char D_004549F8[];
extern char D_00454BB8[];
extern char D_00454BE8[];
extern const char D_00454C78[];
extern const char D_00454CA8[];
extern int D_00454D38;
extern char D_00454D68[];
extern const char D_00454F10[]; /* "E0003: Illigal parameter lsc=NULL"  */
extern const char D_00454F40[]; /* "E0010: Illigal parameter min=%d"    */
extern char D_00454FA0[];
extern char D_00455000[];
extern int D_00455040;
extern const char D_00455090[];
extern const char D_004550B8[];
extern const char D_004550E0[];
extern const char D_00455110[];
extern const char D_00455130[];
extern char D_00455150[];
extern char D_00455170[];
extern char D_00455190[];
extern const char D_004551D0[];
extern int D_004551E8;
extern char D_00455290[];
extern char D_004552D0[];
extern char D_00455308[];
extern char D_00455330[];
extern char D_00455398[];
extern char D_004553C8[];
extern char D_004553F8[];
extern char D_00455438[];
extern char D_00455480[];
extern char D_004554B0[];
extern char D_004554E0[];
extern char D_00455518[];
extern char D_00455548[];
extern char D_00455580[];
extern char D_00455668[];
extern char D_00455788[];
extern char D_004557C8[]; /* "PS2RNA_SetBitPerSmpl: not support %d bps\n" */
extern int D_004558F0[];
extern char D_00455900[];
extern int D_00455910;
extern int D_00455940;
extern char D_00455970[];
extern char D_00455980[];
extern int D_00455990;
extern int D_004559A0;
extern int D_004559B0;
extern int D_004559C0;
extern char D_004559D0[];
extern char D_004559E0[];
extern char D_004559F0[];
extern char D_00455A00[];
extern char D_00455A10[];
extern char D_00455A20[];
extern int D_00455A30;
extern int D_00455A40;
extern int D_00455A50[];
extern char D_00455A60[];
extern int D_00455A70;
extern int D_00455AA0;
extern int D_00455AD0;
extern int D_00455AE0;
extern char D_00455AF0[];
extern char D_00455B00[];
extern char D_00455B10[];
extern char D_00455B20[];
extern char D_00455B38[];
extern char D_00455B48[];
extern char D_00455B58[];
extern char D_00455B68[];
extern char D_00455B78[];
extern int D_00455B88;
extern int D_00455B98;
extern int D_00455BA8[];
extern char D_00455BB8[];
extern int D_00455BC8;
extern int D_00455BF8;
extern char D_00455C28[];
extern char D_00455C38[];
extern int D_00455C48;
extern int D_00455C58;
extern char D_00455C68[];
extern char D_00455C78[];
extern char D_00455DC8[];
extern char D_00455DF8[];
extern char D_00455E20[];
extern char D_00455E78[]; /* "...(type org=%d, type now=%d)" */
extern short D_00456080[];
extern unsigned char D_00456888[];
extern unsigned char D_004568A8[];
extern char D_004568D0[];
extern char D_00456918[]; /* "FORM" */
extern char D_00456920[]; /* "AIFF" */
extern char D_00456930[];
extern char D_00456A10[];
extern char D_00456A30[];
extern char D_00456A58[];
extern char D_00456A88[];
extern char D_00456AB0[];
extern char D_00456F90[];
extern char D_00456FB8[];
extern char D_00456FE8[];
extern char D_00457010[];
extern char D_00457040[]; /* "FORM" */
extern char D_00457048[]; /* "AIFF" */
extern char D_00457140[];
extern char D_004571D8[];
extern char D_004573B8[];
extern char D_004573D8[];
extern char D_00457410[];
extern int D_004575C8;
extern int D_004575F8;
extern int D_00457620;
extern int D_00457650;
extern int D_00457678;
extern char D_004576A0[];
extern char D_00457748[];
extern char D_004577D0[];
extern char D_00457830[];
extern char D_00457890[];
extern char D_004578B8[];
extern char D_00457918[];
extern int D_00457B90;
extern int D_00457BA8;
extern int D_00457BC0;
extern int D_00457BD8;
extern int D_00457BE0;
extern char D_00457EC8[];
extern char D_00457EF8[];
extern char D_00457F28[];
extern char D_00458038[];
extern char D_00458068[];
extern char D_00458088[];
extern char D_004580B0[];
extern char D_004580D8[];
extern char D_00458100[];
extern char D_00458108[];
extern char D_00458110[];
extern char D_00458147[];
extern char D_00458168[];
extern char D_00458238[];
extern char D_00458488[];
extern char D_004585D0[];
extern char D_00458600[];
extern char D_00458628[];
extern char D_00458758[];
extern char D_00458848[];
extern char D_004588B0[];
extern char D_004588D8[];
extern char D_00458900[];
extern char D_00458928[];
extern char D_00458B50[];
extern char D_00458C68[];
extern char D_00458E80[];
extern char D_00458EB0[];
extern char D_00458EE0[];
extern char D_00458F10[];
extern char D_00458F48[];
extern char D_00458F78[];
extern char D_00458FA8[];
extern char D_00458FD8[];
extern char D_00459008[];
extern char D_004590A8[];
extern char D_004590D8[];
extern char D_00459110[];
extern char D_00459210[];
extern char D_00459240[];
extern char D_00459270[];
extern char D_00459298[];
extern char D_004592D0[];
extern char D_00459300[];
extern char D_00459330[];
extern char D_00459410[];
extern int D_004598E0;
extern char D_00459990[];
extern char D_00459BF0[]; /* 0x00459BF0 - ASCII string used as base ptr  */
extern char D_00459C28[];
extern char D_00459C48[];
extern char D_00459C70[];
extern char D_00459CA0[];
extern char D_00459ED8[];
extern char D_00459EE0[];
extern char D_00459F20[];
extern char D_00459F60[];
extern unsigned char D_00459FA8[];
extern char D_00459FE0[]; /* "E201194: sfx_InitHn: work size is short." */
extern char D_0045A010[]; /* "E201281: SfxZHn: can't create." */
extern char D_0045A030[]; /* "E202011: SfxAHn: can't create." */
extern char D_0045A078[];
extern char D_0045A080[];
extern char D_0045A088[];
extern char D_0045A090[];
extern char D_0045A0A0[];
extern unsigned char D_0045A1B0[];
extern char D_0045A1E8[];
extern char D_0045A218[];
extern char D_0045A230[];
extern char D_0045A258[];
extern volatile unsigned*D_0045A260[];
extern int D_0045A290;
extern char D_0045A320[]; /* mode table */
extern unsigned char D_0045A370; /* build tag, must read 4 */
extern char D_0045A3C0[];
extern char D_0045A3C8[];
extern int D_0045A3D0[];
extern char D_0045A420[];
extern int D_0045A460;
extern unsigned char D_0045A470;
extern unsigned char D_0045A478[]; /* entry table */
extern unsigned char D_0045A514; /* decoder build tag, must read 4 */
extern char D_0045A578[];
extern int D_0045A580[];
extern int D_0045A590[];
extern int D_0045A5F8;
extern int D_0045A600[];
extern const float D_0045A610[][2];
extern char D_0045B170[];
extern char D_0045B1B8[];
extern char D_0045B1C8[];
extern char D_0045B1E8[];
extern char D_0045B200[];
extern char D_0045B218[];
extern char D_0045B230[];
extern char D_0045B248[];
extern char D_0045B260[];
extern char D_0045B278[];
extern char D_0045B290[];
extern char D_0045B2A0[];
extern char D_0045B2C0[];
extern char D_0045B2C8[];
extern char D_0045B2D8[];
extern char D_0045B2F0[];
extern char D_0045B300[];
extern char D_0045B308[];
extern char D_0045B350[];
extern char D_0045B360[];
extern char D_0045B388[];
extern char D_0045B3A0[];
extern char D_0045B3E8[];
extern char D_0045B400[];
extern char D_0045B418[];
extern char D_0045B448[];
extern char D_0045B460[];
extern char D_0045B478[];
extern char D_0045B4C0[];
extern char D_0045B4F0[];
extern char D_0045B508[];
extern char D_0045B520[];
extern char D_0045B550[];
extern char D_0045B560[];
extern char D_0045B578[];
extern char D_0045B590[];
extern char D_0045B5A8[];
extern char D_0045B5C0[];
extern char D_0045B5D8[];
extern char D_0045B5F0[];
extern char D_0045B608[];
extern char D_0045B620[];
extern char D_0045B638[];
extern char D_0045B650[];
extern char D_0045B668[];
extern char D_0045B680[];
extern char D_0045B698[];
extern char D_0045B6B0[];
extern char D_0045B6C8[];
extern char D_0045B6E0[];
extern char D_0045B6F8[];
extern char D_0045B710[];
extern char D_0045B728[];
extern char D_0045B738[];
extern char D_0045B740[];
extern char D_0045B758[];
extern char D_0045B760[];
extern char D_0045B868[];
extern char D_0045B888[];
extern char D_0045B8A8[];
extern char D_0045B8C0[];
extern char D_0045B8D8[];
extern char D_0045B8F0[];
extern char D_0045B908[];
extern char D_0045B920[];
extern char D_0045B938[];
extern char D_0045B950[];
extern char D_0045B968[];
extern char D_0045B988[];
extern char D_0045B9A8[];
extern char D_0045B9C8[];
extern char D_0045B9E8[];
extern char D_0045BA08[];
extern char D_0045BA28[];
extern char D_0045BA40[];
extern char D_0045BA58[];
extern char D_0045BA70[];
extern char D_0045BA88[];
extern char D_0045BAA0[];
extern char D_0045BAB8[];
extern char D_0045BAD0[];
extern char D_0045BB50[];
extern char D_0045BB68[];
extern char D_0045BB80[];
extern char D_0045BB98[];
extern char D_0045BBB0[];
extern char D_0045BBC8[];
extern char D_0045BBE0[];
extern char D_0045BBF8[];
extern char D_0045BC10[];
extern char D_0045BC28[];
extern char D_0045BC40[];
extern char D_0045BC58[];
extern char D_0045BC70[];
extern char D_0045BC88[];
extern char D_0045BCA0[];
extern char D_0045BCA8[];
extern char D_0045BD90[];
extern char D_0045BDA0[];
extern char D_0045BDA8[];
extern char D_0045BDB8[];
extern char D_0045BDC0[];
extern char D_0045BDC8[];
extern char D_0045BDD0[];
extern char D_0045BDD8[];
extern char D_0045BDE0[];
extern char D_0045BDE8[];
extern char D_0045C110[];
extern char D_0045C118[];
extern char D_0045C120[];
extern char D_0045C130[];
extern char D_0045C1B8[];
extern char D_0045C1C8[]; /* "%s" */
extern const char D_0045C210[];
extern const char D_0045C220[];
extern const char D_0045C250[];
extern const char D_0045C258[];
extern const char D_0045C270[];
extern char D_0045C2A8[];
extern char D_0045C328[];
extern char D_0045C368[]; /* "-- ADX FILE SELECT --" */
extern char D_0045C380[]; /* "DIR : %s" */
extern char D_0045C390[]; /* "[D]" */
extern char D_0045C398[]; /* "[F]" */
extern char D_0045C3A0[]; /* "ADX[%d] : %s" */
extern char D_0045C3B0[]; /* "AIX : %s" */
extern char D_0045C3C0[]; /* "AFS : %s" */
extern char D_0045C3D0[]; /* "ACX : %s" */
extern char D_0045C3E0;
extern const char D_0045C3F8[]; /* "bastring.cc" */
extern const char D_0045C430[];
extern const char D_0045C440[];
extern char D_0045C470[];
extern char D_0045C4A0[];
extern const char D_0045C4C0[];
extern char D_0045C4F8[];
extern char D_0045C510[];
extern char D_0045C520[];
extern char D_0045C538[];
extern char D_0045C548[];
extern char D_0045C558[];
extern char D_0045C560[];
extern char D_0045C568[];
extern char D_0045C588[];
extern char D_0045C5A8[];
extern char D_0045C5C8[];
extern char D_0045C5E8[];
extern char D_0045C600[];
extern char D_0045C620[];
extern char D_0045C630[];
extern char D_0045C640[];
extern char D_0045C650[];
extern char D_0045C660[];
extern char D_0045C670[];
extern char D_0045C680[];
extern char D_0045C698[];
extern char D_0045C6A8[];
extern char D_0045C6B8[];
extern char D_0045C6C8[];
extern char D_0045C760[];
extern char D_0045C780[];
extern char D_0045C7A0[];
extern char D_0045C7D0[];
extern char D_0045C800[];
extern char D_0045C808[];
extern char D_0045C820[];
extern char D_0045C830[];
extern char D_0045C850[];
extern char D_0045C870[];
extern char D_0045C888[];
extern char D_0045C898[];
extern char D_0045C8A0[];
extern char D_0045C8A8[];
extern char D_0045C8C8[];
extern char D_0045C8E8[];
extern char D_0045C8F8[];
extern char D_0045C908[];
extern char D_0045C918[];
extern char D_0045C928[];
extern char D_0045C948[];
extern char D_0045C960[];
extern char D_0045C970[];
extern char D_0045C980[];
extern char D_0045C990[];
extern char D_0045C9B0[];
extern char D_0045C9C0[];
extern char D_0045C9D0[];
extern char D_0045CA00[];
extern char D_0045CA20[];
extern char D_0045CA58[];
extern char D_0045CAA0[];
extern char D_0045CAB8[];
extern char D_0045CAC0[];
extern char D_0045CAD0[];
extern char D_0045CAE8[];
extern char D_0045CB00[];
extern char D_0045CB10[];
extern char D_0045CB30[];
extern char D_0045CB48[];
extern char D_0045CB68[];
extern char D_0045CB88[];
extern char D_0045CBA0[];
extern char D_0045CBB0[];
extern char D_0045CBC0[];
extern char D_0045CBC8[];
extern char D_0045CBD8[];
extern char D_0045CBE8[];
extern char D_0045CBF8[];
extern char D_0045CC18[];
extern char D_0045CC28[];
extern char D_0045CC38[];
extern char D_0045CC50[];
extern char D_0045CC60[];
extern char D_0045CC80[];
extern char D_0045CCA0[];
extern char D_0045CCB0[];
extern char D_0045CCD0[];
extern char D_0045CCE0[];
extern char D_0045CCF0[];
extern char D_0045CD10[];
extern char D_0045CD28[];
extern char D_0045CD40[];
extern char D_0045CD50[];
extern char D_0045CD60[];
extern char D_0045CD90[];
extern char D_0045CDB0[];
extern char D_0045CDE8[];
extern char D_0045CE00[];
extern char D_0045CE08[];
extern char D_0045CE18[];
extern char D_0045CE30[];
extern char D_0045CE40[];
extern char D_0045CE58[];
extern char D_0045CE68[];
extern char D_0045CE88[];
extern char D_0045CEA8[];
extern char D_0045CEC8[];
extern char D_0045CED8[];
extern char D_0045CEE0[];
extern char D_0045CEE8[];
extern char D_0045CEF8[];
extern char D_0045CF08[];
extern char D_0045CF18[];
extern char D_0045CF30[];
extern char D_0045CF40[];
extern char D_0045CF50[];
extern char D_0045CF70[];
extern char D_0045CF88[];
extern char D_0045CFA8[];
extern char D_0045CFB8[];
extern char D_0045CFC8[];
extern char D_0045D008[]; /* "" */
extern const char D_0045D010[];
extern const char D_0045D018[];
extern char D_0045D188[];
extern char D_0045D1A8[];
extern char D_0045D1AF[];
extern char D_0045D1D0[];
extern const char D_0045D1D7[]; /* "7fstream" sits at +1 */
extern char D_0045D1F7[];
extern char D_0045D208[];
extern char D_0045D20F[];
extern char D_0045D350[];
extern char D_0045D360[];
extern char D_0045D370[];
extern int D_0045D378;
extern int D_0045D388;
extern const char D_0045D7E0[16]; /* blanks */
extern const char D_0045D7F0[16]; /* zeroes */
extern char D_0045DA6F[]; /* 0x0045DA70 = "Infinity", one byte in */
extern char D_0045DA80[]; /* "NaN" */
extern char D_0045DA88[]; /* "0"   */
extern char D_0045DB78[];
extern char D_0045DB88[];
extern char D_0045DB8F[];
extern char D_0045DBA0[];
extern char D_0045DBA8[];
extern char D_0045DBD8[];
extern char D_0045DC20[]; /* the scePrintf format string */
extern char D_0045DD40[];
extern char D_0045DD80[];
extern char D_0045DDB8[];
extern char D_0045DDE8[];
extern char D_0045DE28[];
extern char D_0045DF50[];
extern char D_0045DF98[];
extern char D_0045DFC8[];
extern int D_0045DFE0[10];
extern char D_0045E038[];
extern char D_0045E060[];
extern char D_0045E1A8[];
extern char D_0045E1B8[];
extern char D_0045E1C8[];
extern char D_0045E1D8[];
extern char D_0045E1F0[];
extern char D_0045E210[];
extern char D_0045E228[];
extern char D_0045E238[];
extern char D_0045E248[];
extern char D_0045E260[];
extern char D_0045E288[];
extern char D_0045E2A0[]; /* the scePrintf format string */
extern char D_0045E2B0[]; /* the scePrintf format string */
extern char D_0045E2C0[];
extern char D_0045E2E8[];
extern char D_0045E330[];
extern char D_0045E348[];
extern char D_0045E368[];
extern char D_0045E380[];
extern char D_0045E398[];
extern char D_0045E3B0[];
extern char D_0045E3C0[]; /* the scePrintf format string */
extern unsigned char D_0045E400[];
extern char D_0045E490[];
extern char D_0045E4D0[];
extern char D_0045E510[];
extern char D_0045E548[];
extern char D_0045E568[];
extern char D_0045E588[];
extern char D_0045E5A8[];
extern char D_0045E5D8[];
extern char D_0045E610[]; /* the error message */
extern char D_0045E630[];
extern char D_0045E6C8[]; /* error message: intra and skipped both set */
extern char D_0045E6E0[];
extern char D_0045E700[];
extern char D_0045E720[];
extern char D_0045E750[];
extern char D_0045E770[];
extern char D_0045E7A8[];
extern char D_0045E7D0[];
extern char D_0045E7F8[]; /* "vertical size > 2800" */
extern char D_0045E810[]; /* "_chroma_format needs to be 1: 420" */
extern char D_0045E838[]; /* "Unsupported profile/level" */
extern char D_0045E858[]; /* "load_chroma_intra_quantizer_matrix == 1" */
extern char D_0045E880[]; /* "load_chroma_non_intra_quantizer_matrix == 1" */
extern char s__sequenceScalableExtension___is_n_0045e8b0[];
extern char s_Unknown_Extension_0045e8e0[];
extern char s__pictureSpatialScalableExtension_0045e8f8[];
extern char s__pictureTemporalScalableExtensio_0045e930[];
extern char D_0045E998[];
extern const float D_0045EA08[4]; /* atanhi[0..3] */
extern const float D_0045EA14; /* atanhi[3]    */
extern const float D_0045EA18[4]; /* atanlo[0..3] */
extern const float D_0045EA24; /* atanlo[3]    */
extern const float D_0045EA28[11]; /* aT[0..10]    */
extern char D_0045EA68[]; /* "asinf" */
extern char D_0045EA78[]; /* "expf" */
extern char D_0045EA88[]; /* "logf" */
extern const double D_0045EA90; /* -HUGE */
extern char D_0045EA98[]; /* "powf" */
extern const double D_0045EAA0; /* NaN */
extern char D_0045EAB8[]; /* "sqrtf" */
extern const double D_0045EAC0; /* nan */
extern const float D_0045EAD0[2]; /* halF  */
extern const float D_0045EAE8[2]; /* ln2HI */
extern const float D_0045EAF0[2]; /* ln2LO */
extern const float D_0045EB10; /* huge*huge, folded to +inf */
extern float D_0045EB40;
extern const float D_0045EB48[2]; /* bp   */
extern const float D_0045EB50[2]; /* dp_h */
extern const float D_0045EB58[2]; /* dp_l */
extern const float D_0045EBCC; /* huge*huge, folded to +inf */
extern const int D_0045EBD0[]; /* two_over_pi */
extern const int D_0045EEE8[32]; /* npio2_hw   */
extern const int D_0045EF90[3]; /* init_jk = {4,7,9} */
extern const float D_0045EFA0[]; /* PIo2[] */
extern const float D_0045EFF0[]; /* T[] */
extern const int D_0045F024; /* _LIB_VERSION */
extern const double D_0045F028[2]; /* TWO52 */
extern char D_0045F5C0[];
extern char D_0045F5F0[]; /* "C-SJIS" */
extern char D_0045F5F8[]; /* "C-EUCJP" */
extern char D_0045F600[]; /* "C-JIS" */
extern unsigned char D_0045FB80[];
extern const double D_0045FBE8; /* huge = 1.0e300 */
extern const double D_0045FC60; /* -two54/zero, folded to -inf */
extern const double D_0045FC80; /* -two54/zero == -inf */
extern char D_0045FC90[]; /* the overflow message */
extern const int D_0045FCD8[]; /* p05[3]     */
extern char D_0045FDFF[];
extern char D_0045FE28[];
extern char D_0045FE40[];
extern unsigned char D_00460060;
extern unsigned char D_00460070;
extern unsigned char D_00460080;
extern unsigned char D_00460090;
extern int D_00460108;
extern char D_00460120[];
extern char D_00460138[];
extern char D_004601C8[];
extern char D_00460228[];
extern char D_00460240[];
extern char D_00460370[];
extern char D_00460380[];
extern char D_00460818[];
extern char D_00460840[];
extern char D_00460888[];
extern char D_004608B0[];
extern char D_004608D8[];
extern char D_00460900[];
extern char D_00460928[];
extern int D_00460950;
extern char D_00460A00[];
extern char D_00460A70[];
extern int D_00460AA8;
extern char D_00460AD0[];
extern char D_00460AF8[]; /* "E03032501 : NULL pointer is passed." */
extern char D_00460B20[]; /* "E03032403 : NULL pointer is passed." */
extern char D_00460B48[]; /* "E03032410 : NULL pointer is passed." */
extern char D_00460B70[]; /* "E03032411 : Illegal server frequency is passed." */

/* .sbss */
extern int D_00460D00;
extern int D_00460D08;
extern int D_00460D10;
extern int D_00460D20;
extern int D_00460D28;
extern int D_00460D30;
extern int D_00460D38;
extern int D_00460D40;
extern int D_00460D48;
extern int D_00460D50;
extern int D_00460D58;
extern int D_00460D60;
extern int D_00460D68;
extern int D_00460D70;
extern int D_00460D78;
extern int D_00460D80;
extern int D_00460D88;
extern int D_00460D90;
extern int D_00460D98;

/* .bss */
extern int D_004615F0[];
extern int D_00463964;
extern char D_00464080;
extern int D_00466448[];
extern char D_004A6940[];
extern char D_004A6980[];
extern int D_004A6D80;
extern int D_004A6E10;
extern char D_00506E10[];
extern int D_00566E30;
extern int D_00566E40;
extern int D_00566E44;
extern int D_00566E50;
extern char D_00567D70[];
extern char D_00567D80[];
extern char D_00567E80[];
extern char D_00567F80[];
extern char D_00567FA0[];
extern unsigned char D_00568060[];
extern unsigned char D_00568070[];
extern unsigned char D_005680E0[];
extern int D_00568280;
extern int D_005685B0[];
extern unsigned short D_00568650[];
extern unsigned char D_005686A0[];
extern char D_00569B80[];
extern char D_0056C380[];
extern char D_0057F060[];
extern int D_00580D80;
extern unsigned short D_00583ED4;
extern unsigned short D_00583EEC;
extern char D_00585038[];
extern unsigned char D_0058503A;
extern char D_00585040[];
extern char D_00585240[];
extern char D_00585450[];
extern char D_00585660[];
extern char D_00585720[];
extern char D_00585960[];
extern int D_00586A04;
extern char*D_00586A58;
extern char*D_00586A5C;
extern char*D_00586A7C;
extern char*D_00586A80;
extern char*D_00586A88;
extern unsigned char D_00586AA4;
extern int D_00586B34;
extern float D_00586B84;
extern float D_00586B88;
extern char D_0059ACC8[];
extern char D_0059AFB0[];
extern char D_0059B228[];
extern char D_0059B4A0[];
extern char D_0059B718[];
extern char D_0059B990[];
extern char D_0059BC08[];
extern unsigned short D_005CAC94;
extern short D_005CAE40;
extern int D_005CAFF4;
extern char D_005CB020[];
extern char D_005CB300[];
extern char D_005CB3B0[];
extern char D_005E7910[];
extern char D_005E79D0[]; /* the movie manager */
extern char D_005E7E30[];
extern char D_005E80E0[];
extern int D_005E8600;
extern char D_005F38F0[];
extern char D_005F3970[];
extern int D_005FEAC0; /* 0x005FEAC0: BSS word */
extern void*D_005FEC68;
extern char D_00601F80[];
extern int D_006046C0;
extern int D_0061A998;
extern float D_0061B5C0[];
extern unsigned char D_0061B670;
extern int D_0061B674;
extern int D_00741DB8;
extern float D_00741DC0;
extern char D_00743250[];
extern unsigned char D_0074748C; /* pause state, bit 2 = menu open */
extern int D_007474B0;
extern long D_00747650; /* pad press bits */
extern int D_007476C0[];
extern float D_007479FC;
extern int D_00747A04; /* D_007474A0.frameShift: 1 at 60 FPS doubles each length */
extern int D_00747A10;
extern float D_00747A14; /* global speed rate */
extern int D_00747A18;
extern int D_00747A28;
extern int D_00747A38; /* cheat flags */
extern int D_00747A3C;
extern int D_00747A44;
extern unsigned char D_00747A57;
extern unsigned D_00747A8C[];
extern int D_00747A94; /* 0x00747A94: BSS word */
extern int D_00747AA8;
extern int D_00747B14;
extern char D_00747B20[];
extern int D_00752CF0;
extern int D_00752CF8; /* timer-0 counts MoveObj took */
extern int D_00752CFC;
extern int D_00752D00;
extern int D_00752D08;
extern int D_00752D3C;
extern int D_00752D44;
extern volatile int D_00753D88;
extern unsigned D_00754250[624];
extern float D_00754C48;
extern int D_00755800;
extern int D_00755804;
extern char*D_00755840;
extern int D_007558A0[];
extern int D_007559A8[];
extern short D_00755BC0;
extern int D_00755BC8;
extern unsigned char D_00755BD0[];
extern int D_00755C08; /* set once the context is initialised */
extern void*D_00755C10[2]; /* top_elt, the first dynamic handler chain entry */
extern volatile int D_00755C1C;
extern char D_00755C40[];
extern char D_00755E84[];
extern char D_00756090[];
extern int D_00758500[1];
extern int D_007588B8;
extern int D_00758A30[];
extern int D_00758C80;
extern int D_0075CC80;
extern unsigned char D_00760C80[];
extern int D_00760D80; /* Reset word; no other observed retail references. */
extern int D_00760D84; /* Callback ID for "MWSFSVR_VsyncThrdProc". */
extern int D_00760D88; /* Callback ID for "MWSFSVR_IdleThrdProc". */
extern int D_00760D8C; /* Callback ID for "MWSFSVR_MainThrdProc". */
extern int D_00760DAC;
extern int D_00760DB0;
extern int D_00760DB4;
extern char D_00761E50[];
extern int D_00762058;
extern char D_00762868[];
extern int D_00766C18;
extern int D_00766C1C;
extern int D_00766C20;
extern int D_00766C70;
extern char D_00766C78[];
extern volatile int*D_00766C88;
extern int* volatile D_00766CA0;
extern int* volatile D_00766CA4;
extern int* volatile D_00766CD0;
extern char* volatile D_00766CD4; /* active mode table, volatile keeps retail's lui+addiu address */
extern int D_00766CD8;
extern volatile int D_00766CE0;
extern void*D_00766D44;
extern char D_00766D48[];
extern unsigned char* volatile D_0076A588; /* entry table pointer, volatile keeps retail's lui+addiu address */
extern int*D_0076A5D8;
extern int D_0076A7A4;
extern int D_0076A7AC; /* which allocator D_003F2810 uses */
extern unsigned char D_0076A7B4;
extern char D_0076B040[];
extern int D_0076B080;
extern int D_0076B580[];
extern unsigned char D_00773318[];
extern int D_0077C080; /* result_k */
extern void*D_0077C380;
extern int D_0077C3C0; /* the user callback function pointer */
extern void*D_0077C3CC; /* its gp */
extern void*D_0077C3D0; /* sceCdPoffCbdata */
extern char D_0077C464[]; /* _sf_data.name */
extern int D_0077C580[]; /* sfrdata */
extern int D_0077C5C0[]; /* cdrdsf (sceSifClientData) */
extern int D_0077C610[]; /* sceSifClientData */
extern int D_0077C650[]; /* send buffer */
extern unsigned long long D_0077C680[]; /* _sprtagdata, 0x240 B */
extern char D_0077DA88[]; /* the 0x80-byte staging buffer */
extern char D_0077DB08[]; /* the 0x80-byte staging buffer */
extern int D_0077DB88;
extern char D_0077DB90[];
extern int D_0077DF90;
extern char D_0077E3A0[];
extern int D_0077E514;
extern char*D_0077E524;
extern char*D_0077E52C;
extern int D_0077E6C0[];
extern char D_00780C00[];
extern char D_007816C0[];
extern char D_007816E8[];
extern void*D_00781780;
extern char D_007817C0[];
extern int D_00781800;
extern int D_00781840;
extern char D_00781BA8[];
extern char D_007854B0[];
extern int D_007854D8;
extern int D_007854E8;
extern int D_007854F8;
extern int D_00785508;
extern int D_00785518;
extern int D_00785528;
extern int D_00785538;
extern int D_00785548;
extern int D_00785558;
extern int D_00785568;
extern int D_00785578;
extern int D_00785588;
extern int D_00785598;
extern int D_007855A8;
extern int D_007855B8;
extern int D_007855C8;
extern int D_007855D8;
extern int D_007855E8;
extern int D_007855F8;
extern int D_00785608;
extern int D_00785618;
extern int D_00785628;
extern int D_00785638;
extern int D_00785648;
extern int D_00785658;
extern int D_00785668;
extern int D_00785678;
extern int D_00785688;
extern int D_00785698;
extern int D_007856A8;
extern int D_007856B8;
extern int D_007856C8;
extern int D_007856D8;
extern int D_007856E8;
extern int D_007856F8;
extern int D_00785708;
extern int D_00785718;
extern int D_00785728;
extern int D_00785738;
extern int D_00785748;
extern int D_00785758;
extern int D_00785768;
extern int D_00785778;
extern int D_00785788;
extern int D_007857A8;
extern int D_007857B8;
extern int D_007857C8;
extern int D_007857D8;
extern int D_007857E8;
extern int D_007857F8;
extern int D_00785808;
extern int D_00785818;
extern int D_00785828;
extern int D_00785838;
extern int D_00785848;
extern int D_00785858;
extern int D_00785868;
extern int D_00785888;
extern int D_00785898;
extern int D_007858A8;
extern int D_007858C8;
extern int D_007858D8;
extern int D_007858E8;
extern int D_007858F8;
extern int D_00785908;
extern int D_00785918;
extern int D_00785928;
extern int D_00785938;
extern int D_00785948;
extern int D_00785958;
extern int D_00785968;
extern int D_00785978;
extern int D_00785988;
extern int D_00785998;
extern int D_007859A8;
extern int D_007859C8;
extern int D_007859D8;
extern int D_007859E8;
extern int D_007859F8;
extern int D_00785A08;
extern int D_00785A18;
extern int D_00785A28;
extern int D_00785A38;
extern int D_00785A48;
extern int D_00785A58;
extern int D_00785A68;
extern int D_00785A78;
extern int D_00785A88;
extern int D_00785A98;
extern int D_00785AA8;
extern int D_00785AB8;
extern int D_00785AC8;
extern int D_00785AD8;
extern int D_00785AE8;
extern int D_00785AF8;
extern int D_00785B08;
extern int D_00785B18;
extern int D_00785B28;
extern int D_00785B38;
extern int D_00785B48;
extern int D_00785B58;
extern int D_00785B68;
extern int D_00785B78;
extern int D_00785B88;
extern int D_00785B98;
extern int D_00785BA8;
extern int D_00785BB8;
extern int D_00785BC8;
extern int D_00785BD8;
extern int D_00785BE8;
extern int D_00785BF8;
extern int D_00785C08;
extern int D_00785C18;
extern int D_00785C28;
extern int D_00785C38;
extern int D_00785C48[];
extern int D_00785C58;
extern int D_00785C68;
extern int D_00785C78;
extern int D_00785C88;
extern int D_00785C98;
extern int D_00785CA8;
extern int D_00785CB8;
extern int D_00785CC8;
extern int D_00785CD8;
extern int D_00785CE8;
extern int D_00785CF8;
extern int D_00785D08;
extern int D_00785D18;
extern int D_00785D28;
extern int D_00785D38;
extern int D_00785D48;
extern int D_00785D58;
extern int D_00785D68;
extern int D_00785D78;
extern int D_00785D88;
extern int D_00785D98;
extern int D_00785DA8;
extern int D_00785DB8;
extern int D_00785DC8;
extern int D_00785DD8;
extern int D_00785DE8;
extern int D_00785DF8;
extern int D_00785E08;
extern int D_00785E18;
extern int D_00785E28;
extern int D_00785E38;
extern int D_00785E48;
extern int D_00785E58;
extern int D_00785E68;
extern int D_00785E78;
extern int D_00785E88;
extern void*D_00785E98;
extern int D_00785EA8;
extern int D_00785EB8;
extern int D_00785EC8;
extern int D_00785ED8;
extern int D_00785EE8;
extern int D_00785EF8;
extern int D_00785F08;
extern int D_00785F18;
extern int D_00785F28;
extern int D_00785F38;
extern int D_00785F48;
extern int D_00785F58;
extern int D_00785F68;
extern int D_00785F78;
extern int D_00785F88;
extern int D_00785F98;
extern int D_00785FA8;
extern int D_00785FB8;
extern int D_00785FC8;
extern int D_00785FD8;
extern int D_00785FE8;
extern int D_00785FF8;
extern int D_00786008;
extern int D_00786018;
extern int D_00786028;
extern int D_00786038;
extern int D_00786048;
extern int D_00786058;
extern int D_00786068;
extern int D_00786078;
extern int D_00786088;
extern int D_00786098;
extern int D_007860A8;
extern int D_007860B8;
extern int D_007860C8;
extern int D_007860D8;
extern int D_007860E8;
extern int D_007860F8;
extern int D_00786108;
extern int D_00786118;
extern int D_00786128;
extern int D_00786138;
extern int D_00786148;
extern int D_00786158;
extern int D_00786168;
extern int D_00786178;
extern int D_00786188;
extern int D_00786198;
extern int D_007861A8;
extern int D_007861B8;
extern int D_007861C8;
extern int D_007861D8;
extern int D_007861E8;
extern int D_007861F8;
extern int D_00786208;
extern int D_00786218;
extern int D_00786228;
extern int D_00786238;
extern int D_00786248;
extern int D_00786258;
extern int D_00786268;
extern int D_00786278;
extern int D_00786288;
extern int D_00786298;
extern int D_007862A8;
extern int D_007862B8;
extern int D_007862C8;
extern int D_007862D8;
extern int D_007862E8;
extern int D_007862F8;
extern int D_00786308;
extern int D_00786318;
extern int D_00786328;
extern int D_00786338;
extern int D_00786348;
extern int D_00786358;
extern int D_00786368;
extern int D_00786378;
extern int D_00786388;
extern int D_00786398;
extern int D_007863A8;
extern int D_007863B8;
extern int D_007863C8;
extern int D_007863D8;
extern int D_007863E8;
extern int D_007863F8;
extern int D_00786408;
extern int D_00786418;
extern int D_00786428;
extern int D_00786438;
extern int D_00786448;
extern int D_00786458;
extern int D_00786468;
extern int D_00786478;
extern int D_00786488;
extern int D_00786498;
extern int D_007864A8;
extern int D_007864B8;
extern int D_007864C8;
extern int D_007864D8;
extern int D_007864E8;
extern int D_007864F8;
extern int D_00786508;
extern int D_00786518;
extern int D_00786528;
extern int D_00786538;
extern int D_00786548;
extern int D_00786558;
extern int D_00786568;
extern int D_00786578;
extern int D_00786588;
extern int D_00786598;
extern int D_007865A8;
extern int D_007865B8;
extern int D_007865C8;
extern int D_007865D8;
extern int D_007865E8;
extern int D_007865F8;
extern int D_00786608;
extern int D_00786618;
extern int D_00786628;
extern int D_00786638;
extern int D_00786658;
extern int D_00786668;
extern int D_00786678;
extern int D_00786688;
extern int D_00786698;
extern int D_007866A8;
extern int D_007866B8;
extern int D_007866C8;
extern int D_007866D8;
extern int D_007866E8;
extern int D_007866F8;
extern void*D_00786708;
extern void*D_00786718;
extern void*D_00786728;
extern void*D_00786738;
extern unsigned char D_00786748[]; /* __ti7fstream */
extern int D_786758;
extern int D_786778;
extern void*D_786788;
extern void*D_786798;
extern int D_7867A8;

#endif /* GODHAND_GLOBALS_H */
