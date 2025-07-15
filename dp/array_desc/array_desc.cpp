#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

/*
I got the approach overnight. 
To save on storing all strates 100000 x 100, which will be a lot, I save only 
2 x 100 states. The prev (last processed position) and current. 
Just add prev states to cur, based on position. 
Also take into account if current state digit is wild card or specific given number. 
In the end shift current to prev state. 

Also out of the loop sum the prev state (which is the final state, after processing n numbers)

Time complexity: O(NxM)
Space complexity: O (N + M)

Notes: It kind of feels like a machine learning algo, flowing from left to right. Also if any digits are given. 
they act as filters of a kind, and reduce the total answer by a lot.
*/

signed main() {
	int n, m;
	cin >> n >> m;

	vector<int> vec(n);
	for(int i=0; i<n; i++) {
		cin >> vec[i];
	}

	vector<int> prev(m);
	vector<int> cur(m);

	int v = vec[0];
	if (v != 0)
		prev[v-1] = 1;
	else
		// make everything 1
		for(int i=0; i<m; i++)
			prev[i] = 1;

	/*
	for(int j=0; j<m; j++) {		
		cout << prev[j] << ", ";
	}
	cout << endl;
	*/

	int beg = 0;
	int end = m-1;
	for(int i=1; i<n; i++) {
		// cout << "i: " << i << endl;
		int v = vec[i];
		if (v != 0) {
			beg = v-1;
			end = v-1;
		} else {
			// expand the horizon
			if (beg > 0)
				beg--;
			if (end < m-1)
				end++;
		}

		for(int j=beg; j<=end; j++) {
			cur[j] = (cur[j] + prev[j]) % mod;
			if (j>0)
				cur[j] = (cur[j] + prev[j-1]) % mod;
			if (j<m-1)
				cur[j] = (cur[j] + prev[j+1]) % mod;
		}

		// shift the dp arrays
		for(int j=0; j<m; j++) {
			prev[j] = cur[j];
			// cout << prev[j] << ", ";
			cur[j] = 0;
		}
		//cout << endl << "----" << endl;
	}

	int num_ways = 0;
	for(int i=0; i<m; i++) {
		num_ways = (num_ways + prev[i]) % mod;
	}

	cout << num_ways << endl;
}