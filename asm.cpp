#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "asm.hpp"
#include "errors.hpp"

const int NUMBER_OF_COMMANDS = 8;
const char *commands[] = {"hlt;", "push", "pop;", "add;", "sub;", "mul;", "div;", "out;"};
const int numbers[] = {HLT, PUSH, POP, ADD, SUB, MUL, DIV, OUT};

void assembly( const char *file_in, const char *file_out, const char *log_file_name )
{
    FILE *In = fopen(file_in, "r");
    FILE *Out = fopen(file_out, "w");

    char str[5] = {};
    int string_number = 1;

    while (fscanf(In, "%s", str) != EOF)
    {
        int error = OK;

        if (!strcmp(str, "push"))
        {
            int value = 0;

            if (fscanf(In, "%d", &value))
            {
                char sym = ' ';

                if ((sym = fgetc(In)) == ';')
                    fprintf(Out, "%c %d;\n", PUSH + '0', value);
                else
                    error = INCORRECT_INPUT;
            }
            else
                error = INCORRECT_INPUT;
        }

        else
        {
            if (!strcmp(str, "pop;"))
                fprintf(Out, "%c\n", POP + '0');
            else if (!strcmp(str, "add;"))
                fprintf(Out, "%c\n", ADD + '0');
            else if (!strcmp(str, "sub;"))
                fprintf(Out, "%c\n", SUB + '0');
            else if (!strcmp(str, "mul;"))
                fprintf(Out, "%c\n", MUL + '0');
            else if (!strcmp(str, "div;"))
                fprintf(Out, "%c\n", DIV + '0');
            else if (!strcmp(str, "out;"))
                fprintf(Out, "%c\n", OUT + '0');
            else if (!strcmp(str, "hlt;"))
                fprintf(Out, "%c\n", HLT + '0');
            else
                error = INCORRECT_INPUT;        
        }

        error_handler(log_file_name, error, string_number);
        if (error != OK)
            break;
        
        string_number++;
    }

    fclose(In);
    fclose(Out);
}
