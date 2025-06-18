#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

void print_vec(vector<int> v);

/*

This intuition I had, after working out a few test cases that just 
by sorting on duration is enough. And it was!

*/

signed main() {

	int n;
	cin >> n;

	vector<vector<int>> vec(n);
	for (int i=0; i<n; i++) {
		vector<int> v(2);
		cin >> v[0] >> v[1];
		//print_vec(v);
		vec[i] = v;
	}

	//cout << "before sort" << endl;
	//print_vec(vec[0]);

	sort(vec.begin(), vec.end());

	//cout << "after sort" << endl;
	//print_vec(vec[0]);

	int reward = 0;
	int beg = 0;
	for (int i=0; i<n; i++) {
		int dur = vec[i][0];
		int end = beg + dur;
		reward += vec[i][1] - end;
		beg += dur;
	}

	cout << reward << endl;
}

void print_vec(vector<int> v) {
	for (int i=0; i<v.size(); i++)
		cout << "v[" << i << "] = " << v[i] << ", ";
	cout << endl;
}