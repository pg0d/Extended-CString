#include <stdio.h>
#include <stdlib.h>
#include "alloc.h"
#include "common.h"

void *xs_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (ptr == NULL)
    {
        printf("=> cannot allocation memory\n");
        exit(1);
    }

    return ptr;
}

void *xs_realloc(void *ptr, size_t size)
{
    void *new_ptr = realloc(ptr, size);
    if (new_ptr == NULL)
    {
        printf("=> cannot reallocate memory\n");
        exit(1);
    }

    return new_ptr;
}