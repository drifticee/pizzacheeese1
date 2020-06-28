#include <iostream>
#include <algorithm>

using namespace std;

int cache[10001] = { 0, };
int score[10001] = { 0, };

int winemax(int loc, int n) {
	if (cache[loc] != 0)
		return cache[loc];

	if (loc >= 0) {
		int tmp1 = score[loc] + winemax(loc - 2, n);
		int tmp2 = score[loc] + score[loc - 1] + winemax(loc - 3, n);

		if (tmp1 > tmp2)
			cache[loc] = tmp1;
		else
			cache[loc] = tmp2;

		int tmp3 = score[loc - 1] + score[loc - 2] + winemax(loc - 4, n);

		if (cache[loc] < tmp3)
			cache[loc] = tmp3;

		return cache[loc];
	}
	else if (loc == 3) {
		return cache[loc] = cache[1] + cache[2] + cache[3] - min({ cache[1], cache[2], cache[3] });
	}

	else if (loc == 2)
		return cache[loc] = score[2] + score[1];
	else
		return cache[loc] = score[loc];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> score[i];

	cout << winemax(n, n) << "\n";
}