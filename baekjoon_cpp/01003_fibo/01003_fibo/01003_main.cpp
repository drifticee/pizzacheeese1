#include <iostream>

using namespace std;

int call01[41][2] = { {1,0}, {0,1} };

int main(void) {

	int t;
	int n;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;

		for (int j = 2; j <= n; j++) {
			if (call01[j][0] == 0 && call01[j][1] == 0) {
				call01[j][0] = call01[j - 1][0] + call01[j - 2][0];
				call01[j][1] = call01[j - 1][1] + call01[j - 2][1];
			}
		}

		cout << call01[n][0] << " " << call01[n][1] << "\n";
	}
}