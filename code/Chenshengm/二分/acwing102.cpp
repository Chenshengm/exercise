#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)
vector<long long>s = { 0 };
int n, f;
int valid(long double avg)//是否有可能平均下来超过avg
{
	long double ans = -1e10;
	long double minval = 1e10;
	for (int i = f; i <= n; i++)
	{
		minval = min(minval, s[i - f] - avg * (i - f));
		ans = max(ans, (s[i] - avg * i - minval));
		if (ans > 0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	ios;

	cin >> n >> f;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		s.push_back(k + s[i]);
	}
	//猜平均下来牛的数目
	int l = 100000, r = 200000000;//卡精度很怪
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (valid((mid / 100000.0)))
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}

	}
	cout << l / 100;
}