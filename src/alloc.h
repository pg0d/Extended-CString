#ifndef XS_ALLOC_H
#define XS_ALLOC_H

#include "common.h"

void *xs_malloc(size_t size);
void *xs_realloc(void *ptr, size_t size);

#endif