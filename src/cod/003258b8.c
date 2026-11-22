/* ADX server thread stop: keep requesting a stop (raise the request flag, bump and wake the thread)
 * until the thread acknowledges, then clear the flags and the thread id. One copy per server. */
#include "godhand/adxm.h"
#include "godhand/adxmThread.h"
#include "godhand/eeKernel.h"

extern int WakeupThread(int thid);

#define ADX_STOP_THREAD(name, ack, req, thread)                 \
    __attribute__((section(".text." #name)))                    \
    void name(void)                                             \
    {                                                           \
        while ((ack) == 0) {                                    \
            (req) = 1;                                          \
            ChangeThreadPriority((thread), 1);                  \
            WakeupThread((thread));                             \
            adxm_ResumeThread((thread));                        \
        }                                                       \
        (ack) = 0;                                              \
        (req) = 0;                                              \
        (thread) = 0;                                           \
    }

ADX_STOP_THREAD(func_003258B8, D_003C81A0, D_003C8198, D_003C814C)
ADX_STOP_THREAD(func_00325988, D_003C8180, D_003C8178, D_003C8140)
ADX_STOP_THREAD(func_00325B90, D_003C8160, D_003C8158, D_003C8138)
