#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "asm.hpp"

const int NUMBER_OF_COMMANDS = 8;
const char *commands[] = {"hlt", "push", "pop", "add", "sub", "mul", "div", "out"};
const int numbers[] = {HLT, PUSH, POP, ADD, SUB, MUL, DIV, OUT};

void assembly( const char *file_in, const char *file_out )
{
    FILE *In = fopen(file_in, "r");
    FILE  *Out = fopen(file_out, "w");

    char str[5] = {};

    while (fscanf(In, "%s", str) != EOF)
    {
        if (!strcmp(str, "push"))
        {
            int value = 0;

            if (!fscanf(In, "%d", &value))
                printf("ooo");
            else
                fprintf(Out, "%c %d\n", PUSH + '0', value);
        }

        else
        {
            if (!strcmp(str, "pop") && is_input_correct(In, str))
                fprintf(Out, "%c\n", POP + '0');
            if (!strcmp(str, "add") && is_input_correct(In, str))
                fprintf(Out, "%c\n", ADD + '0');
            if (!strcmp(str, "sub") && is_input_correct(In, str))
                fprintf(Out, "%c\n", SUB + '0');
            if (!strcmp(str, "mul") && is_input_correct(In, str))
                fprintf(Out, "%c\n", MUL + '0');
            if (!strcmp(str, "div") && is_input_correct(In, str))
                fprintf(Out, "%c\n", DIV + '0');
            if (!strcmp(str, "out") && is_input_correct(In, str))
                fprintf(Out, "%c\n", OUT + '0');
            if (!strcmp(str, "hlt") && is_input_correct(In, str))
                fprintf(Out, "%c\n", HLT + '0');
        }
    }
}

char *is_input_correct( FILE *file, char *str )
{
    char *res = NULL;

    fscanf(file, "%s", str);

    for (int i = 0; i < NUMBER_OF_COMMANDS; i++)
        if (!strcmp(str, commands[i]))
        {
            res = (char *)calloc(5, sizeof(char));
            strcpy(res, str);
            break;
        }

    return res;
}
