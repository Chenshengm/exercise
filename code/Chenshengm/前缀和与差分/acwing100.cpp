#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

int main()
{
	ios;
	vector<int> a = { 0 }, diff;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		a.push_back(m);
		diff.push_back(a[i + 1] - a[i]);
	}
	long long pos = 0, neg = 0;
	for (int i = 1; i < n; i++)
	{
		if (diff[i] > 0)
		{
			pos += diff[i];
		}
		else
		{
			neg -= diff[i];
		}
	}
	int r = abs(pos - neg) + 1;
	cout << max(pos, neg) << endl << r;

}