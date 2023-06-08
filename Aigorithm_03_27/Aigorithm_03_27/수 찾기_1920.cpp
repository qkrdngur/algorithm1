#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, vn;
int m, vm;
vector<int> v;

int bisearch(int x)
{
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (v[mid] == x) return 1;
		else if (v[mid] > x)
			high = mid - 1;
		else if (v[mid] < x)
			low = mid + 1;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> vn;
		v.push_back(vn);
	}
	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> vm;
		cout << bisearch(vm) << "\n";
	}
}