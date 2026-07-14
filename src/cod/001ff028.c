/* sn-2.95.3-136 matched TU. */

typedef struct cDataHolder {
    int f00;
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int arr[10];
    int f4C;
    int f50;
    int f54;
    int f58;
} cDataHolder;

__attribute__((section(".text.cDataHolder_systemInit")))
void cDataHolder_systemInit(cDataHolder *this) {
    int i;
    int v;

    this->f00 = 0;
    this->f04 = 0;
    this->f0C = -1;
    this->f10 = 0;
    this->f08 = 0;
    this->f1C = 0;
    this->f20 = 0xFFFF;
    this->f4C = 0xFFFF;
    this->f50 = 0xFFFF;
    this->f54 = 0xFFFF;
    this->f58 = 0xFFFF;
    this->f18 = 0;

    v = -1;
    for (i = 9; i >= 0; i--) {
        this->arr[i] = v;
    }

    this->f14 = 0;
}
