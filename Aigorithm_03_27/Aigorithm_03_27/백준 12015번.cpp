#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
	int n, num, cnt = 0;

	cin >> n;
	v.push_back(-1);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num > v.back())
		{
			v.push_back(num);
			cnt++;
		}
		else
		{
			vector<int>::iterator iter = lower_bound(v.begin(), v.end(), num);
			*iter = num;
		}
	}

	cout << cnt;
}