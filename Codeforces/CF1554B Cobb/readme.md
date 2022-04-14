# [CF1554B Cobb](https://codeforces.com/problemset/problem/1554/B)
You are given n integers a1,a2,…,an and an integer k. Find the maximum value of i⋅j−k⋅(ai|aj) over all pairs (i,j) of integers with 1≤i<j≤n. Here, | is the bitwise OR operator.

Input
The first line contains a single integer t (1≤t≤10000)  — the number of test cases.

The first line of each test case contains two integers n (2≤n≤105) and k (1≤k≤min(n,100)).

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤n).

It is guaranteed that the sum of n over all test cases doesn't exceed 3⋅105.

Output
For each test case, print a single integer  — the maximum possible value of i⋅j−k⋅(ai|aj).

## INPUT
```
4
3 3
1 1 3
2 2
1 2
4 3
0 1 2 3
6 6
3 2 0 0 5 6
```
## OUTPUT
```
-1
-4
3
12
```
