#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define int long long

/*
Since upper size limit of n is 1000. We can easily do n*n i.e. limited to 1 million. 
and store it in a set with value and positions in a vector. 
Just use the positions to avoid clash. And store till only the second one (not beyond that)
*/

void print_vec(vector<int> v);

signed main() {

	int n, x;
	cin >> n >> x;


	vector<pair<int, int>> vec(n);
	for(int i=0; i<n; i++){
		int v;
		cin >> v;
		vec[i] = make_pair(v, i);
	}

	//cout << vec[0].first << ", " << vec[0].second << endl;

	map<int, vector<int>> mymap;
	for(int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i == j)
				continue;

			int sum = vec[i].first + vec[j].first;

			auto it = mymap.find(sum);
			if (it == mymap.end()) {

				vector<int> tmp(2);
				tmp[0] = vec[i].second;
				tmp[1] = vec[j].second;
				mymap[sum] = tmp;
			} else {
				vector<int> tvec = it->second;
				tvec.push_back(vec[i].second);
				tvec.push_back(vec[j].second);
				mymap[sum] = tvec;
			}
		}
	}

	for (const auto & it1: mymap) {
		int rem = x - it1.first;
		vector<int> vec1 = it1.second;

		/*
		cout << it1.first << " ";
		print_vec(vec1);
		cout << "--" << endl;
		*/

		int first = vec1[0];
		int second = vec1[1];

		auto it = mymap.find(rem);
		if (it != mymap.end()) {
			vector<int> vec2 = it->second;
			int v2l = vec2.size();

			// we need to pick from the end, to avoid clash
			int third = vec2[v2l-2];
			int fourth = vec2[v2l-1];
			

			if (third != first && third != second && fourth != first && fourth != second) {
				cout << first + 1 << " " << second + 1 << " " << third + 1 << " " << fourth + 1 << endl;
				return 0;
			}
		}
		
	}

	cout << "IMPOSSIBLE" << endl;

}

void print_vec(vector<int> v) {
	for (int i=0; i<v.size(); i++)
		cout << "v[" << i << "] = " << v[i] << ", ";
	cout << endl;
}