#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/*
Not defining int as long lnng. As n can only be 10^6. And it affects performance, as we saw in 
the problem coin_combinations_1


*/
signed main() {

	int n;
	cin >> n;

	vector<int> v(n+1);

	for (int i=1; i<=n; i++) {

		if (i< 10) {
			v[i] = 1;
			//cout << "v[" << i << "] = " << v[i] << endl;
			continue;
		}

		int min = INT_MAX;
		for (int num=i; num>0; num/=10) {
			int x = num%10;
			//cout << "x: " << x << endl;
			if (x == 0)
				continue;

			int cur = v[i-x] + 1;
			if ( cur < min)
				min = cur; 
		}
		v[i] = min;

		//cout << "v[" << i << "] = " << v[i] << endl;
	}

	cout << v[n] << endl;

}