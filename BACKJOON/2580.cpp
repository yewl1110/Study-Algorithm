#include <iostream>
using namespace std;

int sudoku[10][10];
int row[10][10]; // 가로
int column[10][10]; // 세로
int square[10][10]; // 위치

int square_location(int y, int x) {
	return (y - 1) / 3 * 3 + (x - 1) / 3 + 1;
}

void dfs(int cnt) {
	if (cnt == 81) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << sudoku[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}
    
	int y = cnt / 9 + 1;
	int x = cnt % 9 + 1;

	if (sudoku[y][x]) {
		dfs(cnt + 1);
	}
	else {
		for (int j = 1; j <= 9; j++) {
			if (!row[y][j] && !column[x][j] && !square[square_location(y, x)][j]) {
				sudoku[y][x] = j;
				row[y][j] = true;
				column[x][j] = true;
				square[square_location(y, x)][j] = true;
                
				dfs(cnt + 1);
                
				sudoku[y][x] = 0;
				row[y][j] = false;
				column[x][j] = false;
				square[square_location(y, x)][j] = false;
			}
		}
	}
}

int main() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0) continue;
			row[i][sudoku[i][j]] = true;
			column[j][sudoku[i][j]] = true;
			square[square_location(i, j)][sudoku[i][j]] = true;
		}
	}
	dfs(0);
}
