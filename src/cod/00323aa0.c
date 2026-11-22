/* cygnus-2.96: func_00323AA0, destroys a 0x44-byte stream handle: stops a playing stream, releases the
 * attached stream object and clears the handle, with trace callbacks before and after. */
typedef struct {
    signed char used; /* 0x00 */
    signed char stat; /* 0x01 */
    char pad2[2];
    void *stm; /* 0x04 */
} StmHandle;
extern void adxf_SetCmdHstry(int kind, int phase, void *hn, int a, int b);
extern int OpenStreamHandle(StmHandle *hn);
extern void ADXSTM_ReleaseFile(void *stm);
extern void ADXSTM_Destroy(void *stm);
extern void *func_003A52F0(void *d, int c, unsigned int n);

__attribute__((section(".text.func_00323AA0")))
void func_00323AA0(StmHandle *hn)
{
    void *stm;

    adxf_SetCmdHstry(3, 0, hn, -1, -1);
    if (hn == 0)
        return;
    if (hn->stat == 2)
        OpenStreamHandle(hn);
    stm = hn->stm;
    if (stm != 0) {
        hn->used = 0;
        hn->stm = 0;
        ADXSTM_ReleaseFile(stm);
        ADXSTM_Destroy(stm);
    }
    func_003A52F0(hn, 0, 0x44);
    adxf_SetCmdHstry(3, 1, hn, -1, -1);
}
