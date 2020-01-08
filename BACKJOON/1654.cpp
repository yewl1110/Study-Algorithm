#include <iostream>
using namespace std;
int N, K;
int arr[10000];
long long result, max_;

void f(long long start, long long end) {
	if (start > end) return;

	long long search = (start + end) / 2;
	int count = 0;
	for (int j = 0; j < K; j++) {
		count += arr[j] / search;
	}
	if (count >= N) {
		if(result < search) result = search;
		f(search + 1, end);
	}
	else {
		f(start, search - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		if (arr[i] > max_) max_ = arr[i];
	}
	
	f(1, max_);
	cout << result;
 }
