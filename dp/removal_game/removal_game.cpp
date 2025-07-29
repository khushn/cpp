#include <iostream>
#include <vector>

using namespace std;

#define int long long

/*
Algo: 
1. Take the prefix sums for use later to calculate sums of array(i,j)
2. Have a 2-d dp matrix, where rows are length of the array, and columns mean ending index. 
   Therefore I use starting index from 1 and through n, to avoid confusion
3. For 1st row just populate the input array values
4. For 2nd row onwards apply -> choose better of using first element vs last element. Make use of row above
   for prev best result. Also prefix sum to choose the remainng sum. 

By applying this we arrive at the solution in O(N^2). Since N is at most 5000. It works!
*/

signed main() {
	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> prefix_sum(n+1);
	for(int i=0; i<n; i++) {
		int val;
		cin >> val;
		v[i] = val;
		prefix_sum[i+1]  = prefix_sum[i] + val;
		// cout << "prefix_sum[" << i+1 << "] = " << prefix_sum[i+1] << endl;
	}

	vector<vector<int>> dp(n+1, vector<int>(n+1));
	for(int r=1; r<=n; r++) {
		//cout << "row: " << r << endl;
		for(int c = 1; c<=n; c++) {
			if (r == 1) {
				dp[r][c] = v[c-1];
				continue;
			}

			if (c < r )
				continue;

			// max of the two
			int s1 = prefix_sum[c-1] - prefix_sum[c-r];
			int m1 = (s1 - dp[r-1][c-1]) + v[c-1];
			//cout << "s1: " << s1 << ", m1: " << m1 << endl;

			int s2 = prefix_sum[c] - prefix_sum[c-r+1];
			int m2 = (s2 - dp[r-1][c]) + v[c-r];
			//cout << "s2: " << s2 << ", m2: " << m2 << endl;
			dp[r][c] = max(m1, m2);

		}
	}

	/*
	// debug print
	for(int r=1; r<=n; r++) {
		for(int c = 1; c<=n; c++) {
			cout << dp[r][c] << " ";
		}
		cout << endl;
	}
	*/

	cout << dp[n][n] << endl;


}