#pragma warning(disable:4996)
#include <iostream>
#include <unordered_map>
using namespace std;

typedef struct Matrix {
	long element[5][5];
};

Matrix input;
int N;
long B;

unordered_map<long, Matrix*> m;

void multi(Matrix& matrix1, Matrix& matrix2) {
	Matrix matrix;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			long tmp = 0;
			for (int k = 0; k < N; k++) {
				tmp += (matrix1.element[i][k] % 1000) * (matrix2.element[k][j] % 1000);
			}
			matrix.element[i][j] = tmp % 1000;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix1.element[i][j] = matrix.element[i][j];
		}
	}
}

Matrix* makeMatrix(Matrix& _matrix) {
	Matrix* matrix = new Matrix();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix->element[i][j] = _matrix.element[i][j];
		}
	}
	return matrix;
}

void f(long _B) {
	if (_B == 1)
		return;

	f(_B / 2);

	Matrix* matrix = makeMatrix(*m.at(_B / 2));
	multi(*matrix, *matrix);

	if (_B % 2 == 1) {
		multi(*matrix, input);
	}
	m.insert(make_pair(_B, makeMatrix(*matrix)));
}

int main() {
	scanf("%d %ld", &N, &B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%ld", &input.element[i][j]);
			input.element[i][j] %= 1000;
		}
	}

	m.insert(make_pair(1, makeMatrix(input)));
	f(B);

	Matrix output = *m.at(B);

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {
			printf("%ld ", output.element[i][j]);
		}
		printf("\n");
	}
	for (int j = 0; j < N; j++) {
		printf("%ld ", output.element[N - 1][j]);
	}
}
