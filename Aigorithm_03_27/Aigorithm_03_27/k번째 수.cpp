#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v = {1,2,2,3,4,4,5,6,7,8,8,9};
int arr[]{ 1,2,2,3,3,4,5,6,6,7,7,8 };
int main()
{
	vector<int>::iterator itor = lower_bound(v.begin(), v.end(), 4);
	cout << v[itor - v.begin()] << endl;
	cout << upper_bound(arr, arr + 9, 9) - lower_bound(arr, arr + 9, 4) << endl;
	//어퍼는 찾은 수의 다음 인덱스 번호를 부른다, 로워는 가장 처음 그 숫자를 찾은 인덱스 번호를 부른다.
	long long int a, b;
	int cnt = 0;
	int result = 0;

	cin >> a >> b;

	int low = 1;
	int high = b;
	long long int middle = 0;
	while (low < high)
	{
		middle = (low + high) / 2;
		cnt = 0;
		for (int i = 1; i <= a; i++)
		{
			cnt += min(middle / i, a);
		}
		if (cnt < b)
		{
			low = middle + 1;
		}
		else
		{
			high = middle;
		}
	}

	cout << low;
}