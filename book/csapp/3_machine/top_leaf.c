long leaf(long y) {
    return y + 2;
}

long top(long x) {
    return leaf(x - 5) * 2;
}

int main() {
    return top(100);
}

