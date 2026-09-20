/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 cc1plus — gcc-2.95.2 gcc/cp/exception.cc, verbatim.
   __cp_exception_info, retail 0x00321240, 36 B.  NOT A FUNCTION HEAD in the
   atlas today: splat merges it into the tail of `unexpected`. */
typedef unsigned short __u16;

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

extern "C" void *__cp_exception_info (void)
    __attribute__((section(".text.__cp_exception_info")));

extern "C" void *
__cp_exception_info (void)
{
  return &((*func_00320360 ())->value);
}
