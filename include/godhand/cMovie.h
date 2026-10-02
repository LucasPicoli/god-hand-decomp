/* include/godhand/cMovie.h - the movie player front end.
 *
 * cMovie drives the full motion video. The movie object holds a pointer to
 * a table of MOVIE_TRACK_NUM tracks (0xAC bytes each) and, per track, the
 * handle of the stream player that func_002D3BA8 set up. Starting a movie
 * takes a free track, picks the clip description (D_005E7BF0, or D_005E7D10
 * when D_00747A0C is set), queues it, and sets the "movie playing" bit
 * (0x2000) in the system state word D_00747A84. Stopping clears that bit.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CMOVIE_H
#define GODHAND_CMOVIE_H

#define MOVIE_TRACK_NUM    3
#define MOVIE_SYS_PLAYING  0x2000       /* bit of D_00747A84 */

typedef struct cMovieTrack {
    int handle;                         /* 0x00 stream player, 0 while the track is free */
    char unk04[0xA8];
} cMovieTrack;                          /* 0xAC */

typedef struct cMovie {
    cMovieTrack *track;                 /* 0x00 MOVIE_TRACK_NUM entries */
    int player[MOVIE_TRACK_NUM];        /* 0x04 */
    char unk10[8];
    unsigned int busyMask;              /* 0x18 bit n set while track n plays a flagged clip */
} cMovie;

/* One clip description in the tables D_005E7BF0 (normal) and D_005E7D10
 * (when D_00747A0C is set), 0x30 bytes each. */
#define MOVIE_CLIP_LOCK_PAD  0x20       /* flags: hold the pad while the clip plays */

typedef struct cMovieClip {
    char unk00[0x2C];
    unsigned int flags;                 /* 0x2C */
} cMovieClip;                           /* 0x30 */

typedef char cMovieTrack_size_check[(sizeof(cMovieTrack) == 0xAC) ? 1 : -1];

#endif
