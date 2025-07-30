#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

/*
Just counting number of connected graphs, which would translate to counting rooms.
2nd attempt to avoid TLE (not using a set in this case)
*/

signed main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m));
	//set<pair<int, int>> nodes;
	vector<pair<int, int>> nodes;
	for(int i=0;i<n; i++ ) {
		for(int j=0; j<m; j++) {
			char ch;
			cin >> ch;
			v[i][j] == ch;
			if (ch == '.') {				
				nodes.push_back(make_pair(i, j));
			} else {
				visited[i][j] = true; // need it for wall, for traversal later on
			}

		}
	}

	// cout << "nodes.size() : " << nodes.size() << endl;

	int num_connected_graphs = 0;
	for(auto &node : nodes) {
		int i = node.first;
		int j = node.second;
		if (visited[i][j])
			continue;

		// cout << "coming in for graph, having node i: " << i << ", j: " << j << endl;
		queue<pair<int, int>> q;
		q.push(make_pair(i, j));
		visited[i][j] = true;
		//nodes.erase(make_pair(i, j));
		while(!q.empty()) {
			auto elem = q.front();
			q.pop();
			int i = elem.first;
			int j = elem.second;
			

			// check top
			if (i>0 && !visited[i-1][j]) {
				q.push(make_pair(i-1, j));
				//nodes.erase(make_pair(i-1, j));
				visited[i-1][j] = true;
			}

			// check right
			if (j<m-1 && !visited[i][j+1]) {
				q.push(make_pair(i, j+1));
				//nodes.erase(make_pair(i, j+1));
				visited[i][j+1] = true;
			}

			// check left
			if (j>0 && !visited[i][j-1]) {
				q.push(make_pair(i, j-1));
				//nodes.erase(make_pair(i, j-1));
				visited[i][j-1] = true;
			}

			// check bottom
			if (i<n-1 && !visited[i+1][j]) {
				q.push(make_pair(i+1, j));
				//nodes.erase(make_pair(i+1, j));
				visited[i+1][j] = true;
			}
		}
		
		num_connected_graphs++;
	}


	cout << num_connected_graphs << endl;
}