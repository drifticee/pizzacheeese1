#include <iostream>

using namespace std;

int cache[1000001] = { 0 };

int onemake(int n) {
	if (n == 1)
		return 0;

	if (cache[n] != 0)
		return cache[n];

	cache[n] = onemake(n - 1) + 1;

	int tmp;
	if (n % 3 == 0) {
		tmp = onemake(n / 3) + 1;
		if (tmp < cache[n])
			cache[n] = tmp;
	}

	if (n % 2 == 0) {
		int tmp = onemake(n / 2) + 1;
		if (tmp < cache[n])
			cache[n] = tmp;
	}

	return cache[n];
}

int main(void) {
	int X;
	cin >> X;

	cout << onemake(X) << "\n";
}