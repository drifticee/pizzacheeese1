#include <iostream>
#include <cmath>
using namespace std;

unsigned long long fibarr[91] = { 0,1,1 };

unsigned long long fibo1(int n) {
	if (n == 0)
		return 0;
	else if (n == 1 || n == 2)
		return 1;

	if (fibarr[n] != 0)
		return fibarr[n];

	if (n % 2 == 0) {
		return fibarr[n] = fibo1(n / 2) * (fibo1(n / 2 - 1) + fibo1(n / 2 + 1));
	}
	else {
		return fibarr[n] = fibo1(n / 2) * (fibo1(n / 2 - 1) + fibo1(n / 2) + fibo1(n / 2 + 1)) + pow((fibo1(n / 2 - 1)),2);
	}
}

int main(void) {
	int n;
	cin >> n;

	cout << fibo1(n) << "\n";
}