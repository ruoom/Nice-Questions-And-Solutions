# 最大公约数



### 欧几里得算法(辗转相除法)

```c++
int gcd(int x,int y){
    int t;
    while( y > 0 ){
        t = x % y;
        x = y;
        y = t;
    }
    return x;
}
```





### 扩展欧几里得算法

常用于求$ax+by=gcd(a,b)$的一组解.

```c++
int exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int d = exgcd(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}
```





#### O(值域)预处理, O(1)查询

##### 预处理

```c++
const int mod = 998244353;

const int M = 1000000;
const int T = 1000;

int pre[T + 2][T + 2];
int fac[M + 2][3];
bool isp[M + 2];
int pri[M / 10], tot;

// fac为合法分解，isp表示是否非质数，pri为质数数组，tot为pri的大小，pre为预处理的gcd数组，M为值域，T为sqrt(M)
void work() {
    fac[1][0] = fac[1][1] = fac[1][2] = 1;
    for (int i = 2; i <= M; ++i) {
        if (!isp[i]) {
            fac[i][0] = fac[i][1] = 1;
            fac[i][2] = i;
            pri[++tot] = i;
        }
        for (int j = 1; pri[j] * i <= M; ++j) {
            int tmp = pri[j] * i;
            isp[tmp] = true;
            fac[tmp][0] = fac[i][0] * pri[j];
            fac[tmp][1] = fac[i][1];
            fac[tmp][2] = fac[i][2];
            if (fac[tmp][0] > fac[tmp][1]) {
                fac[tmp][0] ^= fac[tmp][1] ^= fac[tmp][0] ^= fac[tmp][1];
            }
            if (fac[tmp][1] > fac[tmp][2]) {
                fac[tmp][1] ^= fac[tmp][2] ^= fac[tmp][1] ^= fac[tmp][2];
            }
            // 对于整数运算a ^= b ^= a ^= b等价于swap(a, b)这里就是手动进行length = 3的排序
            if (i % pri[j] == 0) {
                break;
            }
        }
    }
    for (int i = 0; i <= T; ++i) {
        pre[0][i] = pre[i][0] = i;
    }
    for (int i = 1; i <= T; ++i) {
        for (int j = 1; j <= i; ++j) {
            pre[i][j] = pre[j][i] = pre[j][i % j];
        }
    }
}
```



##### 查询

```cpp
int qgcd(int a, int b) {
    int ans = 1;
    for (int i = 0; i < 3; ++i) {
        int tmp = (fac[a][i] > T) ?(b % fac[a][i] ?1: fac[a][i])
            : pre[fac[a][i]][b % fac[a][i]];
        b /= tmp;
        ans *= tmp;
    }
    return ans;
}
```
