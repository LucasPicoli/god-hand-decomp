/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_00321D38")))
int func_00321D38(char *p)
{
  int count = 0;
  int off = *((int *) p);
  if (off != 0)
  {
    int field4;
    for (;;)
    {
      char *cur;
      int nxt;
      if ((*((int *) (p + 4))) && (*((int *) (p + 8))))
      {
        count++;
      }
      cur = p + off;
      nxt = *((int *) (cur + 4));
      p = cur + 4;
      if (!nxt)
      {
        break;
      }
      field4 = *((int *) (p + 4));
      off = nxt;
    }

  }
  return count;
}
