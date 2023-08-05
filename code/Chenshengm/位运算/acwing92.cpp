#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> chosen;
void cal(int x)
{
	if (x == n + 1)
	{
		for (int i = 0; i < chosen.size(); i++)
		{
			cout << chosen[i] << " ";
		}
		cout << endl;
		return;
	}
	cal(x + 1);
	chosen.push_back(x);
	cal(x + 1);
	chosen.pop_back();
}
int main()
{

	cin >> n;
	cal(1);
}