/* cygnus-2.96 matched TU. */

__attribute__((section(".text.mwsfcre_IsPlayAudio")))
int mwsfcre_IsPlayAudio(unsigned int a0) {
    switch (a0) {
    case 2:
    case 3:
        return 0;
    case 0:
    case 1:
    case 4:
    case 5:
    default:
        return 1;
    }
}
