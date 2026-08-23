/* ee-2.9-991111 matched TU. */

extern void flushByteBoundary(void *v);

/* Sony libmpeg ext.c::_sceMpegNextHeader -- scan for the next MPEG-2 start code. */

extern int func_0039EAA8(void *v, int n);	/* _sceMpegNextBit  (getBits) */
extern int func_0039EB90(void *v, int n);	/* _sceMpegPeepBit  (peekBits) */
extern int func_003A0E20(void *v, int n);	/* _flushBuf */

extern void func_003A0330(void *v);		/* _sequenceHeader */
extern void func_003A05E0(void *v);		/* _groupOfPicturesHeader */
extern void func_003A0680(void *v);		/* _pictureHeader */
extern void func_0039AB20(int h, void *req);	/* _sceMpegDispatchMpegCallback */

typedef struct {
	int cmd;			/* 0x0 */
	long pts;			/* 0x8 */
	long dts;			/* 0x10 */
} MpegCb;

typedef struct {
	char _pad0[0x160];
	int picture_coding_type;	/* 0x160 */
	char _pad1[0x6D4];
	long pts;			/* 0x838 */
	long dts;			/* 0x840 */
	char _pad2[0x20];
	int cb;				/* 0x868 */
	char _pad3[0xC];
	int stop;			/* 0x878 */
} Mpeg;

__attribute__((section(".text.func_003A0E28")))
int func_003A0E28(Mpeg *v)
{
	MpegCb req;
	unsigned int code;

	for (;;) {
		if (v->stop != 0)
			return -1;
		flushByteBoundary(v);
		while (func_0039EB90(v, 24) != 1 && v->stop == 0)
			func_003A0E20(v, 8);
		code = func_0039EAA8(v, 32);
		switch (code) {
		case 0x1B3:
			func_003A0330(v);
			break;
		case 0x1B8:
			func_003A05E0(v);
			break;
		case 0x100:
			func_003A0680(v);
			req.cmd = 5;
			req.pts = -1;
			req.dts = -1;
			func_0039AB20(v->cb, &req);
			v->dts = req.dts;
			v->pts = req.pts;
			return v->picture_coding_type;
		case 0x1B7:
			return 0;
		}
	}
}
