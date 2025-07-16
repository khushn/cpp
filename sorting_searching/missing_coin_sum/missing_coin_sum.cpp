#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

/*
Basically any new coin which comes in ascending order (so first we need to sort), extends the missing_sum 
by its value. 

*/

signed main() {
	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i=0; i<n; i++) {
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	int missing_sum = 1;

	for (const int& c: vec) {
		if (c > missing_sum) {
			break;
		}

		missing_sum += c;
	}

	cout << missing_sum << endl;
}