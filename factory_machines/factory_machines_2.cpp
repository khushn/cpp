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

	
	// debug print
	
	cout << "debug print " << endl;
	for(auto it = mymap.begin(); it != mymap.end(); it++) {
		vector<int> v = it->first;
		for (int i=0; i<3; i++)
			cout << v[i] << " ";
		cout << " -> " << it->second << endl;
	}
	cout << "-------" << endl;



	int minh = 0;
	bool first = true;
	float n1byd1 = 1.0;
	for(auto it = mymap.begin(); it != mymap.end(); it++) {
		vector<int> v = it->first;
		int h = v[1];
		int count = it->second;

		if (first) {
			int d1 = h;
			int n1 = count;
			float tmp = (1.0 * d1) / (1.0 * n1);
			cout << "initially multiplying t by " << tmp << endl;
			minh = t * tmp;

			n1byd1 = 1/ tmp;

			first = false;
			cout << "n1: " << n1 << endl;
			cout << "d1: " << d1 << endl;
			cout << "n1/d1: " << n1byd1 << endl;
			cout << "minh: " << minh << endl;
			cout << "----" << endl;
			continue;
		}

		cout << "n1/d1: " << n1byd1 << endl;


		int n2 = count;
		int d2 = h;

		cout << "n2: " << n2 << endl;
		cout << "d2: " << d2 << endl;
		float n2byd2 = (1.0 * n2) / (1.0 * d2);
		cout << "n2/d2: " << n2byd2 << endl;

		if (h >=minh) {
			cout << "ignoring as h: " << h << " greater than (or equal to) minh: " << minh << endl;
			continue;
		}

		

		float tmp = (n1byd1) / (n1byd1 + n2byd2);
		cout << "minh multiplied with : " << tmp << endl;

		minh *= tmp;

		cout << "minh: " << minh << endl;
		cout << "----" << endl;


		n1byd1 = 1 / tmp;
			

	}
	
	// debug print
	/*
	for(auto it = mymap.begin(); it != mymap.end(); it++) {
		vector<int> v = it->first;
		print_vec(v);
	}
	cout << endl;
	*/
	
	



	cout << minh << endl;

}


void print_vec(vector<int> v) {
	for (int i=0; i<v.size(); i++)
		cout << "v[" << i << "] = " << v[i] << ", ";
	cout << endl;
}