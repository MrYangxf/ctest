#include <stdio.h>
#include "random_level.h"

int main(int argc, char const *argv[]) {
    size_t iterations = 100000000;
    size_t distribution0[ZSKIPLIST_MAXLEVEL] = {};
    size_t distribution1[ZSKIPLIST_MAXLEVEL] = {};
    size_t distribution2[ZSKIPLIST_MAXLEVEL] = {};
    for (int i = 0; i < iterations; i++) {
        distribution0[zslRandomLevel()]++;
        distribution1[zslRandomLevel1()]++;
        distribution2[zslRandomLevel2()]++;
    }
    printf("LEVEL zslRandomLevel zslRandomLevel1 zslRandomLevel2\n");
    for (int i = 0; i < ZSKIPLIST_MAXLEVEL; i++) {
        printf("Level_%d %ld %ld %ld\n", i, distribution0[i], distribution1[i], distribution2[i]);
    }
}