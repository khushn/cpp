#include <iostream>
//#include <vector>

using namespace std;

#define int long long

signed main() {

	int n;
	cin >> n;

	//vector<int> v(n);
	int max = 0;
	int sum = 0;
	for(int i=0; i<n; i++) {
		int v;
		cin >> v;
		if (v > max)
			max = v;
		sum += v;
	}

	int ans = sum;
	if (max * 2 > sum)
		ans = max *2;

	cout << ans << endl;

}