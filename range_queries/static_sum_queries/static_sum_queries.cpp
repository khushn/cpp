#include <iostream>
#include <vector>

using namespace std;

#define int long long

signed main() {

	int n, q;
	cin >> n >> q;

	vector<int> arr(n);
	vector<int>  pref_sum(n);
	for (int i = 0; i<n; i++) {
		int num;
		cin >> num;
		arr[i] = num;

		int psum;
		if (i == 0) {
			psum = arr[i];
		} else {
			psum = pref_sum[i-1] + arr[i];
		}
		pref_sum[i] = psum;
	}

	for (int i = 0; i<q; i++) {
		int a, b;
		cin >> a >> b;
		int ans = pref_sum[b-1];
		if (a > 1) {
			ans -= pref_sum[a-2];
		}

		cout << ans << endl;
	}
}