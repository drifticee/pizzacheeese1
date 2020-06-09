#include <iostream>

using namespace std;

int score[500][500];
int cache[500][500];

int inttri(int level, int tree, int N) {
	if (level == N - 1) return score[level][tree];

	if (cache[level][tree] != -1) return cache[level][tree];

	int tmp;
	int max = 0;
	for (int i = tree; i < tree + 2; i++) {
		tmp = inttri(level + 1, i, N);
		if (max < tmp) max = tmp;
	}

	return cache[level][tree] = score[level][tree] + max;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> score[i][j];
			cache[i][j] = -1;
		}
	}

	cout << inttri(0, 0, N) << "\n";
}