# [CF1520F1](https://codeforces.com/contest/1520/problem/F1)
**and**
# [CF1520F2](https://codeforces.com/contest/1520/problem/F2)

# tags
`binary search` `interactive` `*1600`

`binary search` `constructive algorithms` `data structures` `interactive` `*2200`


# description

This is an interactive problem.

This is a hard version of the problem. The difference from the easy version is that in the hard version 1≤t≤min(n,104)1≤t≤min(n,104) and the total number of queries is limited to 6⋅1046⋅104.

Polycarp is playing a computer game. In this game, an array consisting of zeros and ones is hidden. Polycarp wins if he guesses the position of the kk-th zero from the left tt times.

Polycarp can make no more than 6⋅1046⋅104 requests totally of the following type:

? ll rr — find out the sum of all elements in positions from ll to rr (1≤l≤r≤n1≤l≤r≤n) inclusive.
To make the game more interesting, each guessed zero turns into one and the game continues on the changed array. More formally, if the position of the kk-th zero was xx, then after Polycarp guesses this position, the xx-th element of the array will be replaced from 00 to 11.

Help Polycarp win the game.

Interaction
First, your program must read two integers nn and tt (1≤n≤2⋅1051≤n≤2⋅105, 1≤t≤min(n,104)1≤t≤min(n,104)).

Then tt lines follow, each of which contains one integer kk (1≤k≤n1≤k≤n). It is guaranteed that at the moment of the request the array contains at least kk zeros. In order to get the next value of kk, you must output the answer for the previous value of kk.

After that, you can make no more than 6⋅1046⋅104 requests in total.

Use the following format to output the answer (it is not a request, it doesn't count in 6⋅1046⋅104):

! xx — position of the kk-th zero.
Positions in the array are numbered from left to right from 11 to nn inclusive.

After printing tt answers, your program should exit immediately.

In this task, the interactor is not adaptive. This means that within the same test, the hidden array and the queries do not change.

In case of an incorrect query, -1 will be displayed. When this value is received, your program must immediately exit normally (for example, by calling exit(0)), otherwise, the testing system may issue an arbitrary verdict.

If the number of requests is exceeded, the verdict wrong answer will be displayed.

Your solution may get the verdict Idleness limit exceeded if you don't print anything or forget to flush the output buffer.

To flush the output buffer, you need to do the following immediately after the query output and the end-of-line character:

fflush(stdout) or cout.flush() in C ++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
see the documentation for other languages.


## input
```
6 2

2

2

1

1

0

1

0
```


## output
```
? 4 6

? 1 1

? 1 2

? 5 5

! 5

? 2 2

! 2

```


# Solution

## unoexp

简单版本的二分从1~i的值就可以了.

加强版的算下来每个例子只能有6次询问, 所以要换方法了. 

我们可以记录下每次询问得到的结果.

每次得到答案以后, 对应位置的数字会从0变为1, 所以可以记录从1~i位置有几个0变为了1, 可以用树状数组来维护.

每次询问, 我们将询问的值保存起来, 但不能保存为当前的值, 而应记录转化为初始数组后的值. 这个值为x-sum(i)

查询时, 如果有保存的结果, 我们将这个结果+sum(i)就是当前的正确的值, 就不需要再询问一次了.


