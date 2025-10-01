#include <iostream>
#include <vector>

using namespace std;

const int N = 200001;
vector<int> g[N];
pair<int, int> to_leaf1[N];
pair<int, int> to_leaf2[N];


void dfs_pass1(int n, int p) {
	int max1 = 0;
	int n1 = 0;
	int max2 = 0;
	int n2 = 0;
	int num_children = 0;
	for(auto c: g[n]) {
		if (c == p)
			continue;

		dfs_pass1(c, n);

		int to_lf = to_leaf1[c].first;
		if (num_children == 0 || to_lf > max1) {
			max2 = max1;
			n2 = n1;
			max1 = to_lf;
			n1 = c;
		} else if (num_children == 1 || to_lf > max2) {
			max2 = to_lf;
			n2 = c;
		}
		num_children++;
	}

	to_leaf1[n] = make_pair(max1 + (num_children >= 1 ? 1 : 0), n1);
	to_leaf2[n] = make_pair(max2 + (num_children >= 2 ? 1 : 0), n2);
}

void dfs_pass2(int n, int p) {
	for(auto c: g[n]) {
		if (c == p)
			continue;

		int cur_max = to_leaf1[c].first;
		int p_dist1 = to_leaf1[n].first + 1;
		if (to_leaf1[n].second != c && p_dist1 > cur_max) {
			to_leaf1[c] = make_pair (p_dist1, n);
		} 
		dfs_pass2(c, n);
	}
}

signed main() {
	int n;
	cin >> n;
	for(int i = 0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs_pass1(1, 1);

	// debug print
	cout << "to_leaf1: ";
	for(int i=1; i<=n; i++) {
		cout << to_leaf1[i].first << " : " << to_leaf1[i].second << "| ";
	}
	cout << endl;
	cout << "to_leaf2: ";
	for(int i=1; i<=n; i++) {
		cout << to_leaf2[i].first << " : " << to_leaf2[i].second << "| ";
	}
	cout << endl;
	

	dfs_pass2(1, 1);
	cout << "after pass2\nto_leaf1: ";
	for(int i=1; i<=n; i++) {
		cout << to_leaf1[i].first << " : " << to_leaf1[i].second << "| ";
	}
	cout << endl;

	for(int i=1; i<=n; i++) {
		cout << to_leaf1[i].first << " ";
	}
	cout << endl;
}