#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

int main(void) {
	int N;
	vector <int> team1;
	cin >> N;

	tft tft1(N);

	cout << tft1.teammake(-1, team1) << "\n";
}