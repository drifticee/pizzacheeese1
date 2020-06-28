#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	int cache[101][10] = { 0, };

	for (int i = 1; i < 10;i++)
		cache[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		if (cache[i][1] == 0) {
			cache[i][0] = cache[i - 1][1];
			cache[i][9] = cache[i - 1][8];

			for (int j = 1;j < 9;j++) {
				cache[i][j] = cache[i - 1][j - 1];
				cache[i][j] += cache[i - 1][j + 1];
				cache[i][j] %= 1000000000;
			}
		}
	}

	int res = 0;
	for (int i = 0; i < 10;i++) {
		res += cache[N][i];
		res %= 1000000000;
	}

	cout << res << "\n";
}