/* sn-2.95.3-136: strncasecmp, newlib strncasecmp (func_003AD0F8 is tolower). */
extern int func_003AD0F8(int c);

__attribute__((section(".text.strncasecmp")))
int strncasecmp(const char *s1, const char *s2, unsigned int n)
{
    if (n == 0)
        return 0;
    while (n-- != 0 && func_003AD0F8(*s1) == func_003AD0F8(*s2)) {
        if (n == 0 || *s1 == '\0' || *s2 == '\0')
            break;
        s1++;
        s2++;
    }
    return func_003AD0F8(*(unsigned char *)s1) - func_003AD0F8(*(unsigned char *)s2);
}
