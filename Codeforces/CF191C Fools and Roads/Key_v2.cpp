/* ***********************************************************************
    > File name: hdu.cpp
    > Author: Key
    > Mail: keyld777@gmail.com
    > Created Time: Mon 12 Jun 2017 04:20:26 PM CST
 ********************************************************************** */
#include <bits/stdc++.h>

#define each(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define reach(i, n) for (int(i) = n - 1; (i) >= 0; (i)--)
#define range(i, st, en) for (int(i) = (st); (i) <= (en); (i)++)
#define rrange(i, st, en) for (int(i) = (en); (i) >= (st); (i)--)
#define fill(ary, num) memset((ary), (num), sizeof(ary))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

struct node {
    int to, next;
} edges[maxn << 1], qedges[maxn << 1];
int head[maxn], idx;
int qhead[maxn], qidx;
int cnt[maxn];
int root[maxn], id[maxn];
bool qvis[maxn], vis[maxn];

void addEdge(node* E, int* H, int& id, int u, int v)
{
    E[id] = (node){ v, H[u] };
    H[u] = id++;
    E[id] = (node){ u, H[v] };
    H[v] = id++;
}

int findRoot(int x) { return root[x] == x ? x : root[x] = findRoot(root[x]); }

int tarjan(int u)
{
    root[u] = u;
    vis[u] = true;
    for (int id = qhead[u]; ~id; id = qedges[id].next) {
        int v = qedges[id].to;
        if (vis[v] && !qvis[id / 2]) {
            cnt[findRoot(v)] -= 2;
            qvis[id / 2] = true;
        }
    }
    for (int i = head[u]; ~i; i = edges[i].next) {
        int v = edges[i].to;
        if (!vis[v]) {
            id[i / 2] = v;
            cnt[u] += tarjan(v);
            root[v] = u;
        }
    }
    return cnt[u];
}

int main()
{
    int n, u, v, m;
    scanf("%d", &n);
    fill(head, -1), fill(qhead, -1);
    range(i, 2, n)
    {
        scanf("%d %d", &u, &v);
        addEdge(edges, head, idx, u, v);
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &u, &v);
        cnt[u]++, cnt[v]++;
        addEdge(qedges, qhead, qidx, u, v);
    }
    tarjan(1);
    each(i, n - 1) printf("%d ", cnt[id[i]]);
    return 0;
}
