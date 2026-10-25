/* include/godhand/sndCmd.h - the sound driver's voice-parameter command queue. */
#ifndef GODHAND_SNDCMD_H
#define GODHAND_SNDCMD_H

/* Queue a voice-parameter command: with val 0 or -1 every channel is reset
 * (mask 0xF), otherwise the channels in mask get (prm, val); returns 0, or
 * -1 if the queue is full. */
int func_00387328(short id, short prm, short val, int mask);

/* func_00387328 for channel id, or for channels 0 and 1 when id is -1. */
int func_00387270(short id, short prm, short val, int mask);

#endif /* GODHAND_SNDCMD_H */
