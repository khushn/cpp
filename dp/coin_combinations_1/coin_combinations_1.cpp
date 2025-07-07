#include <iostream>
#include <vector>

using namespace std;

#define int long long

int mod = 1e9 + 7;

signed main() {
	int n, x;
	cin >> n >> x;

	vector<int> v(n);
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}

	vector<int> m(x+1);
	m[0] = 1;
	for(int i=1; i<=x; i++) {
		
		for (int j=0; j<n; j++) {
			int c = v[j];
			if (i-c < 0)
				continue;
			
			m[i] += m[i-c];
			m[i] %= mod;
			

		}
	}

	
	cout << m[x] << endl;
}