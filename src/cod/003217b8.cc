/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 cc1plus — gcc-2.95.2 gcc/cp/exception.cc, verbatim.
   std::uncaught_exception, retail 0x003217B8, 52 B.  NOT A FUNCTION HEAD in
   the atlas today: splat merges it into the tail of `__check_eh_spec`. */
struct __eh_info {
    void *match_function;
    short language;
    short version;
};

struct cp_eh_info
{
    __eh_info eh_info;
    void *value;
    void *type;
    void (*cleanup)(void *, int);
    bool caught;
    cp_eh_info *next;
    long handlers;
    void *original_value;
};

extern "C" cp_eh_info **func_00320360 ();	/* __get_eh_info */

#define CP_EH_INFO ((cp_eh_info *) *func_00320360 ())

namespace std {
    bool uncaught_exception ();
}

__attribute__((section(".text.uncaught_exception__Fv")))
bool
std::uncaught_exception ()
{
  cp_eh_info *p = CP_EH_INFO;
  return p && ! p->caught;
}
