#include <iostream>
#include <vector>
#include <stack>

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
	// need to traverse from bottom right and put all matches in a stack
	// match when diagonal less than present cell
	stack<int> stk;
	int num = dp[n-1][m-1];

	if (num == 0)
		return 0;
	
	int r = n-1;
	int c = m-1;
	while (true) {
		if (r-1 >= 0 && dp[r-1][c] == dp[r][c]) {
			r = r-1;
		} else if (c-1 >= 0 && dp[r][c-1] == dp[r][c]) {
			c = c-1;
		} else {
			stk.push(v2[c]);
			if (r > 0)
				r = r-1;
			if (c > 0)
				c = c-1;
		}

		if(stk.size() == num)
			break;
	}
	

	for (;!stk.empty(); stk.pop())
		cout << stk.top() << " ";

	cout << endl;


	/*
	cout << "debug" << endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	*/
}