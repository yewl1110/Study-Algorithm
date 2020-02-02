#include <iostream>
#define MAX(x,y) (x>y?x:y)
using namespace std;

int N, result;
int T[16], P[16], dp[16];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
		dp[i] = P[i];
	}
	for (int i = 1; i <= N; i++) {
		int p = 0;
		for (int j = i; j >= 1; j--) {
			if (T[j] + j <= i && p < dp[j]) p = dp[j];
		}
		dp[i] += p;
		if (i + T[i] - 1<= N && result < dp[i]) result = dp[i];
	}
	cout << result;
}
