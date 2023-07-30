#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> PII;
const int N = 25;
const int inf = 0x3f3f3f3f;
int a[N];

signed main() {
	IOS;
	int T;
	cin >> T;
	while (T--) {
		vector<PII> v;
		int n, nmax = -inf, dn, nmin = inf, xn, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] > nmax) {
				dn = i;
				nmax = a[i];
			}
			if (a[i] < nmin) {
				xn = i;
				nmin = a[i];
			}
		}
		if (abs(nmax) > abs(nmin)) {
			for (int i = 2; i <= n; i++) {
				while (a[i] < a[i - 1]) {
					a[i] += nmax;
					ans++;
					v.push_back({ i,dn });
					if (a[i] > nmax) {
						dn = i;
						nmax = a[i];
					}
				}
			}
		}
		else {
			for (int i = n - 1; i > 0; i--) {
				while (a[i] > a[i + 1]) {
					a[i] += nmin;
					ans++;
					v.push_back({ i,xn });
					if (a[i] < nmin) {
						xn = i;
						nmin = a[i];
					}
				}
			}
		}
		cout << ans << endl;
		for (auto u : v) {
			cout << u.first << ' ' << u.second << endl;
		}
	}
	return 0;
}
