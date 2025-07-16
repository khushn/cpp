#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define int long long

void print_vec(vector<int> v);

signed main() {

	int n, t;
	cin >> n >> t;

	vector<int> vec(n);
	int k_min = INT_MAX;
	for (int i=0; i<n; i++) {
		int k;
		cin >> k;
		vec[i] = k;
		if (k < k_min)
			k_min = k;
	}


	int l1 = 1;
	int l2 = k_min * t;

	while (l1 < l2) {
		
		int mid = (l1 + l2) /2;
		//cout << "l1: " << l1 << ", l2: " << l2 << ", mid: " << mid << endl ;

		int tot_p = 0;
		for (int i=0; i<n; i++) {
			tot_p += mid / vec[i];
		}

		//cout << "tot_p: " << tot_p << endl;
		if (tot_p < t)
			l1 = mid+1;
		else 
			l2 = mid;
	}
	

	cout << l2 << endl;

}


void print_vec(vector<int> v) {
	for (int i=0; i<v.size(); i++)
		cout << "v[" << i << "] = " << v[i] << ", ";
	cout << endl;
}