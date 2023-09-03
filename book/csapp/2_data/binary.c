#include <stdio.h>
#include <stdlib.h>

void print_binary(int n) {
    while (n) {
        printf("%d", n & 1);
        n >>= 1;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc == 2)
    	print_binary(atoi(argv[1]));
    return 0;
}
