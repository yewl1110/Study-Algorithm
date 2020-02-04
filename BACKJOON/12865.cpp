#include<iostream>
#define MAX(x,y) (x>y?x:y)
using namespace std;

int N, K;
int dp[101][100001];
int W[101], V[101];


int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> W[i] >> V[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = dp[i - 1][j];
			if (W[i] <= j) dp[i][j] = MAX(V[i] + dp[i - 1][j - W[i]], dp[i][j]);
		}
	}
	cout << dp[N][K];
}
