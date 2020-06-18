#include <iostream>

using namespace std;

int score[301];
int cache[301] = { 0 };

int stairmax(int loc, int N) {
	if (cache[loc] != 0)
		return cache[loc];

	if (loc >= 3) {
		int tmp1 = score[loc] + stairmax(loc - 2, N);
		int tmp2 = score[loc] + score[loc - 1] + stairmax(loc - 3,N);

		if (tmp1 > tmp2)
			return cache[loc] = tmp1;
		else
			return cache[loc] = tmp2;
	}

	else if (loc == 2)
		return cache[2] = score[2] + score[1];

	else
		return cache[loc] = score[loc];
}

int main(void) {
	int N;
	cin >> N;
	score[0] = 0;
	for (int i = 1;i <= N;i++)
		cin >> score[i];

	cout << stairmax(N, N) << "\n";
}