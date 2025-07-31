#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
Algo:
1. Just populated the graph in vec of vec structure (outer is all the n nodes)
2. Put each connected graph unique node in another vec (using a set for bookkeeping)
3. just form k-1 edhes in the k uniqie nodes (one per each connected graph)
*/

signed main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n+1, vector<int>());
	for(int i=0; i<m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}

	/*
	// debug print
	for(int i=1; i<=n; i++) {
		vector<int> nodes = graph[i];
		cout << i << " -- ";
		for(int nd: nodes)
			cout << nd << " ";
		cout << endl;
	}
	cout << "----" << endl;
	*/

	vector<int> unique_graph_nodes;
	vector<bool> visited(n+1);
	for(int i=1; i<=n; i++) {

		if (visited[i])
			continue;

		unique_graph_nodes.push_back(i);

		queue<int> q;
		q.push(i);
		while(!q.empty()) {
			int nd = q.front();
			q.pop();

			if (visited[nd])
				continue;
			
			visited[nd] = true;

			vector<int> child_nodes = graph[nd];
			for (int ch: child_nodes)
				q.push(ch);
				
		}		
	}

	cout << unique_graph_nodes.size() - 1 << endl;

	for(int i=0; i<unique_graph_nodes.size()-1; i++)
		cout << unique_graph_nodes[i] << " " << unique_graph_nodes[i+1] << endl;

}