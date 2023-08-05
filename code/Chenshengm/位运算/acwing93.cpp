#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int n,m;
vector<int> chosen;
void cal(int x)
{
	if (chosen.size() > m || chosen.size() + n - x + 1 < m)//剪枝
	{
		return;
	}
	if (x == n + 1)
	{
		for (int i = 0; i < chosen.size(); i++)
		{
			cout << chosen[i] << " ";
		}
		cout << endl;
		return;
	}
	chosen.push_back(x);
	cal(x + 1);
	chosen.pop_back();
	cal(x + 1);
}
int main()
{

	cin >> n>>m;
	cal(1);
}
//不用递归的实现
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
signed main(){
	cin>>n>>m;
	for(int i=(1<<n)-1;i>=1;i--){
		int cnt=0;
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				cnt++;
			}
		}
		if(cnt==m){
			for(int j=n-1;j>=0;j--){
				if((i>>j)&1){
					cout<<n-j<<" ";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
*/