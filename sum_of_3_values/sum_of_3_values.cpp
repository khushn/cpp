#include <iostream>
#include <vector>
#include <map>
// #include <algorithm>

using namespace std;

#define int long long

/*

Since max n is 5000. Can do it in O(N^2). 

So using a map to check for the 3rd value and avoiding index clash. 

Time complexity:10.in O(N^2) * log (N)
*/

signed main() {
	int n, x;
	cin >> n >> x;

	vector<int> vec(n);
	map<int, vector<int>> mp;
	for(int i=0; i<n; i++){
		int v;
		cin >> v;
		vec[i] = v;
		auto it = mp.find(v);
		if ( it != mp.end()) {
			vector<int> tmp = it->second;
			tmp.push_back(i);
			it->second = tmp;
		} else {
			vector<int> tmp(1);
			tmp[0] = i;
			mp[v] = tmp;
		}
	}

	/*
	for (const auto & it : mp) {
		cout << it.first << " : " << it.second[0] << endl;
	}
	*/

	for(int i=0; i<n; i++){
		for (int j=0; j<n; j++) {
			if (i == j)
				continue;

			int sum = vec[i] + vec[j];

			int rem = x - sum;
			// cout << "rem: " << rem << endl;
			auto it = mp.find(rem);
			if (it != mp.end()) {
				// cout << "coming in for i: " << i << ", and j: " << j << endl;
				vector<int> tmp = it->second;
				int size_or_3 = 3;
				if (tmp.size() < size_or_3)
					size_or_3 = tmp.size();

				for (int k=0; k<size_or_3; k++) {
					int l = tmp[k];
					if ( l != i && l != j) {
						// found!!
						cout << i + 1 << " " << j + 1 << " " << l + 1 << endl;
						return 0;
					}
				}
			}
		}
	}

	cout << "IMPOSSIBLE" << endl;
}
