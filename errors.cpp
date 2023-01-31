#include <stdio.h>
#include <stdlib.h>

#include "errors.hpp"

void error_handler( const char *log_file_name, int error, int string_number )
{
    FILE *log_file = fopen(log_file_name, "w");

    switch(error)
    {
        case OK:
            fprintf(log_file, "SUCCESSFULLY COMPLETED\n");
            break;

        case INCORRECT_INPUT:
            fprintf(log_file, "COMMAND №%d >>> <error> INCORRECT INPUT\n", string_number);
            break;

        default:
            fprintf(log_file, "COMMAND №%d >>> <unknown error>\n", string_number);
            break;
    }

    fclose(log_file);
}
