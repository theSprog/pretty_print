#include "common.h"

int str_eq(const char* const left, const char* const right) {
    return strcmp(left, right) == 0;
}

#ifndef INNER_P_COLOR_STR
#define INNER_P_COLOR_STR(stream, color, format) \
    va_list args;                                \
    va_start(args, format);                      \
    if (isatty(fileno(stream))) {                \
        fprintf(stream, "\033[%dm", color);      \
        vfprintf(stream, format, args);          \
        fprintf(stream, "\033[0m");              \
    } else {                                     \
        vfprintf(stream, format, args);          \
    }                                            \
    fprintf(stream, "\n");                       \
    va_end(args);
#endif

// 通用颜色打印
void p_colored(FILE* stream, u32 color, const char* format, ...) {
    INNER_P_COLOR_STR(stream, color, format);
}

void p_blue(const char* format, ...) {
    INNER_P_COLOR_STR(stdout, COLOR_BLUE, format);
}

void p_red(const char* format, ...) {
    INNER_P_COLOR_STR(stdout, COLOR_RED, format);
}

void p_green(const char* format, ...) {
    INNER_P_COLOR_STR(stdout, COLOR_GREEN, format);
}

void p_yellow(const char* format, ...) {
    INNER_P_COLOR_STR(stdout, COLOR_YELLOW, format);
}

void p_cyan(const char* format, ...) {
    INNER_P_COLOR_STR(stdout, COLOR_CYAN, format);
}

void p_magenta(const char* format, ...) {
    INNER_P_COLOR_STR(stdout, COLOR_MAGENTA, format);
}

void* kmalloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        ERROR("Failed to allocate memory: %s", strerror(errno));
        exit(1);
    }
    memset(ptr, 0, size);
    return ptr;
}

int kopen(const char* filename, int flags, ...) {
    mode_t mode = 0;
    if ((flags & O_CREAT) != 0) {
        va_list args;
        va_start(args, flags);
        mode = va_arg(args, mode_t);
        va_end(args);
    }

    int fd = open(filename, flags, mode);
    if (fd == -1) {
        ERROR("Failed to open file \"%s\": %s", filename, strerror(errno));
        exit(1);
    }
    return fd;
}

FILE* kfopen(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        ERROR("Error: Failed to open file \"%s\" : %s", filename,
              strerror(errno));
        exit(EXIT_FAILURE);  // 或者根据需要执行其他错误处理操作
    }
    return file;
}