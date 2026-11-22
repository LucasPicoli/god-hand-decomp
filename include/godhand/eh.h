/* include/godhand/eh.h - libgcc exception handling: exception.cc's hooks and
 * libgcc2.c's per-thread eh_context. */
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

/* libgcc2.c's per-thread eh_context. eh_context_static clears 0x10 bytes. */
struct eh_context {
    void *handler_label;                /* 0x0 */
    void **dynamic_handler_chain;       /* 0x4 */
    cp_eh_info *info;                   /* 0x8 */
    void *table_index;                  /* 0xC */
};

typedef char eh_context_size_check[(sizeof(struct eh_context) == 0x10) ? 1 : -1];

/* Returns the thread's context. Starts as eh_context_initialize, which
 * installs eh_context_static here. */
extern struct eh_context *(*get_eh_context)(void);

/* Installs eh_context_static in get_eh_context and returns its context. */
struct eh_context *eh_context_initialize(void);

/* The one context, set up on the first call. */
struct eh_context *eh_context_static(void);

/* The current thread's context. */
struct eh_context *__get_eh_context(void);

/* The address of the current thread's exception info. */
cp_eh_info **__get_eh_info(void);

/* The address of the current thread's dynamic handler chain. */
void ***__get_dynamic_handler_chain(void);

/* Call the installed terminate handler (__terminate_func); never returns. */
void terminate(void) __attribute__((noreturn));
#endif

extern eh_handler D_003C4908;           /* __terminate_func */
extern eh_handler D_003C4F00;           /* __unexpected_func */

extern struct eh_context D_00755BF8; /* the context */

#endif
