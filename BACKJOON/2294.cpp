#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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
	if (dp[k] == 100001) cout << "-1";
	else cout << dp[k];
}
