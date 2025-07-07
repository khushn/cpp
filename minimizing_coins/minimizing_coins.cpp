#include <iostream>
#include <vector>

using namespace std;

#define int long long

signed main() {
	int n, x;
	cin >> n >> x;

	vector<int> v(n);
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}

	vector<int> m(x+1);
	for(int i=1; i<=x; i++) {
		m[i] = -1;
		
		for (int j=0; j<n; j++) {
			int c = v[j];
			if (i-c < 0 || m[i-c] == -1 )
				continue;

			int num_coins = m[i-c] + 1;
			int cur = m[i];
			if (cur == -1 || cur > num_coins)
				m[i] = num_coins;

			

		}
	}

	
	cout << m[x] << endl;
}