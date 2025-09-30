#include <iostream> 
#include <vector>

using namespace std;

/*
We just need to implement a count function i.e size of subtree (includnig the node)
at every node. 
We can use DFS and dp

*/

int n;
vector<int> count;
vector<vector<int>> adj;

void dfs(int s, int e);

signed main() {
	cin >> n;
	count.resize(n+1);
	adj.resize(n+1);

	for(int i=2; i<=n; i++) {
		int p;
		cin >> p;
		adj[i].push_back(p);
		adj[p].push_back(i);
	}

	dfs(1, 0);
	for(int i=1; i<=n; i++) {
		cout << count[i]-1 << " ";
	}
	cout << endl;
}


void dfs(int s, int e) {
	count[s] = 1;
	for(auto n: adj[s]) {
		if (n != e) {
			dfs(n, s);
			count[s] += count[n];
		}
	}

}