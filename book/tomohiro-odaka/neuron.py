# -*- coding: utf-8 -*-
from math import exp
from sys import stdin
from typing import Tuple


INPUTNO = 2


def f(u: float) -> float:
    return 1 if u >= 0 else 0
    # return 1 / (1 + exp(-u))


def forward(w: Tuple[float, ...], e: Tuple[float, ...]) -> float:
    return f(sum(x*y for x, y in zip(w, e)) - w[INPUTNO])


def getdata() -> Tuple[Tuple[float, ...], ...]:
    return tuple(tuple(float(s) for s in line.split(' ')[:INPUTNO]) for line in stdin)


def initw() -> Tuple[float, ...]:
    return (1, 1, 1.5)


def main() -> None:
    w = initw()
    e = getdata()
    n_of_e = len(e)
    print('number of data: %d' % n_of_e)
    for i, g in enumerate(e):
        print(i, ' '.join('%lf' % x for x in g), '%lf' % forward(w, g))


if __name__ == '__main__':
    main()
