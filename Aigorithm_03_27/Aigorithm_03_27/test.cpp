#include <iostream>
using namespace std;

int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
int main()
{
	int x, low, high, mid;
	cin >> x;
	low = 0;
	high = 9;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (x == arr[mid])
		{
			cout << x << "�� " << mid << "�� index�� �ֽ��ϴ�." << endl;
			break;
		}
		else if (x < arr[mid])//���ʿ� �ִ� ��Ȳ
		{
			high = mid - 1;
		}
		else if (x > arr[mid])//�����ʿ� �ִ� ��Ȳ
		{
			low = mid + 1;
		}
	}
	/*int x;
	cin >> x;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == x)
		{
			cout << x << "�� " << i << "��°�� �ֽ��ϴ�." << endl;
		}
	}*/
}