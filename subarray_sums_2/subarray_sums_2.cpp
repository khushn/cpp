#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define int long long

/*
Since we can have negative numbers. 
We take the approach of using prefix sums at each index
And tryinh to look up future prefix_sum + x occurences and count them.

*/

signed main() {
	int n, x;
	cin >> n >> x;

	vector<int> vec(n+1);
	set<pair<int, int>> myset;
	int pref_sum = 0;
	vec[0] = 0;
	for (int i=1; i<=n; i++) {
		int v;
		cin >> v;		
		vec[i] = v + vec[i-1];

		myset.insert(make_pair(vec[i], i));
		//cout << vec[i] << " : " << i << endl;
	}

	int ans = 0;
	for (int i=0; i<=n; i++) {
		int target_sum = vec[i] + x;
		auto it = myset.upper_bound(make_pair(target_sum, i));
		while (it != myset.end()) {
			if (it->first == target_sum)
				ans++;
			else
				break;
			it++;
		}
	}

	cout << ans << endl;
}