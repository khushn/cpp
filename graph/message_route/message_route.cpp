#include <iostream>
#include <vector>
#include <queue>

using namespace std;

signed main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n+1, vector<int>());
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
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

	vector<bool> visited(n+1);
	vector<pair<int, int>> cost(n+1, pair<int, int>());
	queue<int> q;
	cost[n]=make_pair(0, -1);
	visited[n] = true;
	q.push(n);
	while(!q.empty()){
		int id = q.front();
		q.pop();

		for(int nd: graph[id]) {
			if (visited[nd])
				continue;

			visited[nd] = true;

			cost[nd] = make_pair(cost[id].first+1, id);
			q.push(nd);
		}
	}

	/*
	// debug print
	for(int i=1; i<=n; i++)
		cout << cost[i].first << " : " << cost[i].second << endl;
	*/

	int id = 1;
	auto cur_node = cost[id];
	if( cur_node.first == 0) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << cur_node.first + 1 << endl;
		while (id != -1) {
			cout << id << " ";
			id = cur_node.second;			
			cur_node = cost[id];
		}
		cout << endl;
	}
}