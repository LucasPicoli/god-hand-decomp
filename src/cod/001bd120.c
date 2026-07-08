/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.cOmDoor_setClose")))
void cOmDoor_setClose(int a0)
{
  int new_var;
  long v = *((unsigned int *) (((char *) a0) + 0x620));
  long b;
  unsigned char *new_var2;
  if ((v & 1) == 0)
  {
 do { } while (0);
    return;
  }
  b = (v >> (new_var = 1)) & new_var;
  new_var2 = (unsigned char *) (((char *) a0) + 0x2F7);
  if (b == new_var)
  {
    return;
  }
  if ((*((unsigned char *) (((char *) a0) + 0x2F4))) < 2)
  {
    *((unsigned char *) (((char *) a0) + 0x2F5)) = 2;
    *((int *) (((char *) a0) + 0x620)) &= ~new_var;
    *((unsigned char *) (((char *) a0) + 0x2F4)) = 0;
    *((unsigned char *) (((char *) a0) + 0x2F6)) = 0;
    *new_var2 = 0;
  }
}
