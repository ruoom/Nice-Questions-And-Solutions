# [CF1661C](https://codeforces.com/problemset/problem/1661/C)

# tags
`binary search` `greedy` `math` `*1700`

# description

There are nn trees in a park, numbered from 11 to nn. The initial height of the ii-th tree is hihi.

You want to water these trees, so they all grow to the same height.

The watering process goes as follows. You start watering trees at day 11. During the jj-th day you can:

Choose a tree and water it. If the day is odd (e.g. 1,3,5,7,…1,3,5,7,…), then the height of the tree increases by 11. If the day is even (e.g. 2,4,6,8,…2,4,6,8,…), then the height of the tree increases by 22.
Or skip a day without watering any tree.
Note that you can't water more than one tree in a day.

Your task is to determine the minimum number of days required to water the trees so they grow to the same height.

You have to answer tt independent test cases.

Input
The first line of the input contains one integer tt (1≤t≤2⋅1041≤t≤2⋅104) — the number of test cases.

The first line of the test case contains one integer nn (1≤n≤3⋅1051≤n≤3⋅105) — the number of trees.

The second line of the test case contains nn integers h1,h2,…,hnh1,h2,…,hn (1≤hi≤1091≤hi≤109), where hihi is the height of the ii-th tree.

It is guaranteed that the sum of nn over all test cases does not exceed 3⋅1053⋅105 (∑n≤3⋅105∑n≤3⋅105).

Output
For each test case, print one integer — the minimum number of days required to water the trees, so they grow to the same height.

## input
```
3
3
1 2 4
5
4 4 3 5 5
7
2 5 4 8 3 7 4
```

## output
```
4
3
16
```
Note
Consider the first test case of the example. The initial state of the trees is [1,2,4][1,2,4].

During the first day, let's water the first tree, so the sequence of heights becomes [2,2,4][2,2,4];
during the second day, let's water the second tree, so the sequence of heights becomes [2,4,4][2,4,4];
let's skip the third day;
during the fourth day, let's water the first tree, so the sequence of heights becomes [4,4,4][4,4,4].
Thus, the answer is 44.


