#include <iostream>

using namespace std;

long long padovan[101] = { 0,1,1,1,2,2,3,4,5,7,9 };

int main(void) {
	int T, N;
	cin >> T;

	for (int i = 0;i < T;i++) {
		cin >> N;

		for (int j = 11;j <= N;j++) {
			if (padovan[j] == 0)
				padovan[j] = padovan[j - 1] + padovan[j - 5];
		}

		cout << padovan[N] << "\n";
	}
}