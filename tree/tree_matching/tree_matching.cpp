#include <iostream>
#include <set>
#include <vector>

using namespace std;


/*
Approach 2. 
1. construct the tree
2. Randomly assign a node as root. 
3. Traverse using dfs
4. Maintain used edges in a hash set. 
5. Add to hashset only if both nodes not present and count it.
Just based on what needs to be done (not even considering tree pov)

*/

int uniq_pairs = 0;
set<int> myset;
vector<vector<int>> adj;

void dfs(int s, int e);

signed main() {
	int n;
	cin >> n;
	adj.resize(n+1);
	
	
	for(int i=0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1,0);

	cout << uniq_pairs << endl;
}

void dfs(int s, int e) {

	for(auto n: adj[s]) {
		if (n != e) {
			//cout << "recursive call dfs(" << n << ", " << s << ")" << endl;
			dfs(n, s);
		}
	}

	if (e!= 0) {
		
		if (myset.find(s) == myset.end() && myset.find(e) == myset.end()) {
			uniq_pairs++;
			//cout << "uniq_pairs: " << uniq_pairs << endl;
			myset.insert(s);
			myset.insert(e);
		}
	}
}