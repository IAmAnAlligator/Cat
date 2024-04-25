// https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
// https://stepik.org/lesson/311876/step/9?unit=294366
// https://habr.com/ru/articles/734254/
// https://www.opennet.ru/man.shtml?topic=getopt_long&category=3&russian=0

#include <stdio.h>
#include <getopt.h>

int main (int argc, char **argv) {
    int c;
    int digit_optind = 0;

    while (1) {

        int this_option_optind = optind ? optind : 1;

        int option_index = 0;

        static struct option long_options[] = {
            {"number-nonblank", 0, 0, 'b'},
            {"number", 0, 0, 'n'},
            {"squeeze-blank", 0, 0, 's'},
            {0, 0, 0, 0}
        };

        c = getopt_long (argc, argv, "benst012", long_options, &option_index);

        if (c == -1)
            break;


        switch (c) {
            case 0:
                printf ("Parameter %s", long_options[option_index].name);
            if (optarg)
                printf (" with argument %s", optarg);
            printf ("\n");
            break;

            case '0':
            case '1':
            case '2':
                if (digit_optind != 0 && digit_optind != this_option_optind)
                    printf ("цифры используются в двух разных элементах argv.\n");
            digit_optind = this_option_optind;
            printf ("параметр  %c\n", c);
            break;

            case 'b':
                printf ("parameter b\n");
            break;

            case 'e':
                printf ("parameter e\n");
            break;

            case 'n':
                printf ("parameter n\n");
            break;

            case 's':
                printf ("parameter s\n");
            break;

            case 't':
                printf ("parameter t\n");
            break;

            case '?':
                break;

            default:
                printf ("?? getopt возвратило код символа 0%o ??\n", c);
        }
    }

    if (optind < argc) {
        printf ("Filename: ");
        while (optind < argc)
            printf ("%s ", argv[optind++]);
        printf ("\n");
    }

    return 0;
}
