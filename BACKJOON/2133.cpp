#include <iostream>
using namespace std;

int N;
int dp[31];

int main() {
	dp[0] = 1;
	dp[2] = 3;
	cin >> N;
	for (int i = 4; i <= N; i += 2) {
		dp[i] = dp[i - 2] * dp[2];
		for (int j = i - 4; j >= 0; j -= 2) dp[i] += dp[j] * 2;
	}
	cout << dp[N];
}
