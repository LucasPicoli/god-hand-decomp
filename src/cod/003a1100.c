/* ee-2.9-991111 matched TU. */

/* MPEG-2 picture_display_extension() -- Sony libmpeg ext.c::_pictureDisplayExtension */

extern int func_0039EAA8(void *v, int n);		/* getBits */

typedef struct {
	char _pad0[0x14C];
	int progressive_sequence;		/* 0x14C */
	char _pad1[0x34];
	int picture_structure;			/* 0x184 */
	int top_field_first;			/* 0x188 */
	char _pad2[0x8];
	int repeat_first_field;			/* 0x194 */
	char _pad3[0x4];
	int frame_centre_horizontal_offset[3];	/* 0x19C */
	int frame_centre_vertical_offset[3];	/* 0x1A8 */
} Mpeg;

__attribute__((section(".text.func_003A1100")))
void func_003A1100(Mpeg *v)
{
	int n;
	int i;

	if (v->progressive_sequence) {
		if (v->repeat_first_field)
			n = v->top_field_first ? 3 : 2;
		else
			n = 1;
	} else if (v->picture_structure != 3) {
		n = 1;
	} else {
		n = v->repeat_first_field ? 3 : 2;
	}
	for (i = 0; i < n; i++) {
		v->frame_centre_horizontal_offset[i] = func_0039EAA8(v, 16);
		func_0039EAA8(v, 1);	/* marker_bit */
		v->frame_centre_vertical_offset[i] = func_0039EAA8(v, 16);
		func_0039EAA8(v, 1);	/* marker_bit */
	}
}
