#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;

	cin >> N;
	int* arr = new int[N];


	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);

	cin >> M;
	int* charr = new int[M];
	for (int i = 0; i < M; i++)
	{
		cin >> charr[i];
	}
	for (int i = 0; i < M; i++)
	{
		cout << upper_bound(arr, arr + N, charr[i]) - lower_bound(arr, arr + N, charr[i]) << " ";
	}
}