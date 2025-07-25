#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

signed main() {

	int n;
	cin >> n;

	vector<string> grid(n);
	for(int i=0; i<n; i++)
		cin >> grid[i];

	vector<vector<int>> dp(n, vector<int>(n));
	dp[n-1][n-1] = 1;
	for(int sum=2*n-2; sum>=0; sum--) {
		int r = min(n-1, sum);
		int c = sum - r;

		//cout << "r: " << r << ", c:" << c << endl;
		// this will have the sorted diagonal based on rank
		//multimap<pair<int, int>, pair<int, int>> mp;

		int size = 2 * n - sum;
		if (sum < n)
			size = sum+1;

		vector<vector<int>> vec(size, vector<int>(4));
		int cnt = 0;
		while(c < n && r>=0) {
			
			int min = n+1;
			// right
			if (c<n-1) {
				min = dp[r][c+1];
			}

			// down
			if (r< n-1) {
				int tmp = dp[r+1][c];
				if (tmp < min) {
					min = tmp;
				}
			}

			//mp[make_pair(grid[r][c], min)] = make_pair(r, c);
			//mp.insert({make_pair(grid[r][c], min), make_pair(r, c)});
			vec[cnt] = {grid[r][c], min, r, c};
			c++;
			r--;
		}

		sort(vec.begin(), vec.end());

		// iterate on the map, and assign ranks to diagonals
		int rank = 1;
		
		for(const auto& v: vec) {
			dp[v[2]][v[3]] = rank;
			rank++;
		}
		
	}

	/*
	// debug print of dp matrix
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/

	// just print the output based on dp array rank (and following the rules of traversal right or below)
	int r=0, c=0;
	for(int i=1; i<2*n; i++) {
		cout << grid[r][c];
		if (r < n-1 && c < n-1) {
			if (dp[r+1][c] < dp[r][c+1])
				r++;
			else 
				c++;
		} else {
			if (r<n-1)
				r++;
			else
				c++;
		}
	}
	cout << endl;
}