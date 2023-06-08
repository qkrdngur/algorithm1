#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> s;
int main()
{
	int result = 0;
	while (true)
	{
		int num;
		getline(cin,);
		s.push(num);

		if (s.top() == '*')
		{
			s.pop();
			int i = s.top();
			s.pop();
			result = i * s.top();
		}

		if (s.top() == '/')
		{
			s.pop();
			int i = s.top();
			s.pop();
			result = s.top() / i;
		}

		if (s.top() == '-')
		{
			s.pop();
			int i = s.top();
			s.pop();
			result = s.top() - i;
		}

		if (s.top() == '+')
		{
			s.pop();
			int i = s.top();
			s.pop();
			result = s.top() + i;
		}
	}
}