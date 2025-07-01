#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define int long long

/*
Had to think a lot for this. But got it on my own
1. Find the max. It will be max of 1.a and 1.b
1.a sum(n) / k. Rounded to nearest greater int
1.b max value in array

2. if M is max, then do a binary search of the solution between 
   M and 2*M. As in some cases the value will exceed M. 

Time complexity is N* log(N)


*/

signed main() {
	int n, k;
	cin >> n >> k;

	vector<int> vec(n);
	int sum = 0;
	int m1 = 0;
	for(int i=0; i<n; i++) {
		int v;
		cin >> v;
		vec[i] = v;
		sum += v;
		if (v > m1)
			m1 = v;
	}

	//cout << "sum: " << sum << endl;

	int m2 = ceil( sum / k);

	//cout << "m1: " << m1 << ", m2: " << m2 << endl;
	int m = max(m1, m2);

	int l1 = m;
	int l2 = 2*m;
	while (l1 < l2) {
		int mid = (l1 + l2) / 2;
		//cout << "mid: " << mid << endl;
		int num_parts = 0;
		int sub_array_sum = 0;
		for(int i=0; i<n; i++) {
			if (sub_array_sum + vec[i] > mid) {
				num_parts++;
				sub_array_sum = vec[i];
			} else {
				sub_array_sum += vec[i];
			}
		}

		if (sub_array_sum > 0)
			num_parts++;

		//cout << "num_parts: " << num_parts << endl;

		if (num_parts > k) {
			// more than desired partitions
			l1 = mid + 1;
		} else {
			l2 = mid;
		}

	}

	cout << l2 << endl;
}