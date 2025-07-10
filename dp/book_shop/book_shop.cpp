#include <iostream>
#include <vector>

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
	for(int i=1; i<=x; i++) {
		for (int j=0; j<n; j++) {
			int m = h[j];
			if (i-m < 0) 
				continue;

			int new_val = tm[i-m] + s[j];
			if (new_val > tm[i])
				tm[i] = new_val;
		}
		cout << "tm[" << i << "] = " << tm[i] << endl;
	}

	cout << tm[x] << endl;
}