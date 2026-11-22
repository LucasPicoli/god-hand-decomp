/* cygnus-2.96 matched TU. */

__attribute__((section(".text.sceMpegClearRefBuff")))
int sceMpegClearRefBuff(int **a0){
  int **p = (int **)a0[0x10];
  if (p[0x72]) ((int *)p[0x72])[0xA] = 0;
  if (p[0x76]) ((int *)p[0x76])[0xA] = 0;
  if (p[0x7A]) ((int *)p[0x7A])[0xA] = 0;
  if (p[0x73]) ((int *)p[0x73])[0xA] = 0;
  if (p[0x77]) ((int *)p[0x77])[0xA] = 0;
  if (p[0x7B]) ((int *)p[0x7B])[0xA] = 0;
  return 1;
}
