#include <iostream>
#include <queue>
using namespace std;

int N, K, L, result;
int map[101][101];
int movement[4][2] = { {1,0}, {0, 1}, {-1, 0}, {0, -1} };
queue<pair<int, char>> control;
queue<pair<int, int>> snake;

void play() {
	int direction = 0;
	snake.push(make_pair(1, 1)); //시작점
	map[1][1] = 1;

	int sec = control.front().first;
	char dic = control.front().second;
	control.pop();

	int x, y;
 	while(true){
		result++;
		x = snake.back().first + movement[direction][0];
		y = snake.back().second + movement[direction][1];
		if (!(1 <= x && x <= N && 1 <= y && y <= N) || map[y][x] == 1) {
			return;
		}
		if (map[y][x] != 2) {
			map[snake.front().second][snake.front().first] = 0;
			snake.pop();
		}
		map[y][x] = 1;
		snake.push(make_pair(x, y));
		if (result == sec) {
			if (dic == 'D') direction = (direction + 1) % 4;
			else direction = (direction + 3) % 4;
			if (!control.empty()) {
				sec = control.front().first;
				dic = control.front().second;
				control.pop();
			}
		}
	}
	return;
}

int main() {
	cin >> N >> K;
	int y, x;
	for (int i = 0; i < K; i++) {
		cin >> y >> x;
		map[y][x] = 2;
	}
	cin >> L;
	int sec;
	char dic;
	for (int i = 0; i < L; i++) {
		cin >> sec >> dic;
		control.push(make_pair(sec, dic));
	}
	play();
	cout << result;
}
