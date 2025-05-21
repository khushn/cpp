#include <iostream>
#include <vector>

using namespace std;

#define int long long

signed main() {

	int n;
	cin >> n;

	vector<int> vec;
	for (int i=0; i<n; i++) {
		int t;
		cin >> t;
		vec.push_back(t);
	}

	int max_sum = vec[0];
	int cur_sum = vec[0];
	for (int i=1; i<n; i++) {
		int t = vec[i];

		if (cur_sum < 0) {
			cur_sum = 0;
		}
		cur_sum += t;
		if (cur_sum > max_sum) {
			max_sum = cur_sum;
		}
	}

	cout << max_sum << endl;
}