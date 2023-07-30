#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;

	while (N--)
	{
		int n;
		cin >> n;
		int num = 0;
		int m;
		for (int i = 1; i <= n; i++)
		{
			cin >> m;
			if (i == m)
			{
				num++;
			}
		}
		cout << (num + 1) / 2 << endl;
	}

}
