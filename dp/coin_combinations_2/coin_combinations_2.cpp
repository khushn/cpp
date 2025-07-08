#include <iostream>
#include <vector>
 
using namespace std;
 
#define int long long
 
int mod = 1e9 + 7;

/*
We need to have coins in the outer loop for this one. 
As we need to process them by order. 

My thought is, no sorting of coins is needed. 

*/
 
signed main() {
	int n, x;
	cin >> n >> x;
 
	vector<int> v(n);
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
 
	vector<int> m(x+1);
	m[0] = 1;
	for (int i=0; i<n; i++) {
		int c = v[i];
		for(int j=1; j<=x; j++){
			
			if (j-c < 0)
				continue;
			
			m[j] += m[j-c];
			if (m[j] >= mod)
				m[j] -= mod;
			
		}
	}
 
	
	cout << m[x] << endl;
}