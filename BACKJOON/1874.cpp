#include <iostream>
#include <vector>
#include <stack>

using namespace std;
stack<int> s;
vector<char> result;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, max = 0;
	cin >> N;
	while (N--) {
		cin >> n;
		if (max < n) {
			for (int i = max + 1; i <= n; i++) {
				s.push(i);
				result.push_back('+');
			}
		}
		else {
			if (s.top() != n) {
				cout << "NO\n";
				exit(0);
			}
		}
		s.pop();
		result.push_back('-');
		if (max < n) max = n;
	}
	for (char r : result) cout << r << '\n';
}
