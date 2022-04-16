# [CF1557C](https://codeforces.com/problemset/problem/1557/C)

# tags
`bitmasks` `combinatorics` `dp` `math` `matrices` `*1700`

# description

Moamen and Ezzat are playing a game. They create an array a of n non-negative integers where every element is less than 2k.

Moamen wins if a1&a2&a3&…&an≥a1⊕a2⊕a3⊕…⊕an.

Here & denotes the bitwise AND operation, and ⊕ denotes the bitwise XOR operation.

Please calculate the number of winning for Moamen arrays a.

As the result may be very large, print the value modulo 1000000007 (109+7).

Input
The first line contains a single integer t (1≤t≤5)— the number of test cases.

Each test case consists of one line containing two integers n and k (1≤n≤2⋅105, 0≤k≤2⋅105).

Output
For each test case, print a single value — the number of different arrays that Moamen wins with.

Print the result modulo 1000000007 (109+7).

## input
```
3
3 1
2 1
4 0
```

## output
```
5
2
1
```
