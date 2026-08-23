/* ee-2.9-991111 matched TU. */

/* MPEG-2 picture_coding_extension() -- Sony libmpeg ext.c::_pictureCodingExtension */

extern int func_0039EAA8(void *v, int n);	/* getBits */

#define IPU_CTRL (*(volatile unsigned int *)0x10002010)

typedef struct {
	char _pad0[0xE8];
	int first_picture_structure;	/* 0xE8 */
	char _pad1[0x88];
	int f_code00;			/* 0x174 */
	int f_code01;			/* 0x178 */
	int f_code10;			/* 0x17C */
	int f_code11;			/* 0x180 */
	int picture_structure;		/* 0x184 */
	int top_field_first;		/* 0x188 */
	int frame_pred_frame_dct;	/* 0x18C */
	int concealment_motion_vectors;	/* 0x190 */
	int repeat_first_field;		/* 0x194 */
	int progressive_frame;		/* 0x198 */
} Mpeg;

__attribute__((section(".text.func_003A0A10")))
int func_003A0A10(Mpeg *v)
{
	int t;

	v->f_code00 = func_0039EAA8(v, 4);
	v->f_code01 = func_0039EAA8(v, 4);
	v->f_code10 = func_0039EAA8(v, 4);
	v->f_code11 = func_0039EAA8(v, 4);
	t = func_0039EAA8(v, 2);			/* intra_dc_precision */
	IPU_CTRL = (IPU_CTRL & 0xFFFCFFFF) | (t << 16);
	t = func_0039EAA8(v, 2);			/* picture_structure */
	v->picture_structure = t;
	if (v->first_picture_structure == 0)
		v->first_picture_structure = t;
	v->top_field_first = func_0039EAA8(v, 1);
	v->frame_pred_frame_dct = func_0039EAA8(v, 1);
	v->concealment_motion_vectors = func_0039EAA8(v, 1);
	t = func_0039EAA8(v, 1);			/* q_scale_type */
	IPU_CTRL = (IPU_CTRL & 0xFFBFFFFF) | (t << 22);
	t = func_0039EAA8(v, 1);			/* intra_vlc_format */
	IPU_CTRL = (IPU_CTRL & 0xFFDFFFFF) | (t << 21);
	t = func_0039EAA8(v, 1);			/* alternate_scan */
	IPU_CTRL = (IPU_CTRL & 0xFFEFFFFF) | (t << 20);
	v->repeat_first_field = func_0039EAA8(v, 1);
	func_0039EAA8(v, 1);				/* chroma_420_type */
	v->progressive_frame = func_0039EAA8(v, 1);
	if (func_0039EAA8(v, 1)) {			/* composite_display_flag */
		func_0039EAA8(v, 1);			/* v_axis */
		func_0039EAA8(v, 3);			/* field_sequence */
		func_0039EAA8(v, 1);			/* sub_carrier */
		func_0039EAA8(v, 7);			/* burst_amplitude */
		return func_0039EAA8(v, 8);		/* sub_carrier_phase */
	}
}
