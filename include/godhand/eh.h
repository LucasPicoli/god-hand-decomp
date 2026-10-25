/* include/godhand/eh.h - libgcc exception handler hooks (exception.cc, ee-2.9-991111). */
#ifndef GODHAND_EH_H
#define GODHAND_EH_H

typedef void (*eh_handler)(void) __attribute__((noreturn));

/* libgcc's language-neutral exception info (eh-common.h). */
typedef void *(*__eh_matcher)(void *, void *, void *);

typedef struct __eh_info {
    __eh_matcher match_function;
    short language;
    short version;
} __eh_info;

#ifndef __cplusplus
/* C view of exception.cc's cp_eh_info (defined there for C++); bool is a word on this target. */
typedef struct cp_eh_info {
    __eh_info eh_info;
    void *value;
    void *type;
    void (*cleanup)(void *, int);
    int caught;                         /* 0x14 */
    struct cp_eh_info *next;
    long handlers;
    void *original_value;
} cp_eh_info;
#endif

extern eh_handler D_003C4908;           /* __terminate_func */
extern eh_handler D_003C4F00;           /* __unexpected_func */

#endif
