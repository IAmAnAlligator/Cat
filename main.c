// https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
// https://stepik.org/lesson/311876/step/9?unit=294366
// https://habr.com/ru/articles/734254/
// https://www.opennet.ru/man.shtml?topic=getopt_long&category=3&russian=0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

void printBuffer(char *buffer) {
    if (buffer) {
        int ch;
        int i = 0;
        do {
            ch = buffer[i];
            printf("%c", ch);
            i++;
        } while (ch != '\0');
    }
}

char *readFile(char *name) {
    long length;
    char *buffer = 0;

    FILE *f = fopen(name, "rb");

    if (f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length + 100); // плюс место для добавочных символов
        if (buffer) {
            fread(buffer, 1, length, f);
            buffer[length] = '\0';
        }

        fclose(f);
    }

    return buffer;
}

void numberLines(char *buffer) {
}

void addEnd(char *buffer) {
    strcat(buffer, "$");
}


int main(int argc, char **argv) {
    while (1) {
        int option_index = 0;

        static struct option long_options[] = {
            {"number-nonblank", 0, 0, 'b'},
            {"number", 0, 0, 'n'},
            {"squeeze-blank", 0, 0, 's'}
        };

        int c = getopt_long(argc, argv, "bevEnstT", long_options, &option_index);

        if (c == -1) {
            break;
        }

        switch (c) {
            case 'b':
                printf("parameter b\n");
                break;

            case 'e':
                printf("parameter e\n");
                break;

            case 'v':
                printf("parameter v\n");
                break;

            case 'E':
                printf("parameter e\n");
                break;

            case 'n':
                printf("parameter n\n");
                break;

            case 's':
                printf("parameter s\n");
                break;

            case 't':
                printf("parameter t\n");
                break;

            case 'T':
                printf("parameter T\n");
                break;

            case '?':
                printf("Undefined\n");
                break;

            default:
                printf("?? getopt 0%o ??\n", c);
        }
    }

    char *buffer = 0;

    if (optind < argc) {
        while (optind < argc) {
            //printf ("%s\n", argv[optind++]);
            buffer = readFile(argv[optind++]);
        }
    }

    addEnd(buffer);
    printBuffer(buffer);

    free(buffer);

    return 0;
}
