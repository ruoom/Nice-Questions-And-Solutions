# [D. Empty Graph](https://codeforces.com/problemset/problem/1712/D)

## tags
`binary search` `constructive algorithms` `data structures` `greedy` `shortest paths` `*2000` 

## description

An array of n positive integers a1,a2,…,an fell down on you from the skies, along with a positive integer k≤n.

You can apply the following operation at most k times:

Choose an index 1≤i≤n and an integer 1≤x≤109. Then do ai:=x (assign x to ai).
Then build a complete undirected weighted graph with n vertices numbered with integers from 1 to n, where edge (l,r) (1≤l<r≤n) has weight min(al,al+1,…,ar).

You have to find the maximum possible diameter of the resulting graph after performing at most k operations.

The diameter of a graph is equal to max1≤u<v≤nd(u,v), where d(u,v) is the length of the shortest path between vertex u and vertex v.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). Description of the test cases follows.

The first line of each test case contains two integers n and k (2≤n≤105, 1≤k≤n).

The second line of each test case contains n positive integers a1,a2,…,an (1≤ai≤109).

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case print one integer — the maximum possible diameter of the graph after performing at most k operations.

## input
```
6
3 1
2 4 1
3 2
1 9 84
3 1
10 2 6
3 2
179 17 1000000000
2 1
5 9
2 2
4 2
```

## output
```
4
168
10
1000000000
9
1000000000
```


## note

In the first test case, one of the optimal arrays is [2,4,5].

The graph built on this array:

![image](https://user-images.githubusercontent.com/44316768/186426077-8066e686-bb78-4096-844a-ed44a5aa48ff.png)

d(1,2)=d(1,3)=2 and d(2,3)=4, so the diameter is equal to max(2,2,4)=4.
