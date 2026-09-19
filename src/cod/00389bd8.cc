/* ee-2.9-991111 matched TU. */

/* __tf7fstream: the g++ 2.95.2 synthesized type-info function for class fstream
   (gcc/cp/rtti.c synthesize_tinfo_fn + expand_class_desc), written out as a
   named function.  ee-2.9-991111.  The two base __tf calls run first, then
   __rtti_class(&__ti7fstream, "7fstream", base_list, 2). */
class type_info;

struct base_info { const type_info *base; unsigned int offset:29, is_virtual:1, access:2; };

extern "C" void func_0038A7E0(void);                 /* __tf of the first base  */
extern "C" void func_0038A340(void);                 /* __tf of the second base */
extern "C" void __rtti_class(void *, const char *, const base_info *, unsigned int);

extern unsigned char D_00786748[];                    /* __ti7fstream */
extern const char D_0045D1D7[];                       /* "7fstream" sits at +1 */
extern const base_info D_0045D1E8[];                  /* the two-entry base list */

extern "C" const type_info &func_00389BD8 (void)
  __attribute__((section(".text.func_00389BD8")));

extern "C" const type_info &func_00389BD8 (void) {
  if ((*(void **) D_00786748) == 0) {
    func_0038A7E0 ();
    func_0038A340 ();
    __rtti_class (D_00786748, D_0045D1D7 + 1, D_0045D1E8, 2);
  }
  return *(const type_info *) D_00786748;
}
