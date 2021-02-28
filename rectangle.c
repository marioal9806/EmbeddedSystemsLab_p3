#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int area = 0;
    int perimeter = 0;
    int length;
    int width;
    int result;

    char ch;

    while (((ch = getopt(argc, argv, "apl:w:")) != -1) && (ch != 255))
        switch (ch)
        {
        case 'a':
            area = 1;
            break;
        case 'p':
            perimeter = 1;
            break;
        case 'l':
            length = atoi(optarg);
            break;
        case 'w':
            width = atoi(optarg);
            break;
        default:
            fprintf(stderr, "Unknown option: %s\n", optarg);
            return 1;
        }

    if (area) {
        result = length * width;
        printf("area = %i units\n", result);
    }

    if (perimeter) {
        result = (2 * length) + (2 * width);
        printf("perimeter = %i units\n", result);
    }

    return 0;
}
