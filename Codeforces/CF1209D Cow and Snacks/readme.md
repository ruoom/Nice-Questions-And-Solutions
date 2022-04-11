# [CF1209D Cow and Snacks](https://codeforces.com/problemset/problem/1209/D)
# tags
`dfs and similar` `dsu` `graphs` `*1700`
# description
The legendary Farmer John is throwing a huge party, and animals from all over the world are hanging out at his house. His guests are hungry, so he instructs his cow Bessie to bring out the snacks! Moo!

There are n snacks flavors, numbered with integers 1,2,…,n. Bessie has n snacks, one snack of each flavor. Every guest has exactly two favorite flavors. The procedure for eating snacks will go as follows:

First, Bessie will line up the guests in some way.
Then in this order, guests will approach the snacks one by one.
Each guest in their turn will eat all remaining snacks of their favorite flavor. In case no favorite flavors are present when a guest goes up, they become very sad.
Help Bessie to minimize the number of sad guests by lining the guests in an optimal way.

Input
The first line contains integers n and k (2≤n≤105, 1≤k≤105), the number of snacks and the number of guests.

The i-th of the following k lines contains two integers xi and yi (1≤xi,yi≤n, xi≠yi), favorite snack flavors of the i-th guest.

Output
Output one integer, the smallest possible number of sad guests.
## input
```
5 4
1 2
4 3
1 4
3 4
```
## output
```
1
```

## input
```
6 5
2 3
2 1
3 4
6 5
4 5
```
## output
```
0
```
