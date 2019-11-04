#include <iostream>
#include <queue>
using namespace std;

typedef struct Point{
	int x;
	int y;
};
char arr[101][101];
int _move[4][2] = {
	{1,0},{0, 1},{-1,0},{0,-1}
};
int d[101][101];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}

	d[0][0] = 1;
	queue<Point> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		Point p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (p.x >= 0 && p.x < N && p.y >= 0 && p.y < M) {
				int x = _move[i][0];
				int y = _move[i][1];
				if (arr[p.x + x][p.y + y] == '1' && d[p.x + x][p.y + y] == 0) {
					q.push({ p.x + x , p.y + y });
					d[p.x + x][p.y + y] = d[p.x][p.y] + 1;
				}
			}
		}
	}
	printf("%d\n", d[N - 1][M - 1]);
}
