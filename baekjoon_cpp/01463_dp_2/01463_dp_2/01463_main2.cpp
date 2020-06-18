#include <iostream>

using namespace std;

int cache[1000001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	cin >> x;

	cache[1] = 0;

	for (int i = 2;i <= x;i++) {
		cache[i] = cache[i - 1] + 1;
		if (i % 2 == 0)
			if (cache[i / 2] + 1 < cache[i])
				cache[i] = cache[i / 2] + 1;
		if (i % 3 == 0)
			if (cache[i / 3] + 1 < cache[i])
				cache[i] = cache[i / 3] + 1;
	}

	cout << cache[x] << "\n";
}