#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*https://codeforces.com/contest/1851/problem/D*/
int main()
{
	int N;
	cin >> N;
l1:while (N--)
{
	int n;
	cin >> n;
	bool a[200002] = { false };
	long long int s = 0;
	long long int f = -1;
	bool once = false;
	bool no = false;
	for (int i = 0; i < n - 1; i++)
	{
		long long int p;
		cin >> p;
		if (no)
		{
			continue;
		}
		if ((p - s) > n || a[p - s] == true)
		{
			if (once)
			{
				no = true;
			}
			f = p - s;
			once = true;
			s = p;
			continue;
		}
		a[p - s] = true;
		s = p;
	}
	if (no)
	{
		cout << "No" << endl;
		goto l1;
	}

	long long int sum = 0;
	int flag = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!a[i])
		{
			sum += i;
			flag++;
		}
	}
	if ((flag != 2 || sum != f) && (!(flag == 1 && f == -1)))//考虑最后一个数丢失
	{
		cout << "No" << endl;
		goto l1;
	}
	cout << "Yes" << endl;
}
}