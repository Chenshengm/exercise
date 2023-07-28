#include<iostream>
#include<algorithm>
using namespace std;

typedef struct a {
	int num;
	int index;
} a;

bool cmp(const a& x, const a& y) {
	if (x.num == y.num)
		return x.index < y.index; // Choose the monster with smaller index if health is the same
	return x.num > y.num;
}

int main() {
	int N;
	cin >> N;

	while (N--) {
		int n, k;
		cin >> n >> k;
		a* arr = new a[n]; // Use dynamic memory allocation

		for (int i = 0; i < n; i++) {
			int s;
			cin >> s;
			arr[i].num = s % k;
			if (arr[i].num == 0)
			{
				arr[i].num = k;
			}
			arr[i].index = i + 1;
		}
		sort(arr, arr + n, cmp);

		for (int i = 0; i < n; i++) {
			cout << arr[i].index << " ";
		}
		cout << endl;

		delete[] arr; // Deallocate the memory
	}
}
