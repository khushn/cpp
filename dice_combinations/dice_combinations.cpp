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

	int ans = recurse(n);
	cout << ans << endl;

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