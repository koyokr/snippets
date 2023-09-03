long last(long u, long v) {
    return u * v;
}

long first(long x) {
    return last(x - 1, x + 1);
}

int main() {
    return first(10);
}
