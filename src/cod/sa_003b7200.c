/* ee-2.9-991111 matched TU. */
typedef struct TimerCounter {
    struct TimerCounter *next;
    int reserved04;
    int id;
    int flags;
    long startTime;
    long elapsed;
    int reserved20[2];
    int callback;
} TimerCounter;
typedef struct TimerControl {
    int reserved00[3];
    int generation;
    int allocated;
    TimerCounter *freeList;
} TimerControl;
extern volatile TimerControl D_003FBE90;

/* Allocate a free timer counter and issue a generation-tagged identifier. */
__attribute__((section(".text.iAllocTimerCounter")))
int iAllocTimerCounter(void)
{
  volatile TimerCounter *timer;
  TimerCounter *next;
  int allocated;
  int generation;
  int addressBits;
  timer = D_003FBE90.freeList;
  if (timer == 0)
  {
    return 0x80008005;
  }
  allocated = D_003FBE90.allocated + 1;
  addressBits = ((int) timer) * 16;
  next = timer->next;
 do { } while (0);
  timer->callback = 0;
  D_003FBE90.allocated = allocated;
  timer->flags = 0;
  D_003FBE90.freeList = next;
  generation = D_003FBE90.generation + 1;
  timer->elapsed = 0;
  D_003FBE90.generation = generation;
  timer->id = ((D_003FBE90.generation * 2) & 0x3FE) | 1;
  return addressBits | timer->id;
}
