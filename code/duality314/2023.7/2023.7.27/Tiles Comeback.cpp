#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
l1:	while (t--)
{
	int n, k, c[200000];
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	int first = c[0], last = c[n - 1];
	if (first == last)
	{
		int num = 0;
		for (int i = 0; i < n; i++)
		{
			num += (c[i] == first);
			if (num >= k)
			{
				cout << "Yes" << endl;
				goto l1;
			}
		}
		cout << "No" << endl;
	}
	else
	{
		int last_num = 0, first_num = 0;
		int firstend = -1, lastend = -1;

		for (int i = 0; i < n; i++)
		{
			first_num += (c[i] == first);
			last_num += (c[n - i - 1] == last);
			if (first_num >= k && firstend == -1)
			{
				firstend = i;
			}
			if (last_num >= k && lastend == -1)
			{
				lastend = n - i - 1;
			}

		}
		if (firstend < lastend && firstend != -1 && lastend != -1)
		{
			cout << "Yes" << endl;
			goto l1;
		}
		cout << "No" << endl;
	}

}
}