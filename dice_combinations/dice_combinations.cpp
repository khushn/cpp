#include <iostream>
#include <vector>

using namespace std;

#define int long long


const int mod = 1e9 + 7;

vector<int> dp;

int recurse(int x);

signed main() {
	int n;
	cin >> n;

	dp.resize(n+1);



	//int ans = recurse(n);
	//cout << ans << endl;

	// building an iterative solution
	dp[0] = 1;
	for (int i=0; i<=n; i++) {
		for (int j=1; j<=6; j++) {
			if (i+j <= n) {
				dp[i+j] += dp[i];
				dp[i+j] %= mod;
				// cout << (i+j) << " : " << dp[i+j] << endl;
			}

		}
	}

	cout << dp[n] << endl;
}


int recurse(int x) {
	cout << "recurse called for x: " << x << ", with total: " << endl;

	if (x == 0)
		return 1;

	// we could get any of the 6 in the last attempt
	int ans = 0;
	for (int i=1; i<=6; i++) {

		if (x >= i) {
			if (dp[x-i] > 0)
				ans += dp[x-i];
			else {
				int ret = recurse(x-i);
				dp[x-i] = ret % mod;
				ans +=  dp[x-i];
			}
		}
	}
	return ans % mod;
}