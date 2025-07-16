#include <iostream>
#include <vector>
#include <algorithm>

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

	sort(vec.begin(), vec.end());
	int mid = n/2;

	int median = vec[mid];
	int sum = 0;
	for (int i=0; i<n; i++) {
		sum += abs(vec[i] - median);
	}

	cout << sum << endl;
}