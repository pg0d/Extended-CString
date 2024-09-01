#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "alloc.h"
#include "namespace.h"

xs xs_raw_with_len(const char *bstr, size_t len)
{
    char *buf = xs_malloc(sizeof(*buf) * len + 1);
    if (buf == NULL)
    {
        return NULL;
    }

    memcpy(buf, bstr, len);
    buf[len] = '\0';

    xs s = xs_malloc(sizeof(struct xs));
    if (s == NULL)
    {
        free(buf);
        return NULL;
    }

    s->buf = buf;
    s->len = len;

    return s;
}

xs xs_raw_str(const char *bstr)
{
    if (bstr == NULL)
        return xs_empty();

    size_t len = strlen(bstr);
    return xs_raw_with_len(bstr, len);
}

xs xs_empty(void)
{
    return xs_raw_with_len("", 0);
}

void xs_to_lower(xs s)
{
    char *ptr = s->buf;
    size_t len = s->len, i = 0;

    while (i < len)
    {
        *ptr = tolower(*ptr);
        ++ptr;
        ++i;
    }
}

void xs_to_upper(xs s)
{
    char *ptr = s->buf;
    size_t len = s->len, i = 0;

    while (i < len)
    {
        *ptr = toupper(*ptr);
        ++ptr;
        ++i;
    }
}

void xs_free_mem(xs s)
{
    free(s->buf);
    free(s);
}

void xs_push_str(xs s, const char *str)
{
    size_t new_len = s->len + strlen(str);
    s->buf = xs_realloc(s->buf, new_len + 1);
    if (s->buf == NULL)
    {
        return;
    }

    strcat(s->buf, str);
    s->len = new_len;
}

const xs_ops xt = {
    .tolower    = xs_to_lower,
    .toupper    = xs_to_upper,
    .from       = xs_raw_str,
    .free       = xs_free_mem,
    .push_str   = xs_push_str,
};