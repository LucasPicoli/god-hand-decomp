/* ee-2.9-991111 matched TU. */

/* MPEG-2 picture_header() -- Sony libmpeg ext.c::_pictureHeader */

extern int func_0039EAA8(void *v, int n);	/* getBits */
extern int func_003A0E20(void *v, int n);	/* flushBits */
extern void func_003A0C18(void *v);		/* _extensionAndUserData */

typedef struct {
	char _pad0[0x160];
	int picture_coding_type;	/* 0x160 */
	int full_pel_forward_vector;	/* 0x164 */
	int forward_f_code;		/* 0x168 */
	int full_pel_backward_vector;	/* 0x16C */
	int backward_f_code;		/* 0x170 */
	char _pad1[0x48];
	int display_index;		/* 0x1BC */
	char _pad2[0x69C];
	int base_index;			/* 0x85C */
	int max_index;			/* 0x860 */
	int wrap_flag;			/* 0x864 */
} Mpeg;

__attribute__((section(".text.func_003A0680")))
void func_003A0680(Mpeg *v)
{
	int tr;
	int ok;
	int prev;
	int m;

	tr = func_0039EAA8(v, 10);		/* temporal_reference */
	v->picture_coding_type = func_0039EAA8(v, 3);
	func_0039EAA8(v, 16);			/* vbv_delay */
	if (v->picture_coding_type == 2 || v->picture_coding_type == 3) {
		v->full_pel_forward_vector = func_0039EAA8(v, 1);
		v->forward_f_code = func_0039EAA8(v, 3);
	}
	if (v->picture_coding_type == 3) {
		v->full_pel_backward_vector = func_0039EAA8(v, 1);
		v->backward_f_code = func_0039EAA8(v, 3);
	}
	while (func_0039EAA8(v, 1))		/* extra_bit_picture */
		func_003A0E20(v, 8);		/* extra_information_picture */
	func_003A0C18(v);

	ok = 0;
	prev = 0;
	if (v->picture_coding_type != 3 && tr != 0) {
		if (tr < 0)
			ok = (v->wrap_flag == 0);
		v->wrap_flag = 0;
		prev = tr;
	}
	v->display_index = v->base_index + tr;
	if (ok && prev >= tr)
		v->display_index = v->base_index + tr + 0x400;
	m = v->max_index;
	if (m < v->display_index)
		m = v->display_index;
	v->max_index = m;
}
