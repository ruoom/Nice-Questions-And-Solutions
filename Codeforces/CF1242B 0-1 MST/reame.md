# [CF1242B](https://codeforces.com/problemset/problem/1242/B)

# tags
`dfs and similar` `dsu` `graphs` `sortings` `*1900`

# description
Ujan has a lot of useless stuff in his drawers, a considerable part of which are his math notebooks: it is time to sort them out. This time he found an old dusty graph theory notebook with a description of a graph.

It is an undirected weighted graph on nn vertices. It is a complete graph: each pair of vertices is connected by an edge. The weight of each edge is either 00 or 11; exactly mm edges have weight 11, and all others have weight 00.

Since Ujan doesn't really want to organize his notes, he decided to find the weight of the minimum spanning tree of the graph. (The weight of a spanning tree is the sum of all its edges.) Can you find the answer for Ujan so he stops procrastinating?

Input
The first line of the input contains two integers nn and mm (1≤n≤1051≤n≤105, 0≤m≤min(n(n−1)2,105)0≤m≤min(n(n−1)2,105)), the number of vertices and the number of edges of weight 11 in the graph.

The ii-th of the next mm lines contains two integers aiai and bibi (1≤ai,bi≤n1≤ai,bi≤n, ai≠biai≠bi), the endpoints of the ii-th edge of weight 11.

It is guaranteed that no edge appears twice in the input.

Output
Output a single integer, the weight of the minimum spanning tree of the graph.

## input
```
6 11
1 3
1 4
1 5
1 6
2 3
2 4
2 5
2 6
3 4
3 5
3 6
```
## output
```
2
```

## input
```
3 0
```

## output
```
0
```

Note
The graph from the first sample is shown below. Dashed edges have weight 00, other edges have weight 11. One of the minimum spanning trees is highlighted in orange and has total weight 22.

![](https://espresso.codeforces.com/d7579dba606d56379186e72951e611825b4bb38f.png)

In the second sample, all edges have weight 00 so any spanning tree has total weight 00.

