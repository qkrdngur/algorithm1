#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, m;
long long vn,low, high, mid, cnt;
long long result, iMax;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> vn;
		v.push_back(vn);
		if (iMax < v[i])
			iMax = v[i];
	}

	low = 0;
	high = iMax;

	while (low <= high)
	{
		mid = (low + high) / 2;
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if(v[i] - mid > 0)
				cnt += v[i] - mid;
		}
		if (cnt >= m)
		{
			low = mid + 1;
			if (result < mid)
				result = mid;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << result;
}