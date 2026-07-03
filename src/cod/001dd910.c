/* sn-2.95.3-136 matched TU. */

extern void SetCustomIDDispOneOrAll_1DD258(void *a0, int a1, int a2);

__attribute__((section(".text.func_001DD910")))
void func_001DD910(void *a0, unsigned char a1) {
    switch (a1) {
    case 0:
        SetCustomIDDispOneOrAll_1DD258(a0, 9, 1);
        SetCustomIDDispOneOrAll_1DD258(a0, 10, 1);
        SetCustomIDDispOneOrAll_1DD258(a0, 11, 1);
        break;
    case 1:
        SetCustomIDDispOneOrAll_1DD258(a0, 9, 0);
        SetCustomIDDispOneOrAll_1DD258(a0, 10, 1);
        SetCustomIDDispOneOrAll_1DD258(a0, 11, 1);
        break;
    case 2:
        SetCustomIDDispOneOrAll_1DD258(a0, 9, 0);
        SetCustomIDDispOneOrAll_1DD258(a0, 10, 0);
        SetCustomIDDispOneOrAll_1DD258(a0, 11, 1);
        break;
    default:
        break;
    }
}
