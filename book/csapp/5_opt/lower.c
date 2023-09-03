#include <string.h>

size_t _strlen(const char *const s) {
    return strlen(s);
}

void lower1(char *s) {
    size_t i;

    for (i = 0; i < _strlen(s); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] -= ('A' - 'a');
}

void lower2(char *s) {
    size_t i;
    size_t len = _strlen(s);

    for (i = 0; i < len; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] -= ('A' - 'a');
}

