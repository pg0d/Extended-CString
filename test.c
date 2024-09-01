#include <stdio.h>
#include "src/string.h"

int main()
{
    
    xs sample = xt.from("hello world");
    printf("str %s\n", sample->buf);
    printf("len %ld\n", sample->len);

    xt.push_str(sample, " sample");
    printf("str %s\n", sample->buf);
    printf("len %ld\n", sample->len);

    xt.free(sample);
    return 0;
}
