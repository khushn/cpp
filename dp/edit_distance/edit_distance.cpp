#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
This is implementati0on of Levenshtein distance algo, explained in the pdf
*/

signed main() {

	string str1, str2;
	cin >> str1 >> str2;

	int n = str1.length();
	int m = str2.length();

	vector<vector<int>> dp = vector(n+1, vector<int>(m+1));

	// initialize the dp for top row and left most col
	for(int i=1; i<=m; i++)
		dp[0][i] = i;

	for(int i=1; i<=n; i++)
		dp[i][0] = i;


	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			// distance(i-1, j-1) + compare curr pos(1 if diff, 0 if same) -- replace case
			int d1 = dp[i-1][j-1];
			if (str1[i-1] != str2[j-1])
				d1++;

			// distance(i-1, j) + 1 (case of insertion)
			int d2 = dp[i-1][j] + 1;

			// distnnce(i, j-1) + s (case of deletion)
			int d3 = dp[i][j-1] + 1;

			dp[i][j] = min({d1, d2, d3});
			//cout << d1 << ", " << d2 << ", " << d3 << "; --";

			//cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << "; --";

		}
		//cout << endl;
	}

	cout << dp[n][m] << endl;
}