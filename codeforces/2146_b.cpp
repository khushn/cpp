#include <iostream>
#include <map>
#include <vector>

using namespace std;


signed main() {
	int t;
	cin >> t;

	for(int i=0; i<t; i++) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> vec(n);
		for(int j=0; j<n; j++) {
			int l;
			cin >> l;

			for (int k=0; k<l; k++) {
				int x;
				cin >> x;
				vec[j].push_back(x);
			}
		}

		

		//cout << "first print" << endl;

		/*
		for(int j=0; j<n; j++) {
			//cout << "size: " << vec[j].size() << endl;
			for(int k : vec[j]) {
				cout << k << " ";
			}
			cout << endl;
		}
		*/

		vector<int> ans(m);
		for(int j=0; j<n; j++) {
			for(int k : vec[j]) {
				ans[k-1] +=1;
			}
		}

		// 1st combo
		bool combo_found = true;
		for(int j=0; j<m; j++) {
			if (ans[j] < 1) {
				combo_found = false;
			}
		}

		if (!combo_found) {
			cout << "NO" << endl;
			continue;
		}
	

		// now we need two more compbos
		int num_combos = 1;
		for(int j=0; j<n; j++) {
			bool combo_found = true;
			for(int k : vec[j]) {
				
				if (ans[k-1] <= 1) {
					combo_found = false;
					break;
				}
			}

			if (combo_found) {
				num_combos++;
				if (num_combos>=3)
					break;
			}

			
		}

		if (num_combos >=3) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

}