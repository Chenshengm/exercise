#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int, int> cal(int n, int a)
{
	if (n == 1)
	{
		switch (a)
		{
		case 0:
			return make_pair(-5, 5);
		case 1:
			return make_pair(5, 5);
		case 2:
			return make_pair(5, -5);
		case 3:
			return make_pair(-5, -5);

		default:
			break;
		}
	}
	int p = pow(4, n - 1);
	if (a < p)//左上
	{
		pair<int, int>temp = cal(n - 1, a);
		//顺时针转90度，再水平翻转
		int x = temp.first;
		int y = temp.second;
		//-y,-x
		return make_pair(-pow(2, n - 2) * 10 - y, pow(2, n - 2) * 10 - x);
	}
	else if (a < 2 * p)//右上
	{
		pair<int, int>temp = cal(n - 1, a - p);
		//不变
		int x = temp.first;
		int y = temp.second;
		//-y,-x
		return make_pair(pow(2, n - 2) * 10 + x, pow(2, n - 2) * 10 + y);
	}
	else if (a < 3 * p)
	{
		pair<int, int>temp = cal(n - 1, a - 2 * p);
		//不变
		int x = temp.first;
		int y = temp.second;
		//-y,-x
		return make_pair(pow(2, n - 2) * 10 + x, -pow(2, n - 2) * 10 + y);
	}
	else
	{
		pair<int, int>temp = cal(n - 1, a - 3 * p);
		//顺时针转90度，再水平翻转
		int x = temp.first;
		int y = temp.second;
		//y,x
		return make_pair(-pow(2, n - 2) * 10 + y, -pow(2, n - 2) * 10 + x);
	}

}
signed main()
{
	int N;
	cin >> N;

	cout << fixed << setprecision(0); // 设置输出格式，取消科学计数法，小数点后 0 位

	while (N--)
	{
		int n, a, b;
		cin >> n >> a >> b;
		pair<int64_t, int64_t> ia, ib;
		ia = cal(n, a - 1);
		ib = cal(n, b - 1);

		// 计算平方和，使用 long double 类型
		long double a1 = static_cast<long double>(ia.first - ib.first);
		long double b1 = static_cast<long double>(ia.second - ib.second);
		long double distance = round(sqrt(a1 * a1 + b1 * b1));

		// 输出结果
		cout << static_cast<int64_t>(distance) << endl;
	}

	return 0;
}