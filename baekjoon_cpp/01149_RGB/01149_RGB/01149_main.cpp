#include <iostream>
#include <vector>

using namespace std;
int rgb[1001][3];
int cache[1001][3] = { 0 };

int rgbbt(int idx, int color, int N) {
	if (idx == N - 1) return rgb[idx][color];

	if (cache[idx][color] != 0) {
		return cache[idx][color];
	}

	int min = 1000001;
	int tmp;

	for (int i = 0; i < 3; i++) {
		if (i != color) {
			tmp = rgbbt(idx + 1, i, N);
			if (min > tmp) min = tmp;
		}
	}

	return cache[idx][color] = rgb[idx][color] + min;
}

int main(void) {
	int N;
	int min = 1000001;
	int tmp;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> rgb[i][j];
		}
	}

	for (int j = 0; j < 3; j++) {
		tmp = rgbbt(0, j, N);
		if (min > tmp) min = tmp;
	}
	cout << min << "\n";
}