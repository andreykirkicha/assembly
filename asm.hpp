#ifndef ASM_HPP
#define ASM_HPP

enum COMMANDS {
    HLT, PUSH, POP, ADD, SUB, MUL, DIV, OUT
};

void assembly( const char *file_in, const char *file_out, const char *log_file_name );
char *is_input_correct( FILE *file, char *str );

#endif
