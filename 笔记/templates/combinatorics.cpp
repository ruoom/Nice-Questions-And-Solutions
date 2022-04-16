
const int mod = 1e9 + 7;

const int N = 200005;
vector<int> fac(N), inv(N);

void init(){
    fac[0] = inv[0] = 1;
    for(int i = 1; i < N; ++i){
        fac[i] = fac[i-1] * i % mod;
        inv[i] = qpow(fac[i], mod-2, mod);
    }
}
int C(int n, int m){
    return fac[n] * inv[m] % mod * inv[n-m] % mod;
}
int stling2(int n, int m){
    if(n < m) return 0;
    if(n >= 1 && m == 1)return 1;
    int res = 0;
    for(int k = 0, f = 1; k <= m; ++k, f = -f){
        res += f * C(m,k) * qpow(m-k,n,mod) % mod;
    }
    return res % mod;
}
//-------------------------------------------------------------------------------------

int C(int m, int n, int p)
{
    return m < n ? 0 : fac[m] * inv[n] % p * inv[m - n] % p;
}
int lucas(int m, int n, int p)
{
    return n == 0 ? 1 % p : lucas(m / p, n / p, p) * C(m % p, n % p, p) % p;
}

//-------------------------------------------------------------------------------------
