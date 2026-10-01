/* include/godhand/cMessage.h - cMessage, the message window manager.
 *
 * The manager keeps a singly linked list of open windows at 0x10. A window
 * starts with its work id (the handle callers hold) and links to the next
 * at 0x08. cMessage_create returns the new window's work id, or
 * CMESSAGE_NONE when no window could be made.
 * Offsets are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_CMESSAGE_H
#define GODHAND_CMESSAGE_H

#define CMESSAGE_NONE  0xFFFF

typedef struct cMessageWin {
    unsigned short workId;      /* 0x00 handle returned by create */
    char unk02[6];
    struct cMessageWin *next;   /* 0x08 */
} cMessageWin;

typedef struct cMessage {
    char unk00[0x10];
    cMessageWin *head;          /* 0x10 open windows */
} cMessage;

#endif
