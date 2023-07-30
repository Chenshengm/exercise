#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
/*https://codeforces.com/contest/1851/problem/B*/
int main()
{
	int N;
	cin >> N;
l1:	while (N--)
{
	int n, a[200000];
	bool is_odd[200000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		is_odd[i] = a[i] % 2;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != is_odd[i])
		{
			cout << "No" << endl;
			goto l1;
		}
	}
	cout << "Yes" << endl;
}
}