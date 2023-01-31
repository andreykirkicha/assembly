#ifndef ERRORS_HPP
#define ERRORS_HPP

enum ERORRS {
    OK, INCORRECT_INPUT
};

void error_handler( const char *log_file_name, int error, int string_number );

#endif