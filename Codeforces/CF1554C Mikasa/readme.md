# [CF1554C](https://codeforces.com/contest/1554/problem/C)

# tags 
`binary search` `bitmasks` `greedy` `implementation` `*1800`

# description
You are given two integers n and m. Find the MEX of the sequence n⊕0,n⊕1,…,n⊕m. Here, ⊕ is the bitwise XOR operator.

MEX of the sequence of non-negative integers is the smallest non-negative integer that doesn't appear in this sequence. For example, MEX(0,1,2,4)=3, and MEX(1,2021)=0.

Input
The first line contains a single integer t (1≤t≤30000)  — the number of test cases.

The first and only line of each test case contains two integers n and m (0≤n,m≤109).

Output
For each test case, print a single integer  — the answer to the problem.

## input
```
5
3 5
4 6
3 2
69 696
123456 654321
```
## output
```
4
3
0
640
530866
```
