#pragma once
#include <vector>
using namespace std;

class tft {
	int minp = 100;
	int N;
	int** S = new int* [N];

public:
	tft(int X) {
		N = X;
		for (int i = 0; i < N;i++) {
			S[i] = new int[N];
			for (int j = 0; j < N;j++)
				cin >> S[i][j];
		}
	}

	~tft() {};

	int pointcheck(vector<int>& team1) {
		vector <int> team2;
		int j = 1;
		// the first element of team1 is always 0, so starting from index 1.
		int result = 0;

		for (int i = 1;i < N;i++) { // same reason above.
			if (j < N / 2)
				if (team1[j] == i)
					j += 1;
				else
					team2.push_back(i);
			else
				team2.push_back(i);
		}

		for (int m = 0;m < N / 2;m++) {
			for (int n = 0;n < N / 2;n++) {
				if (m != n) {
					result += S[team1[m]][team1[n]];
					result -= S[team2[m]][team2[n]];
				}
			}
		}

		return abs(result);
	}

	int teammake(int nw, vector<int>& team1) {
		if (team1.size() == N / 2) {
			int temp = pointcheck(team1);
			if (minp > temp)
				minp = temp;
			return 0;
		}

		for (int i = nw + 1; i < N;i++) {
			if (i == 1 && team1.size() == 0)
				break;

			team1.push_back(i);
			teammake(i, team1);
			team1.pop_back();
		}

		if (team1.size() == 0)
			return minp;
		else
			return 0;
	}
};