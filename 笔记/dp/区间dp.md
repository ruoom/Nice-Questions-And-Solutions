给定长为n的序列a[i]，每次可以将连续一段回文序列消去，消去后左右两边会接到一起，求最少消几次能消完整个序列，n≤500。









区间DP的做法较为固定，即枚举区间长度，再枚举左端点，之后枚举区间的断点进行转移。





#### 例题

[CF1312E]([Problem - E - Codeforces](https://codeforces.com/contest/1312/problem/E))

