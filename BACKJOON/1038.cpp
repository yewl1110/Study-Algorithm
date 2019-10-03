#pragma warning(disable:4996)
#include <iostream>
#include <vector>
using namespace std;
vector<unsigned int> v;
int cnt, N;

void insert(int _index) {
	while (_index >= 0) {
		v.push_back(_index);
		_index--;
	}
}

void print() {
	for (int h = 1; h < v.size(); h++)
		printf("%d", v.at(h));
	printf("\n");
}

int main() {
	v.push_back(10);
	int length = 2;
	scanf("%d", &N);

	if (N < 10) {
		printf("%d", N);
		return 0;
	}

	for (int length = 2, cnt = 9; length <= 10; length++) {

		if (cnt >= N) { print(); return 0; }

		insert(length - 1);
		cnt++;

		if (cnt >= N) { print(); return 0; }

		while (v.back() != 10 && N > cnt) {
			int n = v.back();
			v.pop_back();

			if (v.back() <= n + 1) {
				int c = 0, nn = 0;
				do {
					nn = v.back();
					v.pop_back();
					c++;
				} while (v.back() != 10 && v.back() <= nn + 1);
				if (nn == 9) break;

				v.push_back(nn + 1);
				insert(c - 1);
			}
			else {
				v.push_back(n + 1);
			}
			cnt++;
			if (cnt >= N) { print(); return 0; }
		}
	}

	printf("-1");
	return 0;
}
