# [CF1646E](https://codeforces.com/contest/1646/problem/E)

## tags
`brute force` `dp` `math` `number theory` `*2200`

## description
You have a rectangular board of size n×m (n rows, m columns). The n rows are numbered from 1 to n from top to bottom, and the m columns are numbered from 1 to m from left to right.

The cell at the intersection of row i and column j contains the number ij (i raised to the power of j). For example, if n=3 and m=3 the board is as follows:

![pic](https://espresso.codeforces.com/afa8db65b99d759cfbbcd49261d8394bd961875e.png)

Find the number of distinct integers written on the board.

Input
The only line contains two integers n and m (1≤n,m≤106) — the number of rows and columns of the board.

Output
Print one integer, the number of distinct integers on the board.

## input
```
3 3
```

## output
```
7
```

## input
```
2 4
```

## output
```
5
```

## input
```
4 2
```

## output
```
6
```

## Note

The statement shows the board for the first test case. In this case there are 7 distinct integers: 1, 2, 3, 4, 8, 9, and 27.

In the second test case, the board is as follows:

![pic](https://espresso.codeforces.com/34d10dbc65f224705db23fe58e1325724b18e64e.png)

There are 5 distinct numbers: 1, 2, 4, 8 and 16.

In the third test case, the board is as follows:

![pic](https://espresso.codeforces.com/624027d7bf49ecb62c4a73b92f886fe2f742770f.png)

There are 6 distinct numbers: 1, 2, 3, 4, 9 and 16.



