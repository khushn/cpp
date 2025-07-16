#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

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
	vector<pair<int, int>> vec2;
	int pref_sum = 0;
	vec[0] = 0;
	for (int i=1; i<=n; i++) {
		int v;
		cin >> v;		
		vec[i] = v + vec[i-1];

		vec2.push_back(make_pair(vec[i], i));
		//cout << vec[i] << " : " << i << endl;
	}

	sort(vec2.begin(), vec2.end());

	int ans = 0;
	for (int i=0; i<=n; i++) {
		int target_sum = vec[i] + x;
		auto lower_it = lower_bound(vec2.begin(), vec2.end(), make_pair(target_sum, i+1));
		auto upper_it = upper_bound(vec2.begin(), vec2.end(), make_pair(target_sum, n));
		
		ans += upper_it - lower_it;
	}

	cout << ans << endl;
}