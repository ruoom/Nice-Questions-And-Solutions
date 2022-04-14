查找最大质因数

```c++
int big_fac(int n)
{   
    int p = 1;
    while(n > 1)
    {
        p++;
        while(n % p == 0)
            n /= p; 
    }
    return p;
}

```





### PR模板

```c++
//复杂度O(N^1/4)
int Pollard_Rho(int n) {
    int x, y, z;
    int c, d, i, k;

    while (1) {
        y = x = rand() % n;
        z = 1;
        c = rand() % n;
        i = 0; k = 1;
        while (++i) {                   //XXX
            x = (qmul(x, x, n) + c) % n;
            //z = abs(y - x) % n;
            z = qmul(z, abs(y - x), n); //XXX
            if (y == x ) break;         //XXX
            if (!(i % 127) || i == k) { //XXX
                d = gcd(z, n);
                if (1 < d)return d;
                if (i == k)y = x, k <<= 1;
            }
        }
    }
}
```



#### 用PR找最大质因数模板

[P4718 【模板】Pollard-Rho算法]([P4718 【模板】Pollard-Rho算法 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P4718))

```c++
int ans;

void find(int n) {
    if (n <= 1)return;
    if (ans >= n)return;
    int p = n;
    if (MR(n)) {
        ans = n > ans ? n : ans;
        return;
    }
    while (p >= n) 
        p = PR(n);
    while ((n % p) == 0)
        n /= p;
    find(n); find(p);
}
```

