#include <iostream>
#include <set>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

/*
Ordered set blog on codeforces:
https://codeforces.com/blog/entry/123624
*/

template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


signed main() {
	int n, k;
	cin >> n >> k; 

	ordered_multiset<int> ss;
	//vector<int> myvec(n);
	for (int i=0; i<n; i++) {
		//myset.insert(i+1);
		//myvec[i] = i + 1;
		ss.insert(i+1);
	}


	int pos = 0;
	for (int i=0; i<n; i++) {
		pos = (pos + k) % (n-i);
		// cout << "debug pos: " << pos << endl;
		auto it = ss.find_by_order(pos);
		cout << *it << " ";
		ss.erase(it);
		//cout << myvec[pos] << " ";
		//myvec.erase(myvec.begin() + pos);
	}
	cout << endl;

}
