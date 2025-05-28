#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define int long long

signed main() {
	int n, k;
	cin >> n >> k; 

	vector<int> myvec(n);
	for (int i=0; i<n; i++) {
		//myset.insert(i+1);
		myvec[i] = i + 1;
	}


	int pos = 0;
	for (int i=0; i<n; i++) {
		pos = (pos + k) % (n-i);
		// cout << "debug pos: " << pos << endl;
		cout << myvec[pos] << " ";
		myvec.erase(myvec.begin() + pos);
	}
	cout << endl;

}
