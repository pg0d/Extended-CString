#ifndef XS_NAMESPACE_H
#define XS_NAMESPACE_H

#include "common.h"

typedef struct xs *xs;

typedef struct {
    void    (*tolower)(xs s);
    void    (*toupper)(xs s);
    void    (*free)(xs s);
    void    (*push_str)(xs s, const char *str);
    xs      (*from)(const char *buf);
} xs_ops;

extern const xs_ops xt;

#endif