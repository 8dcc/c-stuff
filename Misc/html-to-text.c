
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* string.h function does weird stuff when strings overlap (our case) */
static char* my_strcpy(char* dest, const char* src) {
    size_t i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];

    dest[i] = '\0';

    return dest;
}

static char* html2txt(char* str) {
    char* ret = str;

    char* label_start = str;
    bool in_br        = false;

    while (*str != '\0') {
        switch (*str) {
            case '<':
                label_start = str;
                str++;

                /* If label is <br>, store */
                if (*str++ == 'b' && *str++ == 'r')
                    in_br = true;
                break;
            case '>':
                /* We are closing a <br> string, place '\n' before shifting */
                if (in_br) {
                    *label_start = '\n';
                    label_start++;
                    in_br = false;
                }

                /* Shift rest of string */
                my_strcpy(label_start, str + 1);
                str = label_start;
                break;
            default:
                str++;
                break;
        }
    }

    return ret;
}

int main() {
    char str[] = "<a href=\"#p96207730\" "
                 "class=\"quotelink\">96207730</a><br>Let me rephrase: would "
                 "it be possible for an individual, or small group of "
                 "individuals, to do this.<br><a href=\"asd\">Other "
                 "line.</a><br>Another line.";

    printf("Original:\n%s\n\n", str);
    printf("Final:\n%s\n", html2txt(str));

    return 0;
}
