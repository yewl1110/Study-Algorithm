#include <iostream>
using namespace std;

int N;
long long dp[101][101];
int map[101][101];

long long dfs(int y,int x) {
	if (x == N && y == N) return 1;
	if (!(1 <= x && x <= N && 1 <= y && y <= N)) return 0;
	if (dp[y][x] > -1) return dp[y][x];

	dp[y][x] = 0;
	dp[y][x] += dfs(y + map[y][x], x);
	dp[y][x] += dfs(y, x + map[y][x]);
	return dp[y][x];
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
	cout << dfs(1, 1);
}
