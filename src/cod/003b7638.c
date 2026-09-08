/* ee-2.9-991111 matched TU. */

__attribute__((section(".text.TimerUSec2BusClock")))
unsigned long long TimerUSec2BusClock(unsigned int sec, unsigned int usec) {
    return (unsigned long long)sec * 147456000u
         + (unsigned long long)usec * 147456000u / 1000000u;
}
