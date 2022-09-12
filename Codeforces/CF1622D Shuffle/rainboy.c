#include <stdio.h>

#define N	5000
#define MD	998244353

int vv[N + 1], ff[N + 1], gg[N + 1];

void init() {
	int i;

	ff[0] = gg[0] = 1;
	for (i = 1; i <= N; i++) {
		vv[i] = i == 1 ? 1 : (long long) vv[i - MD % i] * (MD / i + 1) % MD;
		ff[i] = (long long) ff[i - 1] * i % MD;
		gg[i] = (long long) gg[i - 1] * vv[i] % MD;
	}
}

int choose(int n, int k) {
	return k < 0 || k > n ? 0 : (long long) ff[n] * gg[k] % MD * gg[n - k] % MD;
}

int main() {
	static char cc[N + 1];
	int n, k_, i, j, k, ans;

	init();
	scanf("%d%d%s", &n, &k_, cc);
	k = 0;
	for (i = 0; i < n; i++)
		if (cc[i] == '1')
			k++;
	if (k < k_) {
		printf("1\n");
		return 0;
	}
	ans = 1;
	for (i = 0; i < n; i++) {
		k = cc[i] == '1' ? 1 : 0;
		for (j = i + 1; j < n; j++) {
			if (cc[j] == '1')
				k++;
			if (k <= k_)
				ans = (ans + choose(j - i - 1, k - (cc[i] == '1' ? 0 : 1) - (cc[j] == '1' ? 0 : 1))) % MD;
		}
	}
	printf("%d\n", ans);
	return 0;
}
