#include "common.h"
#include "usage.h"

typedef void (*CommandFunc)(u32 input_count, char** inputs);

typedef struct {
    const char* command;
    CommandFunc func;
} CommandMapping;

const CommandMapping mappings[] = {
    {"-z", zip},   {"--zip", zip},     {"-i", info},    {"--info", info},
    {"-s", split}, {"--split", split}, {"-e", extract}, {"--extract", extract}};

int main(int argc, char** argv) {
    if (argc < 2) {
        usage();
        return 1;
    }

    if (str_eq(argv[1], "-h") || str_eq(argv[1], "--help")) {
        usage();
        return 0;
    }
    if (str_eq(argv[1], "-v") || str_eq(argv[1], "--version")) {
        version();
        return 0;
    }

    char* command = argv[1];
    for (usize i = 0; i < Array_Len(mappings); ++i) {
        if (str_eq(command, mappings[i].command)) {
            mappings[i].func(argc - 2, argv + 2);
            return 0;
        }
    }

    ERROR("Unknown command %s", command);
    exit(1);
}