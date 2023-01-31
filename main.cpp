#include <stdio.h>

#include "asm.hpp"
#include "errors.hpp"

int main()
{
    const char *file_in = "test.asm", *file_out = "test.code", *log_file = "asm.log";

    assembly(file_in, file_out, log_file);

    return 0;
}
