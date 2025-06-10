#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define int long long

void print_vec(vector<int> v);

signed main() {

	int n, t;
	cin >> n >> t;

	map<vector<int>, int> mymap;
	//vector<int> vec(n);
	for (int i=0; i<n; i++) {
		int k;
		cin >> k;
		vector<int> v(3);
		v[0] = k; // sorting order k + h
		v[1] = k;
		v[2] = 0;
		if (mymap.find(v) != mymap.end() ) {
			int count = mymap[v];
			mymap[v] = count+1;

		} else
			mymap[v] = 1;
	}

	if (n == 1) {
		auto it = mymap.begin();
		vector<int> v = it->first;
		int ans = t * v[1];
		cout << ans << endl;
		return 0;
	}

	if (mymap.size() == 1) {
		auto it = mymap.begin();
		vector<int> v = it->first;
		int count = it->second;
		int mul = t / count;
		if (t%count != 0)
			mul++;
		int ans = mul * v[1];
		cout << ans << endl;
		return 0;
	}

	
	// debug print
	/*
	cout << "debug print " << endl;
	for(auto it = mymap.begin(); it != mymap.end(); it++) {
		vector<int> v = it->first;
		for (int i=0; i<3; i++)
			cout << v[i] << " ";
		cout << " -> " << it->second << endl;
	}
	cout << "-------" << endl;
	*/


	int mint = 0;
	while ( t > 0) {
	
		auto it = mymap.begin();
		vector<int> v = it->first;
		// print_vec(v);

		int count = it->second;
		//mymap.erase(it);

		
		it++;
		vector<int> v2 = it->first;
		// print_vec(v2);

		int diff = v2[0] - v[2];
		//if (v2[2] == 0) 
		//	diff = v2[1] - v[2];

		int nump = diff / v[1];

		if (nump * count > t) {
			nump = t / count;
			if (t% count != 1)
				nump++;

			if (nump == 0)
				nump++;
		}
		

		int incr = nump * v[1];
		int new_height = v[2] + incr;

		if ( new_height > mint)
			mint = new_height;

		v[0] += incr;
		v[2] += incr;

		mymap.erase(mymap.begin());
		mymap[v] = count;

		t -= nump * count;
		// cout << "t: " << t << endl;
	}

	
	//cout << "coming here " << endl;

	
	// debug print
	/*
	for(auto it = mymap.begin(); it != mymap.end(); it++) {
		vector<int> v = it->first;
		print_vec(v);
	}
	cout << endl;
	*/
	
	



	cout << mint << endl;

}


void print_vec(vector<int> v) {
	for (int i=0; i<v.size(); i++)
		cout << "v[" << i << "] = " << v[i] << ", ";
	cout << endl;
}