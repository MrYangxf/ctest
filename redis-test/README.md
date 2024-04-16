# Test function
## zslRandomLevel
```c
int zslRandomLevel() {
    static const int threshold = ZSKIPLIST_P*RAND_MAX;
    int level = 1;
    while (random() < threshold)
        level += 1;
    return (level<ZSKIPLIST_MAXLEVEL) ? level : ZSKIPLIST_MAXLEVEL;
}
```

## zslRandomLevel1
```c
int zslRandomLevel1() {
    int level = 1;
    int rnd = random();
    while (((rnd = rnd / ZSKIPLIST_RECIPROCAL_OF_P) % ZSKIPLIST_RECIPROCAL_OF_P) == 1)
        level += 1;
    return (level<ZSKIPLIST_MAXLEVEL) ? level : ZSKIPLIST_MAXLEVEL;
}
```
## zslRandomLevel2
```c
int zslRandomLevel2() {
    int level = 1 + __builtin_ctz(random()) / ZSKIPLIST_RECIPROCAL_OF_P_BITS;
    return (level<ZSKIPLIST_MAXLEVEL) ? level : ZSKIPLIST_MAXLEVEL;
}
```

# Benchmark
```
2024-04-16T08:15:59+00:00
Running ./random_level_benchmark
Run on (2 X 3243.34 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x1)
  L1 Instruction 32 KiB (x1)
  L2 Unified 512 KiB (x1)
  L3 Unified 32768 KiB (x1)
Load Average: 0.50, 0.36, 0.36
---------------------------------------------------------------------------------------------------
Benchmark                                                         Time             CPU   Iterations
---------------------------------------------------------------------------------------------------
BM_zslRandomLevel/min_time:10.000/min_warmup_time:5.000        16.1 ns         15.9 ns    841703018
BM_zslRandomLevel1/min_time:10.000/min_warmup_time:5.000       15.2 ns         15.1 ns    945539172
BM_zslRandomLevel2/min_time:10.000/min_warmup_time:5.000       9.18 ns         9.09 ns   1527291499
```

# Level distribution
```
LEVEL zslRandomLevel zslRandomLevel1 zslRandomLevel2
Level_0 0 0 0
Level_1 74952123 74999933 75000364
Level_2 18786863 18748145 18749077
Level_3 4694439 4686542 4688544
Level_4 1178364 1173988 1172224
Level_5 291639 293675 292433
Level_6 72032 73082 73180
Level_7 18565 18580 18090
Level_8 4491 4541 4595
Level_9 1092 1143 1100
Level_10 310 274 302
Level_11 67 72 74
Level_12 11 20 13
Level_13 4 3 2
Level_14 0 1 2
Level_15 0 1 0
Level_16 0 0 0
Level_17 0 0 0
Level_18 0 0 0
Level_19 0 0 0
Level_20 0 0 0
Level_21 0 0 0
Level_22 0 0 0
Level_23 0 0 0
Level_24 0 0 0
Level_25 0 0 0
Level_26 0 0 0
Level_27 0 0 0
Level_28 0 0 0
Level_29 0 0 0
Level_30 0 0 0
Level_31 0 0 0
```