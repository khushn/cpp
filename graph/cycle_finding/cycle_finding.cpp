#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

#define int long long 

const int N = 2501;

int graph[N][N] = {0};
bool g_e[N][N] = {false};
bool visited[N] = {false};
map<int, int> nodes;
stack<int> myst;

int n, m;

bool find_cycle(int n1, int cost, bool *neg_cycle) {
	visited[n1] = true;
	for(int i=1; i<=n; i++) {
		if (!g_e[n1][i])
			continue;


		int c2 = cost + graph[n1][i];
		auto it = nodes.find(i);
		if ( it != nodes.end()) {
			int cur_cost = it->second;
			if (c2 < cur_cost) {
				// negative cycle
				*neg_cycle = true;
				vector<int> cycle_nodes;
				cycle_nodes.push_back(i);
				int tmp = myst.top();
				myst.pop();
				while (tmp != i) {
					cycle_nodes.push_back(tmp);
					tmp = myst.top();
					myst.pop();
				}
				cycle_nodes.push_back(i);
				cout << "YES" << endl;
				for(int j=cycle_nodes.size()-1; j>=0; j--) {
					cout << cycle_nodes[j] << " ";
				}
				cout << endl;
				return true;
			} else {
				// positive cycle
				return true;
			}
		} else {
			nodes[i] = c2;
			myst.push(i);
			int ret = find_cycle(i, c2, neg_cycle);
			nodes.erase(i);
			myst.pop();
			if (ret && *neg_cycle) {
				return true;
			}
		}
	}

	return false;
}

signed main() {

	
	cin >> n >> m;	
	for(int i=1; i<=m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
		g_e[a][b] = true;
	}

	for(int i=1; i<=n; i++) {
		if (visited[i])
			continue;

		bool neg_cycle = false;
		nodes[i] = 0;
		myst.push(i);
		bool ret = find_cycle(i, 0, &neg_cycle);

		if (ret && neg_cycle) {
			// negative cycle found
			// print and return;

			//cout << "ret: " << ret << endl;
			//cout << "neg_cycle: " << neg_cycle << endl;
			return 0;
		}

		nodes.erase(i);
		myst.pop();
	}

	cout << "NO" << endl;


}


