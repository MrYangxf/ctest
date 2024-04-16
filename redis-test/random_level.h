
#ifndef REDIS_RANDOM_LEVEL
#define REDIS_RANDOM_LEVEL

#include <stdlib.h>

#define ZSKIPLIST_MAXLEVEL 32
#define ZSKIPLIST_P 0.25
#define ZSKIPLIST_RECIPROCAL_OF_P 4 // same as 1/ZSKIPLIST_P

#if (ZSKIPLIST_RECIPROCAL_OF_P & (ZSKIPLIST_RECIPROCAL_OF_P - 1)) == 0
#define ZSKIPLIST_RECIPROCAL_OF_P_BITS __builtin_ctz(ZSKIPLIST_RECIPROCAL_OF_P)
#endif

int zslRandomLevel() {
    static const int threshold = ZSKIPLIST_P*RAND_MAX;
    int level = 1;
    while (random() < threshold)
        level += 1;
    return (level<ZSKIPLIST_MAXLEVEL) ? level : ZSKIPLIST_MAXLEVEL;
}

int zslRandomLevel1() {
    int level = 1;
    int rnd = random();
    while (((rnd = rnd / ZSKIPLIST_RECIPROCAL_OF_P) % ZSKIPLIST_RECIPROCAL_OF_P) == 1)
        level += 1;
    return (level<ZSKIPLIST_MAXLEVEL) ? level : ZSKIPLIST_MAXLEVEL;
}

int zslRandomLevel2() {
    int level = 1 + __builtin_ctz(random()) / ZSKIPLIST_RECIPROCAL_OF_P_BITS;
    return (level<ZSKIPLIST_MAXLEVEL) ? level : ZSKIPLIST_MAXLEVEL;
}

int zslRandomLevelMixed() {
#if ZSKIPLIST_RECIPROCAL_OF_P <= 1
    return ZSKIPLIST_MAXLEVEL;
#elif defined ZSKIPLIST_RECIPROCAL_OF_P_BITS
    int level = 1 + __builtin_ctz(random()) / ZSKIPLIST_RECIPROCAL_OF_P_BITS;
    return (level<ZSKIPLIST_MAXLEVEL) ? level : ZSKIPLIST_MAXLEVEL;
#else
    int level = 1;
    int rnd = random();
    while (((rnd = rnd / ZSKIPLIST_RECIPROCAL_OF_P) % ZSKIPLIST_RECIPROCAL_OF_P) == 1)
        level += 1;
    return (level<ZSKIPLIST_MAXLEVEL) ? level : ZSKIPLIST_MAXLEVEL;
#endif
}

#endif