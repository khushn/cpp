#include <iostream>
#include <vector>
#include <climits>

using namespace std;

signed main() {

	int a, b;
	cin >> a >> b;

	vector<vector<int>> dp(a+1, vector<int>(b+1));
	for(int i=1; i<=a; i++) {
		for(int j=1; j<=b; j++) {
			if (i == j) {
				// already a square (value is zero)
				continue;
			}

			if (i == 1) {
				dp[i][j] = j - 1;
				continue;
			}

			if (j == 1) {
				dp[i][j] = i - 1;
				continue;
			}

			int min = INT_MAX;
			// consider horizontal
			for(int c=1; c<=i/2; c++) {
				int v = dp[c][j] + dp[i-c][j] + 1; // plus 1 for the cut
				if (v < min)
					min = v;
			}
			
			// consider vertical
			for(int r=1; r<=j/2; r++) {
				int v = dp[i][r] + dp[i][j-r] + 1; // plus 1 for the cut
				if (v < min)
					min = v;
			}

			dp[i][j] = min;
		}
	}

	cout << dp[a][b] << endl;

}