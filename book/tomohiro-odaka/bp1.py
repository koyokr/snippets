# -*- coding: utf-8 -*-
from math import exp
from random import random
from sys import stderr, stdin
from typing import Generator, Tuple

INPUTNO = 3
HIDDENNO = 50
ALPHA = 10
MAXINPUTNO = 100
BIGNUM = 100
LIMIT = 0.000001


def f(u: float) -> float:
    return 1.0 / (1.0 + exp(-u))


def forward(wh: Tuple[Tuple[float, ...], ...],
            wo: Tuple[float, ...],
            e: Tuple[float, ...]) -> Tuple[Tuple[float, ...], float]:
    hi = tuple(f(sum(x * y for x, y in zip(wh_, e)) - wh_[INPUTNO]) for wh_ in wh)
    o = f(sum(x * y for x, y in zip(hi, wo)) - wo[HIDDENNO])
    return hi, o


def hlearn(wh: Tuple[Tuple[float, ...], ...],
           wo: Tuple[float, ...],
           hi: Tuple[float, ...],
           e: Tuple[float, ...],
           o: float) -> Tuple[Tuple[float, ...], ...]:
    def gen() -> Generator:
        for wh_, wo_, h in zip(wh, wo, hi):
            dj = h * (1 - h) * wo_ * (e[INPUTNO] - o) * o * (1 - o)
            yield tuple(x + ALPHA * y * dj for x, y in zip(wh_, e + (-1.0,)))
    return tuple(gen())


def olearn(wo: Tuple[float, ...],
           hi: Tuple[float, ...],
           e: Tuple[float, ...],
           o: float) -> Tuple[float, ...]:
    d = (e[INPUTNO] - o) * o * (1 - o)
    return tuple(x + ALPHA * h * d for x, h in zip(wo, hi + (-1.0,)))


def printw(wh: Tuple[Tuple[float, ...], ...], wo: Tuple[float, ...]) -> None:
    print(' '.join('%lf' % v for wh_ in wh for v in wh_))
    print(' '.join('%lf' % v for v in wo))


def getdata() -> Tuple[Tuple[float, ...], ...]:
    return tuple(tuple(float(s) for s in line.split(' ')[:INPUTNO+1]) for line in stdin)


def drnd() -> float:
    return random() * 2 - 1


def initwh() -> Tuple[Tuple[float, ...], ...]:
    return tuple(tuple(drnd() for _ in range(INPUTNO+1)) for _ in range(HIDDENNO))


def initwo() -> Tuple[float, ...]:
    return tuple(drnd() for _ in range(HIDDENNO+1))


def main() -> None:
    wh = initwh()
    wo = initwo()
    printw(wh, wo)

    e = getdata()
    n_of_e = len(e)
    print('number of data: %d' % n_of_e)

    count = 0
    err = BIGNUM
    while err > LIMIT:
        err = 0.0
        for x in e:
            hi, o = forward(wh, wo, x)
            wo = olearn(wo, hi, x, o)
            wh = hlearn(wh, wo, hi, x, o)
            err += (o - x[INPUTNO]) ** 2
        count += 1
        stderr.write('%d\t%lf\n' % (count, err))
    printw(wh, wo)

    for i, x in enumerate(e):
        print(i, ' '.join('%lf' % x for x in x), '%lf' % forward(wh, wo, x)[1])


if __name__ == '__main__':
    main()
