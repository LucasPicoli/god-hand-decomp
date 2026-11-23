/* include/godhand/Sfd.h - Sofdec movie player records.
 *
 * A Sofdec handle keeps its track table at 0x1310, one 0x74-byte SfdTrack per
 * track number. A track that is set up has a nonzero `ready` word. Names are
 * ours; unnamed fields stay as unkNN padding.
 */
#ifndef GODHAND_SFD_H
#define GODHAND_SFD_H

#define SFD_ERR_TRACK_NOT_READY  0xFF000401  /* error raised for a track that is not set up */
#define SFD_TRIF_IDLE_CALL       0xB         /* track-interface call made on a track that is not set up */

/* The ring buffer part of a track, from 0x10: the SFBUF_* calls take its address
 * (SFBUF_AddRtotSj, SFBUF_GetWTot, SFBUF_SetUoch). */
typedef struct SfdBufCh {
    int unk00;                          /* 0x00 */
    void *obj;                          /* 0x04 the track's object */
    char unk08[0x24 - 0x08];
    int rtotSj;                         /* 0x24 bytes read, or negative when not counted */
    char unk28[0x3C - 0x28];
} SfdBufCh;
typedef char SfdBufCh_size_check[(sizeof(SfdBufCh) == 0x3C) ? 1 : -1];

typedef struct SfdTrack {
    int unk00;                          /* 0x00 */
    int ready;                          /* 0x04 nonzero once the track is set up */
    char unk08[0x10 - 0x08];
    SfdBufCh buf;                       /* 0x10 */
    int type;                           /* 0x4C track type, selects the track interface */
    char unk50[0x74 - 0x50];
} SfdTrack;
typedef char SfdTrack_size_check[(sizeof(SfdTrack) == 0x74) ? 1 : -1];

typedef struct SfdHandle {
    char unk0000[0x1310];
    SfdTrack track[1];                  /* 0x1310 indexed by track number */
} SfdHandle;

#endif
