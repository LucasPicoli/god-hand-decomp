/* sn-2.95.3-136 matched TU. */

typedef struct { int base; int count; } Range;
__attribute__((section(".text.SJ_SplitChunk")))
void SJ_SplitChunk(Range *a0, int a1, Range *a2, Range *a3){
    int c; int n;
    *a2 = *a0;
    a3->count = a2->count;
    c = a2->count;
    if (a1 < c) { a2->count = a1; c = a1; }
    a3->count -= c;
    if (a3->count == 0) { a3->base = 0; } else {
        n = a2->count; a3->base = a2->base + n;
    }
}
