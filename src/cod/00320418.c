/* sn-2.95.3-136 matched TU. */

extern void *(*D_003C490C)(void);

__attribute__((section(".text.func_00320418")))
void ***func_00320418(void)
{
  char *eh = (char *)(*D_003C490C)();
  return (void ***)(eh + 4);
}
