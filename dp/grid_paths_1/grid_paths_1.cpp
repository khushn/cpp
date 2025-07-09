#include <iostream>
#include <vector>
#include <string>

using namespace std;

int mod = 1e9 + 7;

signed main() {
	int n;
	cin >> n;

	vector<vector<int>> grid(n, vector<int>(n));
	for (int i=0; i<n; i++) {
		string str;
		cin >> str;
		//cout << str << endl;

		for (int j=0; j<n; j++) {
			if (str[j] == '*') {
				grid[i][j] = 0; // need to do it if '*' is there in (n-1, n-1) location
				continue;
			}

			if (i == 0 && j == 0)
				grid[i][j] = 1;

			// increment right
			if (j + 1 < n) {
				grid[i][j+1] += grid[i][j];
				grid[i][j+1] %= mod;
			}

			// increment bottom
			if (i+1 < n) {
				grid[i+1][j] += grid[i][j];
				grid[i+1][j] %= mod;
			}

		}		
	}

	cout << grid[n-1][n-1] << endl;
}