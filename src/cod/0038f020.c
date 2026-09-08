/* ee-2.9-991111 matched TU. */

extern int _IO_file_close_it();

__attribute__((section(".text.close__7filebuf")))
void *close__7filebuf(void *a0)
{
  if (_IO_file_close_it(a0) == 0) return a0;
  return 0;
}
