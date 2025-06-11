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

	
	// debug print
	
	cout << "debug print " << endl;
	for(auto it = mymap.begin(); it != mymap.end(); it++) {
		vector<int> v = it->first;
		for (int i=0; i<3; i++)
			cout << v[i] << " ";
		cout << " -> " << it->second << endl;
	}
	cout << "-------" << endl;



	int minh = INT_MAX;
	float div = 0.0;
	for(auto it = mymap.begin(); it != mymap.end(); it++) {
		vector<int> v = it->first;
		float h = v[1];
		if (h >= minh) {
			cout << "ignoring h: " << h << " as more than minh: " << minh << endl;
			continue;
		}
		float count = it->second;
		div += count / h;
		cout << "div: " << div << endl;
		minh = t / div;
		cout << "minh: " << minh << endl;
	}

	

	cout << minh << endl;

}


void print_vec(vector<int> v) {
	for (int i=0; i<v.size(); i++)
		cout << "v[" << i << "] = " << v[i] << ", ";
	cout << endl;
}