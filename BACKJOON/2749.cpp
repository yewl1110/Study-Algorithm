#include <iostream>
#include <map>
#define MOD 1000000
using namespace std;

typedef unsigned long long ULL;

map<ULL, ULL> m;

ULL f(ULL n) {
	if (n < 2)
		return n;

	if (m.count(n) > 0)
		return m.at(n);

	ULL N = n + 1;

	ULL result1 = 0;
	ULL result2 = 0;
	ULL result = 0;


	if (m.count(N / 2 - 1) > 0) {
		result1 = m.at(N / 2 - 1);
	}
	else {
		result1 = f(N / 2 - 1);
		m.insert(make_pair(N / 2 - 1, result1));
	}

	if (m.count(N / 2) > 0) {
		result2 = m.at(N / 2);
	}
	else {
		result2 = f(N / 2);
		m.insert(make_pair(N / 2, result2));
	}

	if (n % 2 == 1) {
		result = ((result1 % MOD) * (result1 % MOD) + (result2 % MOD) * (result2 % MOD)) % MOD;
	}
	else {
		ULL result3 = 0;
		if (m.count(N / 2 + 1) > 0) {
			result3 = m.at(N / 2 + 1);
		}
		else {
			result3 = f(N / 2 + 1);
			m.insert(make_pair(N / 2 + 1, result3));
		}
		result = ((result1 % MOD + result3 % MOD) % MOD) * result2 % MOD;
	}

	m.insert(make_pair(n, result));
	return result;
}

int main() {
    ULL input;
	m.insert(make_pair(0, 0));
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 1));
    scanf("%lld", &input);
	printf("%lld", f(input));
}

//( n >= 2),
//F( 2n - 1 ) = F(n-1) ^ 2 + F(n) ^ 2
//F( 2n ) = ( F(n-1) + F(n+1) ) * F( n )
