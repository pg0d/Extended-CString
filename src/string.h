#ifndef EXT_STRING_H
#define EXT_STRING_H

#include <stdbool.h>
#include "common.h"
#include "namespace.h"

typedef struct xs
{
    size_t len;
    char *buf;
} *xs;

xs xs_raw_str(const char *buf);
xs xs_raw_with_len(const char *bstr, size_t size);
xs xs_empty(void);
bool xs_is_empty(xs s);


void xs_push_str(xs s, const char *str);
void xs_change_case(xs s, CaseMethod method);
void xs_free_mem(xs s);
char xs_pop(xs s);

#endif
