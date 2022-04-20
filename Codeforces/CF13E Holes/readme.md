# [Problem - 13E - Codeforces](https://codeforces.com/problemset/problem/13/E)

# tags
`data structures` `dsu` `*2700`

# description

Little Petya likes to play a lot. Most of all he likes to play a game «Holes». This is a game for one person with following rules:

There are N holes located in a single row and numbered from left to right with numbers from 1 to N. Each hole has it's own power (hole number i has the power ai). If you throw a ball into hole i it will immediately jump to hole i + ai, then it will jump out of it and so on. If there is no hole with such number, the ball will just jump out of the row. On each of the M moves the player can perform one of two actions:

Set the power of the hole a to value b.
Throw a ball into the hole a and count the number of jumps of a ball before it jump out of the row and also write down the number of the hole from which it jumped out just before leaving the row.
Petya is not good at math, so, as you have already guessed, you are to perform all computations.

Input
The first line contains two integers N and M (1 ≤ N ≤ 105, 1 ≤ M ≤ 105) — the number of holes in a row and the number of moves. The second line contains N positive integers not exceeding N — initial values of holes power. The following M lines describe moves made by Petya. Each of these line can be one of the two types:

0 a b
1 a
Type 0 means that it is required to set the power of hole a to b, and type 1 means that it is required to throw a ball into the a-th hole. Numbers a and b are positive integers do not exceeding N.
Output
For each move of the type 1 output two space-separated numbers on a separate line — the number of the last hole the ball visited before leaving the row and the number of jumps it made.

有n个洞, 每个都有一个能量ai, 如果你扔一个球进去, 那么他会立刻跳进第ai+i个洞. 如果没有这个洞, 那么他就会跳没.

共有m次操作, 有两种操作:

- 将洞a能量变成x
- 往洞a扔一个球, 请你输出在球弹飞之前一共走了几个洞, 并且输出所经过的最后一个洞.

## input
```
8 5
1 1 1 1 1 2 8 2
1 1
0 1 3
1 1
0 3 4
1 2
```

## output
```
8 7
8 5
7 3
```

# solution

![](https://latex.codecogs.com/svg.image?n\sqrt{n})解法 **分块**:  

预处理: 分别计算每个点逃出所在块时步数和最后一个洞编号. 复杂度![](https://latex.codecogs.com/svg.image?n\sqrt{n})

分块方法: 计算sqrtn记为sq, 然后开一数组记录分组, 每个下标/sq即为组号.

修改查询: 查询时从那个点开始, 依次查询预处理的结果. 复杂度根号n; 修改时只在块内重新跳一遍更新答案即可.

需要注意优化, 区间修改的时候, 在那个点后面的不受影响, 前面的会有影响, 需要从这个点往前修改直到第一个点, 这样复杂度比较低(O(1)). 

[Submission #144948477 - Codeforces](https://codeforces.com/contest/13/submission/144948477)

![](https://latex.codecogs.com/svg.image?nlogn)解法 **链剖(dsu)**


