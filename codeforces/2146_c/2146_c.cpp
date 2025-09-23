#include <iostream>
#include <vector>

using namespace std;

signed main() {
	int t;
	cin >> t;
	for(int t1=0; t1 < t; t1++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans[n];
		bool no_answer = false;
		//vector<int> v(n);
		int l = 1;
		char prev = 'N';
		//int arr_ind = 0;
		for(int i=1; i<=n; i++) {
			
			if (s[i-1] == '1') {
				if (prev == '0') {
					int r = i-1;
					// try putting r to l (i.e. in reverse order)
					int arr_ind = l-1;
					//cout << "l: " << l << ", r: " << r << endl;
					if ((r-l+1) == 1) {
						no_answer = true;
						break;
					}
					for(int j = r; j>=l; j--) {
						ans[arr_ind++] = j;
					}

					if (no_answer)
						break;
				}
				//cout <<  "i: " << i << endl;
				ans[i-1] = i;
				l = i + 1;
			} 
			prev = s[i-1];			
		}

		if ((n-l+1) == 1)
			no_answer = true;
		else {
			int arr_ind = l-1;
			for(int i=n; i>=l; i--) {
				ans[arr_ind++] = i;
			}
		}

		if(no_answer) {
			cout << "NO" << endl;
		} else {
			
			
			
			
			cout << "YES" << endl;
			for(int i=0; i<n; i++)
				cout << ans[i] << " ";

			cout << endl;
		}

		

	}
}