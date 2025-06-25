#include <iostream>
#include <map> 
#include <vector>

using namespace std;

#define int long long 

signed main() {

	int n;
	cin >> n;

	map<int, int> mp;
	vector<int> res(n);
	for (int i=0; i<n; i++) {
		int v;
		cin >> v;

		auto it = mp.lower_bound(v);
		res[i] = 0;

		
		if (it != mp.begin()) {
			it--;
			res[i] = it->second + 1;
		}
		
		mp[v] = i;
		auto end_it = mp.end();
		end_it--;
		end_it->second = i;

	}


	/*
	for (auto it: mp) {
		int k = it.first;
		int v = it.second;
		cout << k << " : " << v << endl;
	}
	*/

	for(int i=0; i<n; i++)
		cout << res[i] << " ";

	cout << endl;

}