/* ee-2.9-991111 matched TU. */

/* MPEG-2 sequence_extension() -- Sony libmpeg ext.c::_sequenceExtension */

extern int func_0039EAA8(void *v, int n);		/* getBits */
extern void func_0039C390(void *v, char *msg);		/* _sceMpegError */

extern char D_0045E810[];	/* "_chroma_format needs to be 1: 420" */
extern char D_0045E838[];	/* "Unsupported profile/level" */

#define IPU_CTRL (*(volatile unsigned int *)0x10002010)

typedef struct {
	char _pad0[0x134];
	int horizontal_size;		/* 0x134 */
	int vertical_size;		/* 0x138 */
	char _pad1[0x8];
	int bit_rate;			/* 0x144 */
	int vbv_buffer_size;		/* 0x148 */
	int progressive_sequence;	/* 0x14C */
	int chroma_format;		/* 0x150 */
	char _pad2[0x704];
	int is_mpeg2;			/* 0x858 */
} Mpeg;

__attribute__((section(".text.func_003A07C8")))
void func_003A07C8(Mpeg *v)
{
	unsigned int n;
	unsigned int m;
	int profile_and_level_indication;
	int chroma_format;
	int horizontal_size_extension;
	int vertical_size_extension;
	int bit_rate_extension;
	int vbv_buffer_size_extension;

	v->is_mpeg2 = 1;
	IPU_CTRL = IPU_CTRL & 0xFF7FFFFF;
	n = func_0039EAA8(v, 28);
	bit_rate_extension = (n >> 1) & 0xFFF;
	vertical_size_extension = (n >> 13) & 3;
	horizontal_size_extension = (n >> 15) & 3;
	chroma_format = (n >> 17) & 3;
	v->chroma_format = chroma_format;
	if (chroma_format != 1)
		func_0039C390(v, D_0045E810);
	v->progressive_sequence = (n >> 19) & 1;
	profile_and_level_indication = n >> 20;
	m = func_0039EAA8(v, 16);
	vbv_buffer_size_extension = m >> 8;
	if (profile_and_level_indication != 0x48 &&
	    profile_and_level_indication != 0x58 &&
	    profile_and_level_indication != 0x44)
		func_0039C390(v, D_0045E838);
	v->horizontal_size = (horizontal_size_extension << 12) | (v->horizontal_size & 0xFFF);
	v->vertical_size = (vertical_size_extension << 12) | (v->vertical_size & 0xFFF);
	v->bit_rate += bit_rate_extension << 18;
	v->vbv_buffer_size += vbv_buffer_size_extension << 10;
}
