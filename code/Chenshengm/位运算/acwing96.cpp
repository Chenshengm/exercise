#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f
int d(int i)
{
	if (i == 1)
	{
		return 1;
	}
	return 2 * d(i - 1) + 1;
}
int f(int i)
{
	if (i == 1)
	{
		return 1;
	}
	int min1 = INF;
	for (int k = 1; k < i; k++)
	{
		min1 = min(min1, 2 * f(k) + d(i - k));
	}
	return min1;
}
int main()
{
	for (int i = 1; i <= 12; i++)
	{
		cout << f(i) << endl;
	}
}