#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <map>

using namespace std;

/*
Implemented a BFS startng at node B. Adding from the initial distance in each neighbors. 
Then start from A and print as per decreasing distance.

NOTE: The program must return 0, else gives run time error by CSES site, even though output matches.
*/

signed main() {
	int n, m;
	cin >> n >> m;

	vector<string> inp(n);
	vector<vector<int>> graph(n, vector<int>(m));
	int si, sj, ei, ej;
	for(int i=0; i<n; i++) {
		cin >> inp[i];
		for(int j=0; j<m; j++) {
			if (inp[i][j] == '#')
				graph[i][j] = -1;
			else if(inp[i][j] == 'A') {
				si = i;
				sj = j;
				graph[i][j] = INT_MAX;
			} else if(inp[i][j] == 'B') {
				ei = i;
				ej = j;
				graph[i][j] = 0;
			} else {
				graph[i][j] = INT_MAX;
			}
		}
	}

	/*
	// debug print
	for(int i=0; i<n; i++) {
		cout << inp[i] << endl;
		for(int j=0; j<m; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	*/

	// traverse the graph using DFS
	// starting at 'B' i.e. ei, ej
	queue<pair<int, int>> q;
	q.push(make_pair(ei, ej));
	while(!q.empty()) {
		auto pr = q.front(); q.pop();
		int i = pr.first;
		int j = pr.second;
		
		pair<int, int> neighbors[] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
		for (auto [di, dj]: neighbors) {
			int neb_i = i + di;
			int neb_j = j + dj;
			if (neb_i >=0 && neb_i < n && neb_j >=0 && neb_j < m) {
				if (graph[neb_i][neb_j] == INT_MAX) {
					graph[neb_i][neb_j] = graph[i][j] + 1;
					q.push(make_pair(neb_i, neb_j));
				}
			}
		}

	}

	//cout << "coming here" << endl;

	int num_steps = graph[si][sj];

	if( num_steps == INT_MAX) {
		cout << "NO" << endl;
		return 0;
	} else {
		cout << "YES" << endl;
	}
	cout <<  num_steps << endl;
	int r = si;
	int c = sj;

	map<pair<int, int>, char> dir_map;
	dir_map[make_pair(1,0)] = 'D';
	dir_map[make_pair(-1,0)] = 'U';
	dir_map[make_pair(0,-1)] = 'L';
	dir_map[make_pair(0,1)] = 'R';
	for(int num=num_steps-1; num >= 0; num--) {
		for(const auto &it : dir_map) {
			int i = r + it.first.first;
			int j = c + it.first.second;
			char dir = it.second;
			if( i >=0 && i<n && j>=0 && j<m && graph[i][j] == num) {
				cout << dir;
				r = i;
				c = j;
				break;
			}
		}

	}
	cout << endl;

}