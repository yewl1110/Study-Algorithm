#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int x, y, crash;
}Point;

char arr[1001][1001];
int dp[1001][1001][2];
int result, N, M;
int move_[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

int bfs() {
	queue<Point> q;
	q.push({ 1,1 , arr[1][1] - '0' });
	dp[1][1][0] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int crash = q.front().crash;
		q.pop();

		if (x == M && y == N) return dp[y][x][crash];

		for (int i = 0; i < 4; i++) {
			int nx = x + move_[i][0];
			int ny = y + move_[i][1];
			if (1 <= nx && nx <= M && 1 <= ny && ny <= N && dp[ny][nx][crash] <= 0) {
				if (arr[ny][nx] == '0') {
					q.push({ nx, ny, crash });
					dp[ny][nx][crash] = dp[y][x][crash] + 1;
				}
				if (arr[ny][nx] == '1' && crash == 0) {
					q.push({ nx, ny, 1 });
					dp[ny][nx][1] = dp[y][x][crash] + 1;
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> arr[i][j];
	}
	cout << bfs();
}
