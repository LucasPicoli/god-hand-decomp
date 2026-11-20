/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 cc1plus — gcc-2.95.2 gcc/cp/exception.cc, verbatim.
   __cp_exception_info, retail 0x00321240, 36 B; __cplus_type_matcher,
   __cp_push_exception and __cp_pop_exception follow at 0x00321308.  NOT A FUNCTION HEAD in the
   atlas today: splat merges it into the tail of `unexpected`. */
#include "godhand/eh.h"

typedef unsigned short __u16;


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

struct exception_lang_info
{
  char unk00[4];
  short language;
};

typedef void (*cleanup_fn)(void *, int);

#define EH_LANG_C_PLUS_PLUS 4
#define CATCH_ALL_TYPE ((void *) -1)

extern "C" cp_eh_info **__get_eh_info ();
extern "C" void *func_003212C0 (unsigned int);	/* __eh_alloc */
extern "C" void Tramp_UpdateGlobalPtrWithParam_3A7CC0_3212E8 (void *);	/* __eh_free */
extern "C" void *func_0031F508 (void *, void *, void *);	/* __throw_type_match_rtti */
extern "C" int func_0031F9D0 (void *);	/* __is_pointer */
extern void terminate (void) __attribute__ ((__noreturn__));

extern "C" void *__cp_exception_info (void)
    __attribute__((section(".text.__cp_exception_info")));

extern "C" void *
__cp_exception_info (void)
{
  return &((*__get_eh_info ())->value);
}

extern "C" void *__cplus_type_matcher (__eh_info *, void *, exception_lang_info *)
    __attribute__((section(".text.__cplus_type_matcher")));
extern "C" void __cp_push_exception (void *, void *, cleanup_fn)
    __attribute__((section(".text.__cp_push_exception")));
extern "C" void __cp_pop_exception (cp_eh_info *)
    __attribute__((section(".text.__cp_pop_exception")));

extern "C" void *
__cplus_type_matcher (__eh_info *info_, void *match_info,
                      exception_lang_info *exception_table)
{
  cp_eh_info *info = (cp_eh_info *) info_;

  if (exception_table != 0
      && exception_table->language != EH_LANG_C_PLUS_PLUS)
    return 0;

  if (match_info == CATCH_ALL_TYPE)
    return info->value;

  void *match_type = ((void *(*)()) match_info) ();
  void *ret = func_0031F508 (match_type, info->type, info->original_value);
  if (ret)
    info->value = ret;

  return ret;
}

extern "C" void
__cp_push_exception (void *value, void *type, void (*cleanup) (void *, int))
{
  cp_eh_info *p = (cp_eh_info *) func_003212C0 (sizeof (cp_eh_info));

  p->value = value;
  p->type = type;
  p->cleanup = cleanup;
  p->handlers = 0;
  p->caught = false;
  p->original_value = value;

  p->eh_info.match_function = (__eh_matcher) __cplus_type_matcher;
  p->eh_info.language = EH_LANG_C_PLUS_PLUS;
  p->eh_info.version = 1;

  cp_eh_info **q = __get_eh_info ();

  p->next = *q;
  *q = p;
}

extern "C" void
__cp_pop_exception (cp_eh_info *p)
{
  cp_eh_info **stack = __get_eh_info ();
  cp_eh_info **q = stack;

  --p->handlers;

  if (p->handlers != 0 || (p == *q && !p->caught))
    return;

  for (; *q; q = &(*q)->next)
    if (*q == p)
      break;

  if (! *q)
    terminate ();

  *q = p->next;

  if (p->cleanup)
    p->cleanup (p->value, 2);

  if (! func_0031F9D0 (p->type))
    Tramp_UpdateGlobalPtrWithParam_3A7CC0_3212E8 (p->original_value);

  Tramp_UpdateGlobalPtrWithParam_3A7CC0_3212E8 (p);
}
