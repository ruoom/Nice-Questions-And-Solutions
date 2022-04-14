#### 费马小定理

$a^{p-1}≡1(mod p)$

若$p$为质数, 则对于任意自然数$a$, 满足

$a^p \equiv a \ (mod\ p) $

$ \Rightarrow a^{p-1} \equiv 1\ (mod\ p)$ 即

$a^{p-1}\ mod\ p =1$ 

而满足此式的$p$ 不一定是质数, 如561:

$5^{561}\ \%\ 561 = 5$

但561不是素数, 它能被3整除.

这类数叫做卡迈克尔数(Carmichael Number).

所以将此条性质反过来用, 除了卡迈克尔数都能判断.

#### 二次探测

若$p$是质数, 则满足方程

$a^2 \equiv \ 1 (mod\ p)$ 即

$a^2\ mod\ p = 1$ 



### 模板

```c++
//Miller_Rabbin素性检测 复杂度最高O(klgn) k为检验次数

bool Miller_Rabbin(int n) {
    if (n == 2)
        return true;
    if (n < 2 || !(n & 1))return false;
    int x, y, a, m = n - 1;
    int k = 0;
    while ((m & 1) == 0) {
        k++; m >>= 1;
    }
    for (int i = 0; i < 5; ++i) {
        a = rand() % (n - 2) + 2;
        x = qpow(a, m, n);
        y = 0;
        for (int j = 0; j < k; ++j) {
            y = qmul(x, x, n);
            if (y == 1 && x != 1 && x != n - 1)return false;
            x = y;
        }
        if (y != 1)return false;
    }
    return true;
}
```

