#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*
https://codeforces.com/contest/1851/problem/A
*/
int main()
{
	int N, n, m, k, H;
	int num = 0;
	cin >> N;
	int h;
	while (N--)
	{
		cin >> n >> m >> k >> H;
		for (int i = 0; i < n; i++)
		{
			cin >> h;
			int c = abs(H - h);
			if ((c % k == 0) && (c / k < m) && (c / k > 0))
			{
				num++;
			}
		}
		cout << num << endl;
		num = 0;
	}
}