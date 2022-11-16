#include <stdio.h>

#include "asm.hpp"

int main()
{
    const char *file_1 = "test.asm", *file_2 = "test.code";

    assembly(file_1, file_2);

    return 0;
}
