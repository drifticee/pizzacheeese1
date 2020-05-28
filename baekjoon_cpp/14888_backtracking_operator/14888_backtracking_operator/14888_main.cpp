#include <iostream>

using namespace std;

int nums[11];
int maxmin[2] = { -1000000001, 1000000001};

int opscalcul(int N, int* nums, int* opbatch) {
	int result = nums[0];

	for (int i = 0; i < N-1; i++) {
		if (opbatch[i] == 0)
			result += nums[i + 1];
		else if (opbatch[i] == 1)
			result -= nums[i + 1];
		else if (opbatch[i] == 2)
			result *= nums[i + 1];
		else {
			if (result < 0) {
				result = -(-result / nums[i + 1]);
			}
			else
				result /= nums[i + 1];
		}
	}

	return result;
}

void batch(int N, int *ops, int *opbatch, int order) {

	
	if (order == N-1) { // at the final step, calculate them all
		int result;
		result = opscalcul(N, nums, opbatch);

		if (result > maxmin[0])
			maxmin[0] = result;
		if (result < maxmin[1])
			maxmin[1] = result;
	}

	else {
		for (int i = 0; i < 4; i++) {
			if (ops[i] != 0) {
				opbatch[order] = i;
				ops[i] -= 1;
				batch(N, ops, opbatch, order + 1);
				ops[i] += 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int ops[4];
	cin >> N;
	int opbatch[11];

	for (int i = 0; i < N; i++)
		cin >> nums[i];
	for (int j = 0; j < 4; j++)
		cin >> ops[j];

	batch(N, ops, opbatch, 0);
	cout << maxmin[0] << "\n" << maxmin[1] << "\n";
}
