#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

#define int long long

/*

This seemed difficult at first. But was able to solve it in 2 hours (got the idea)

1. Take prefix sums
2. maintain a multiset of prefix_sums from index (a to b) 
3. Move the sliding window right
4. Take the max value of the multiset and subtract from it a prefix_sum value which is a distance away from 
left position of the set.

*/

signed main() {
	int n, a, b;
	cin >> n >> a >> b;

	vector<int> pref_sum(n+1);
	pref_sum[0] = 0;
	for(int i=1; i<=n; i++) {
		int v;
		cin >> v;
		pref_sum[i] = pref_sum[i-1] + v;
		//cout << pref_sum[i] << " ";
	}
	//cout << endl << "pref sum ---" << endl;

	// top (b-a+1) max prefix sums in the sliding window
	// from left
	multiset<int> max_sums;
	int sub_index = 0;
	int left = a;
	int right = b;


	// discovered via a test case to use min for long long!!
	int max = LLONG_MIN;

	for(int i = a; i<=b; i++) {
		max_sums.insert(pref_sum[i]);
	}

	
	while (sub_index <= n - a) {

		auto it = max_sums.end();
		it--;
		int local_max = *it - pref_sum[sub_index];
		//cout << "local_max: " << local_max << endl;

		if (local_max > max)
			max = local_max;

		// move set right
		auto it_rm = max_sums.find(pref_sum[left]);
		max_sums.erase(it_rm);

		// possibility to reduce the set size, once reach end (discovered by test case 4.in)
		if (right < n)
			max_sums.insert(pref_sum[right+1]);
		left++;
		right++;
		sub_index++;

		
		
	}


	cout << max << endl;
}
