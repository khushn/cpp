#include <iostream>
#include <vector>
#include <map>


using namespace std;

#define int long long

/*
We tweak the prefix sum approach of the previous one, 
with remainder by dividing by n.

Basiclly (a - b) mod n == a mod n - b mod n

So we just need to count pairs where remainder is same.

*/

signed main() {
	int n;
	cin >> n;

	vector<int> vec(n+1);	
	int pref_sum = 0;
	vec[0] = 0;
	for (int i=1; i<=n; i++) {
		int v;
		cin >> v;		
		vec[i] = v + vec[i-1];
		//cout << vec[i] << " ";
	}
	//cout << endl;
	// convert prefix sum array to prefix sum remainders
	// also strore remainder counts in a map
	map<int, int> mp;
	for (int i=0; i<=n; i++) {
		int rem = vec[i] % n;

		// this step is important if remainder is -5 when n = 100
		// better to store it as 95!
		if (rem < 0)
			rem = n + rem;
		mp[rem] += 1;
	}

	int ans = 0;
	for (auto it : mp) {
		//cout << it.first << " : " << it.second << endl;
		int k = it.second;
		// calculate k-c-2 and add to answer
		if (k < 2)
			continue;
		else {
			int kc2 = (k*(k-1))/2;
			ans += kc2;
		}
	}


	
	cout << ans << endl;
}