#include <iostream>
using namespace std;

int sum(int n)
{
	int a = 0;
	for (int i = 1; i < n + 1; i++)
	{
		a += i;
	}
	return a;
}

int main()
{
	//int n;
	//cin >> n;
	//cout << sum(n) << endl;

	string str;
	clock_t start, end;
	int n;
	cin >> n;
	start = clock();
	for (int i = 0; i < n; i++)
	{
		str += "X";
	}
	end = clock();
	cout << end - start << endl;
	return 0;
}