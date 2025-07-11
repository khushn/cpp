#include <iostream>
#include <vector>
#include <set>

using namespace std;

signed main() {
	int n, x;
	cin >> n >> x;

	vector<int> h(n);
	for(int i=0; i<n; i++) {
		cin >> h[i];
	}

	vector<int> s(n);
	for(int i=0; i<n; i++) {
		cin >> s[i];
	}

	// dp array of total money (tm)
	vector<int> tm(x+1);

	for(int i=0; i<n; i++) {
		// avoid dups
		set<int> dup_check;

		int m = h[i];
		int p = s[i];
		//cout << "m: " << m << ", p: " << p << endl;
		if (p > tm[m]) {
			tm[m] = p;
			dup_check.insert(m);
		}

		

		for(int j=m+1; j<=x; j++) {

			int r = j - m;
			if (dup_check.find(r) != dup_check.end())
				continue;

			int p0 = tm[r];
			if (p0 > 0 && p0 + p > tm[j]) {
				tm[j] = p0+p;
				dup_check.insert(j);
			}

		}

		/*
		for (int k=1; k<= x; k++)
			cout << "tm[" << k << "] = " << tm[k] << endl;

		cout << "----" << endl;
		*/


		dup_check.clear();
	}

	// ensure higher money position is not less than its prev position
	for (int i=1; i<=x; i++) {
		if (tm[i] < tm[i-1])
			tm[i] = tm[i-1];
	}

	cout << tm[x] << endl;
}