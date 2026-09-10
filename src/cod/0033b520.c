/* cygnus-2.96 matched TU. */

struct SJX { signed char f0; char pad[0xF]; int f10; };
extern int DTX_CallUrpc(int cmd, void *in, int nin, void *out, int nout);

__attribute__((section(".text.SJX_Destroy")))
void SJX_Destroy(struct SJX *p)
{
    int buf[1];
    buf[0] = p->f10;
    DTX_CallUrpc(1, buf, 1, 0, 0);
    p->f0 = 0;
}
