#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int s[5005][5005] = { 0 };
short a[5005][5005] = { 0 };//用int会MLE
int maxx = 0, maxy = 0;
void cals()
{
	for (int i = 1; i < maxx; i++)
	{
		for (int j = 1; j < maxy; j++)
		{
			s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
		}
	}
}
int main()
{
	int n, r;
	cin >> n >> r;

	for (int i = 0; i < n; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		a[x + 1][y + 1] += w;
		maxx = max(maxx, x + 2);
		maxy = max(maxy, y + 2);
	}
	cals();//计算前缀和
	int maxn = -1;
	for (int i = 0; i < maxx; i++)
		for (int j = 0; j < maxy; j++)
		{
			int x = min(maxx - 1, i + r);
			int y = min(maxy - 1, j + r);
			maxn = max(s[x][y] + s[i][j] - s[x][j] - s[i][y], maxn);
		}
	cout << maxn;
}