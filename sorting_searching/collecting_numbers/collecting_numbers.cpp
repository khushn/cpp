#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define int long long 

/*
I just put it in a map (tree map by default in C++) - key as number value and its vector position as value.
Then traverse in reverse direction to count spans
*/

signed main() {

	int n;
	cin >> n;

	vector<int> vec(n);
	map<int, int> mp;
	for (int i=0; i<n; i++) {
		cin >> vec[i];
		mp.insert(pair(vec[i], i));
	}

	int num_spans = 0;
	int prev_ind = -1;
	for (auto it = mp.rbegin(); it != mp.rend(); ++it) {

		//cout << "it->first: " << it->first << ", it->second: " << it->second << endl;
		if (num_spans == 0) {
			num_spans++;
			prev_ind = it->second;
			continue;
		}

		if (it->second > prev_ind) {
			num_spans++;
		}

		//cout << "num_spans: " << num_spans << endl;
		prev_ind = it->second;

	}

	cout << num_spans << endl;

	

}