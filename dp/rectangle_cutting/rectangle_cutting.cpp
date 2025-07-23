#include <iostream>
#include <vector>

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

			int val = 0;
			if (i > j) {
				val = i/j;
				int rem = i%j;
				if ( rem == 0)
					val--;
				else 
					val += dp[rem][j];			
			} else {
				val = j/i;
				int rem = j%i;
				if ( rem == 0)
					val--;
				else 
					val += dp[i][rem];
			}

			dp[i][j] = val;
		}
	}

	cout << dp[a][b] << endl;

}