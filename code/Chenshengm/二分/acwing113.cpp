#include<bits/stdc++.h>
using namespace std;
#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)
class Solution {
public:
	vector<int> specialSort(int N) {
		vector<int> d = { 1 };
		int l = 0, r = 0;
		for (int i = 2; i <= N; i++)
		{
			while (l != r)
			{
				int mid = (l + r) / 2;
				if (compare(d[mid], i))
				{
					l = mid + 1;
				}
				else
				{
					r = mid;
				}
			}
			if (compare(d[l], i))
			{
				//插到第l位
				d.insert(d.begin() + l + 1, i);;
			}
			else
			{
				d.insert(d.begin() + l, i);
			}
			l = 0; r = d.size() - 1;
		}
		return d;
	}
};