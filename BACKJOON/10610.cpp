#include <iostream>
#include <algorithm>

char input[100001];
bool compare(char a, char b) {
	return a >  b;
}

int main() {
	scanf("%s", input);
	std::sort(input, &input[100000], compare);
	int zero = 0, sum = 0; 
	for (char ch : input) {
		if (ch == NULL) break;
		(ch == '0') ? zero++ : sum += ch - '0';
	}
	(sum % 3 == 0 && zero > 0) ? printf("%s", input) : printf("-1");
}
