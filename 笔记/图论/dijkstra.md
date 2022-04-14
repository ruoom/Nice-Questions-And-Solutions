# Dijkstra



### 	最短路径问题

求从图中一个点到另一个点的最短距离, 并输出路径.

* 迪杰斯特拉(Dijkstra) 用于有非负权的有向图或无向图的单个点求最短路径.
* [弗洛伊德(Floyd)](Floyd.md) 用于无负权回路的有向图或无向图的多个点求最短路径.
* [SPFA](SPFA.md) 用于有负权的图求最短路径.



### 预备数组

```c++
const int maxn = 1e5 + 5;
const int INF  = 1e9 + 9;
bool isok[maxn]; //保存点n是否已为最短路径 初始为0
int pre[maxn];   //到达此点最短路径的前一个点
int dist[maxn];  //到达此点的最短距离
memset(dist, INF, sizeof(dist));  //初始最短距离均为无穷
```



### 过程

先将`dist[a]`置零, 从自身出发到达自身的距离是0, 此时为最优,将$a$点标记, `isok[a]=1` . 然后从初始点$a$开始, 遍历$a$指向的所有未被标记过的点$p$, 将`dist[a]`和$(a,p)$的权值之和与`dist[p]`比较, 取两者中的最小值. 若更新了`dist[p]`的值,则将$a$点记录为$p$的前一个点, 即`pre[p]=a`. 

遍历过$a$指向的所有未被标记过的点后, 在所有未被标记过的点中寻找距离出发点最小的点, 也就是$min(dist[i])), (isok[i]≠1)$, 将其标记.

* 查找未被标记过的点中据出发点距离最小的点, 可使用优先队列.

当目标点$b$被标记时, 代表已找到最短路径, 最短距离即`dist[b]`, 最短路径可通过`pre`数组向前回溯.

时间复杂度$O(n^2)$.

使用堆优化, 时间复杂度$O(nlogn)$

#### 代码实现如下:

图的存储使用邻接vector表:

```c++
struct edge{
    int pt;  //此点
    int val;  //边权值
};
vector<edge> Map[maxn]; //Map[i] 存储i指向的所有顶点
void add(int a, int b, int c){//无向图, 两点互相添加
    Map[a].push_back(edge{b,c});
    Map[b].push_back(edge{a,c});
}
```

dijkstra算法, 无返回值, 传入出发点a和目标点b.

```c++
void dijkstra(int a, int b){
    dist[a] = 0;  isok[a] = 1;
    priority_queue<pair<int,int>,  //优先队列  优先dist 其次点号
    		vector<pair<int,int> >,greater<pair<int,int> > > m;
    do{
        for(auto& point : Map[a]) //遍历a点所指向的所有点
            if(!isok[point.pt])   //忽略标记过的点
                if(dist[a] + point.val < dist[point.pt]){ 
                    //由起点经由a到point更近 则更新dist和pre
                    dist[point.pt] = dist[a] + point.val;
                    pre[point.pt]  = a;
                    m.push(make_pair(dist[point.pt],point.pt));
                }
        //遍历所有a指向的点后, 找出未被标记的最佳的点
        //直接在优先队列中寻找, 丢弃已经被标记过的点
        while(!m.empty() && isok[m.top().second])
        {
            //在m不为空的前提下, 判断dist最短的点是否被标记
            //若被标记, 则将这个点移出队列
            m.pop();
        }
        if(!m.empty())//若此时队列还不为空, 则队列中第一个元素即我们要中的点
            a = m.top().second; //用a记录该点, 稍后进入下一轮循环
        else
            break;  //队列为空 所有能到达的点均已标记
        isok[a] = 1;//标记最佳的点
    }while(!m.empty());
}
```

在已经查找出路径后, 可使用`findPath()`函数查找最优路径

```c++
void findPath(int a, int b, stack<int>& path) {
    if (pre[b] == 0)return;
    path.push(b);
    do{
        path.push(pre[b]);
        b = pre[b];
    } while (pre[b] != 0);
}
```



#### [例题CF20C]([Problem - 20C - Codeforces](https://codeforces.com/problemset/problem/20/C))

AC代码:

```C++
#include<bits/stdc++.h>
#define int long long
#define ll long long 
#define ull unsigned long long
#define debug(x) cout << #x << " is " << x << endl
#define mkp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
using namespace std;
const int maxn = 1e5 + 5;
const int INF = 1e9 + 9;
bool isok[maxn]; //保存点n是否已为最短路径 初始为0
int pre[maxn];   //到达此点最短路径的前一个点
int dist[maxn];  //到达此点的最短距离
struct edge {
	int pt;  //此点
	int val;  //边权值
};
vector<edge> Map[maxn]; //Map[i] 存储i指向的所有顶点
void add(int a, int b, int c) {//无向图, 两点互相添加
	Map[a].push_back(edge{ b, c });
	Map[b].push_back(edge{ a, c });
}
void dijkstra(int a, int b) {
    dist[a] = 0;
    isok[a] = 1;
    priority_queue < pair<int, int>,  //优先队列  优先dist 其次点号
        vector < pair<int, int>>, greater<pair<int, int> > > m;
    do {
        for (auto& point : Map[a]) //遍历a点所指向的所有点
            if (!isok[point.pt])   //忽略标记过的点
                if (dist[a] + point.val < dist[point.pt]) {
                    //由起点经由a到point更近 则更新dist和pre
                    dist[point.pt] = dist[a] + point.val;
                    pre[point.pt] = a;
                    m.push(make_pair(dist[point.pt], point.pt));
                }
        //遍历所有a指向的点后, 找出未被标记的最佳的点
        //直接在优先队列中寻找, 丢弃已经被标记过的点
        while (!m.empty() && isok[m.top().second])
        {
            //在m不为空的前提下, 判断dist最短的点是否被标记
            //若被标记, 则将这个点移出队列
            m.pop();
        }
        if (!m.empty())//若此时队列还不为空, 则队列中第一个元素即我们要中的点
            a = m.top().second; //用a记录该点, 稍后进入下一轮循环
        else
            break;  //队列为空 所有能到达的点均已标记
        isok[a] = 1;//标记最佳的点
    } while (!m.empty());
}
void findPath(int a, int b, stack<int>& path) {
    if (pre[b] == 0)return;
    path.push(b);
    do{
        path.push(pre[b]);
        b = pre[b];
    } while (pre[b] != 0);
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(dist, INF, sizeof(dist));  //初始最短距离均为无穷
	int n, m;
	cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    dijkstra(1, n);
    stack<int> ans;
    findPath(1, n, ans);
    if (ans.empty())
        cout << -1;
    else
        while (!ans.empty()){
            cout << ans.top() << " ";
            ans.pop();
        }
	return 0;
}

```

