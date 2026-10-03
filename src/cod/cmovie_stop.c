#include "godhand/cMovie.h"

/* cMovie_Stop — stop the active movie: if the player object exists
 * (func_002B4F98), tear it down (func_002D42E0), then clear the playing flags
 * (bit 0x2000) in the movie-system state D_00747A84.  sn-2.95.3-136. */

extern cMovieTrack *func_002B4F98(void);
extern void func_002D42E0(cMovieTrack *track);
extern int D_00747A84;

/* Stop the active track, then clear the "movie playing" bit. */
__attribute__((section(".text.cMovie_Stop")))
void cMovie_Stop(void) {
    cMovieTrack *track = func_002B4F98();
    if (track)
        func_002D42E0(track);
    D_00747A84 &= ~MOVIE_SYS_PLAYING;
}
