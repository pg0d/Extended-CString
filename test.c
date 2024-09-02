#include <stdio.h>
#include "src/string.h"

int main()
{

    xs sample = xt.from("as");
    // printf("str %s\n", sample->buf);
    // printf("len %ld\n", sample->len);

    // xt.change_case(sample, CASE_UPPER);
    
    // printf("str %s\n", sample->buf);
    // printf("%d \n", xt.is_empty(sample));

    while (!xt.is_empty(sample))
        printf("%c \n", xt.pop(sample));
        
    xt.free(sample);
    return 0;
}
