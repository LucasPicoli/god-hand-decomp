/* ee-2.9-991111 matched TU. */

/* MPEG-2 copyright_extension() -- bit-field skip. */

extern int func_0039EAA8(void *v, int n);	/* getBits */

__attribute__((section(".text.func_003A1068")))
int func_003A1068(void *v)
{
	func_0039EAA8(v, 1);	/* copyright_flag       */
	func_0039EAA8(v, 8);	/* copyright_identifier */
	func_0039EAA8(v, 1);	/* original_or_copy     */
	func_0039EAA8(v, 7);	/* reserved             */
	func_0039EAA8(v, 1);	/* marker_bit           */
	func_0039EAA8(v, 20);	/* copyright_number_1   */
	func_0039EAA8(v, 1);	/* marker_bit           */
	func_0039EAA8(v, 22);	/* copyright_number_2   */
	func_0039EAA8(v, 1);	/* marker_bit           */
	return func_0039EAA8(v, 22);	/* copyright_number_3   */
}
