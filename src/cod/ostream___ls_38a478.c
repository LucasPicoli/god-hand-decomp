/* __ls__7ostreamPFR7ostream_R7ostream — ostream::operator<<(manipulator): invoke the manipulator
 * a1 on the stream a0 and return its result.  sn-2.95.3-136. */

__attribute__((section(".text.__ls__7ostreamPFR7ostream_R7ostream")))
void *__ls__7ostreamPFR7ostream_R7ostream(void *a0, void *(*a1)(void *)) {
    void *r = a1(a0);
    return r;
}
