#include <iostream>
#include <queue>
using namespace std;

int N, K, result;
int check[100001];

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));
	while (!q.empty()) {
		int n = q.front().first;
		int sec = q.front().second;
		check[n] = true;
		q.pop();
		if (n == K) {
			result = sec;
			break;
		}
		if (n - 1 >= 0 && !check[n - 1]) q.push(make_pair(n - 1, sec + 1));
		if (n + 1 <= 100000 && !check[n + 1]) q.push(make_pair(n + 1, sec + 1));
		if (1 <= n && n <= 50000 && !check[n * 2]) q.push(make_pair(n * 2, sec + 1));
	}
}

int main() {
	cin >> N >> K;
	bfs();
	cout << result;
}
