#include <iostream>
#include <set>

using namespace std;

#define int long long

signed main() {

	int n;
	cin >> n;

	int ntowers = 0;
	multiset<int> mset;
	for(int i =0; i<n; i++) {
		int t;
		cin >> t;

		auto it = mset.lower_bound(t+1);
		if ( it == mset.end()) {
			ntowers++;			
		} else {
			// note we must erase using the iterator and not the value i.e *it. 
			// in latter case it erases all the values which fails the 9th test case 
			// i.e. 5 5 3 4 (deletes both 5s)
			mset.erase(it);
		}
		mset.insert(t);
	}

	cout << ntowers << endl;
}