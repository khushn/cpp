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

	// book index added at a specific money sum
	vector<int> book_added(x+1);
	book_added[0] = -1;
	for(int i=1; i<=x; i++) {
		tm[i] = tm[i-1];
		book_added[i] = book_added[i-1];
		for (int j=0; j<n; j++) {
			int m = h[j];
			if (i-m < 0) 
				continue;

			int new_val = tm[i-m] + s[j];
			if (new_val > tm[i]) {
				// check before adding, if index 'j' book is already in this path
				int y = i-m;
				bool dup_book = false;
				while (y>0) {
					int j2 = book_added[y];
					if ( j2 == j) {
						// dup book
						dup_book = true;
						break;
					}
					y -= h[j2];
				}

				if (!dup_book) {
					tm[i] = new_val;
					book_added[i] = j;
				}
			}
		}
		cout << "tm[" << i << "] = " << tm[i] << endl;
		cout << "book_added[" << i << "] = " << book_added[i] << endl;
	}

	cout << tm[x] << endl;
}