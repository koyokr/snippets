struct rect {
    long width;
    long height;
};

long area(struct rect *rp) {
    return rp->width * rp->height;
}

