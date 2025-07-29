#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int DP_SIZE = 100001;

signed main() {
	int n;
	cin >> n;

	vector<int> coins(n);
	for(int i=0; i<n; i++)
		cin >> coins[i];

	sort(coins.begin(), coins.end());

	vector<int> dp(DP_SIZE);
	dp[coins[0]] = 1;

	int max1 = coins[0];
	//cout << "max1: " << max1 << endl;

	for(int i=1; i<n; i++) {
		int c = coins[i];
		
		for(int j=max1; j>=1; j--) {
			//cout << "c: " << c << ", j: " << j << endl;
			if (dp[j] == 0)
				continue;

			dp[j+c] = 1;
		}
		dp[c] = 1;

		max1 += c;
		//cout << "max1: " << max1 << endl;
	}

	int sum_count = 0;
	for(int i=1; i<=max1; i++)
		if (dp[i] == 1)
			sum_count++;

	cout << sum_count << endl;
	for(int i=1; i<=max1; i++)
		if (dp[i] == 1)
			cout << i << " ";

	cout << endl;

}