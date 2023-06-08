#include <iostream>
#include <algorithm>
using namespace std;

int needline, haveline;
int* arr = new int[haveline];
int sum(int input)
{
	int sum;
	for (int i = 0; i < haveline; i++)
		sum = arr[i] / input;
	return sum;
}

int main()
{
	int savesum;
	cin >> haveline >> needline;

	for (int i = 0; i < haveline; i++)
	{
		cin >> arr[i];
		savesum += arr[i];
	}

	sort(arr, arr+haveline);

	int low = 0;
	int high = haveline - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int asdf = sum(mid);
		if (v[mid] == x) return 1;
		else if (v[mid] > x)
			high = mid - 1;
		else if (v[mid] < x)
			low = mid + 1;
	}
}