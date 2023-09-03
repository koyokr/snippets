# -*- coding: utf-8 -*-
from random import randint


MAXVALUE = 100
N = 30


def main() -> int:
    for _ in range(N):
        print(randdata(), randdata())
    return 0


def randdata() -> int:
    return randint(1, MAXVALUE)


if __name__ == '__main__':
    main()
