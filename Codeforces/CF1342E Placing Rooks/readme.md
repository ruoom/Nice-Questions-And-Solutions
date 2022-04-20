# [Problem - 1342E - Codeforces](https://codeforces.com/problemset/problem/1342/E)

# tags
`combinatorics` `fft` `math` `*2300`

# description

Calculate the number of ways to place nn rooks on n×nn×n chessboard so that both following conditions are met:

each empty cell is under attack;
exactly kk pairs of rooks attack each other.
An empty cell is under attack if there is at least one rook in the same row or at least one rook in the same column. Two rooks attack each other if they share the same row or column, and there are no other rooks between them. For example, there are only two pairs of rooks that attack each other in the following picture:

![](https://espresso.codeforces.com/39e963e792c25d833bed0b97bbe92cc970fe9f67.png)

One of the ways to place the rooks for n=3n=3 and k=2k=2
Two ways to place the rooks are considered different if there exists at least one cell which is empty in one of the ways but contains a rook in another way.

The answer might be large, so print it modulo 998244353998244353.

Input
The only line of the input contains two integers nn and kk (1≤n≤2000001≤n≤200000; 0≤k≤n(n−1)20≤k≤n(n−1)2).

Output
Print one integer — the number of ways to place the rooks, taken modulo 998244353998244353.

有一个n*n的棋盘, 一共放n个棋子.问满足以下条件的数量:

- 所有空的格子都是under attack (如果这个格子的同一行或同一列有别的棋子, 则under attack)
- 有k对棋子互相under attack

答案对998244353取模

## input
```
3 2
```

## output
```
6
```

# solution

要求每行或每列都得有棋子. 如果斜着一排(所有棋子都不同行不同列). 那么就没有棋子互相attack. 如果放在同行/同列, 那么就会有n-1对互相attack. 所以k的上限是n-1. 

假设n行都有棋子, m列有棋子, 那么每列中的棋子可以互相攻击. 每列最多有ai-1对, 也就是说, 每有一列, k就要减少1, 进而推出列数m必须等于n-k

然后行列互换, 数量一样, 答案*2.

然后就变成了从n列中任选n-k列, 然后再将n任意分为n-k组, 每组最少1个的问题.

[**第二类斯特林数**](../../笔记/数论丶数学丶公式/斯特林数.md): n个元素划分为m组, 每组都至少有一个元素的方案数. 写作$\begin{Bmatrix}n\\m \end{Bmatrix}$.



注意k=0的时候 行列一样的, 不用*2.

