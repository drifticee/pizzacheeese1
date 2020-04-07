#include <iostream>

using namespace std;

int sd[9][9];

void sdoku_1()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sd[i][j] == 0)
			{
				int ch[10];
				fill_n(ch, 10, 1);
				ch[0] = 0;

				for (int a = 0; a < 9; a++)
				{
					if (ch[sd[i][a]] == 1)
						ch[sd[i][a]] = 0;

					if (ch[sd[a][j]] == 1)
						ch[sd[a][j]] = 0;
				}

				if (i < 3)
				{
					if (j < 3)
					{
						for (int i3 = 0; i3 < 3; i3++)
						{
							for (int j3 = 0; j3 < 3; j3++)
							{
								if (ch[sd[i3][j3]] == 1)
									ch[sd[i3][j3]] = 0;
							}
						}
					}

					else if (j < 6)
					{
						for (int i3 = 0; i3 < 3; i3++)
						{
							for (int j6 = 3; j6 < 6; j6++)
							{
								if (ch[sd[i3][j6]] == 1)
									ch[sd[i3][j6]] = 0;
							}
						}
					}

					else
					{
						for (int i3 = 0; i3 < 3; i3++)
						{
							for (int j9 = 6; j9 < 9; j9++)
							{
								if (ch[sd[i3][j9]] == 1)
									ch[sd[i3][j9]] = 0;
							}
						}
					}
				}

				else if (i < 6)
				{
					if (j < 3)
					{
						for (int i6 = 3; i6 < 6; i6++)
						{
							for (int j3 = 0; j3 < 3; j3++)
							{
								if (ch[sd[i6][j3]] == 1)
									ch[sd[i6][j3]] = 0;
							}
						}
					}

					else if (j < 6)
					{
						for (int i6 = 3; i6 < 6; i6++)
						{
							for (int j6 = 3; j6 < 6; j6++)
							{
								if (ch[sd[i6][j6]] == 1)
									ch[sd[i6][j6]] = 0;
							}
						}
					}

					else
					{
						for (int i6 = 3; i6 < 6; i6++)
						{
							for (int j9 = 6; j9 < 9; j9++)
							{
								if (ch[sd[i6][j9]] == 1)
									ch[sd[i6][j9]] = 0;
							}
						}
					}
				}

				else
				{
					if (j < 3)
					{
						for (int i9 = 6; i9 < 9; i9++)
						{
							for (int j3 = 0; j3 < 3; j3++)
							{
								if (ch[sd[i9][j3]] == 1)
									ch[sd[i9][j3]] = 0;
							}
						}
					}

					else if (j < 6)
					{
						for (int i9 = 6; i9 < 9; i9++)
						{
							for (int j6 = 3; j6 < 6; j6++)
							{
								if (ch[sd[i9][j6]] == 1)
									ch[sd[i9][j6]] = 0;
							}
						}
					}

					else
					{
						for (int i9 = 6; i9 < 9; i9++)
						{
							for (int j9 = 6; j9 < 9; j9++)
							{
								if (ch[sd[i9][j9]] == 1)
									ch[sd[i9][j9]] = 0;
							}
						}
					}
				}

				for (int b = 1; b < 10; b++)
					if (ch[b] == 1)
						sd[i][j] = b;
			}
		}
	}
}

int main()
{

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sd[i][j];
		}
	}

	sdoku_1();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << sd[i][j] << " ";
		}
		cout << "\n";
	}
}