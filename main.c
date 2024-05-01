#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


typedef struct arguments {
    int numberNonBlankFlag;
    int endOfLineFlag;
    int numberFlag;
    int squeezeBlankFlag;
    int tabFlag;
    int nonPrintableFlag;
} arguments;

arguments argumentParser(int argc, char **argv) {
    arguments arg = {0};

    static struct option long_options[] = {
        {"number-nonblank", no_argument, NULL, 'b'},
        {"number", no_argument, NULL, 'n'},
        {"squeeze-blank", no_argument, NULL, 's'},
        {NULL, no_argument, NULL, 0},
        {0, no_argument, NULL, 0}
    };

    int opt = getopt_long(argc, argv, "bevEnstT", NULL, 0);

    switch (opt) {
        case 'b':
            arg.numberNonBlankFlag = 1;
            break;
        case 'e':
            arg.endOfLineFlag = 1;
        case 'v':
            arg.nonPrintableFlag = 1;
            break;
        case 'E':
            arg.endOfLineFlag = 1;
            break;
        case 'n':
            arg.numberFlag = 1;
            break;
        case 's':
            arg.squeezeBlankFlag = 1;
            break;
        case 't':
            arg.nonPrintableFlag = 1;
        case 'T':
            arg.tabFlag = 1;
            break;
        case '?':
            printf("Undefined flag\n");
            break;
        default:
            printf("Error\n");
            break;
    }

    return arg;
}

void outline(char *line, int n) {
    for(int i = 0; i < n; i++) {
        putchar(line[i]);
    }
}

void readFile() {
}

int main(int argc, char *argv[]) {



    return 0;
}
