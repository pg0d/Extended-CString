#include <stdio.h>
#include "src/string.h"

int main()
{

    xs sample = xt.from("hello world");
    // printf("str %s\n", sample->buf);
    // printf("len %ld\n", sample->len);

    // xt.change_case(sample, CASE_UPPER);
    
    // printf("str %s\n", sample->buf);
    // printf("%d \n", xt.is_empty(sample));

    while (!xt.is_empty(sample))
        printf("%c \n", xt.pop(sample));

    printf("\n");

    size_t idx = xt.get_index(sample, "w");
    while (sample->buf[++idx] != '\0')
        printf("%c", sample->buf[idx]);
    
    printf("\n");
    xt.free(sample);
    return 0;
}
