#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline int read()
{
    int ans = 0;
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c))
    {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans;
}
const int MAXN = 2e5 + 5, MAXQ = 2e5 + 5, MAXM = 1e6 + 5;
int sq;
struct query // 把询问以结构体方式保存
{
    int l, r, id;
    bool operator<(const query &o) const // 重载<运算符，奇偶化排序
    {
        if (l / sq != o.l / sq)
            return l < o.l;
        if (l / sq & 1)
            return r < o.r;
        return r > o.r;
    }
} Q[MAXQ];
int A[MAXN], Cnt[MAXM], l = 1, r = 0;
ll cur, ans[MAXQ];
inline void add(int p)
{
    cur += 1ll * (Cnt[A[p]] * 2 + 1) * A[p];
    Cnt[A[p]]++;
}
inline void del(int p)
{
    cur -= 1ll * (Cnt[A[p]] * 2 - 1) * A[p];
    Cnt[A[p]]--;
}
int main()
{
    int n = read(), q = read();
    sq = sqrt(n);
    for (int i = 1; i <= n; ++i)
        A[i] = read();
    for (int i = 0; i < q; ++i)
        Q[i].l = read(), Q[i].r = read(), Q[i].id = i; // 把询问离线下来
    sort(Q, Q + q);                                    // 排序
    for (int i = 0; i < q; ++i)
    {
        while (l < Q[i].l)
            del(l++);
        while (l > Q[i].l)
            add(--l);
        while (r < Q[i].r)
            add(++r);
        while (r > Q[i].r)
            del(r--);
        ans[Q[i].id] = cur; // 储存答案
    }
    for (int i = 0; i < q; ++i)
        printf("%lld\n", ans[i]); // 按编号顺序输出
    return 0;
}
