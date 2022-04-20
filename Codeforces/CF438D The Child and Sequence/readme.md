# [Problem - 438D - Codeforces](https://codeforces.com/problemset/problem/438/D)

# tags
`data structures` `math` `*2300`

# description

outputstandard output
At the children's day, the child came to Picks's house, and messed his house up. Picks was angry at him. A lot of important things were lost, in particular the favorite sequence of Picks.

Fortunately, Picks remembers how to repair the sequence. Initially he should create an integer array a[1], a[2], ..., a[n]. Then he should perform a sequence of m operations. An operation can be one of the following:

Print operation l, r. Picks should write down the value of .
Modulo operation l, r, x. Picks should perform assignment a[i] = a[i] mod x for each i (l ≤ i ≤ r).
Set operation k, x. Picks should set the value of a[k] to x (in other words perform an assignment a[k] = x).
Can you help Picks to perform the whole sequence of operations?

Input
The first line of input contains two integer: n, m (1 ≤ n, m ≤ 105). The second line contains n integers, separated by space: a[1], a[2], ..., a[n] (1 ≤ a[i] ≤ 109) — initial value of array elements.

Each of the next m lines begins with a number type .

If type = 1, there will be two integers more in the line: l, r (1 ≤ l ≤ r ≤ n), which correspond the operation 1.
If type = 2, there will be three integers more in the line: l, r, x (1 ≤ l ≤ r ≤ n; 1 ≤ x ≤ 109), which correspond the operation 2.
If type = 3, there will be two integers more in the line: k, x (1 ≤ k ≤ n; 1 ≤ x ≤ 109), which correspond the operation 3.
Output
For each operation 1, please print a line containing the answer. Notice that the answer may exceed the 32-bit integer.

给长度为n的数组, m次询问, 询问方式如下:

- 1 输出区间lr之和
- 2 对于区间lr每个元素, 模x
- 3 单点赋值a[k] = x


## input
```
5 5
1 2 3 4 5
2 3 5 4
3 3 5
1 2 5
2 1 3 3
1 1 3
```

## output
```
8
5
```


## input
```
10 10
6 9 6 7 6 1 10 10 9 5
1 3 9
2 7 10 9
2 5 10 8
1 4 7
3 3 7
2 7 9 9
1 2 4
1 6 6
1 5 9
3 1 10
```

## output
```
49
15
23
1
9
```

# solution

线段树搞定.

正常是懒标记缩减复杂度, 但发现这个题的模操作没法pushdown, 但暴力挨个取模会超时, 所以我们尝试优化这里. 可以发现如果区间中所有数都比模x小, 那么所有数是原封不变的, 所以在节点中维护一个区间最大值, 在取模更新中判断一下这个区间有没有数需要改变, 没数的话直接不管就行了.


