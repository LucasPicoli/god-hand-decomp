/* ee-2.9-991111 matched TU. */

/* MPEG-2 sequence_display_extension(). */

extern int func_0039EAA8(void *v, int n);	/* getBits */

typedef struct {
	char _pad0[0x154];
	int matrix_coefficients;	/* 0x154 */
	int display_horizontal_size;	/* 0x158 */
	int display_vertical_size;	/* 0x15C */
} SeqDisp;

__attribute__((section(".text.func_003A0FD8")))
void func_003A0FD8(SeqDisp *v)
{
	func_0039EAA8(v, 3);				/* video_format */
	if (func_0039EAA8(v, 1)) {			/* colour_description */
		func_0039EAA8(v, 8);			/* colour_primaries */
		func_0039EAA8(v, 8);			/* transfer_characteristics */
		v->matrix_coefficients = func_0039EAA8(v, 8);
	}
	v->display_horizontal_size = func_0039EAA8(v, 14);
	func_0039EAA8(v, 1);				/* marker_bit */
	v->display_vertical_size = func_0039EAA8(v, 14);
}
