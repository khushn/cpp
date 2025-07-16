#include <iostream>
#include <vector>

using namespace std;

#define int long long

signed main() {
	int n, x;
	cin >> n >> x;

	vector<int> vec(n);
	for (int i=0; i<n; i++) {
		cin >> vec[i];
	}

	int l= 0;
	int r =0;
	int sum = vec[0];
	int ans = 0;
	while (l < n && r<n) {		
		//cout << "l: " << l << ", r: " << r << ", sum: " << sum << endl;
		if (sum >= x) {
			if (sum == x)
				ans++;

			sum -= vec[l];
			l++;
			if (r < l) {
				r = l;
				sum += vec[r];
			}
		} else {
			r++;
			sum += vec[r];
		}
	}

	cout << ans << endl;
}