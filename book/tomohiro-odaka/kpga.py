# -*- coding: utf-8 -*-
from datetime import datetime
from random import random, randrange
from typing import List

from plotting import plot

MAXVALUE = 100
N = 30
WEIGHTLIMIT = N*MAXVALUE/4
POOLSIZE = 30
LASTG = 50
MRATE = 0.01

pts1 = set()
pts2 = set()
count1 = 0
GRAPESIZE = 1500
GPL = GRAPESIZE/LASTG


def main() -> None:
    global parcel
    parcel = [[int(v) for v in input().split(' ')] for i in range(N)]
    pool = [[randrange(2) for j in range(N)] for i in range(POOLSIZE)]
    ngpool = [[0 for _ in range(N)] for _ in range(POOLSIZE*2)]
    for generation in range(1, LASTG+1):
        print('%dth generation' % generation)
        mating(pool, ngpool)
        mutation(ngpool)
        selectng(ngpool, pool)
        printp(pool)
    plot(pts1, GRAPESIZE, 2)
    plot(pts2, GRAPESIZE, 1)


def selectng(ngpool: List[List[int]], pool: List[List[int]]) -> None:
    for i in range(POOLSIZE):
        roulette = [evalfit(g) for g in ngpool]
        totalfitness = sum(roulette)
        ball = randrange(totalfitness)
        acc = 0
        for c, v in enumerate(roulette):
            acc += v
            if acc > ball:
                break
        for j in range(N):
            pool[i][j] = ngpool[c][j]


def selectp(roulette: List[int], totalfitness: int) -> int:
    ball = randrange(totalfitness)
    acc = 0
    for i, v in enumerate(roulette):
        acc += v
        if acc > ball:
            break
    return i


def mating(pool: List[List[int]], ngpool: List[List[int]]) -> None:
    roulette = [evalfit(g) for g in pool]
    totalfitness = sum(roulette)
    for i in range(POOLSIZE):
        while True:
            mama = selectp(roulette, totalfitness)
            papa = selectp(roulette, totalfitness)
            if mama != papa:
                break
        crossing(pool[mama], pool[papa], ngpool[i*2], ngpool[i*2+1])


def crossing(m: List[int], p: List[int], c1: List[int], c2: List[int]) -> None:
    cp = randrange(N)
    for j in range(cp):
        c1[j] = m[j]
        c2[j] = p[j]
    for j in range(cp, N):
        c2[j] = m[j]
        c1[j] = p[j]


def evalfit(g: List[int]) -> int:
    global parcel
    value = 0
    weight = 0
    for pos in range(N):
        weight += parcel[pos][0]*g[pos]
        value += parcel[pos][1]*g[pos]
    if weight >= WEIGHTLIMIT:
        value = 0
    return value


def printp(pool: List[List[int]]) -> None:
    roulette = [evalfit(g) for g in pool]
    bestfit = max(roulette)
    elite = roulette.index(bestfit)
    meanfitness = sum(roulette) / POOLSIZE
    for g, f in zip(pool, roulette):
        print('%s\t%d' % (''.join('%1d' % v for v in g), f))
    print('%d\t%d \t%lf' % (elite, bestfit, meanfitness))
    global count1
    count1 += GPL
    pts1.add(count1 + 1j * bestfit)
    pts2.add(count1 + 1j * meanfitness)


def mutation(ngpool: List[List[int]]) -> None:
    for i in range(POOLSIZE*2):
        for j in range(N):
            if random() <= MRATE:
                ngpool[i][j] = notval(ngpool[i][j])


def notval(v: int) -> int:
    return int(not v)


if __name__ == '__main__':
    beg = datetime.now()
    main()
    end = datetime.now()
    print(end - beg)
