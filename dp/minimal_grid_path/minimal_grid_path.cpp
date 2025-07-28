#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/*
Came up with a new approach. Going from top-left most cell to bottom-right most cell
0,0 to n-1, n-1. 
Going each diagonal wise. Assifning 'A' or the least character to 1.
Also ignoring a cell, if is top and left both are greater than 1.

After that step. Just going in reverse direction of the dp matrix and populating a stack wherever 
the dp cell == 1. 

Then reverse printing the stack. 

This worked! All test cases passed.
*/

signed main() {
	int n;
	cin >> n;

	vector<string> grid(n);
	for(int i=0; i<n; i++)
		cin >> grid[i];

	vector<vector<int>> dp(n, vector<int>(n));
	dp[0][0] = 1;

	for(int sum=1; sum<=2*n-1; sum++) {
		int r = min(n-1, sum);
		int c = sum - r;

		int mini = 'Z' - 'A' + 1;
		while(c < n && r>=0) {

			bool top_bad = true;
			if (r>0 && dp[r-1][c] == 1) {
				top_bad = false;
			}

			bool left_bad = true;
			if (c>0 && dp[r][c-1] == 1) {
				left_bad = false;
			}

			if (top_bad && left_bad) {
				c++;
				r--;
				continue;
			}

			int tmp = grid[r][c] - 'A' + 1;
			if (mini > tmp)
				mini = tmp;

			dp[r][c] = tmp;
			c++;
			r--;
		}

		// repeat to assign 1 to min val
		r = min(n-1, sum);
		c = sum - r;
		while(c < n && r>=0) {
			if (dp[r][c] == 0) {
				c++;
				r--;
				continue;
			}

			dp[r][c] -= (mini - 1);
			c++;
			r--;
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

	// gp back from destination in the dp matrix to find a path and put it in the stack
	stack<char> stk;
	int r = n-1;
	int c = n-1;
	for(int i=0; i<2*n-1; i++) {
		if (dp[r][c] == 1)
			stk.push(grid[r][c]);

		if (r> 0 && dp[r-1][c] == 1)
			r--;
		else if (c>0 && dp[r][c-1] == 1)
			c--;
	}

	while(!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}

	cout << endl;

}