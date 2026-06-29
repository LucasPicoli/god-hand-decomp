/* ee-2.9-991111 matched TU. */

extern long long __fixunsdfdi (double a);

__attribute__((section(".text.__fixunsdfdi")))
long long
__fixunsdfdi (double a)
{
  double b;
  unsigned long long v;

  if (a < 0)
    return 0;

  b = (a / (((unsigned long long) 1) << 32));
  v = (unsigned int) b;
  v <<= 32;
  a -= (double)v;
  if (a < 0)
    v -= (unsigned int) (- a);
  else
    v += (unsigned int) a;
  return v;
}

__attribute__((section(".text.__fixdfdi")))
long long
__fixdfdi (double a)
{
  if (a < 0)
    return - __fixunsdfdi (-a);
  return __fixunsdfdi (a);
}

__attribute__((section(".text.__fixunssfdi")))
long long
__fixunssfdi (float original_a)
{
  double a = original_a;
  double b;
  unsigned long long v;

  if (a < 0)
    return 0;

  b = (a / (((unsigned long long) 1) << 32));
  v = (unsigned int) b;
  v <<= 32;
  a -= (double)v;
  if (a < 0)
    v -= (unsigned int) (- a);
  else
    v += (unsigned int) a;
  return v;
}
