#include <iostream>
using namespace std;

int N, result = 19000, score[2];
int arr[21][21], check[21];

int scorecheck() {
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (check[i] == check[j]) {
				score[check[i]] += (arr[i][j] + arr[j][i]);
			}
		}
	}
	return abs(score[1] - score[0]);
}

void f(int n, int start) {
	if (n == N / 2 + 1) {
		int s = scorecheck();
		if (result > s) result = s;
		score[0] = 0; score[1] = 0;
		return;
	}
	for (int i = start; i <= N; i++) {
		if (check[i]) continue;
		check[i] = 1;
		f(n + 1, i + 1);
		check[i] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> arr[i][j];
	}
	f(1, 1);
	cout << result;
}
