#ifndef COMMON_H
#define COMMON_H

// // 默认是 debug 的, define NDEBUG 则关闭 debug 模式
// #define NDEBUG

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef size_t usize;

typedef float f32;
typedef double f64;

#define TRUE 1
#define FALSE 0

#define COLOR_BLACK 30
#define COLOR_RED 31
#define COLOR_GREEN 32
#define COLOR_YELLOW 33
#define COLOR_BLUE 34
#define COLOR_MAGENTA 35
#define COLOR_CYAN 36
#define COLOR_WHITE 37

void colored(FILE* stream, u32 color, const char* format, ...);
int str_eq(const char* const left, const char* const right);

// 使用 ##__VA_ARGS__ 提示编译器把末尾的多于 ',' 删除, 以防止编译报错
#define ERROR(format, ...)                                           \
    do {                                                             \
        colored(stderr, COLOR_RED, "[ERROR]" format, ##__VA_ARGS__); \
    } while (0)

#define WARN(format, ...)                                               \
    do {                                                                \
        colored(stderr, COLOR_YELLOW, "[ WARN]" format, ##__VA_ARGS__); \
    } while (0)

#define INFO(format, ...)                                             \
    do {                                                              \
        colored(stdout, COLOR_CYAN, "[ INFO]" format, ##__VA_ARGS__); \
    } while (0)

#define DEBUG(format, ...)                                             \
    do {                                                               \
        colored(stdout, COLOR_GREEN, "[DEBUG]" format, ##__VA_ARGS__); \
    } while (0)

#define TRACE(format, ...)                                            \
    do {                                                              \
        colored(stdout, COLOR_BLUE, "[TRACE]" format, ##__VA_ARGS__); \
    } while (0)

#define BUF_LEN 128

#ifndef NDEBUG
#define Assert(cond, ...)                                                    \
    do {                                                                     \
        if (!(cond)) {                                                       \
            if (sizeof(#__VA_ARGS__) > 1) {                                  \
                char _macro_formatter_[BUF_LEN];                             \
                sprintf(_macro_formatter_, "" __VA_ARGS__);                  \
                ERROR("%s:%d: Assertion failed at " #cond " : %s", __FILE__, \
                      __LINE__, _macro_formatter_);                          \
            } else {                                                         \
                ERROR("%s:%d: Assertion failed at " #cond, __FILE__,         \
                      __LINE__);                                             \
            }                                                                \
            exit(1);                                                         \
        }                                                                    \
    } while (0)
#else
#define Assert(cond, ...) \
    do {                  \
    } while (0)
#endif

#ifndef NDEBUG
#define Assert_eq(left, right, ...)                                            \
    do {                                                                       \
        if ((left) != (right)) {                                               \
            if (sizeof(#__VA_ARGS__) > 1) {                                    \
                char _macro_formatter_[BUF_LEN];                               \
                sprintf(_macro_formatter_, "" __VA_ARGS__);                    \
                ERROR("%s:%d: Assertion failed : %s == %s: %s", __FILE__,      \
                      __LINE__, #left, #right, _macro_formatter_);             \
            } else {                                                           \
                ERROR("%s:%d: Assertion failed: %s == %s", __FILE__, __LINE__, \
                      #left, #right);                                          \
            }                                                                  \
            exit(1);                                                           \
        }                                                                      \
    } while (0)
#else
#define Assert_eq(left, right, ...) \
    do {                            \
    } while (0)
#endif

#ifndef NDEBUG
#define Assert_ne(left, right, ...)                                            \
    do {                                                                       \
        if ((left) == (right)) {                                               \
            if (sizeof(#__VA_ARGS__) > 1) {                                    \
                char _macro_formatter_[BUF_LEN];                               \
                sprintf(_macro_formatter_, "" __VA_ARGS__);                    \
                ERROR("%s:%d: Assertion failed : %s != %s: %s", __FILE__,      \
                      __LINE__, #left, #right, _macro_formatter_);             \
            } else {                                                           \
                ERROR("%s:%d: Assertion failed: %s != %s", __FILE__, __LINE__, \
                      #left, #right);                                          \
            }                                                                  \
            exit(1);                                                           \
        }                                                                      \
    } while (0)
#else
#define Assert_ne(left, right, ...) \
    do {                            \
    } while (0)
#endif

#define Panic(...)                                                \
    do {                                                          \
        if (sizeof(#__VA_ARGS__) > 1) {                           \
            char _macro_formatter_[BUF_LEN];                      \
            sprintf(_macro_formatter_, "" __VA_ARGS__);           \
            ERROR("%s:%d: Paniced occur: %s", __FILE__, __LINE__, \
                  _macro_formatter_);                             \
        } else {                                                  \
            ERROR("%s:%d: Paniced occur", __FILE__, __LINE__);    \
        }                                                         \
        exit(1);                                                  \
    } while (0)

#define Todo()                                                   \
    do {                                                         \
        ERROR("%s:%d: not implemented yet", __FILE__, __LINE__); \
        exit(1);                                                 \
    } while (0)

#define Unreachable()                                                 \
    do {                                                              \
        ERROR("%s:%d: Reached unreachable code", __FILE__, __LINE__); \
        exit(1);                                                      \
    } while (0)

#define Array_Len(array) (sizeof(array) / sizeof((array)[0]))
#define Array_Last(array) ((array) + Array_Len(array) - 1)
#define Array_First(array) (array[0])

#endif