int flag[N], phi[N], prime[N], num = 0;
void euler(int n = N - 1) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (flag[i] == 0){
            prime[++num] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= num && prime[j] * i <= n; j++){
            flag[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
}
