#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define int long long

signed main() {

	int n, x;
	cin >> n >> x;

	vector<int> vec;
	multimap<int, int> mp;
	for (int i = 0; i<n; i++) {
		int v;
		cin >> v;
		vec.push_back(v);
		mp.insert({v, i});
	}

	int n1 = -1, n2 = -1;
	bool pair_found = false;
	for (int i = 0; i<n; i++) {
		int diff = x - vec[i];
		//cout << "diff: " << diff << endl;;
		auto range = mp.equal_range(diff);
		for (auto it = range.first; it != range.second; ++it) {
			//cout << "first: " << it->first << ", second: " << it-> second << endl;
			if (it->second != i) {
				n1 = i;
				n2 = it->second;
				pair_found = true;
				break;
			}
		}
		if (pair_found)
			break;
	}

	if (n1 >= 0)
		cout << n1+1 << " " << n2+1 << endl;
	else 
		cout << "IMPOSSIBLE" << endl;

}