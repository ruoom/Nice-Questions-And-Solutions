# [CF191C](https://codeforces.com/problemset/problem/191/C)

# tags
`data structures` `dfs and similar` `trees` `*1900`

# description
They say that Berland has exactly two problems, fools and roads. Besides, Berland has n cities, populated by the fools and connected by the roads. All Berland roads are bidirectional. As there are many fools in Berland, between each pair of cities there is a path (or else the fools would get upset). Also, between each pair of cities there is no more than one simple path (or else the fools would get lost).

But that is not the end of Berland's special features. In this country fools sometimes visit each other and thus spoil the roads. The fools aren't very smart, so they always use only the simple paths.

A simple path is the path which goes through every Berland city not more than once.

The Berland government knows the paths which the fools use. Help the government count for each road, how many distinct fools can go on it.

Note how the fools' paths are given in the input.

Input
The first line contains a single integer n (2 ≤ n ≤ 105) — the number of cities.

Each of the next n - 1 lines contains two space-separated integers ui, vi (1 ≤ ui, vi ≤ n, ui ≠ vi), that means that there is a road connecting cities ui and vi.

The next line contains integer k (0 ≤ k ≤ 105) — the number of pairs of fools who visit each other.

Next k lines contain two space-separated numbers. The i-th line (i > 0) contains numbers ai, bi (1 ≤ ai, bi ≤ n). That means that the fool number 2i - 1 lives in city ai and visits the fool number 2i, who lives in city bi. The given pairs describe simple paths, because between every pair of cities there is only one simple path.

Output
Print n - 1 integer. The integers should be separated by spaces. The i-th number should equal the number of fools who can go on the i-th road. The roads are numbered starting from one in the order, in which they occur in the input.

## input
```
5
1 2
1 3
2 4
2 5
2
1 4
3 5
```

## output
```
2 1 1 1 
```

## input
```
5
3 4
4 5
1 4
2 4
3
2 3
1 3
3 5
```

## output
```
3 1 1 1 
``` 
