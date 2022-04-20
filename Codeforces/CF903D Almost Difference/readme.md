# [Problem - 903D - Codeforces](https://codeforces.com/problemset/problem/903/D)

# tags
`data structures` `math` `*2200`

# description

Let's denote a function

![](https://espresso.codeforces.com/ccd6b10105ec02e1e62a5b638601921c152f8d05.png)

You are given an array a consisting of n integers. You have to calculate the sum of d(ai, aj) over all pairs (i, j) such that 1 ≤ i ≤ j ≤ n.

给一长度为n的数组, 给函数:

![](https://latex.codecogs.com/svg.image?d(x,y)&space;=&space;\begin{cases}y-x,&space;&|x-y|>1&space;\\0,&space;&|x-y|\leq1&space;&space;&space;&space;\end{cases})

计算:

![](https://latex.codecogs.com/svg.image?\sum^{n}_{i=1}\sum^{n}_{j=i&plus;1}d(a_i,a_j))


Input
The first line contains one integer n (1 ≤ n ≤ 200000) — the number of elements in a.

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 109) — elements of the array.

Output
Print one integer — the sum of d(ai, aj) over all pairs (i, j) such that 1 ≤ i ≤ j ≤ n.

## input
```
5
1 2 3 1 3
```

## output
```
4
```

## input
```
4
6 6 5 5
```
## output
``` 
0
```

## input 
```
4
6 6 4 4
```

## output
```
-8
```

Note
In the first example:

d(a1, a2) = 0;
d(a1, a3) = 2;
d(a1, a4) = 0;
d(a1, a5) = 2;
d(a2, a3) = 0;
d(a2, a4) = 0;
d(a2, a5) = 0;
d(a3, a4) =  - 2;
d(a3, a5) = 0;
d(a4, a5) = 2.


# solution

可以发现, 当相差为0的时候, 两个式子相等, 所以不同的情况就只有|x-y|=1, 用一个map来记录所有数字出现的次数, 统计的时候先全按第一个式子, 然后再去掉第二个式子的情况.

计算前缀和, 然后倒着统计. longlong精度不够, 可以开long double

输出格式: cout << fixed << setprecision(0) << ans;
