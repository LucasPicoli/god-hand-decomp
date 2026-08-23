/* ee-2.9-991111 matched TU. */

extern void _initSeq(int h);
extern void func_003B63F0(void);

/* MPEG-2 sequence_header() -- Sony libmpeg ext.c::_sequenceHeader */

extern int func_0039EAA8(void *v, int n);	/* getBits */
extern void func_0039C390(void *v, char *msg);	/* _sceMpegError */
extern void func_003A0DE8(void *v);		/* _waitIpuIdle */
extern void func_0039AB20(int h, void *req);	/* _sceMpegDispatchMpegCallback */
extern void func_003A0C18(void *v);		/* _extensionAndUserData */




extern char D_0045E7F8[];			/* "vertical size > 2800" */
extern unsigned char D_003FA280[];		/* _defIQM  */
extern unsigned char D_003FA2C0[];		/* _defNIQM */

#define IPU_CMD  (*(volatile unsigned int *)0x10002000)
#define D4_CHCR  (*(volatile unsigned int *)0x1000B400)
#define D4_MADR  (*(volatile unsigned int *)0x1000B410)
#define D4_QWC   (*(volatile unsigned int *)0x1000B420)

typedef struct {
	int cmd;
	long a;
	long b;
} MpegCb;

typedef struct {
	char _pad0[0xE8];
	int first_picture_structure;		/* 0xE8 */
	char _pad1[0x48];
	int horizontal_size;			/* 0x134 */
	int vertical_size;			/* 0x138 */
	char _pad2[0x8];
	int bit_rate;				/* 0x144 */
	int vbv_buffer_size;			/* 0x148 */
	char _pad3[0x6DC];
	int ipu_busy;				/* 0x828 */
	unsigned int ipu_cmd;			/* 0x82C */
	char _pad4[0x20];
	int load_intra_quantiser_matrix;	/* 0x850 */
	int load_non_intra_quantiser_matrix;	/* 0x854 */
	char _pad5[0x10];
	int cb;					/* 0x868 */
} Mpeg;

__attribute__((section(".text.func_003A0330")))
void func_003A0330(Mpeg *v)
{
	MpegCb req;
	unsigned int n;
	int vsize;
	int r;

	v->first_picture_structure = 0;
	n = func_0039EAA8(v, 32);
	vsize = (n >> 8) & 0xFFF;
	v->horizontal_size = n >> 20;
	v->vertical_size = vsize;
	if (vsize > 2800)
		func_0039C390(v, D_0045E7F8);

	n = func_0039EAA8(v, 30);
	v->bit_rate = n >> 12;
	v->vbv_buffer_size = (n >> 1) & 0x3FF;

	v->load_intra_quantiser_matrix = func_0039EAA8(v, 1);
	if (v->load_intra_quantiser_matrix) {
		func_003A0DE8(v);
		IPU_CMD = 0x50000000;
		v->ipu_cmd = 0x50000000;
		v->ipu_busy = 1;
		func_003A0DE8(v);
	} else {
		unsigned int p = (unsigned int)D_003FA280;
		unsigned int cmd = 0x50000000;
		req.cmd = 2;
		func_0039AB20(v->cb, &req);
		func_003A0DE8(v);
		IPU_CMD = 0;
		func_003A0DE8(v);
		r = func_003B63A0();
		D4_MADR = p & 0x0FFFFFFF;
		D4_QWC = 4;
		D4_CHCR = 0x101;
		if (r != 0)
			func_003B63F0();
		IPU_CMD = cmd;
		v->ipu_cmd = 0x50000000;
		v->ipu_busy = 1;
		func_003A0DE8(v);
		req.cmd = 3;
		func_0039AB20(v->cb, &req);
	}

	v->load_non_intra_quantiser_matrix = func_0039EAA8(v, 1);
	if (v->load_non_intra_quantiser_matrix) {
		func_003A0DE8(v);
		IPU_CMD = 0x58000000;
		v->ipu_cmd = 0x50000000;
		v->ipu_busy = 1;
		func_003A0DE8(v);
	} else {
		unsigned int p = (unsigned int)D_003FA2C0;
		unsigned int cmd = 0x58000000;
		req.cmd = 2;
		func_0039AB20(v->cb, &req);
		func_003A0DE8(v);
		IPU_CMD = 0;
		func_003A0DE8(v);
		r = func_003B63A0();
		D4_MADR = p & 0x0FFFFFFF;
		D4_QWC = 4;
		D4_CHCR = 0x101;
		if (r != 0)
			func_003B63F0();
		IPU_CMD = cmd;
		v->ipu_cmd = 0x50000000;
		v->ipu_busy = 1;
		func_003A0DE8(v);
		req.cmd = 3;
		func_0039AB20(v->cb, &req);
	}

	func_003A0C18(v);
	_initSeq(v->cb);
}
