# [Problem - 1311E - Codeforces](https://codeforces.com/problemset/problem/1311/E)

# tags
`brute force` `constructive algorithms` `trees` `*2200` 

# description
You are given two integers nn and dd. You need to construct a rooted binary tree consisting of nn vertices with a root at the vertex 11 and the sum of depths of all vertices equals to dd.

A tree is a connected graph without cycles. A rooted tree has a special vertex called the root. A parent of a vertex vv is the last different from vv vertex on the path from the root to the vertex vv. The depth of the vertex vv is the length of the path from the root to the vertex vv. Children of vertex vv are all vertices for which vv is the parent. The binary tree is such a tree that no vertex has more than 22 children.

You have to answer tt independent test cases.

Input
The first line of the input contains one integer tt (1≤t≤10001≤t≤1000) — the number of test cases.

The only line of each test case contains two integers nn and dd (2≤n,d≤50002≤n,d≤5000) — the number of vertices in the tree and the required sum of depths of all vertices.

It is guaranteed that the sum of nn and the sum of dd both does not exceed 50005000 (∑n≤5000,∑d≤5000∑n≤5000,∑d≤5000).

Output
For each test case, print the answer.

If it is impossible to construct such a tree, print "NO" (without quotes) in the first line. Otherwise, print "{YES}" in the first line. Then print n−1n−1 integers p2,p3,…,pnp2,p3,…,pn in the second line, where pipi is the parent of the vertex ii. Note that the sequence of parents you print should describe some binary tree.

给n和d, 分别代表一个二叉树树的节点总数和每个结点的深度之和. 请你构造出这样的一棵树.

## input
```
3
5 7
10 19
10 18
```

## output
```
YES
1 2 1 3 
YES
1 2 3 3 9 9 2 1 6 
NO
```
## Note
Pictures corresponding to the first and the second test cases of the example:

![](https://espresso.codeforces.com/94d2346ee349d5dcb535dcd106cfbaa389c1b21c.png)
![](https://espresso.codeforces.com/c6a4bb4f01e3c79a7c34c54ab163323733690f43.png)

# solution

先生成一颗完全二叉树, 对应深度之和最小的情况.

然后每次从最深层开始往前找, 每次拿一个叶子节点移动到下一层.

最后根据每层的结点数随便构造一棵树.

