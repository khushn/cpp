#include <iostream>
#include <vector>

using namespace std;

/*

simple algo using 2-d dp. 
To print the sequence (had to think!) Just gp through the bottom row, and present col values (top)
where count increments
*/

signed main() {

	int n, m;
	cin >> n >> m;

	vector<int> v1(n);
	for(int i=0; i<n; i++)
		cin >> v1[i];

	vector<int> v2(m);
	for(int i=0; i<m; i++)
		cin >> v2[i];

	vector<vector<int>> dp(n, vector<int>(m));

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {

			int diag = 0;
			if (v1[i] == v2[j])
				diag = 1;

			if (i > 0 && j > 0)
				diag += dp[i-1][j-1];

			int top = 0;
			if (i > 0) {
				top = dp[i-1][j];
			}

			int left = 0;
			if (j > 0) {
				left = dp[i][j-1];
			}

			dp[i][j] = max(diag, max(left, top));

		}
	}

	cout << dp[n-1][m-1] << endl;


	// print the common sequence
	int cur = 0;
	for(int i=0; i<m; i++) {
		int tmp = dp[n-1][i];
		if (tmp > cur) {
			cout << v2[i] << " ";
			cur = tmp; 
		}
	}

	cout << endl;
	
	cout << "debug" << endl;
	for(int i=0; i<m; i++) {
		cout << dp[n-1][i] << " ";
	}

	cout << endl;
}