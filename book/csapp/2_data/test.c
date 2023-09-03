#include <stdio.h>
#include <stdint.h>

int main() {
    uint16_t u1 = 0x7777;
    uint16_t u2 = 0xAAAA;
    uint16_t u3 = u1 * u2;
    uint32_t u4 = u1 * u2;

    int16_t t1 = 0x7777;
    int16_t t2 = 0xAAAA;
    int16_t t3 = t1 * t2;
    int32_t t4 = t1 * t2;

    printf("u3: %8x\n", u3);
    printf("t3: %8x\n", t3);
    printf("u4: %8x\n", u4);
    printf("t4: %8x\n", t4);

    return 0;
}
