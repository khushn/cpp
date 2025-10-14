/*
Problem https://codeforces.com/contest/2160/problem/B
*/

#include <iostream>
#include <vector>

using namespace std;

#define int long long

signed main() {

	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		int n;
		cin >> n;
		vector<int> a(n);
		
		
		int prev = -1;
		for(int i=0; i<n; i++) {
			int num;
			cin >> num;

		
			if (i > 0) {
				int diff = num - prev;
				if (diff == i+1)
					a[i] = diff;
				else
					a[i] = a[i-diff];
			} else {
				a[i] = 1;
			}
			
			
			
			prev = num;			
		}
		for(int i=0; i<n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}

}