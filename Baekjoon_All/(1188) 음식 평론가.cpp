#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	for (int i = min(a, b); i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			return i;
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	cout << M - gcd(N, M);

	return 0;
}