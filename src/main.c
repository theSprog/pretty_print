#include "common.h"
#include "usage.h"

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

    return 0;
}