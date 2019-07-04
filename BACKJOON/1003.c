#include <stdio.h>

int memo[41][2] = { {1,0},{0,1} };

void fibonacci(int n) {
	if (n <= 1) {
		return;
	}
	else {
		if (!memo[n - 1][0] && !memo[n - 1][1])
			fibonacci(n - 1);
		if (!memo[n - 2][0] && !memo[n - 2][1])
			fibonacci(n - 2);
		memo[n][0] = memo[n - 1][0] + memo[n - 2][0];
		memo[n][1] = memo[n - 1][1] + memo[n - 2][1];
		return;
	}
}

int main() {
	int n,j;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &j);
		fibonacci(j);
		printf("%d %d\n", memo[j][0], memo[j][1]);
	}
}
