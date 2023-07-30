#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {

	IOS;
	int N;
	cin >> N;
	while (N--) {
		int n, m;
		cin >> n >> m;
		string str;
		cin >> str;
		vector<int> pre(n, -1), nxt(n, n);//优化后的开始和结尾的最大范围
		for (int i = 0; i < n; i++) {
			if (i > 0) pre[i] = pre[i - 1];
			if (str[i] == '0') pre[i] = i;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (i < n - 1) nxt[i] = nxt[i + 1];
			if (str[i] == '1') nxt[i] = i;
		}
		set<pair<int, int> > s;
		while (m--) {
			int l, r;
			cin >> l >> r;
			l--, r--;
			if (nxt[l] > pre[r]) {//与原来相同
				s.insert({ -1, -1 });
			}
			else {
				s.insert({ nxt[l], pre[r] });
			}
		}
		cout << s.size() << '\n';
	}

}