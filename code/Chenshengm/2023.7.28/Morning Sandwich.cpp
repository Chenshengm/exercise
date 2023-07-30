#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int b, c, h;
		cin >> b >> c >> h;
		int k = 2 * b - 1;
		if (b > (c + h + 1))
		{
			k = 2 * (c + h) + 1;
		}
		cout << k << endl;
	}
}