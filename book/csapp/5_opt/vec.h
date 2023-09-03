#define IDENT 0
#define OP *

typedef double data_t;

typedef struct {
    long len;
    data_t *data;
} vec_rec, *vec_ptr;

long vec_length(vec_ptr v);
data_t *get_vec_start(vec_ptr v);
