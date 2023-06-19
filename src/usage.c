#include "usage.h"

void usage() {
    colored(stdout, COLOR_GREEN, "Usage: %s [OPTIONS]", SOFTWARE_NAME);
    colored(stdout, COLOR_GREEN,
            " \t-z|--zip <out_file> <in_file_1> <in_file_2> ...");
    colored(stdout, COLOR_GREEN, "\t\tzip all input files to fat file");

    colored(stdout, COLOR_GREEN, "\t-i|--info <fat_file>");
    colored(stdout, COLOR_GREEN, "\t\tdisplay information about fat file");

    colored(stdout, COLOR_GREEN, "\t-s|--split <fat_file>");
    colored(stdout, COLOR_GREEN,
            "\t\tsplit fat file into multiple files "
            "which embeded in fat file");

    colored(stdout, COLOR_GREEN, "\t-e|--extract <fat_file> <n-th>");
    colored(stdout, COLOR_GREEN,
            "\t\textract n-th(starting from 0) file into single file");

    return;
}

void version() {
    colored(stdout, COLOR_GREEN, "%s", SOFTWARE_NAME);
    colored(stdout, COLOR_GREEN, "  Version: %s", VERSION);
    colored(stdout, COLOR_GREEN, "  Release Date: %s", RELEASE_DATE);
    colored(stdout, COLOR_GREEN, "  Author: %s", AUTHOR);
    colored(stdout, COLOR_GREEN, "  Copyright © 2023, %s", AUTHOR);
    return;
}