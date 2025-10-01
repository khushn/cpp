#include <iostream>
#include <vector>

using namespace std;

const int N = 200001;
vector<int> g[N];
int to_leaf[N];
int max_length[N];

int diameter = 0;

/*
Just applying the diameter formula (given in the pdf)
a) Use dfs and DP to compure to_leaf() for each node (max distance to leaf)
b) add two highets children with to_leaf() + 2, which gives max_length via a node
c) diameter is the highest balue of max_length encountered

*/

void dfs(int n, int p) {

	int max1 = 0;
	int max2 = 0;

	int num_children = 0;
	for(auto n2: g[n]) {
		if (n2 == p)
			continue;

		if (max_length[n2] == 0)
			dfs(n2, n);
		
		int m = to_leaf[n2];
		if ( m > max1) {
			max2 = max1;
			max1 = m;
		} else if (m > max2) {
			max2 = m;
		}
		num_children++;
	}

	//cout << "n: " << n << ", max1: " << max1 << ", max2: " << max2 << ", num_children: " << num_children << endl;

	max_length[n] = max1 + max2 +  (num_children > 2 ? 2 :  num_children);
	if (max_length[n] > diameter)
		diameter = max_length[n];

	to_leaf[n] = max1 + (num_children >= 1 ? 1: 0);

	//cout << "n: " << n << ", to_leaf: " << to_leaf[n] << ", max_length: " << max_length[n] << endl;

}

signed main() {

	int n;
	cin >> n;
	for(int i=0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1, 0);

	cout << diameter << endl;
}