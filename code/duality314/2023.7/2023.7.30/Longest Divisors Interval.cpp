#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*

int main()
{
	int N;
	cin >> N;

	while (N--)
	{
		long long int n, copyn;
		vector<int> v = { 1 };

		cin >> n;
		copyn = n;
		for (long long int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				int times = 0;
				while (n % i == 0)
				{
					n /= i;
					times++;
				}
				v.push_back(i);
			}
		}
		int maxsize = -1, k = -1;
		for (auto i : v)
		{
			if (k > i)
			{
				continue;
			}
			for (int size = 0; size >= 0; size++)
			{
				if (copyn % i != 0)
				{
					k = i;
					maxsize = max(maxsize, size);
					break;
				}
				i++;
			}
		}
		cout << maxsize << endl;
	}
}*/

int main()
{
	int N;
	cin >> N;

	while (N--)
	{
		long long int n;
		int size = 1;
		cin >> n;
		for (int i = 2; i <= n; i++)
		{
			if (n % i != 0)
			{
				break;
			}
			size++;
		}

		cout << size << endl;
	}
}