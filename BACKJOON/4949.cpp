#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> s;
string input;

bool isBrace(char current) {
	if (current == '(' || current == '[' || current == ']' || current == ')')
		return true;
	return false;
}

int nextDot(int currentIndex) {
	for (int i = currentIndex; i < input.size(); i++) {
		if (input[i] == '.')
			return i;
	}
}

bool check(char current) {
	if (current == ')') {
		if (s.empty() || s.back() == '[') {
			cout << "no" << endl;
			return false;
		}
		s.pop_back();
	}
	else if (current == ']') {
		if (s.empty() || s.back() == '(') {
			cout << "no" << endl;
			return false;
		}
		s.pop_back();
	}
	else {
		s.push_back(current);
	}
	return true;
}

void f() {
	int i = 0;
	while (i++ < input.size()) {
		if (input[i] == '.') {
			if (s.empty())
				cout << "yes" << endl;
			else
				cout << "no" << endl;
			s.clear();
			continue;
		}
		if (isBrace(input[i])) {
			if (!check(input[i])) {
				s.clear();
				i = nextDot(i);
			}
		}
	}
}

int main() {
	string str;
	while (1) {
		str.clear();
		getline(cin, str);
		if (str.compare(".") == 0)
			break;
		input += str;
	}
	f();
}
