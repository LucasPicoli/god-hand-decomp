/* ee-2.9-991111 matched TU. */

#pragma interface
/* gcc-2.95.2 gcc/cp/tinfo2.cc, the BUILTIN(f) macro (lines 288-300).
   ee-2.9-991111.  `#pragma interface` keeps the vtable extern, so this TU
   references _vt$19__builtin_type_info instead of emitting its own copy. */

class type_info {
private:
  type_info& operator= (const type_info&);
  type_info (const type_info&);
protected:
  explicit type_info (const char *n): _name (n) { }
  const char *_name;
public:
  virtual ~type_info ();
  bool before (const type_info& arg) const;
  const char* name () const { return _name; }
  bool operator== (const type_info& arg) const;
  bool operator!= (const type_info& arg) const;
};

struct __builtin_type_info : public type_info {
  __builtin_type_info (const char *n): type_info (n) {}
};

/* the default placement form from gcc/cp/inc/new.  `throw()` is load-bearing:
   gcc/cp/init.c:2315 sets check_new from TYPE_NOTHROW_P, and that null check
   is retail's `beqz $a1`. */
inline void *operator new (unsigned int, void *place) throw() { return place; }

extern unsigned char D_003C4458[8];          /* __tif */
extern const char D_00451120[];              /* "f" */

extern "C" const type_info &func_0031FDC8 (void)
  __attribute__((section(".text.func_0031FDC8")));

extern "C" const type_info &func_0031FDC8 (void) {
  if ((*(void **) D_003C4458) == 0)
    new (D_003C4458) __builtin_type_info (D_00451120);
  return *(type_info *)D_003C4458;
}

