#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

signed main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));
	set<pair<int, int>> nodes;
	for(int i=0;i<n; i++ ) {
		for(int j=0; j<m; j++) {
			char ch;
			cin >> ch;
			v[i][j] == ch;
			if (ch == '.')
				nodes.insert(make_pair(i, j));

		}
	}

	//cout << "nodes.size() : " << nodes.size() << endl;

	int num_connected_graphs = 0;
	while(!nodes.empty()) {
		auto it = nodes.begin();
		int i = it->first;
		int j = it->second;
		//cout << "coming in for graph, having node i: " << i << ", j: " << j << endl;
		queue<pair<int, int>> q;
		q.push(make_pair(i, j));
		nodes.erase(make_pair(i, j));
		while(!q.empty()) {
			auto elem = q.front();
			q.pop();
			int i = elem.first;
			int j = elem.second;
			

			// check top
			if (i>0 && nodes.find(make_pair(i-1, j)) != nodes.end()) {
				q.push(make_pair(i-1, j));
				nodes.erase(make_pair(i-1, j));
			}

			// check right
			if (j<m-1 && nodes.find(make_pair(i, j+1)) != nodes.end()) {
				q.push(make_pair(i, j+1));
				nodes.erase(make_pair(i, j+1));
			}

			// check left
			if (j>0 && nodes.find(make_pair(i, j-1)) != nodes.end()) {
				q.push(make_pair(i, j-1));
				nodes.erase(make_pair(i, j-1));
			}

			// check bottom
			if (i<n-1 && nodes.find(make_pair(i+1, j)) != nodes.end()) {
				q.push(make_pair(i+1, j));
				nodes.erase(make_pair(i+1, j));
			}
		}
		
		num_connected_graphs++;
	}


	cout << num_connected_graphs << endl;
}