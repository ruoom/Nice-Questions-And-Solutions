# [CF1609D](https://codeforces.com/contest/1609/problem/D)

# tags
`dsu` `graphs` `greedy` `implementation` `trees` `*1600`

# description
William arrived at a conference dedicated to cryptocurrencies. Networking, meeting new people, and using friends' connections are essential to stay up to date with the latest news from the world of cryptocurrencies.

The conference has n participants, who are initially unfamiliar with each other. William can introduce any two people, a and b, who were not familiar before, to each other.

William has d conditions, i'th of which requires person xi to have a connection to person yi. Formally, two people x and y have a connection if there is such a chain p1=x,p2,p3,…,pk=y for which for all i from 1 to k−1 it's true that two people with numbers pi and pi+1 know each other.

For every i (1≤i≤d) William wants you to calculate the maximal number of acquaintances one person can have, assuming that William satisfied all conditions from 1 and up to and including i and performed exactly i introductions. The conditions are being checked after William performed i introductions. The answer for each i must be calculated independently. It means that when you compute an answer for i, you should assume that no two people have been introduced to each other yet.

Input
The first line contains two integers n and d (2≤n≤103,1≤d≤n−1), the number of people, and number of conditions, respectively.

Each of the next d lines each contain two integers xi and yi (1≤xi,yi≤n,xi≠yi), the numbers of people which must have a connection according to condition i.

Output
Output d integers. ith number must equal the number of acquaintances the person with the maximal possible acquaintances will have, if William performed i introductions and satisfied the first i conditions.

## input
```
7 6
1 2
3 4
2 4
7 6
6 5
1 7
```

## output
```
1
1
3
3
3
6
```

## input
```
10 8
1 2
2 3
3 4
1 4
6 7
8 9
8 10
1 4
```

## output
```
1
2
3
4
5
5
6
8
```

Note
The explanation for the first test case:

In this explanation, the circles and the numbers in them denote a person with the corresponding number. The line denotes that William introduced two connected people. The person marked with red has the most acquaintances. These are not the only correct ways to introduce people.

![](https://espresso.codeforces.com/758cd71474e38e42aa7fbd9646140431c4e6641c.png)
