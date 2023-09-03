long Q(long u) {
    return u;
}

long P(long x, long y) {
    long u = Q(y);
    long v = Q(x);
    return u + v;
}

