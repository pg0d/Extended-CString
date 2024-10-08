#ifndef XS_NAMESPACE_H
#define XS_NAMESPACE_H

#include "common.h"
#include "string.h"

typedef struct xs *xs;

typedef enum CaseMethod {
    CASE_UPPER = 0,
    CASE_LOWER = 1
} CaseMethod;

typedef struct {
    void    (*change_case)(xs s, CaseMethod method);
    void    (*free)(xs s);
    void    (*push_str)(xs s, const char *str);
    xs      (*from)(const char *buf);
    bool    (*is_empty)(xs s);
    char    (*pop)(xs s);
    size_t  (*get_index)(xs haystack, const char *needle);
} xs_ops;

extern const xs_ops xt;

#endif