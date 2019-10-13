#pragma warning (disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Building{
	int building;
	bool visit;
};

Building building[25][25];
int N;

int cnt;
int arr_cnt[313];
char input[26];

void f(int row,int col, int _cnt) {
	if (row<0 || row>=N || col<0 || col>=N || building[row][col].building == 0 || building[row][col].visit == true)
		return;
	arr_cnt[_cnt - 1]++;
	building[row][col].visit = true;
	f(row - 1, col, _cnt);
	f(row, col - 1, _cnt);
	f(row, col + 1, _cnt);
	f(row + 1, col, _cnt);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", input);
		for (int j = 0; j < N; j++) {
			building[i][j].building = input[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (building[i][j].building == 1 && building[i][j].visit == false) {
				cnt++;
				f(i, j, cnt);
			}
		}
	}
	printf("%d\n", cnt);

	sort(arr_cnt, arr_cnt + cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", arr_cnt[i]);
	}
}
