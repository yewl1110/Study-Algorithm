#include <iostream>
#include <vector>
using namespace std;

int N, M, min_ = 64;
int map[9][9];
vector<pair<int, int>> cctv;
int direction[8];

void marking(int n, int d, int tmp[][9]) {
	int x = cctv.at(n).first;
	int y = cctv.at(n).second;

	switch (d) {
	case 0:
		while (map[--y][x] != 6 && y >= 1) tmp[y][x] = -1;
		break;
	case 1:
		while (map[y][++x] != 6 && x <= M) tmp[y][x] = -1;
		break;
	case 2:	
		while (map[++y][x] != 6 && y <= N) tmp[y][x] = -1;
		break;
	case 3:
		while (map[y][--x] != 6 && x >= 1) tmp[y][x] = -1;
	}
}

int check() {
	int cnt = 0;
	int tmp[9][9] = { 0, };
	for (int i = 0; i < cctv.size(); i++) {
		int x = cctv.at(i).first;
		int y = cctv.at(i).second;
		tmp[y][x] = 1;
		switch (map[y][x]) {
		case 1:
			marking(i, direction[i], tmp);
			break;
		case 2:
			marking(i, (direction[i] + 2) % 4, tmp);
			marking(i, direction[i], tmp);
			break;
		case 3:
			marking(i, (direction[i] + 3) % 4, tmp);
			marking(i, direction[i], tmp);
			break;
		case 4:
			marking(i, (direction[i] + 3) % 4, tmp);
			marking(i, direction[i], tmp);
			marking(i, (direction[i] + 2) % 4, tmp);
			break;
		case 5:
			marking(i, 0, tmp);
			marking(i, 1, tmp);
			marking(i, 2, tmp);
			marking(i, 3, tmp);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (tmp[i][j] == 0) cnt++;
			if (map[i][j] == 6) cnt--;
		}
	}
	return cnt;
}

void dfs(int n, int d) {
	if (n == cctv.size()) {
		int result = check();
		if (min_ > result) min_ = result;
		return;
	}
	int x = cctv.at(n).first;
	int y = cctv.at(n).second;
	if (map[y][x] == 5) dfs(n + 1, 4);
	else {
		for (int i = 0; i < 4; i++) {
			direction[n] = i;
			dfs(n + 1, i);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] % 6 != 0) cctv.push_back(make_pair(j, i));
		}
	}
	dfs(0, 0);
	cout << min_;
}
