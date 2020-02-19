#include <iostream>
using namespace std;

int N, L, result;
int map[101][101];
int height[101][101];

int main() {
	cin >> N >> L;
	result = N * 2;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> map[i][j];
	}

	for (int i = 1; i <= N; i++) {
		// row 검사
		int p = map[i][1];
		int cnt = 1;
		for (int j = 2; j <= N; j++) {
			if (p != map[i][j]) {
				if (abs(p - map[i][j]) == 1) {
					height[i][j - 1] = cnt;
					height[i][j - cnt] = cnt;
				}
				if (abs(p - map[i][j]) != 1 || p < map[i][j] && cnt < L) {
					height[i][1] = -1;
					break;
				}
				p = map[i][j];
				cnt = 1;
			}
			else cnt++;
		}

		height[i][N] = cnt;
		height[i][N - cnt + 1] = cnt;

		if (height[i][1] == -1) {
			result--;
			continue;
		}
		for (int j = 2; j <= N; j++) {
			if (abs(map[i][j - 1] - map[i][j]) == 1) {
				if (map[i][j - 1] < map[i][j]) { // 오르막
					if (height[i][j - 1] < L) {
						result--; break;
					}
				}
				else { // 내리막
					if (height[i][j] < L) {
						result--; break;
					}
					else {
						if (height[i][j] == 1) height[i][j]--;
						else {
							int cnt = height[i][j];
							height[i][j + cnt - 1] -= L;
							height[i][j] -= L;
						}
					}
				}
			}
			if (abs(map[i][j - 1] - map[i][j]) > 1) {
				result--; break;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		// col 검사
		int p = map[1][i];
		int cnt = 1;
		for (int j = 2; j <= N; j++) {
			if (p != map[j][i]) {
				if (abs(p - map[j][i]) == 1) {
					height[j - 1][i] = cnt;
					height[j - cnt][i] = cnt;
				}
				if (abs(p - map[j][i]) != 1 || p < map[j][i] && cnt < L) {
					height[1][i] = -1;
					break;
				}
				p = map[j][i];
				cnt = 1;
			}
			else cnt++;
		}

		height[N][i] = cnt;
		height[N - cnt + 1][i] = cnt;

		if (height[1][i] == -1) {
			result--;
			continue;
		}
		for (int j = 2; j <= N; j++) {
			if (abs(map[j - 1][i] - map[j][i]) == 1) {
				if (map[j - 1][i] < map[j][i]) { // 오르막
					if (height[j - 1][i] < L) {
						result--; break;
					}
				}
				else { // 내리막
					if (height[j][i] < L) {
						result--; break;
					}
					else {
						if (height[j][i] == 1) height[j][i]--;
						else {
							int cnt = height[j][i];
							height[j + cnt - 1][i] -= L;
							height[j][i] -= L;
						}
					}
				}
			}
			if (abs(map[j - 1][i] - map[j][i]) > 1) {
				result--; break;
			}
		}
	}
	cout << result;
}
