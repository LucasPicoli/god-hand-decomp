/* sn-2.95.3-136: func_002B8B50, initialise the pair table, allocate 400 entries and switch on the fixed set of
 * (a, b) pairs over ids 1..8. */
extern void func_002BA1B0(void *self);
extern void arrayAlloc(void *self, int n);
extern void func_002B8D88(void *self, int on, int a, int b);

__attribute__((section(".text.func_002B8B50")))
void func_002B8B50(void *p)
{
    func_002BA1B0(p);
    arrayAlloc(p, 400);
    func_002B8D88(p, 1, 1, 4);
    func_002B8D88(p, 1, 1, 6);
    func_002B8D88(p, 1, 1, 8);
    func_002B8D88(p, 1, 2, 3);
    func_002B8D88(p, 1, 2, 5);
    func_002B8D88(p, 1, 2, 7);
    func_002B8D88(p, 1, 3, 2);
    func_002B8D88(p, 1, 3, 6);
    func_002B8D88(p, 1, 3, 8);
    func_002B8D88(p, 1, 4, 1);
    func_002B8D88(p, 1, 4, 5);
    func_002B8D88(p, 1, 4, 7);
    func_002B8D88(p, 1, 5, 2);
    func_002B8D88(p, 1, 5, 4);
    func_002B8D88(p, 1, 5, 8);
    func_002B8D88(p, 1, 6, 1);
    func_002B8D88(p, 1, 6, 3);
    func_002B8D88(p, 1, 6, 7);
    func_002B8D88(p, 1, 7, 2);
    func_002B8D88(p, 1, 7, 4);
    func_002B8D88(p, 1, 7, 6);
    func_002B8D88(p, 1, 7, 8);
    func_002B8D88(p, 1, 8, 1);
    func_002B8D88(p, 1, 8, 3);
    func_002B8D88(p, 1, 8, 5);
    func_002B8D88(p, 1, 8, 7);
}
