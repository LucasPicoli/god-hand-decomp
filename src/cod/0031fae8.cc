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

struct __user_type_info : public type_info {
  __user_type_info (const char *n) : type_info (n) {}
  virtual void* dcast (const type_info &, int, void *,
		       const type_info * = 0, void * = 0) const;
};

extern "C" void *__dynamic_cast (const type_info& (*from)(void), const type_info& (*to)(void),
		int require_public, void *address,
		const type_info & (*sub)(void), void *subptr)
  __attribute__((section(".text.__dynamic_cast")));

extern "C" void *
__dynamic_cast (const type_info& (*from)(void), const type_info& (*to)(void),
		int require_public, void *address,
		const type_info & (*sub)(void), void *subptr)
{
  return static_cast <const __user_type_info &> (from ()).dcast
    (to (), require_public, address, &(sub ()), subptr);
}
