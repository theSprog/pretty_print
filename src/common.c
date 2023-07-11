#include "common.h"

int str_eq(const char* const left, const char* const right) {
    return strcmp(left, right) == 0;
}

void p_colored(FILE* stream, u32 color, const char* format, ...) {
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

void p_red(const char* format, ...) {
    va_list args;
    va_start(args, format);
    p_colored(stdout, COLOR_RED, format, args);
    va_end(args);
}

void p_green(const char* format, ...) {
    va_list args;
    va_start(args, format);
    p_colored(stdout, COLOR_GREEN, format, args);
    va_end(args);
}

void p_yellow(const char* format, ...) {
    va_list args;
    va_start(args, format);
    p_colored(stdout, COLOR_YELLOW, format, args);
    va_end(args);
}

void p_blue(const char* format, ...) {
    va_list args;
    va_start(args, format);
    p_colored(stdout, COLOR_BLUE, format, args);
    va_end(args);
}

void p_cyan(const char* format, ...) {
    va_list args;
    va_start(args, format);
    p_colored(stdout, COLOR_CYAN, format, args);
    va_end(args);
}

void* kmalloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        ERROR("Failed to allocate memory.");
        exit(1);
    }
    return ptr;
}

int kopen(const char* filename, int flags, mode_t mode) {
    int fd = open(filename, flags, mode);
    if (fd == -1) {
        ERROR("Error opening file: %s", strerror(errno));
        exit(1);
    }
    return fd;
}
