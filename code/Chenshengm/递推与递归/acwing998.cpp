#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
/*
long long int k[32];
inline void operate()
{
	string op;
	long long int t;
	cin >> op >> t;
	switch (op[0])
	{
	case 'A':
		for (long long int i = 0; i < 32; i++)
		{
			if ((t & 1) == 0)
			{
				k[i] = 0;
			}
			t >>= 1;
		}
		break;
	case 'O':
	{
		for (long long int i = 0; t != 0; i++)
		{
			if ((t & 1) == 1)
			{
				k[i] = 1;
			}
			t >>= 1;
		}
		break;
	}
	case 'X'://异或满足结合律
	{
		for (long long int i = 0; i < 32; i++)
		{

			k[i] ^= (t & 1);//负数也直接异或，只有最后一位可能改变

			t >>= 1;
		}
		break;
	}
	default:
		break;
	}
}
long long int get_num(long long int m)
{
	long long int sum = 0;
	long long int lastm = 0;//在已确定的位为0，不确定的位争取为1
	for (long long int i = 31; i >= 0; i--)
	{
		if (k[i] < 0)
		{
			k[i] &= 1;//如果最后是0，那么初始取0最大，如果最后是1，那么初始取1最大，因此此时的k[i]代表最初的值
			if (lastm + (k[i] << (long long int) i) <= m)
			{
				lastm += (k[i] << (long long int) i);
				k[i] = 1;
			}
			else
			{
				k[i] = 0;
			}
		}
		sum += (k[i] << (long long int) i);
	}
	return sum;

}
int main()
{
	long long int n, m;
	cin >> n >> m;
	for (long long int i = 0; i <= (log(m + 1) / log(2)); i++)
	{
		k[i] = -1;//不确定位
	}
	for (long long int i = 0; i < n; i++)
	{
		operate();
	}
	cout << get_num(m) << endl;
}

*/

//另一种，学习用bitset
#include<bitset>
int main()
{
	bitset<32>zero, one;
	zero.reset();
	one.set();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string x;
		int y;
		cin >> x >> y;

		if (x == "AND") zero &= y, one &= y;
		else if (x == "OR") zero |= y, one |= y;
		else if (x == "XOR") zero ^= y, one ^= y;
	}
	long long int sum = 0;
	long long int initial = 0;
	for (int i = 31; i >= 0; i--)//也是从最高位开始
	{
		if (zero[i] == 1)
		{
			sum += (1LL << i);//注意用long long
		}
		else if (one[i] == 1 && initial + (1LL << i) <= m)
		{
			sum += (1LL << i);
			initial += (1LL << i);
		}
	}
	cout << sum;

}