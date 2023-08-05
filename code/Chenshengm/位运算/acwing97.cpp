#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<pair<int, int>> m;
int power(int num, int cs)//快速幂
{
	int ans = 1;
	for (; cs; cs >>= 1)
	{
		if (cs & 1) ans = (long long)ans * num % 9901;
		num = (long long)num * num % 9901;
	}
	return ans;
}
int cal(int num, int cs)
{
	if (cs == 1)
	{
		return num + 1;
	}
	if (cs == 0)
	{
		return 1;
	}
	int ans;
	if (cs % 2 == 0)
	{
		ans = (1 + power(num, cs / 2)) * cal(num, cs / 2 - 1) + power(num, cs);
		return ans % 9901;
	}
	else
	{
		ans = (1 + power(num, (cs + 1) / 2)) * cal(num, (cs - 1) / 2);
		return  ans % 9901;
	}
}
int main()
{

	int a, b;
	cin >> a >> b;
	if (b == 0)
	{
		a = 1;
	}
	if (a == 0)
	{
		cout << 0;
		return 0;
	}
	for (int i = 2; i <= a; i++)
	{
		if (a % i == 0)
		{
			int cs = 0;
			while (a % i == 0)
			{
				a /= i;
				cs++;
			}
			m.push_back(make_pair(i, cs * b));
		}
	}
	int ans = 1;
	for (auto i : m)
	{
		ans *= cal(i.first, i.second);
		ans %= 9901;
	}
	cout << ans;
}