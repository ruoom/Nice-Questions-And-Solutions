# [CF1537E1](https://codeforces.com/problemset/problem/1537/E1)
**AND**
# [CF1537E2](https://codeforces.com/problemset/problem/1537/E2)

# tags
`binary search` `brute force` `dp` `greedy` `hashing` `implementation` `string suffix structures` `strings` `two pointers` `*1600`

`binary search` `data structures` `greedy` `hashing` `string suffix structures` `strings` `two pointers` `*2200`


# description

You have a string ss, and you can do two types of operations on it:

Delete the last character of the string.
Duplicate the string: s:=s+ss:=s+s, where ++ denotes concatenation.
You can use each operation any number of times (possibly none).

Your task is to find the lexicographically smallest string of length exactly kk that can be obtained by doing these operations on string ss.

A string aa is lexicographically smaller than a string bb if and only if one of the following holds:

aa is a prefix of bb, but a≠ba≠b;
In the first position where aa and bb differ, the string aa has a letter that appears earlier in the alphabet than the corresponding letter in bb.
Input
The first line contains two integers nn, kk (1≤n,k≤50001≤n,k≤5000) — the length of the original string ss and the length of the desired string.

The second line contains the string ss, consisting of nn lowercase English letters.

Output
Print the lexicographically smallest string of length kk that can be obtained by doing the operations on string ss.

## input
```
8 16
dbcadabc
```

## output
```
dbcadabcdbcadabc
```

## input
```
4 5
abcd
```

## output
```
aaaaa
```


# Solution
不难发现找到一个最小的前缀(循环) 把他循环以后取前k个就是答案

然后考虑如何找到最小的前缀

前面找了几种方法 不是wa就是T, 感觉太麻烦了

简单想一想 每次和第一个比 大于的话后面的肯定也不行  直接break

小于的话可以加入进来

问题是等于的时候

可以发现等于的时候 只考虑当前位是判断不了加还是不加的

但是可以确定下次比较肯定比第二个

所以用一个变量c来记录需要对比的位置

遇到相同的就把变量c+1

遇到不同的时候 如果可以加入 就将把从当前-c到当前位置的所有都加入进来

否则不加入 直接break

想出办法来了就不难


