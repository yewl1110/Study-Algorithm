#include <iostream>
#include <vector>

using namespace std;
int arr[301][301];
int dp[301][301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, n;
	int K, c, r, x, y;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			dp[i][j] = arr[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= M; j++) dp[i][j] += dp[i][j - 1];
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= M; j++) dp[i][j] += dp[i - 1][j];
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> r >> c >> y >> x;
		cout << dp[y][x] - dp[r - 1][x] - dp[y][c - 1] + dp[r - 1][c - 1] << '\n';
	}
}
