/* cygnus-2.96 matched TU. */

typedef signed char Sint8;
typedef unsigned char Uint8;
typedef short Sint16;
typedef unsigned short Uint16;
typedef int Sint32;
typedef unsigned int Uint32;

typedef struct {
    Sint32 mode;
    Sint32 size;
    Sint32 rsv1;
    Sint32 rsv2;
    Sint32 rsv3;
    Sint32 nstm;
} MWSFCRE_PRM;

__attribute__((section(".text.mwsfcre_CalcWorkStmBuf")))
void mwsfcre_CalcWorkStmBuf(MWSFCRE_PRM *prm, Sint32 *sbuf, Sint32 *abuf,
                            Sint32 *vbuf, Sint32 *wk1, Sint32 *wk2, Sint32 *wk3)
{
    Sint32 nstm;
    Sint32 size;

    nstm = prm->nstm;
    size = prm->size;
    if (nstm <= 0) nstm = 1;
    if (prm->mode == 2) {
        Sint32 nsct = size / 16384;
        *sbuf = nsct * nstm * 2048;
        *abuf = 0;
        *vbuf = 0;
        *wk1 = 0;
        *wk2 = 0;
        *wk3 = 0;
    } else if (prm->mode == 3) {
        Sint32 nsct2 = size / 16384;
        *sbuf = nsct2 * nstm * 2048;
        *abuf = 0;
        *vbuf = nsct2 * 1024 + 2048;
        *wk1 = 0;
        *wk2 = 0;
        *wk3 = 0;
    } else {
        Sint32 nsct3 = size / 16384;
        *sbuf = nsct3 * nstm * 2048;
        *abuf = 0;
        *vbuf = nsct3 * 1024 + 2048;
        *wk1 = 24012;
        *wk2 = 24332;
        *wk3 = 33216;
    }
}
