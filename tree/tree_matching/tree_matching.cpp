#include <iostream>
#include <set>

using namespace std;


/*
Trying a very simple algo using a hash set. 
Just based on what needs to be done (not even considering tree pov)

*/

signed main() {
	int n;
	cin >> n;
	set<int> myset;
	int uniq_pairs = 0;
	for(int i=0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		if (myset.find(a) == myset.end() && myset.find(b) == myset.end()) {
			uniq_pairs++;
			myset.insert(a);
			myset.insert(b);
		}
	}

	if (n-uniq_pairs -1 > uniq_pairs)
		uniq_pairs = n-uniq_pairs -1;
	
	cout << uniq_pairs << endl;
}