#include "common.h"

void colored(FILE* stream, u32 color, const char* format, ...) {
    va_list args;
    va_start(args, format);
    if (isatty(fileno(stream))) {
        fprintf(stream, "\033[%dm", color);
        vfprintf(stream, format, args);
        fprintf(stream, "\033[0m");
    } else {
        vfprintf(stream, format, args);
    }
    fprintf(stream, "\n");
    va_end(args);
}

int str_eq(const char* const left, const char* const right) {
    return strcmp(left, right) == 0;
}