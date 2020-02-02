#include <iostream>
#define MAX(x,y) (x>y?x:y)
using namespace std;

int N;
int dp[1001];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> dp[i];
	for (int i = 1; i <= N; i++) {
		for (int j = i / 2; j > 0; j--) {
			dp[i] = MAX(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[N];
}
