#include <stdio.h>

#include "string.h"




int main() {


    struct string_t str = string_create(0);


    string_move(&str, "Hello", -1);

    printf("%s\n", str.bytes);

    free_string(&str);
    return 0;
}


