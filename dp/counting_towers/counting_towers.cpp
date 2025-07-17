#include <iostream>
#include <vector>

using namespace std;

#define int long long


const int MAX = 1000000;

const int mod = 1e9 + 7;


/*

Approach:
Its visual! Have taken pics of the work in my register (notebook) and tweeted 
DP is simple. Just that had to think (for 2 days) of the top row configuration
and where they are possible. 

* Overall 6 possible sets of top row. 
* some need a vertical bar below
* some don't need it. 
Also need to maintain the vertical and non-vertical bar sums, right till the end. 

Will also upload images to the directory, where code is, of my notebook scribble

*/

signed main() {
	
	// 2d dp vector
	// it stores vertical and non-vertical for all positions
	vector<vector<int>> dp(MAX, vector<int>(2));


	// for 1 heiht tower
	dp[0][0] = 1; // non vertical
	dp[0][1] = 1; // vertical
	for(int i=1; i<MAX; i++) {
		// size type of new tops possible

		int prev_total = (dp[i-1][0] + dp[i-1][1]) % mod;
		// non vertical
		dp[i][0] = (dp[i-1][0] + prev_total) % mod;

		dp[i][1] = (dp[i-1][1] * 3 + prev_total) % mod;


	}


	//cout << dp[5][0] << " + " << dp[5][1] << endl;

	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		int n;
		cin >> n;
		int ans = (dp[n-1][0] + dp[n-1][1]) % mod;
		cout << ans << endl;
	}


}