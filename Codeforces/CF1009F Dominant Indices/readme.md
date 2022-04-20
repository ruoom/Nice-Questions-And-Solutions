# [Problem - 1009F - Codeforces](https://codeforces.com/problemset/problem/1009/F)

# tags
`data structures` `dsu` `trees` `*2300` 

# description

You are given a rooted undirected tree consisting of nn vertices. Vertex 11 is the root.

Let's denote a depth array of vertex xx as an infinite sequence [dx,0,dx,1,dx,2,…][dx,0,dx,1,dx,2,…], where dx,idx,i is the number of vertices yy such that both conditions hold:

xx is an ancestor of yy;
the simple path from xx to yy traverses exactly ii edges.
The dominant index of a depth array of vertex xx (or, shortly, the dominant index of vertex xx) is an index jj such that:

for every k<jk<j, dx,k<dx,jdx,k<dx,j;
for every k>jk>j, dx,k≤dx,jdx,k≤dx,j.
For every vertex in the tree calculate its dominant index.

Input
The first line contains one integer nn (1≤n≤1061≤n≤106) — the number of vertices in a tree.

Then n−1n−1 lines follow, each containing two integers xx and yy (1≤x,y≤n1≤x,y≤n, x≠yx≠y). This line denotes an edge of the tree.

It is guaranteed that these edges form a tree.

Output
Output nn numbers. ii-th number should be equal to the dominant index of vertex ii.

给n个结点的无向图, 1是根节点. 设d(x,i)是以x为根节点, 距离为y的结点个数. 

对于每一个节点i , 求出一个下标j: 对于k<j, d(i,k) < d(i,j) 对于k>j, d(i,k) <= d(i,j)

也就是找到结点数最多的那一层(第一次出现).

## input
```
4
1 2
2 3
3 4
```
## output
```
0
0
0
0
```

## input
```
4
1 2
1 3
1 4
```

## output
```
1
0
0
0
```

# solution

**dsu on tree**

前几天做了很多类似的, 这个题可以不用看题解就能做出来了, 用dsu求每个根节点下每层的结点数, 用cnt数组记录, 并记录最大的位置. 要注意这个是要求最先出现的最大值, 判断的时候分两种情况, 大于的话直接覆盖, 等于的时候判断深度, 小于则覆盖.

