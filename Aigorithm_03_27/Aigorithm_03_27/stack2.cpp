#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int main()
{
	int n , result = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (input == 0)
		{
			st.pop();
		}
		else
		{
			st.push(input);
		}
	}
	while (!st.empty())
	{
		result += st.top();
		st.pop();

	}
	cout << result;
}