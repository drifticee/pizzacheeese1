#include <iostream>

using namespace std;

int tile[1000001] = { 0,1,2 };

int main(void) {
	int N;
	cin >> N;

	for (int i = 3; i <= N;i++) {
		tile[i] = (tile[i - 1] + tile[i - 2]) % 15746;
	}

	cout << tile[N]  << "\n";
}