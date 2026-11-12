/* cygnus-2.96 matched TU. */

#define CLOCK_90MHZ 90000000    /* 0x55D4A80 */

/* Sftim_toClock90M: scale a count to the 90 MHz clock, count * 90000000 / rate, in 64 bits. */
__attribute__((section(".text.Sftim_toClock90M")))
long long Sftim_toClock90M(int count, int rate) {
    return (long long)count * CLOCK_90MHZ / rate;
}
