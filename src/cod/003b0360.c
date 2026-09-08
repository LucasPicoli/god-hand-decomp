/* ee-2.9-991111 matched TU. */

extern int *Obj0000_Get_D_003FA62C_3A4FB8(void);

__attribute__((section(".text.open")))
int open(char *name)
{
    *Obj0000_Get_D_003FA62C_3A4FB8() = 5;
    return -1;
}
