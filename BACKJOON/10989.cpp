#include <iostream>

int index[10001];
int MAX;


int main() {
	int n;
	int i = 1;
	int num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		index[num]++;
		if (MAX < num)
			MAX = num;
	}
	while (index[MAX] > 0) {
		if (index[i]--) {
			printf("%d\n", i);
		}
		else {
			i++;
		}
	}
}
