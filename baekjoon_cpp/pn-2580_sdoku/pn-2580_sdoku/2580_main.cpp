#include <iostream>

using namespace std;

int sd[9][9];
bool rowcheck[9][10];
bool colcheck[9][10];
bool sqrcheck[9][10];

void sdoku_1(int row = 0, int col = 0)
{
	if (row == 9)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << sd[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}


	if (!sd[row][col])
	{
		int sqrnum = (row / 3) * 3 + (col / 3);

		for (int k = 1; k <= 9; k++)
		{
			if (!rowcheck[row][k] && !colcheck[col][k] && !sqrcheck[sqrnum][k])
			{
				sd[row][col] = k;
				rowcheck[row][k] = true;
				colcheck[col][k] = true;
				sqrcheck[sqrnum][k] = true;
				if (col == 8)
					sdoku_1(row + 1, 0);
				else
					sdoku_1(row, col + 1);
				sd[row][col] = 0;
				rowcheck[row][k] = false;
				colcheck[col][k] = false;
				sqrcheck[sqrnum][k] = false;
			}
		}
	}
	else
	{
		if (col == 8)
			sdoku_1(row + 1, 0);
		else
			sdoku_1(row, col + 1);
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cin >> sd[i][j];
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			if (sd[i][j])
			{
				int sqrnum = (i / 3) * 3 + (j / 3);
				rowcheck[i][sd[i][j]] = true;
				colcheck[j][sd[i][j]] = true;
				sqrcheck[sqrnum][sd[i][j]] = true;
			}
	}

	sdoku_1();
}