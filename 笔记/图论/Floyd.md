#  Floyd



### 	最短路径问题

求从图中一个点到另一个点的最短距离, 并输出路径.

* [迪杰斯特拉(Dijkstra)](dijkstra.md) 用于有非负权的有向图或无向图的单个点求最短路径.
* 弗洛伊德(Floyd) 用于无负权回路的有向图或无向图的多个点求最短路径.
* [SPFA](SPFA.md) 用于有负权的图求最短路径.



**适用范围：无负权回路即可，边权可正可负，运行一次算法即可求得任意两点间最短路。(多源最短) **

**若固定起点, 求单源最短, 可以用[Bellman-Ford]()算法**

图使用邻接矩阵存储:

```c++
const int maxn = 105;
int mp[maxn][maxn];
```



核心代码:

```c++
for(int k = 1; k <= n; ++k)
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(dist[i][j] > dist[i][k] + dist[k][j])
                dist[i][j] = dist[i][k] + dist[k][j];
```

每次循环找出前$k-1$个点的最短路径. 



#### 求最小环

要多定义一个数组来存储实际边

```c++
int w[maxn][maxn];
```



在每次Floyd前找边, 用$i$到$j$的最短距离$+$$i$到$k$和$j$到$k$的实际距离, 与`ans`作比较.

```c++
for (int k = 1; k <= t; ++k){
	for (int i = 1; i < k; ++i)
		for (int j = i + 1; j < k; ++j)
			ans = min(ans, mp[i][j] + w[k][i] + w[j][k]);

	for (int i = 1; i <= t; ++i)
		for (int j = 1; j <= t; ++j)
			mp[i][j] = mp[j][i] = min(mp[i][j], mp[i][k] + mp[k][j]);
}
```



##### 例题:

[CF25C]([Problem - 25C - Codeforces](https://codeforces.com/problemset/problem/25/C))

[CF1205B]([Problem - 1205B - Codeforces](https://codeforces.com/problemset/problem/1205/B))

[洛谷P6175]([P6175 无向图的最小环问题 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P6175))

[洛谷P2888]([P2888 [USACO07NOV\]Cow Hurdles S - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P2888))

