#include <iostream>
#include <stack>

using namespace std;
int res = 0;

void nq(int N, int row, deque<int> dq)
{


	if (row == N)
	{
		res += 1;
//		for (int i = 0; i < N; i++)
//			cout << dq[i] << " ";
//		cout << "\n";
		return;
	}
// ���� ����
	else if (row == 0)
	{
		for (int i = 0; i < N; i++)
		{
			dq.push_back(i);
			nq(N, row + 1, dq);
			dq.pop_back();
		}
	}

	else
	{
		int check[15] = { 0, };

		for (int j = 0; j < dq.size(); j++)
		{
			check[dq[j]] = 1;
			if (dq[j] + row - j < N)
				check[dq[j] + row - j] = 1;
			if (dq[j] - row + j >= 0)
				check[dq[j] - row + j] = 1;
		}

		for (int i = 0; i < N; i++)
		{
			if (check[i] == 0)
			{
				dq.push_back(i);
				nq(N, row + 1, dq);
				dq.pop_back();
			}
		}
	}
}
// (j, dq[j]) <- stack �ȿ� �ִ� �� / (row, i) <- stack�� ���� �� üũ�� ��
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	deque<int> dq;
	cin >> N;

	nq(N,0,dq);

	cout << res << "\n";
}