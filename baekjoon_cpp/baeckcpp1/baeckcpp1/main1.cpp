#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

/*
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
*/

//2504번 괄호의 값
/*

string input;
stack<char> s;

int main(void)
{
	cin >> input;

	long long result = 0;
	int temp = 1;
	bool imp = false;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			temp *= 2;
			s.push('(');
		}
		else if (input[i] == '[')
		{
			temp *= 3;
			s.push('[');
		}

		else if (input[i] == ')' && (s.empty() || s.top() != '('))
		{
			imp = true;
			break;
		}
		else if (input[i] == ']' && (s.empty() || s.top() != '['))
		{
			imp = true;
			break;
		}

		else if (input[i] == ')')
		{
			if (input[i - 1] == '(')
				result += temp;
			s.pop();
			temp /= 2;
		}
		else if (input[i] == ']')
		{
			if (input[i - 1] == '[')
				result += temp;
			s.pop();
			temp /= 3;
		}
	}

	if (imp || !s.empty())
		cout << 0 << "\n";
	else
		cout << result << "\n";
}

*/

//1436번 영화감독 숌
/*

int input;

int main(void)
{
	cin >> input;

	int N = 0;
	long long ini = 665;

	while (N < input)
	{
		ini += 1;
		if (to_string(ini).find("666") < to_string(ini).size())
			N += 1;
	}

	cout << ini << endl;
}

*/

//2750번 수 정렬하기
/*

int N;

int main(void)
{
	cin >> N;
	int *arr = (int*)malloc(N*sizeof(int));
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int tmp;
	for (int j = 0; j < N - 1; j++)
	{
		for (int k = j + 1; k < N; k++)
		{
			if (arr[j] > arr[k])
			{
				tmp = arr[j];
				arr[j] = arr[k];
				arr[k] = tmp;
			}
		}
	}

	for (int l = 0; l < N; l++)
		cout << arr[l] << endl;
	free(arr);
}

*/

//2751번 수 정렬하기 2 - 병합 정렬 #divide and conquer
// 아래 main은 printf와 scanf 사용하여 시간 줄임.
/*

int N;
void part(int* arr, int* comp, int start, int end);
void merge(int* arr, int* comp, int start, int end);

void part(int *arr, int*comp, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		part(arr, comp, start, mid);
		part(arr, comp, mid + 1, end);
		merge(arr, comp, start, end);
	}
}

void merge(int *arr, int *comp, int start, int end)
{
	int mid = (start + end) / 2;

	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
			comp[k] = arr[i++];
		else
			comp[k] = arr[j++];
		k++;
	}
	if (i > mid)
	{
		for (int l = j; l <= end; l++)
			comp[k++] = arr[l];
	}
	else
	{
		for (int m = i; m <= mid; m++)
			comp[k++] = arr[m];
	}
	
	for (int n = start; n <= end; n++)
		arr[n] = comp[n];
}

int main(void)
{
	cin >> N;
	int* arr = new int[N];
	int* comp = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	part(arr, comp, 0, N-1);

	for (int l = 0; l < N; l++)
		cout << arr[l] << "\n";

	free(arr);
	free(comp);
}

int main(void)
{
	scanf_s("%d",&N);
	int* arr = new int[N];
	int* comp = new int[N];

	for (int i = 0; i < N; i++)
		scanf_s("%d",&arr[i]);

	part(arr, comp, 0, N - 1);

	for (int l = 0; l < N; l++)
		printf("%d\n",arr[l]);
}

*/

//10989번, 메모리와 시간 고려 필요한 문제 - 카운팅 정렬에서 간소화하여 풀었음
//1. ios::sync_with_stdio(false), cin.tie, \n 활용하여 cin cout 씀. 시간은 아래보다 적게 나옴, 하지만
// 기본값인 true일 때는 cout << "HI"; printf("BYE"); cout<<"hi" 가 순서대로 출력되지만, false일때는 어떤 순서로 출력될지 알 수가 없죠. 그렇기 때문에 ios::sync_with_stdio(false); 를 추가하시면, iostream 함수인 cin / cout을 stdio 함수인 getchar()와 같이 쓰시면 안됩니다.
// 라고 함. (문제 생길 수도 있다는 뜻)
//2.시간 고려하여 printf와 scanf 사용
/*

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int max = 0;
	int count[10000] = { 0, };
	int t;

	for (int i = 0; i < N; i++)
	{
		cin >> t;
		count[t - 1] += 1;
		if (t > max)
			max = t;
	}

	for (int j = 0; j < max; j++)
	{
		if (count[j] != 0)
		{
			for (int k = 0; k < count[j]; k++)
				cout << j + 1 << "\n";
		}
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);
	int max = 0;
	int count[10000] = { 0, };

	int t;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &t);
		count[t - 1] += 1;
		if (t > max)
			max = t;
	}

	for (int j = 0; j < max; j++)
	{
		if (count[j] != 0)
		{
			for (int k = 0; k < count[j]; k++)
				printf("%d\n", j + 1);
		}
	}
}

*/

//2018번, 통계학 문제 - 입력을 받을 때마다 새로 평균 계산하여 마지막 출력 때 floor(avg+0.5) 했더니 53%에서 틀렸습니다 뜸
//입력 받을 때마다 sum += input을 해주고 마지막에 floor(float(sum)/N+0.5) 했더니 맞음
//이유는 모르겠음... 여러 예시들 넣어봐도 둘 다 똑같이 맞았는데...
/*

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int count[8001] = { 0, };
	//count[0] = -4000 => +4000
	int max = -4001;
	int min = 4001;
	int sum = 0;
	int input = 0;
	int* arr = new int[N];
	int comax;
	int cmxidx1;
	int cmxidx2;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		count[input + 4000] += 1;

		sum += input;

		if (input > max)
			max = input;
		if (input < min)
			min = input;
	}

	for (int j = min + 4000; j < max + 4001; j++)
	{
		if (j == min + 4000)
		{
			comax = count[j];
			cmxidx1 = j - 4000;
			cmxidx2 = cmxidx1;
		}
		else
		{
			if (comax < count[j])
			{
				comax = count[j];
				cmxidx1 = j - 4000;
				cmxidx2 = j - 4000;
			}
			else if (comax == count[j])
			{
				if (cmxidx1 == cmxidx2)
				{
					cmxidx2 = j - 4000;
				}
			}

			count[j] += count[j - 1];
		}
	}

	for (int k = min + 4000; k < max + 4001; k++)
	{
		if (k == min + 4000)
		{
			for (int l = 0; l < count[k]; l++)
				arr[l] = k - 4000;
		}
		else if (count[k-1] < count[k])
		{
			for (int m = count[k - 1]; m < count[k]; m++)
				arr[m] = k - 4000;
		}
	}
	cout << floor(float(sum)/float(N)+0.5) << "\n" << arr[(N / 2)] << "\n" << cmxidx2 << "\n" << max - min << "\n";
}

*/

//c++에서 float과 int의 계산 = float이 포함되면 float 됨, int끼리 계산하면 그대로 int 결과 (소수점 결과 버림)
/*
int main(void)
{
	int a = 15;
	float b = 2.7;
	double c = -7.2;
	int d = 4;

	cout << "int a / int d = " << a / d << "\n"; // int끼리 만나면 그대로 int, 3.75가 아닌 3으로 결과는 int
	cout << "float b / int a = " << b / a << "\n"; // 결과 float
	cout << "int a / float b = " << a / b << "\n"; // 위와 동일, int와 float 만나면 float으로 변형되는 듯
	cout << "int a / double c = " << a / c << "\n"; // 결과 double?
	cout << "float b / double c = " << b / c << "\n"; // 결과 double?
}
*/

//14681번 - if문 문제 - 사분면 고르기
/*
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> x;
	cin >> y;

	if (x > 0)
	{
		if (y > 0)
			cout << 1 << "\n";
		else
			cout << 4 << "\n";
	}
	else
	{
		if (y > 0)
			cout << 2 << "\n";
		else
			cout << 3 << "\n";
	}
}
*/

//1427번 - 소트인사이드 - algorithm 헤더의 sort 활용
/*
bool desc(int a, int b)
{
	return a > b;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char N[10];
	cin >> N;

	sort(N, N + strlen(N), desc);

	cout << N << "\n";
}
*/

//11650번 - 좌표 정렬하기 - vector 활용해봄
/*

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(2));

	for (int i = 0; i < N; i++)
		cin >> arr[i][0] >> arr[i][1];
	sort(arr.begin(), arr.end());

	for (int j = 0; j < arr.size(); j++)
		cout << arr[j][0] << " " << arr[j][1] << "\n";
}

*/

//11651번 - 좌표 정렬하기2
//- 위와 비슷하지만 vector의 pair, first, second 사용해서
//sort의 3번째 매개변수에 판단 기준 함수 만들어 넣어 풀었음
//참고한 링크: https://jaimemin.tistory.com/1039
/*
bool standard_y(pair<int,int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int,int>> arr(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end(), standard_y);

	for (int j = 0; j < arr.size(); j++)
		cout << arr[j].first << " " << arr[j].second << "\n";
}
*/

//1181번 - 단어 정렬 - iterator 사용하는 방법과 erase 사용하는 방법 등등
/*

bool strcomp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> arr;
	int N;
	cin >> N;
	string tmp;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}
	
	sort(arr.begin(), arr.end(), strcomp);

	//unique 사용 시 중복 값은 vector의 맨 뒤로 보내져 쓰레기값이 됨
	//이 때 unique 함수의 return 값은 버려진 값들의 시작 iterator 값이 됨.
	//이 iterator를 활용하여 쓰레기값 전까지 print하는 방법
	//아래 둘 중 하나 선택하여 활용
//-----------------------------------------------------------------------	
	vector<string>:: iterator idx;
	vector<string>:: iterator endidx = unique(arr.begin(), arr.end());

	for (idx = arr.begin(); idx < endidx; idx++)
		cout << *idx << "\n";
//-----------------------------------------------------------------------
	//혹은 뒤의 쓰레기값을 지우고 print하는 방법
	//arr.erase(unique(arr.begin(), arr.end()), arr.end());
	//for (int i = 0; i < arr.size(); i++)
	//	cout << arr[i] << "\n";
}

*/

//포인터 기초
/*
int main(void)
{
	int value = 4;
	int* vptr = &value;

	*vptr = 9;

	cout << "value의 주소 vptr로 접근해 value의 값을 바꿈 => " << value << endl;

	int arr[7] = {5, 3, 1, 9, 7, 13, 11};

	cout << "arr[7]은 = {";
	for (int i = 0; i < 6; i++)
		cout << *(arr + i) << ", ";
	cout << *(arr + 6) << "}" << endl;
	cout << "배열을 주소값으로 접근해봄 => arr 배열을 역참조할 시 가장 처음 값 arr[0]이 나옴 => *arr: " << *arr << endl;
	cout << "arr 자체는 arr 배열의 주소값을 가짐 => arr 값에 2를 더하여 역참조할 시 arr[0]이 아닌 arr[2]가 출력됨 => *(arr + 2): " << *(arr + 2) << endl;
}
*/

//10814번 - 나이순 정렬
//https://ldgeao99.tistory.com/341
//위 링크에서 여러 방법 소개 (구조체 struct 사용하는 방법도 있음)
//http://blog.naver.com/zephyehu/150013176075
//위 링크에는 stable sort와 unstable sort에 대한 이야기
//여러 sort algorithm에 대해 stable한지 unstable한지 언급되어 있음
//참고로 기존의 순서가 섞이지 않으며 sorting 되는 것이 stable sort임
/*
bool ordercomp(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, string>> vect(N);

	for (int i = 0; i < N; i++)
		cin >> vect[i].first >> vect[i].second;

	stable_sort(vect.begin(), vect.end(), ordercomp);

	for (int i = 0; i < N; i++)
		cout << vect[i].first << " " << vect[i].second << "\n";
}
*/

//10039번 - 평균 점수
/*

int main(void)
{
	int N;
	int res = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> N;
		if (N < 40)
			N = 40;
		res += N;
	}

	cout << res / 5 << "\n";
}

*/

//2523번 - 별 찍기 13
/*

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
			cout << "*";
		cout << "\n";
	}

	for (int k = N - 1; k > 0; k--)
	{
		for (int l = 0; l < k; l++)
			cout << "*";
		cout << "\n";
	}
}

*/

//2446번 - 별 찍기 9
/*

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 2 * N - 1; i > 0; i -= 2)
	{
		for (int j = 0; j < (2 * N - 1 - i) / 2; j++)
			cout << " ";

		for (int k = 0; k < i; k++)
			cout << "*";

		cout << "\n";
	}

	for (int l = 3; l <= 2 * N - 1; l += 2)
	{
		for (int m = 0; m < (2 * N - 1 - l) / 2; m++)
			cout << " ";

		for (int n = 0; n < l; n++)
			cout << "*";

		cout << "\n";
	}
}

*/

//10996번 - 별 찍기 21
/*

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j % 2 == 0)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";

		for (int k = 0; k < N; k++)
		{
			if (k % 2 == 0)
				cout << " ";
			else
				cout << "*";
		}
		cout << "\n";
	}
}

*/

//15650번 - N과 M (1)
/*
int vis[9];
int arr[9];

void nm1(int N, int M, int tmp)
{
	if (tmp == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
		if (vis[i] == false)
		{
			vis[i] = true;
			arr[tmp] = i;
			nm1(N, M, tmp + 1);
			vis[i] = false;
		}
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	fill_n(vis, 9, false);

	nm1(N, M, 0);
}
*/

//15650번 - N과 M (2)
/*
int main(void)
{
	int N, M;
	cin >> N >> M;

	deque <int> dq;

	int tmp = 1;
	dq.push_back(tmp);

	while (1)
	{
		if (dq.size() == M)
		{
			for (int i = 0; i < M; i++)
				cout << dq.at(i) << " ";
			cout << "\n";

			if (dq.front() == N - M + 1)
				break;

			dq.pop_back();
		}

		tmp++;
		if (tmp > N - M + dq.size() + 1)
		{
			tmp = dq.back();
			dq.pop_back();
		}
		else
			dq.push_back(tmp);
	}
}
*/

//15651번 - N과 M (3)
/*
int arr[9];

void nm1(int N, int M, int tmp)
{
	if (tmp == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		arr[tmp] = i;
		nm1(N, M, tmp+1);
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;

	nm1(N, M, 0);
}
*/

//15652번 - N과 M (4)
/*
int arr[9];
int ininum;

void nm1(int N, int M, int tmp)
{
	if (tmp == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	if (tmp == 0)
		ininum = 1;
	else
		ininum = arr[tmp-1];

	for (int i = ininum; i <= N; i++)
	{
		arr[tmp] = i;
		nm1(N, M, tmp + 1);
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;

	nm1(N, M, 0);
}
*/