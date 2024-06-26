
#include <stdio.h>

int main(void) {
    char c = getchar();

    /* NOTE: Switch ranges are not standard and will give a warning when
     * compiling with -Wpedantic */
    switch (c) {
        case 'a' ... 'z': {
            puts("Lowercase.");
        } break;

        case 'A' ... 'Z': {
            puts("Uppercase.");
        } break;

        case '0' ... '9': {
            puts("Digit.");
        } break;

        default: {
            puts("Unknown.");
        } break;
    }

    return 0;
}
