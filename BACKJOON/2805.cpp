#include <iostream>
#include <map>
#define MAX(x,y) (x>y?x:y)
using namespace std;

int N, M;
long result;
map<long, long , greater<long>> m;

void f(long start, long range) {
	if (start > range) return;
	int tmp = false;
	long search = (start + range) / 2;
	long n = 0;
	if (m.count(search) == 0) {
		tmp = true;
		m.insert(make_pair(search, 1));
	}
	for (auto p : m) {
		if (p.first == search) break;
		n += (p.first - search) * p.second;
	}
	if (tmp) m.erase(search);
	if (n < M) {
		f(start, search - 1);
	}
	else {
		if (result < search) result = search;
		f(search + 1, range);
	}
}

int main() {
	cin >> N >> M;
	int n, start = 0;
	for (int i = 0; i < N; i++) {
		cin >> n;
		if (n > start) start = n;
		if (m.count(n) == 0) m.insert(make_pair(n, 1));
		else {
			int v = m[n];
			m.erase(n);
			m.insert(make_pair(n, v + 1));
		}
	}
	f(0, start);
	cout << result;
}
