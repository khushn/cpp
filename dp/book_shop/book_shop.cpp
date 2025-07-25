#include <iostream>
#include <vector>
//#include <set>

using namespace std;

/*
In the earlier approach I was making the mistake of going left to right for values of x. 

Once it did occur to me to go right to left, but I ignored it. 

Going right to left, makes the logic simler of setting values of only relevant cells (without checkin for dups)
You need to check for dups when going L 2 R. 

The knapsack problem explained in the cses pdf (dp chapter) explains this approach.
*/

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
		

		int m = h[i];
		int p = s[i];
		//cout << "m: " << m << ", p: " << p << endl;
		

		for(int j=x-m; j>=0; j--) {

			int p0 = tm[j];
			int right_ind = j+m;
			if ( (j == 0 || p0 > 0) && p0 + p > tm[right_ind]) {
				tm[right_ind] = p0+p;
				// dup_check.insert(j);
			}

		}

		/*
		for (int k=1; k<= x; k++)
			cout << "tm[" << k << "] = " << tm[k] << endl;

		cout << "----" << endl;
		*/


		//dup_check.clear();
	}

	// ensure higher money position is not less than its prev position
	for (int i=1; i<=x; i++) {
		if (tm[i] < tm[i-1])
			tm[i] = tm[i-1];
	}

	cout << tm[x] << endl;
}