extern int func_003A5148(int, int, int);

__attribute__((section(".text.sfmpv_CopyPicUsrInf")))
void sfmpv_CopyPicUsrInf(int *destination, int *source)
{
    func_003A5148(destination[0], source[0], source[1]);
    destination[1] = source[1];
}
