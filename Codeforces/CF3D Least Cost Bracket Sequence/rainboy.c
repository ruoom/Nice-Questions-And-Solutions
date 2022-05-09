#include <stdio.h>
#include <string.h>

#define N	50000

int dd[N], pq[N + 1];
int k;

int i2(int i) {
	i *= 2;
	if (i > k)
		return 0;
	return i + 1 <= k && dd[pq[i]] > dd[pq[i + 1]] ? i + 1 : i;
}

void pq_dn(int i) {
	int j, idx;

	for (idx = pq[i]; (j = i2(i)) > 0 && dd[pq[j]] < dd[idx]; i = j)
		pq[i] = pq[j];
	pq[i] = idx;
}

void pq_up(int i) {
	int j, idx;

	for (idx = pq[i]; (j = i / 2) > 0 && dd[pq[j]] > dd[idx]; i = j)
		pq[i] = pq[j];
	pq[i] = idx;
}

int pq_remove_first() {
	int idx = pq[1];

	pq[1] = pq[k--];
	pq_dn(1);
	return idx;
}

void pq_add(int idx) {
	pq[++k] = idx;
	pq_up(k);
}

int main() {
	static char cc[N + 1];
	int n, i, j, cnt, a, b;
	long long cost;

	scanf("%s", cc);
	n = strlen(cc);
	cnt = 0;
	cost = 0;
	k = 0;
	for (i = 0; i < n; i++) {
		if (cc[i] == '(')
			cnt++;
		else if (cc[i] == ')')
			cnt--;
		else {
			scanf("%d%d", &a, &b);
			cnt--;
			cost += b;
			dd[i] = a - b;
			pq_add(i);
			cc[i] = ')';
		}
		if (cnt < 0) {
			if (k == 0) {
				printf("-1\n");
				return 0;
			}
			cnt += 2;
			j = pq_remove_first();
			cost += dd[j];
			cc[j] = '(';
		}
	}
	if (cnt > 0)
		printf("-1\n");
	else
		printf("%lld\n%s\n", cost, cc);
	return 0;
}
