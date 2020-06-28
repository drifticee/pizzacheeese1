#include <iostream>

using namespace std;

__int64 cache[101][10] = { 0, };

int main(void) {
	for (int i = 1; i < 10;i++)
		cache[1][i] = 1;

	cache[2][0] = 1;
	cache[2][1] = 1;
	cache[2][9] = 1;
	for (int i = 2; i < 9;i++)
		cache[2][i] = 2;

	int N;
	cin >> N;

	if (N == 0) {
		cout << 0 << "\n";
		return 0;
	}

	if (N == 1) {
		cout << 9 << "\n";
		return 0;
	}

	else if (N == 2) {
		cout << 17 << "\n";
		return 0;
	}

	for (int i = 2 - (N % 2);i <= N;i += 2) {
		if (i == 1)
			continue;
		if (cache[i][1] == 0) {
			cache[i][0] += cache[i - 2][0];
			cache[i][2] += cache[i - 2][0];

			cache[i][1] += 2 * cache[i - 2][1];
			cache[i][3] += cache[i - 2][1];

			cache[i][8] += 2 * cache[i - 2][8];
			cache[i][6] += cache[i - 2][8];

			cache[i][9] += cache[i - 2][9];
			cache[i][7] += cache[i - 2][9];

			for (int j = 2; j <= 7; j++) {
				cache[i][j] += 2 * cache[i - 2][j];
				cache[i][j - 2] += cache[i - 2][j];
				cache[i][j + 2] += cache[i - 2][j];
			}

			for (int k = 0; k < 10;k++)
				cache[i][k] %= 1000000000;
		}
	}

	__int64 res = 0;
	for (int i = 0; i < 10;i++)
		res += cache[N][i];

	cout << res % 1000000000 << "\n";
}