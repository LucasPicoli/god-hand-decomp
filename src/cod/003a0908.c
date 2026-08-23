/* ee-2.9-991111 matched TU. */

/* MPEG-2 quant_matrix_extension() -- Sony libmpeg ext.c::_quantMatrixExtension */

extern int func_0039EAA8(void *v, int n);		/* getBits */
extern void func_003A0DE8(void *v);			/* _waitIpuIdle */
extern void func_0039C390(void *v, char *msg);		/* _sceMpegError */

extern char D_0045E858[];	/* "load_chroma_intra_quantizer_matrix == 1" */
extern char D_0045E880[];	/* "load_chroma_non_intra_quantizer_matrix == 1" */

#define IPU_CMD (*(volatile unsigned int *)0x10002000)

typedef struct {
	char _pad0[0x828];
	int ipu_busy;			/* 0x828 */
	unsigned int ipu_cmd;		/* 0x82C */
	char _pad1[0x20];
	int load_intra_quantiser_matrix;	/* 0x850 */
	int load_non_intra_quantiser_matrix;	/* 0x854 */
} Mpeg;

__attribute__((section(".text.func_003A0908")))
void func_003A0908(Mpeg *v)
{
	v->load_intra_quantiser_matrix = func_0039EAA8(v, 1);
	if (v->load_intra_quantiser_matrix) {
		func_003A0DE8(v);
		IPU_CMD = 0x50000000;
		v->ipu_cmd = 0x50000000;
		v->ipu_busy = 1;
		func_003A0DE8(v);
	}
	v->load_non_intra_quantiser_matrix = func_0039EAA8(v, 1);
	if (v->load_non_intra_quantiser_matrix) {
		func_003A0DE8(v);
		IPU_CMD = 0x58000000;
		v->ipu_cmd = 0x50000000;
		v->ipu_busy = 1;
		func_003A0DE8(v);
	}
	if (func_0039EAA8(v, 1))
		func_0039C390(v, D_0045E858);
	if (func_0039EAA8(v, 1))
		func_0039C390(v, D_0045E880);
}
