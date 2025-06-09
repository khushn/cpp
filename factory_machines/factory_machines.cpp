#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define int long long

signed main() {

	int n, t;
	cin >> n >> t;

	multiset<vector<int>> myset;
	vector<int> vec(n);
	for (int i=0; i<n; i++) {
		int k;
		cin >> k;
		vector<int> v(2);
		v[0] = k;
		v[1] = k;
		myset.insert(v);
	}

	int mint = 0;
	for (int i=0; i<t; i++) {
		auto it = myset.begin();
		vector<int> v = *it;
		myset.erase(it);
		if (v[0] > mint)
			mint = v[0];
		v[0] += v[1];
		myset.insert(v);
	}

		
	// debug print
	for(auto it = myset.begin(); it != myset.end(); it++) {
		vector<int> v = *it;
		for (int i=0; i<2; i++)
			cout << v[i] << " ";
		cout << endl;
	}
	cout << endl;
	



	cout << mint << endl;

}