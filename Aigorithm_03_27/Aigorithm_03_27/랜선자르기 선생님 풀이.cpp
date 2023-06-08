#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int k, n;
long long vn, low, high, mid, cnt;
long long iMax, result;

int main()
{
	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		cin >> vn;
		v.push_back(vn);
		if (iMax < v[i])
			iMax = v[i];
	}
	low = 1;
	high = iMax;
	while (low <= high)
	{
		mid = (low + high) / 2;
		cnt = 0;
		for (int i = 0; i < k; i++)
		{
			cnt += v[i] / mid;
		}
		if (cnt >= n)//더 많이 자름
		{
			low = mid + 1;
			if (result < mid)
				result = mid;
		}
		else
		{
			high = mid - 1;
		}
	};
	cout << result;
}