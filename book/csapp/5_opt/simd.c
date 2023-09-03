#include "vec.h"
#include <stddef.h>

#define VBYTES (32)
#define VSIZE  (VBYTES / (long)sizeof(data_t))

typedef data_t vec_t __attribute__ ((vector_size(VBYTES)));

data_t innerv(vec_t av, vec_t bv) {
    long i;
    vec_t pv = av * bv;
    data_t result = 0;

    for (i = 0; i < VSIZE; i++) {
        result += pv[i];
    }
    return result;
}

void simd_v1_combine(vec_ptr v, data_t *dest) {
    long i;
    vec_t accum;
    data_t *data = get_vec_start(v);
    long cnt = vec_length(v);
    data_t result = IDENT;

    for (i = 0; i < VSIZE; i++)
        accum[i] = IDENT;

    while ((((size_t)data) % VBYTES) != 0 && cnt) {
        result = result OP *data++;
        cnt--;
    }

    while (cnt >= VSIZE) {
        vec_t chunk = *((vec_t *)data);
        accum = accum OP chunk;
        data += VSIZE;
        cnt -= VSIZE;
    }

    while (cnt) {
        result = result OP *data++;
        cnt--;
    }

    for (i = 0; i < VSIZE; i++)
        result = result OP accum[i];

    *dest = result;
}
