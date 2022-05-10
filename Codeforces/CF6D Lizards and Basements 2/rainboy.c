#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int ****alloc(int a, int b, int c, int d) {
	int ****aaa, i, j, k;

	aaa = malloc(a * sizeof *aaa);
	for (i = 0; i < a; i++) {
		aaa[i] = malloc(b * sizeof *aaa[i]);
		for (j = 0; j < b; j++) {
			aaa[i][j] = malloc(c * sizeof *aaa[i][j]);
			for (k = 0; k < c; k++)
				aaa[i][j][k] = malloc(d * sizeof *aaa[i][j][k]);
		}
	}
	return aaa;
}

int ****dp, ****ii, ****hh0, ****hh1, ****hh2, *hh;

void print(int i, int h0, int h1, int h2) {
	if (i < 0)
		return;
	print(ii[i][h0][h1][h2], hh0[i][h0][h1][h2], hh1[i][h0][h1][h2], hh2[i][h0][h1][h2]);
	if (ii[i][h0][h1][h2] == i)
		printf("%d ", i + 1);
}

int main() {
	int n, a, b, i, h, h0, h1, h2;

	scanf("%d%d%d", &n, &a, &b);
	hh = malloc(n * sizeof *hh);
	h = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &hh[i]);
		hh[i]++;
		if (h < hh[i])
			h = hh[i];
	}
	dp = alloc(n, h + 1, h + 1, h + 1);
	ii = alloc(n, h + 1, h + 1, h + 1);
	hh0 = alloc(n, h + 1, h + 1, h + 1);
	hh1 = alloc(n, h + 1, h + 1, h + 1);
	hh2 = alloc(n, h + 1, h + 1, h + 1);
	for (i = 1; i < n; i++)
		for (h0 = 0; h0 <= h; h0++)
			for (h1 = 0; h1 <= h; h1++)
				for (h2 = 0; h2 <= h; h2++) {
					dp[i][h0][h1][h2] = INT_MAX;
					ii[i][h0][h1][h2] = -1;
					hh0[i][h0][h1][h2] = -1;
					hh1[i][h0][h1][h2] = -1;
					hh2[i][h0][h1][h2] = -1;
				}
	dp[1][hh[0]][hh[1]][hh[2]] = 0;
	for (i = 1; i < n - 1; i++)
		for (h0 = h; h0 >= 0; h0--)
			for (h1 = h; h1 >= 0; h1--)
				for (h2 = h; h2 >= 0; h2--)
					if (dp[i][h0][h1][h2] < INT_MAX) {
						int h0_, h1_, h2_;

						if (h0 == 0) {
							int h3 = i == n - 2 ? 0 : hh[i + 2];

							if (dp[i + 1][h1][h2][h3] > dp[i][h0][h1][h2]) {
								dp[i + 1][h1][h2][h3] = dp[i][h0][h1][h2];
								ii[i + 1][h1][h2][h3] = i;
								hh0[i + 1][h1][h2][h3] = h0;
								hh1[i + 1][h1][h2][h3] = h1;
								hh2[i + 1][h1][h2][h3] = h2;
							}
						}
						h0_ = h0 - b;
						if (h0_ < 0)
							h0_ = 0;
						h1_ = h1 - a;
						if (h1_ < 0)
							h1_ = 0;
						h2_ = h2 - b;
						if (h2_ < 0)
							h2_ = 0;
						if (dp[i][h0_][h1_][h2_] > dp[i][h0][h1][h2] + 1) {
							dp[i][h0_][h1_][h2_] = dp[i][h0][h1][h2] + 1;
							ii[i][h0_][h1_][h2_] = i;
							hh0[i][h0_][h1_][h2_] = h0;
							hh1[i][h0_][h1_][h2_] = h1;
							hh2[i][h0_][h1_][h2_] = h2;
						}
					}
	printf("%d\n", dp[n - 1][0][0][0]);
	print(n - 1, 0, 0, 0);
	printf("\n");
	return 0;
}
