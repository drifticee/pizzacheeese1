#include <iostream>

using namespace std;

long long fibarr[90] = {0,1,1};

long long fibo1(int n) {
	for (int i = 1; i < n + 1; i++) {
		if (fibarr[i + 1] == 0)
			fibarr[i + 1] = fibarr[i - 1] + fibarr[i];
	}
	return fibarr[n];
}

int main(void) {
	int n;
	cin >> n;

	cout << fibo1(n) << "\n";
}