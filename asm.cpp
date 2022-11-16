#include <stdio.h>
#include <string.h>

#include "asm.hpp"

const char *commands[] = {"hlt", "pop", "push", "add", "sub", "mul", "div", "out"};

void assembly( const char *file_1, const char *file_2 )
{
    FILE *In = fopen(file_1, "r");
    FILE  *Out = fopen(file_2, "w");

    char str[5] = {};

    while (fscanf(In, "%s", str) != EOF)
    {
        for (int i = 0; i < 8; i++)
            if (!strcmp(str, commands[i]))
            {
                int value = 0;

                if (!fscanf(In, "%d", &value))
                    printf("ooo");
                else
                    fprintf(Out, "%c %d\n", i + '0', value);
            }
    }
}
