#include <iostream>
using namespace std;

int arr[50][50];
int test;

void search(int x, int y, int var_x, int var_y) {
	if (x >= var_x || y >= var_y || x < 0 || y < 0) return;

	if (arr[x][y] > 0) arr[x][y] *= -1;
	else return;

	search(x - 1, y, var_x, var_y);
	search(x, y + 1, var_x, var_y);
	search(x + 1, y, var_x, var_y);
	search(x, y - 1, var_x, var_y);
}

void f() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			arr[i][j] = 0;
		}
	}
	int count = 0;
	int var_x, var_y, amount;
	scanf("%d %d %d", &var_x, &var_y, &amount);

	for (int i = 0; i < amount; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
	}

	for (int i = 0; i < var_x; i++) {
		for (int j = 0; j < var_y; j++) {
			if (arr[i][j] > 0) {
				count++;
				search(i, j, var_x, var_y);
			}
		}
	}
	printf("%d\n", count);
}

int main() {
	scanf("%d", &test);
	for (int i = 0; i < test; i++) f();
}
