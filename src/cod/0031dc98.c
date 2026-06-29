/* ee-2.9-991111 matched TU. */

__attribute__((section(".text.__floatdidf")))
double
__floatdidf (long long u)
{
  double d;

  d = (int) (u >> 32);
  d *= (((unsigned long long) 1) << 16);
  d *= (((unsigned long long) 1) << 16);
  d += (unsigned int) (u & ((((unsigned long long) 1) << 32) - 1));

  return d;
}
