#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)
int main()
{
	int n, p, h, m;
	cin >> n >> p >> h >> m;
	int diff[5000] = { 0 };
	set<pair<int, int>> a;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		a.insert(make_pair(min(s, e), max(s, e)));
	}
	for (auto i : a)
	{
		diff[i.first - 1] -= 1;
		diff[i.second - 2] += 1;
	}
	int height[5005];
	height[p] = h;
	for (int k = p - 1; k > 0; k--)
	{
		height[k] = -diff[k - 1] + height[k + 1];
	}
	for (int k = p + 1; k <= n; k++)
	{
		height[k] = height[k - 1] + diff[k - 2];
	}
	for (int i = 1; i <= n; i++)
	{
		cout << height[i] << endl;
	}
}