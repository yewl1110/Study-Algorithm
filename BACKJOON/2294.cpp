#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int dp[10001];

int main() {
	int value;
	cin >> n >> k;

	dp[0] = 0;
	for (int i = 1; i <= k; i++) dp[i] = 100001;
	for (int i = 0; i < n; i++) {
		cin >> value;
		for (int j = value; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - value] + 1);
		}
	}
	if (dp[k] == 100001) dp[k] = -1;
	cout << dp[k];
}
