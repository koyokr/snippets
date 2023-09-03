#include <stdio.h>

char *gets(char *s);

void echo() {
    char buf[8];
    gets(buf);
    puts(buf);
}

